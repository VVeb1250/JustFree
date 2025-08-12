#pragma once
#include <unordered_map>
#include "role.h"
#include "pattern_factory.h"

template<typename T>
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
    static const MovementPattern<T>& get(role _role) {
        static std::unordered_map<role, MovementPattern<T>> cache;
        if (cache.empty()) {
            // Initialize all patterns
            auto& v = cache[role::vanguard];
            v.addPatternRule(vanguard_pattern);

            auto& t = cache[role::tank];
            t.addPatternRule(tank_pattern);

            auto& m = cache[role::mage];
            m.addPatternRule(mage_pattern);

            auto& kn = cache[role::knight];
            kn.addPatternRule(knight_pattern);

            auto& a = cache[role::archer];
            a.addPatternRule(archer_pattern);

            auto& s = cache[role::striker];
            s.addPatternRule(striker_pattern);

            auto& c = cache[role::crusader];
            c.addPatternRule(crusader_pattern);

            auto& as = cache[role::assassin];
            as.addPatternRule(assassin_pattern);

            auto& r = cache[role::rook];
            // r.addPatternRule(rook_pattern);
            r.addLineRule({{1,0},{0,1},{-1,0},{0,-1}}, 3, true);

            auto& b = cache[role::bishop];
            // b.addPatternRule(bishop_pattern);
            b.addLineRule({{1,1},{1,-1},{-1,1},{-1,-1}}, 3, true);

            auto& g = cache[role::grandmaster];
            g.addPatternRule(grandmaster_pattern);
            g.addLineRule({{1,1},{1,-1},{-1,1},{-1,-1}}, 2, true);

            auto& q = cache[role::queen];
            q.addPatternRule(queen_pattern);

            auto& k = cache[role::king];
            k.addPatternRule(king_pattern);
        }
        return cache.at(_role);
    }
};

// --- Patterns --- //
template<typename T>
const bool role_movement<T>::vanguard_pattern[7][7] = {
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,1,1,1,0,0},
    {0,0,1,0,1,0,0},
    {0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
};
template<typename T>
const bool role_movement<T>::tank_pattern[7][7] = {
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0},
    {0,0,1,0,1,0,0},
    {0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
};
template<typename T>
const bool role_movement<T>::mage_pattern[7][7] = {
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,1,0,1,0,0},
    {0,0,0,0,0,0,0},
    {0,0,1,0,1,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
};
template<typename T>
const bool role_movement<T>::knight_pattern[7][7] = {
    {0,0,0,0,0,0,0},
    {0,0,1,0,1,0,0},
    {0,1,0,0,0,1,0},
    {0,0,0,0,0,0,0},
    {0,1,0,0,0,1,0},
    {0,0,1,0,1,0,0},
    {0,0,0,0,0,0,0},
};
template<typename T>
const bool role_movement<T>::archer_pattern[7][7] = {
    {0,0,0,0,0,0,0},
    {0,1,0,1,0,1,0},
    {0,0,0,0,0,0,0},
    {0,1,0,0,0,1,0},
    {0,0,0,0,0,0,0},
    {0,1,0,1,0,1,0},
    {0,0,0,0,0,0,0},
};
template<typename T>
const bool role_movement<T>::striker_pattern[7][7] = {
    {0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0},
    {0,0,1,0,1,0,0},
    {0,1,0,0,0,1,0},
    {0,0,1,0,1,0,0},
    {0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0},
};
template<typename T>
const bool role_movement<T>::crusader_pattern[7][7] = {
    {0,0,0,1,0,0,0},
    {0,0,0,1,0,0,0},
    {0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,1,0,1,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
};
template<typename T>
const bool role_movement<T>::assassin_pattern[7][7] = {
    {0,0,0,0,0,0,0},
    {0,0,1,0,1,0,0},
    {1,0,0,0,0,0,1},
    {0,1,0,0,0,1,0},
    {1,0,0,0,0,0,1},
    {0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0},
};
template<typename T>
const bool role_movement<T>::rook_pattern[7][7] = {
    {0,0,0,1,0,0,0},
    {0,0,0,1,0,0,0},
    {0,0,0,1,0,0,0},
    {1,1,1,0,1,1,1},
    {0,0,0,1,0,0,0},
    {0,0,0,1,0,0,0},
    {0,0,0,1,0,0,0},
};
template<typename T>
const bool role_movement<T>::bishop_pattern[7][7] = {
    {1,0,0,0,0,0,1},
    {0,1,0,0,0,1,0},
    {0,0,1,0,1,0,0},
    {0,0,0,0,0,0,0},
    {0,0,1,0,1,0,0},
    {0,1,0,0,0,1,0},
    {1,0,0,0,0,0,1},
};
template<typename T>
const bool role_movement<T>::grandmaster_pattern[7][7] = {
    {0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {1,0,0,0,0,0,1},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0},
};
template<typename T>
const bool role_movement<T>::queen_pattern[7][7] = {
    {0,0,0,1,0,0,0},
    {0,1,0,0,0,1,0},
    {0,0,0,1,0,0,0},
    {1,0,1,0,1,0,1},
    {0,0,0,1,0,0,0},
    {0,1,0,0,0,1,0},
    {0,0,0,1,0,0,0},
};
template<typename T>
const bool role_movement<T>::king_pattern[7][7] = {
    {0,0,1,0,1,0,0},
    {0,0,0,1,0,0,0},
    {1,0,1,0,1,0,1},
    {0,1,0,0,0,1,0},
    {1,0,1,0,1,0,1},
    {0,0,0,1,0,0,0},
    {0,0,1,0,1,0,0},
};