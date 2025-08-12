#pragma once

struct board_position {
    int x, y;
    board_position(int x = 0, int y = 0) : x(x), y(y) {}
    
    template<typename T>
    bool equal(T& compare) {
        if (this->x == compare.x && this->y == compare.y) { return true; }
        return false;
    }
};
