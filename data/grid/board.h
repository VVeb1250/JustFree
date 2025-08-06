#pragma once
#include <stdint.h>
#include <vector>
#include <optional>
#include <iostream>
#include "..\..\util\validator.h"

using namespace std;

template <typename T>
class Board
{
private:
    vector<vector<T*>> items;
    int width_digits;
    int width;
    int height;

    int raw_log(int num, int total = 1) {
        if (num == 10) return total + 1;
        if (num < 10) return total;
        return raw_log(num / 10, total + 1);
    }
    string spacing_width(const int& space) {
        return string(space, ' ');
    }
    void print_width_Board() {
        for (int j = 0; j < height; j++) {
            cout << "+---";
        } cout << "+" << endl;
    }
public:
    Board(int widths, int heights, default_location) : width(widths), height(heights), 
    items(widths, vector<T*>(heights, nullptr)), width_digits(raw_log(widths)) { 
        validator::non_negative("width", widths, sent_location);
        validator::non_negative("height", heights, sent_location);
        validator::not_exceed<decltype(width)>("width", widths, sent_location);
        validator::not_exceed<decltype(height)>("height", heights, sent_location);
        validator::morethan(26, "width", widths, sent_location);
        validator::morethan(26, "height", heights, sent_location);
    }
    
    void add(T& obj, int x, int y, default_location) {
        validator::non_negative("x", x, sent_location);
        validator::non_negative("y", y, sent_location);
        validator::morethan(width, "width", x - 1, sent_location);
        validator::morethan(height, "height", y - 1, sent_location);
        if (items[x][y] == nullptr) { items[x][y] = &obj; } 
        else { cout << "[warning]" << obj.name << ": this position already has " << items[x][y]->name <<", use " << items[x][y]->name << " instead." << endl; }
    }
    void tostring() {
        string width_space = spacing_width(width_digits);

        // print header
        cout << width_space;
        for (int i = 0; i < height; i++) {
            cout << "   " << static_cast<char>('A' + i) ;
        } cout << endl;

        // print Board
        for (int y = 0; y < width; y++) {
            cout << width_space << " ";
            print_width_Board();
            cout << spacing_width(width_digits - raw_log(y)) << y << " ";
            // print inside data
            for (int x = 0; x < height; x++) {
                cout << "| ";
                if (items[x][y] == nullptr) { cout << " "; } 
                else { cout << items[x][y]->getFirstName(); }
                cout << " ";
            } cout << "|" << endl;
        }
        cout << width_space << " ";
        print_width_Board();
    }
};

#undef entity
#undef position

//   
// + - + - +
// |   | s |
// + - + - +