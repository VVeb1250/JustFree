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
    int row_digits;
    int row;
    int col;

    int raw_log(int num, int total = 1) {
        if (num == 10) return total + 1;
        if (num < 10) return total;
        return raw_log(num / 10, total + 1);
    }
    string spacing_row(const int& space) {
        return string(space, ' ');
    }
    void print_row_Board() {
        for (int j = 0; j < col; j++) {
            cout << "+---";
        } cout << "+" << endl;
    }
public:
    Board(int rows, int cols, default_location) : row(rows), col(cols), 
    items(rows, vector<T*>(cols, nullptr)), row_digits(raw_log(rows)) { 
        validator::non_negative("row", rows, sent_location);
        validator::non_negative("col", cols, sent_location);
        validator::not_exceed<decltype(row)>("row", rows, sent_location);
        validator::not_exceed<decltype(col)>("col", cols, sent_location);
        validator::morethan(26, "row", rows, sent_location);
        validator::morethan(26, "col", cols, sent_location);
    }
    
    void add(T& obj, int x, int y, default_location) {
        validator::non_negative("x", x, sent_location);
        validator::non_negative("y", y, sent_location);
        validator::morethan(row, "row", x - 1, sent_location);
        validator::morethan(col, "col", y - 1, sent_location);
        if (items[x][y] == nullptr) { items[x][y] = &obj; } 
        else { cout << "[warning]" << obj.name << ": this position already has " << items[x][y]->name <<", use " << items[x][y]->name << " instead." << endl; }
    }
    void tostring() {
        string row_space = spacing_row(row_digits);

        // print header
        cout << row_space;
        for (int i = 0; i < col; i++) {
            cout << "   " << static_cast<char>('A' + i) ;
        } cout << endl;

        // print Board
        for (int y = 0; y < row; y++) {
            cout << row_space << " ";
            print_row_Board();
            cout << spacing_row(row_digits - raw_log(y)) << y << " ";
            // print inside data
            for (int x = 0; x < col; x++) {
                cout << "| ";
                if (items[x][y] == nullptr) { cout << " "; } 
                else { cout << items[x][y]->getFirstName(); }
                cout << " ";
            } cout << "|" << endl;
        }
        cout << row_space << " ";
        print_row_Board();
    }
};

#undef entity
#undef position

//   
// + - + - +
// |   | s |
// + - + - +