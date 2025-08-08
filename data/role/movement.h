#pragma once
#include "role.h"

class role_movement {
private:
    static const bool vanguard_pattern[7][7];
    static const bool tank_pattern[7][7];
    static const bool mage_pattern[7][7];
    static const bool knight_pattern[7][7];
    static const bool archer_pattern[7][7];
    static const bool striker_pattern[7][7];
    static const bool crusader_pattern[7][7];
    static const bool assassin_pattern[7][7];
    static const bool rook_pattern[7][7];
    static const bool bishop_pattern[7][7];
    static const bool grandmaster_pattern[7][7];
    static const bool queen_pattern[7][7];
    static const bool king_pattern[7][7];
    
public:
    
};

// --- Patterns --- //
const bool role_movement::vanguard_pattern[7][7] = {
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,1,1,1,0,0},
    {0,0,1,0,1,0,0},
    {0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
};
const bool role_movement::tank_pattern[7][7] = {
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0},
    {0,0,1,0,1,0,0},
    {0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
};
const bool role_movement::mage_pattern[7][7] = {
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,1,0,1,0,0},
    {0,0,0,0,0,0,0},
    {0,0,1,0,1,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
};
const bool role_movement::knight_pattern[7][7] = {
    {0,0,0,0,0,0,0},
    {0,0,1,0,1,0,0},
    {0,1,0,0,0,1,0},
    {0,0,0,0,0,0,0},
    {0,1,0,0,0,1,0},
    {0,0,1,0,1,0,0},
    {0,0,0,0,0,0,0},
};
const bool role_movement::archer_pattern[7][7] = {
    {0,0,0,0,0,0,0},
    {0,1,0,1,0,1,0},
    {0,0,0,0,0,0,0},
    {0,1,0,0,0,1,0},
    {0,0,0,0,0,0,0},
    {0,1,0,1,0,1,0},
    {0,0,0,0,0,0,0},
};
const bool role_movement::striker_pattern[7][7] = {
    {0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0},
    {0,0,1,0,1,0,0},
    {0,1,0,0,0,1,0},
    {0,0,1,0,1,0,0},
    {0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0},
};
const bool role_movement::crusader_pattern[7][7] = {
    {0,0,0,1,0,0,0},
    {0,0,0,1,0,0,0},
    {0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,1,0,1,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
};
const bool role_movement::assassin_pattern[7][7] = {
    {0,0,0,0,0,0,0},
    {0,0,1,0,1,0,0},
    {1,0,0,0,0,0,1},
    {0,1,0,0,0,1,0},
    {1,0,0,0,0,0,1},
    {0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0},
};
const bool role_movement::rook_pattern[7][7] = {
    {0,0,0,1,0,0,0},
    {0,0,0,1,0,0,0},
    {0,0,0,1,0,0,0},
    {1,1,1,0,1,1,1},
    {0,0,0,1,0,0,0},
    {0,0,0,1,0,0,0},
    {0,0,0,1,0,0,0},
};
const bool role_movement::bishop_pattern[7][7] = {
    {1,0,0,0,0,0,1},
    {0,1,0,0,0,1,0},
    {0,0,1,0,1,0,0},
    {0,0,0,0,0,0,0},
    {0,0,1,0,1,0,0},
    {0,1,0,0,0,1,0},
    {1,0,0,0,0,0,1},
};
const bool role_movement::grandmaster_pattern[7][7] = {
    {0,0,0,1,0,0,0},
    {0,1,0,0,0,1,0},
    {0,0,1,0,1,0,0},
    {1,0,0,0,0,0,1},
    {0,0,1,0,1,0,0},
    {0,1,0,0,0,1,0},
    {0,0,0,1,0,0,0},
};
const bool role_movement::queen_pattern[7][7] = {
    {0,0,0,1,0,0,0},
    {0,1,0,0,0,1,0},
    {0,0,0,1,0,0,0},
    {1,0,1,0,1,0,1},
    {0,0,0,1,0,0,0},
    {0,1,0,0,0,1,0},
    {0,0,0,1,0,0,0},
};
const bool role_movement::king_pattern[7][7] = {
    {0,0,1,0,1,0,0},
    {0,0,0,1,0,0,0},
    {1,0,1,0,1,0,1},
    {0,1,0,0,0,1,0},
    {1,0,1,0,1,0,1},
    {0,0,0,1,0,0,0},
    {0,0,1,0,1,0,0},
};