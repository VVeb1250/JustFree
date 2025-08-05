#pragma once
#include "move_type.h"

class role {
private:
    static const bool vanguard_pattern[7][7];
    static const bool mage_pattern[7][7];

public:
    
};

// --- Patterns ---
const bool role::vanguard_pattern[7][7] = {
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,1,1,1,0,0},
    {0,0,1,1,1,0,0},
    {0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
};

const bool role::mage_pattern[7][7] = {
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,1,0,1,0,0},
    {0,0,0,1,0,0,0},
    {0,0,1,0,1,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
};