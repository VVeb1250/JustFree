#pragma once

// low tier : vanguard,tank,mage
// mid tier : knight,archer,striker,crusader
// top tier : assassin,rook,bishop
// god tier : grandmaster,queen,king

// max 8 pawn
// god tier - 1
// top tier - 1
// mid tier - 2
// low tier - 4 

// max 16 pawn
// god tier - 2
// top tier - 2
// mid tier - 4
// low tier - 8 

enum class role {
    vanguard, // around 1 range 
    /*
    - - - - - - -
    - - - - - - -
    - - * * * - -
    - - * V * - -
    - - * * * - -
    - - - - - - -
    - - - - - - -
    */
    tank, // plus 1 range
    /*
    - - - - - - -
    - - - - - - -
    - - - * - - -
    - - * T * - -
    - - - * - - -
    - - - - - - -
    - - - - - - -
    */
    mage, // cross 1 range
    /*
    - - - - - - -
    - - - - - - -
    - - * - * - -
    - - - M - - -
    - - * - * - -
    - - - - - - -
    - - - - - - -
    */
    knight, // L shape
    /*
    - - - - - - -
    - - * - * - -
    - * - - - * -
    - - - K - - -
    - * - - - * -
    - - * - * - -
    - - - - - - -
    */
    archer, // cross + plus 2 range
    /*
    - - - - - - -
    - * - * - * -
    - - - - - - -
    - * - A - * -
    - - - - - - -
    - * - * - * -
    - - - - - - -
    */
    striker, // cross + plus 2 range with inner pattern
    /*
    - - - - - - -
    - - - * - - -
    - - * - * - -
    - * - S - * -
    - - * - * - -
    - - - * - - -
    - - - - - - -
    */
    crusader, // straight 3 range + cross backward 1
    /*
    - - - * - - -
    - - - * - - -
    - - - * - - -
    - - - C - - -
    - - * - * - -
    - - - - - - -
    - - - - - - -
    */
    assassin, // space cross + plus
    /*
    - - - - - - -
    - - * - * - -
    * - - - - - *
    - * - A - * -
    * - - - - - *
    - - - * - - -
    - - - - - - -
    */
    rook, // plus in full range
    /*
    - - - * - - -
    - - - * - - -
    - - - * - - -
    * * * R * * *
    - - - * - - -
    - - - * - - -
    - - - * - - -
    */
    bishop, // cross full range
    /*
    * - - - - - *
    - * - - - * -
    - - * - * - -
    - - - B - - -
    - - * - * - -
    - * - - - * -
    * - - - - - *
    */
    grandmaster , // circle sharp
    /*
    - - - * - - -
    - * - - - * -
    - - * - * - -
    * - - G - - *
    - - * - * - -
    - * - - - * -
    - - - * - - -
    */
    queen, // circle soft
    /*
    - - - * - - -
    - * - - - * -
    - - - * - - -
    * - * Q * - *
    - - - * - - -
    - * - - - * -
    - - - * - - -
    */
    king // circle tactical
    /*
    - - * - * - -
    - - - * - - -
    * - * - * - *
    - * - K - * -
    * - * - * - *
    - - - * - - -
    - - * - * - -
    */
};

/*
???
- - - - - - -
- - - - - - -
- - - - - - -
- - - ? - - -
- - - - - - -
- - - - - - -
- - - - - - -
*/

#include <unordered_map>

namespace role_data {
    static const std::string getRoleName(role _role) {
        static std::unordered_map<role, std::string> cache;
        if (cache.empty()) {
            cache[role::vanguard] = "vanguard";
            cache[role::tank] = "tank";
            cache[role::mage] = "mage";
            cache[role::knight] = "knight";
            cache[role::archer] = "archer";
            cache[role::striker] = "striker";
            cache[role::crusader] = "crusader";
            cache[role::assassin] = "assassin";
            cache[role::rook] = "rook";
            cache[role::bishop] = "bishop";
            cache[role::grandmaster] = "grandmaster";
            cache[role::queen] = "queen";
            cache[role::king] = "king";
        }
        return cache.at(_role);
    }
}