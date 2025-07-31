#pragma once
#include "..\..\util\calculate.h"

using namespace constants;
/**
 * @brief using ACC, EVA
 * @param chanceDodge in %
 * @param reduceDamage in %
 * @param canDodge true or false
 * @param multiplier x0.---- for final damage
 */ 
class DodgeCalculator {
private:
    float multiplier;
    float reduceDamage; // value in %
    float chanceDodge; // value in %
    bool canDodge;

    static constexpr float EVA_MULTIPLY = 1.5f; // make more possible dodge stat for easier dodge
    static constexpr uint_fast16_t FIX_HALF_DODGE = 100; // stat make 50% dodge
    static constexpr uint_fast8_t MIN_reducedamage = 40; // higest damage can take(%)
    static constexpr uint_fast8_t MAX_reducedamage = 10; // lowest damage can take(%)
    
public:
    DodgeCalculator() { }
    // getter
    inline float getMultiplier() { return multiplier; }
    inline float getReduceDamage() { return reduceDamage; }
    inline float getChanceDodge() { return chanceDodge; }
    inline bool isDodge() { return canDodge; }
    // reset dodge to false
    inline void resetCanDodge() { canDodge = false; }

    // calculate possible dodge from ACC / EVA
    template<typename T>
    float __cal_possibleDodge(const T& ACC, const T& EVA) {
        float new_EVA = EVA * EVA_MULTIPLY;
        if (ACC >= new_EVA) { return 0.0f; }
        float temp = std::round(static_cast<float>(ACC) * f_10000 / new_EVA) * INV_100;
        return f_100 - (temp + (std::round(function::computeY(f_100-temp, FIX_HALF_DODGE, new_EVA) * f_100) * INV_100));
    }
    // call multiplier from possibleDodge (so complex TT)
    float __cal_multiplier(float& multiplier, const float& possibleDodge) {
        multiplier = (((f_100 - possibleDodge) - MIN_reducedamage) * INV_100);
        multiplier = multiplier + function::computeY(
            possibleDodge / ((f_100 / (MAX_reducedamage + MIN_reducedamage)) * f_100), 
            possibleDodge, 
            multiplier
        );
        return multiplier;
    }
    // call randomSuscess to return canDodge or not
    bool __cal_canDodge(const float& possibleDodge) {
        return random::randomSuscess(possibleDodge);
    }
    // calculate reducedamage from possibleDodge and have damage floor
    float __cal_reducedamage(const float& possibleDodge) {
        multiplier = __cal_multiplier(multiplier, possibleDodge);
        return std::round((f_100 - (multiplier * f_100)) * f_10000) * INV_10000;
    }
    // complete dodge damage calculator
    template<typename R, typename T>
    R apply(const R& DMG, const T& ACC, const T& EVA) {
        chanceDodge = __cal_possibleDodge(ACC, EVA);
        canDodge = __cal_canDodge(chanceDodge);
        if (canDodge) {
            reduceDamage =  __cal_reducedamage(chanceDodge);
            return std::round(multiplier * DMG);
        } else { return DMG; }
    }
    /**
     * @brief update dodge value
     * @param chanceDodge in %
     * @param reduceDamage in %
     * @param multiplier x0.---- for cal final damage
     */
    template<typename T>
    void update_value(const T& ACC, const T& EVA) {
        chanceDodge = __cal_possibleDodge(ACC, EVA);
        reduceDamage =  __cal_reducedamage(chanceDodge);
        multiplier = __cal_multiplier(multiplier, chanceDodge);
    }
};