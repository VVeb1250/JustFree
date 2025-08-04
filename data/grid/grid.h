#pragma once
#include <stdint.h>
#include <vector>
#include <iostream>
#include "..\..\util\validator.h"

#define entity first;
#define position second;

using namespace std;

template <typename T1, typename T2>
class combat_area
{
private:
    vector<vector<pair<T1, T2>>> grid;
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
    void print_row_grid() {
        for (int j = 0; j < col; j++) {
            cout << "+ - ";
        } cout << "+" << endl;
    }
public:
    combat_area(int row, int col, default_location) : row(row), col(col), 
    grid(row, vector<T>(col)), row_digits(raw_log(row)) { 
        validator::non_negative("row", row, sent_location);
        validator::non_negative("col", col, sent_location);
        validator::not_exceed<decltype(row)>("row", row, sent_location);
        validator::not_exceed<decltype(col)>("col", col, sent_location);
        validator::morethan(26, "row", row, sent_location);
        validator::morethan(26, "col", col, sent_location);
    }


    void tostring() {
        string row_space = spacing_row(row_digits);

        // print position
        cout << row_space;
        for (int i = 0; i < col; i++) {
            cout << "   " << static_cast<char>('A' + i) ;
        } cout << endl;

        // print grid
        for (int i = 0; i < row; i++) {
            cout << row_space << " ";
            for (int j = 0; j < col; j++) {
                cout << "+ - ";
            } cout << "+" << endl;
            cout << spacing_row(row_digits - raw_log(i)) << i << " ";
            for (int j = 0; j < col; j++) {
                cout << "| " << " " << " ";
            } cout << "|" << endl;
        }
        cout << row_space << " ";
        for (int j = 0; j < col; j++) {
            cout << "+ - ";
        } cout << "+" << endl;
    }
};

#undef entity
#undef position

//   
// + - + - +
// |   | s |
// + - + - +