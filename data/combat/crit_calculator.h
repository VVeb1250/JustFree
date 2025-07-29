#pragma once
#include "../../util/calculate.h"

using namespace constants;
/**
 * @brief using CR, CDMG, CDEF 
 * @param critRate in %
 * @param isCrit true or false
 * @param multiplier lowest x1, highest x655.35
 */
class CritCalculator {
private:
    float multiplier;
    float critRate;
    bool isCrit;

    static constexpr float FIX_LOWEST_CDMG = 1.5f; // mininum multiplier if it crit
    static constexpr float FIX_LOWEST_EQUAL = 2.0f; // mininum multiplier if CDMG and CDEF is equal
    static constexpr float cal_LOWEST_CDMG = FIX_LOWEST_CDMG - 1.0f;
    static constexpr uint_fast16_t FIX_CR_HALF = 500; // stat of cr to make 50% crit
    
public:
    CritCalculator() { }
    // getter
    inline float getmultiplier() { return multiplier ; }
    inline float getcritRate() { return critRate ; }
    inline bool isCrit() { return isCrit ; }
    //reset crit paramiter
    inline void resetIsCrit() { isCrit = false; }

    // calculate possibleCrit from computeY(CR, FIX_CR_HALF+(CDEF/4))
    template<typename T>
    float __cal_possibleCrit(const T& CR, const T& CDEF) {
        return std::round(function::computeY(CR, FIX_CR_HALF) * f_100) * INV_100; // + (static_cast<float>(CDEF) / 4)
    }
    // call randomSuscess to return canCrit or not
    bool __cal_canCrit(const float& possibleCrit) {
        return random::randomSuscess(possibleCrit);
    }
    // calculate damage and multiplier from CDMG and can take lower from CDEF
    template<typename R, typename T>
    R __cal_criticaldamage(R DMG, const T& CDMG, const T& CDEF) {
        if (CDMG == 0) { multiplier = FIX_LOWEST_CDMG; return DMG; }
        if (CDEF == 0) {
            multiplier = (std::round((CDMG + f_100) * f_100) * INV_10000) + cal_LOWEST_CDMG;
            return std::round(multiplier * DMG);
        }
        // old : use half_param = CDMG, but crit landing high damage even have high CDEF
        float half_param = (CDMG * (FIX_LOWEST_EQUAL - FIX_LOWEST_CDMG) * f_100) / CDEF; // number is maxium equal case
        multiplier = (std::round((static_cast<float>(CDMG) - (function::computeY(CDMG, CDEF, half_param)) + f_100) * f_100) * INV_10000) + cal_LOWEST_CDMG;
        return std::round(multiplier * DMG);
    }
    // complete crit damage calculator 
    template<typename R, typename T>
    R apply(R DMG, const T& CR, const T& CDMG, const T& CDEF) {
        critRate = __cal_possibleCrit(CR, CDEF);
        isCrit = __cal_canCrit(critRate);
        if (isCrit) { return __cal_criticaldamage(DMG, CDMG, CDEF); } 
        else { return DMG; }
    }
    /**
     * @brief update crit value
     * @param critRate in %
     * @param multiplier lowest x1, highest x655.35
     */
    template<typename T>
    void update_value(const T& CR, const T& CDMG, const T& CDEF) {
        critRate = __cal_possibleCrit(CR, CDEF);
        if (CDMG == 0) { multiplier = FIX_LOWEST_CDMG; }
        else if (CDEF == 0) { multiplier = (std::round((CDMG + f_100) * f_100) * INV_10000) + cal_LOWEST_CDMG; }
        else {
            float half_param = (CDMG * (FIX_LOWEST_EQUAL - FIX_LOWEST_CDMG) * f_100) / CDEF; // number is maxium equal case
            multiplier = (std::round((static_cast<float>(CDMG) - (function::computeY(CDMG, CDEF, half_param)) + f_100) * f_100) * INV_10000) + cal_LOWEST_CDMG;
        }
    }
};