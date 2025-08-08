#pragma once
#include "board.h"

template <typename T>
class combat_area : public Board<T>
{
private:
    /* data */
public:
    combat_area(int rows, int cols, default_location) : Board<T>(rows, cols, sent_location) {  } 
};

