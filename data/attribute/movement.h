#pragma once
#include "role.h"

class role {
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

// --- Patterns ---
const bool role::vanguard_pattern[7][7] = {
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,1,1,1,0,0},
    {0,0,1,0,1,0,0},
    {0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
};
const bool role::tank_pattern[7][7] = {
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0},
    {0,0,1,0,1,0,0},
    {0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
};
const bool role::mage_pattern[7][7] = {
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,1,0,1,0,0},
    {0,0,0,0,0,0,0},
    {0,0,1,0,1,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
};
const bool role::knight_pattern[7][7] = {
    {0,0,0,0,0,0,0},
    {0,0,1,0,1,0,0},
    {0,1,0,0,0,1,0},
    {0,0,0,0,0,0,0},
    {0,1,0,0,0,1,0},
    {0,0,1,0,1,0,0},
    {0,0,0,0,0,0,0},
};
const bool role::archer_pattern[7][7] = {
    {0,0,0,0,0,0,0},
    {0,1,0,1,0,1,0},
    {0,0,0,0,0,0,0},
    {0,1,0,0,0,1,0},
    {0,0,0,0,0,0,0},
    {0,1,0,1,0,1,0},
    {0,0,0,0,0,0,0},
};
const bool role::striker_pattern[7][7] = {
    {0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0},
    {0,0,1,0,1,0,0},
    {0,1,0,0,0,1,0},
    {0,0,1,0,1,0,0},
    {0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0},
};
const bool role::crusader_pattern[7][7] = {
    {0,0,0,1,0,0,0},
    {0,0,0,1,0,0,0},
    {0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,1,0,1,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
};
const bool role::assassin_pattern[7][7] = {
    {0,0,0,0,0,0,0},
    {0,0,1,0,1,0,0},
    {1,0,0,0,0,0,1},
    {0,1,0,0,0,1,0},
    {1,0,0,0,0,0,1},
    {0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0},
};
const bool role::rook_pattern[7][7] = {
    {0,0,0,1,0,0,0},
    {0,0,0,1,0,0,0},
    {0,0,0,1,0,0,0},
    {1,1,1,0,1,1,1},
    {0,0,0,1,0,0,0},
    {0,0,0,1,0,0,0},
    {0,0,0,1,0,0,0},
};
const bool role::bishop_pattern[7][7] = {
    {1,0,0,0,0,0,1},
    {0,1,0,0,0,1,0},
    {0,0,1,0,1,0,0},
    {0,0,0,0,0,0,0},
    {0,0,1,0,1,0,0},
    {0,1,0,0,0,1,0},
    {1,0,0,0,0,0,1},
};
const bool role::grandmaster_pattern[7][7] = {
    {0,0,0,1,0,0,0},
    {0,1,0,0,0,1,0},
    {0,0,1,0,1,0,0},
    {1,0,0,0,0,0,1},
    {0,0,1,0,1,0,0},
    {0,1,0,0,0,1,0},
    {0,0,0,1,0,0,0},
};
const bool role::queen_pattern[7][7] = {
    {0,0,0,1,0,0,0},
    {0,1,0,0,0,1,0},
    {0,0,0,1,0,0,0},
    {1,0,1,0,1,0,1},
    {0,0,0,1,0,0,0},
    {0,1,0,0,0,1,0},
    {0,0,0,1,0,0,0},
};
const bool role::king_pattern[7][7] = {
    {0,0,1,0,1,0,0},
    {0,0,0,1,0,0,0},
    {1,0,1,0,1,0,1},
    {0,1,0,0,0,1,0},
    {1,0,1,0,1,0,1},
    {0,0,0,1,0,0,0},
    {0,0,1,0,1,0,0},
};