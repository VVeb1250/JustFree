#pragma once
#include "../../util/calculate.h"

using namespace constants;
/**
 * @brief using DEF, AP
 * @param reduceDamage in %
 * @param multiplier x0.---- for final damage
 */ 
class DefenseCalculator {
private:
    float reduceDamage; // reduce damage in percent
    float multiplier; // final damage multiplier

    static constexpr uint16_t FIX_HALF_DEF = 1000; // stat that make 50% reduce damage

public:
    DefenseCalculator() { }
    // getter
    inline float getReduceDamage() { return reduceDamage; }
    inline float getMultiplier() { return multiplier; }

    // caluculate reduce damage from computeY(DEF, FIX_HALF_DEF+AP)
    template<typename T>
    float __cal_reducedamage(const T& AP, const T& DEF) {
        return (std::round(function::computeY(DEF, FIX_HALF_DEF + AP) * f_10000)) * INV_10000;
    }
    // caluculate reduce damage from 100 - reduceDamage
    template<typename T>
    inline float __cal_multiplier(const T& reduceDamage) {
        return (f_100 - reduceDamage) * INV_100;
    }
    // complete defense calculator
    template<typename R, typename T>
    R apply(R DMG, const T& AP, const T& DEF) {
        reduceDamage = __cal_reducedamage(AP, DEF);
        multiplier = __cal_multiplier(reduceDamage);
        return std::round(multiplier * DMG);
    }
    /**
     * @brief update defense value
     * @param reduceDamage in %
     * @param multiplier x0.---- for cal final damage
     */
    template<typename T>
    void update_value(const T& AP, const T& DEF) {
        reduceDamage = __cal_reducedamage(AP, DEF);
        multiplier = __cal_multiplier(reduceDamage);
    }
};