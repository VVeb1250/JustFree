#pragma once
#include <stdint.h>
#include <vector>
#include <optional>
#include <iostream>
#include <algorithm>
#include "position.h"
#include "..\..\util\validator.h"

// Forward declarations
template<typename T> class MovementPattern;
template<typename T> class role_movement;

#include "..\role\movement.h"
#include "..\role\pattern_factory.h"

using namespace std;

template <typename T>
class Board
{
private:
    vector<vector<T*>> items;
    vector<pair<T*, board_position>> items_position;
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
    
    bool isWithinBounds(int x, int y) const {
        return x >= 0 && x < width && y >= 0 && y < height;
    }
    bool hasObstacle(int x, int y) const {
        return items[x][y] != nullptr;
    }
    void add(T& obj, int x, int y, default_location) {
        validator::non_negative("x", x, sent_location);
        validator::non_negative("y", y, sent_location);
        validator::morethan(width, "width", x - 1, sent_location);
        validator::morethan(height, "height", y - 1, sent_location);
        if (items[x][y] == nullptr) { 
            items[x][y] = &obj;
            items_position.push_back({&obj, board_position(x,y)});
        }
        else {
            T* oldItem = items[x][y];
            cout << "[warning]" << obj.name << ": this position already has " << items[x][y]->name <<", use " << obj.name << " instead." << endl;
            // Find and remove old item from items_position
            auto it = std::find_if(items_position.begin(), items_position.end(),
                [oldItem](const auto& pair) { return pair.first == oldItem; });
        
            if (it != items_position.end()) {
                items_position.erase(it);
            }

            items[x][y] = &obj;
            items_position.push_back({&obj, board_position(x,y)});
        }
    }
    vector<board_position> getMoves(T& obj) const {
        for (const pair<T*, board_position>& check : items_position) {
            if (check.first == &obj) {  // Compare addresses since we store pointers
                const MovementPattern<T>& pattern = role_movement<T>::get(check.first->getRole());
                return pattern.getPossibleMoves(*this, check.second.x, check.second.y);
            }
        }
        return { board_position() };  // Return empty position if not found
    }
    vector<board_position> getAllMoves(T& obj) const {
        for (const pair<T*, board_position>& check : items_position) {
            if (check.first == &obj) {  // Compare addresses since we store pointers
                const MovementPattern<T>& pattern = role_movement<T>::get(check.first->getRole());
                return pattern.getAllPossibleMoves(*this, check.second.x, check.second.y);
            }
        }
        return { board_position() };  // Return empty position if not found
    }
    // bool doMove(T& obj, int x, int y) {

    // }
    bool doMove(T& obj, const board_position& position) {
        // Find obj's current position
        auto it = std::find_if(items_position.begin(), items_position.end(),
            [&obj](const auto& pair) { return pair.first == &obj; });
        
        // If object not found on board, return false
        if (it == items_position.end()) {
            cout << obj.name << " is not on the board." << endl;
            return false;
        }

        // Check if move is valid
        vector<board_position> moveable = getMoves(obj);
        for (board_position& check : moveable) {
            if (check.equal(position)) {
                // Store old position
                board_position oldPos = it->second;
                
                // Update board array
                items[oldPos.x][oldPos.y] = nullptr;
                items[position.x][position.y] = &obj;
                
                // Update position in items_position
                it->second = position;
                
                return true;
            }
        }

        // Move not allowed
        cout << obj.name << " can't move to this position." << endl;
        return false;
    }

    void tostring() {
        string width_space = spacing_width(width_digits);

        // print header
        cout << width_space;
        for (int i = 0; i < height; i++) {
            cout << "   " << static_cast<char>('A' + i) ;
        } cout << endl;

        // gets move able data
        vector<board_position> moveable = getAllMoves(*items_position.at(0).first);

        // print Board
        for (int y = 0; y < width; y++) {
            cout << width_space << " ";
            print_width_Board();
            cout << spacing_width(width_digits - raw_log(y)) << y << " ";
            // print inside data
            for (int x = 0; x < height; x++) {
                // check is can move to that grid first
                bool canMove = false;
                for (board_position check : moveable) {
                    if (x == check.x && y == check.y) {
                        canMove = true;
                        break;
                    }
                }
                cout << "|";
                if (items[x][y] == nullptr) { 
                    cout << " "; 
                    cout << (canMove? "*" : " ");
                    cout << " "; 
                } 
                else { 
                    cout << (canMove? "-" : " ");
                    cout << items[x][y]->getFirstName(); 
                    cout << (canMove? "-" : " ");
                }
            } cout << "|" << endl;
        }
        cout << width_space << " ";
        print_width_Board();
    }
};

//   
// + - + - +
// |   | s |
// + - + - +