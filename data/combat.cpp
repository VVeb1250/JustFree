#pragma once
#include "../util/calculate.cpp"

namespace combat {
    using namespace constants;
    /**
     * @brief using DEF, AP
     * @param reduceDamage in %
     * @param multiplier x0.---- for final damage
     */ 
    class DefenseCalculator {
    private:
        static float reduceDamage;
        static float multiplier;

        static constexpr uint16_t FIX_HALF_DEF = 1000;

    public:
        DefenseCalculator() { }
        // getter
        inline static float getReduceDamage() { return reduceDamage; }
        inline static float getMultiplier() { return multiplier; }

        // caluculate reduce damage from computeY(DEF, FIX_HALF_DEF+AP)
        template<typename T>
        static float __cal_reducedamage(const T& AP, const T& DEF) {
            return (std::round(function::computeY(DEF, FIX_HALF_DEF + AP) * f_10000)) * INV_10000;
        }
        // complete defense calcilator
        template<typename R, typename T>
        static R applyDefense(R DMG, const T& AP, const T& DEF) {
            reduceDamage = __cal_reducedamage(AP, DEF);
            multiplier = (f_100 - reduceDamage) * INV_100;
            return multiplier * DMG;
        }
        /**
         * @brief update defense value
         * @param reduceDamage in %
         * @param multiplier x0.---- for cal final damage
         */
        template<typename T>
        static void update_value(const T& AP, const T& DEF) {
            reduceDamage = __cal_reducedamage(AP, DEF);
            multiplier = (f_100 - reduceDamage) * INV_100;
        }
    };
    /**
     * @brief using ACC, EVA
     * @param chanceDodge in %
     * @param reduceDamage in %
     * @param canDodge true or false
     * @param multiplier x0.---- for final damage
     */ 
    class DodgeCalculator {
    private:
        static float multiplier;
        static float reduceDamage; // value in %
        static float chanceDodge; // value in %
        static bool canDodge;

        static constexpr float EVA_MULTIPLY = 1.5f; // make more possible dodge stat for easier dodge
        static constexpr uint_fast16_t FIX_HALF_DODGE = 100; // stat make 50% dodge
        static constexpr uint_fast8_t MIN_reducedamage = 40; // higest damage can take(%)
        static constexpr uint_fast8_t MAX_reducedamage = 10; // lowest damage can take(%)
        
    public:
        DodgeCalculator() { }
        // getter
        inline static float getMultiplier() { return multiplier; }
        inline static float getReduceDamage() { return reduceDamage; }
        inline static float getChanceDodge() { return chanceDodge; }
        inline static bool getcanDodge() { return canDodge; }
        // reset dodge to false
        static void resetCanDodge() { canDodge = false; }

        // calculate possible dodge from ACC / EVA
        template<typename T>
        static float __cal_possibleDodge(const T& ACC, const T& EVA) {
            float new_EVA = EVA * EVA_MULTIPLY;
            if (ACC >= new_EVA) { return 0.0f; }
            float temp = std::round(static_cast<float>(ACC) * f_10000 / new_EVA) * INV_100;
            return f_100 - (temp + (std::round(function::computeY(f_100-temp, FIX_HALF_DODGE, new_EVA) * f_100) * INV_100));
        }
        // call randomSuscess to return canDodge or not
        static bool __cal_canDodge(float possibleDodge) {
            return random::randomSuscess(possibleDodge);
        }
        // calculate reducedamage from possibleDodge and have damage floor
        static float __cal_reducedamage(float possibleDodge) {
            multiplier = (((f_100 - possibleDodge) - MIN_reducedamage) * INV_100);
            multiplier = multiplier + function::computeY(
                possibleDodge / ((f_100 / (MAX_reducedamage + MIN_reducedamage)) * f_100), possibleDodge, multiplier
            );
            return std::round((f_100 - (multiplier * f_100)) * f_10000) * INV_10000;
        }
        // complete dodge damage calculator
        template<typename R, typename T>
        static R applyDodge(R DMG, const T& ACC, const T& EVA) {
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
        static void update_value(const T& ACC, const T& EVA) {
            chanceDodge = __cal_possibleDodge(ACC, EVA);
            reduceDamage =  __cal_reducedamage(chanceDodge);
            multiplier = (((f_100 - chanceDodge) - MIN_reducedamage) * INV_100);
            multiplier = multiplier + function::computeY(
                chanceDodge / ((f_100 / (MAX_reducedamage + MIN_reducedamage)) * f_100), chanceDodge, multiplier
            );
        }
    };
    /**
     * @brief using CR, CDMG, CDEF 
     * @param critRate in %
     * @param isCrit true or false
     * @param multiplier lowest x1, highest x655.35
     */
    class CritCalculator {
    private:
        static float multiplier;
        static float critRate;
        static bool isCrit;

        static constexpr float FIX_LOWEST_CDMG = 1.5f; // mininum multiplier if it crit
        static constexpr float FIX_LOWEST_EQUAL = 2.0f; // mininum multiplier if CDMG and CDEF is equal
        static constexpr float cal_LOWEST_CDMG = FIX_LOWEST_CDMG - 1.0f;
        static constexpr uint_fast16_t FIX_CR_HALF = 500; // stat of cr to make 50% crit
        
    public:
        CritCalculator() { }
        // getter
        inline static float getmultiplier() { return multiplier ; }
        inline static float getcritRate() { return critRate ; }
        inline static bool getisCrit() { return isCrit ; }
        //reset crit paramiter
        static void resetIsCrit() { isCrit = false; }

        // calculate possibleCrit from computeY(CR, FIX_CR_HALF+(CDEF/4))
        template<typename T>
        static float __cal_possibleCrit(const T& CR, const T& CDEF) {
            return std::round(function::computeY(CR, FIX_CR_HALF) * f_100) * INV_100; // + (static_cast<float>(CDEF) / 4)
        }
        // call randomSuscess to return canCrit or not
        static bool __cal_canCrit(const float& possibleCrit) {
            return random::randomSuscess(possibleCrit);
        }
        // calculate damage and multiplier from CDMG and can take lower from CDEF
        template<typename R, typename T>
        static R __cal_criticaldamage(R DMG, const T& CDMG, const T& CDEF) {
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
        static R applyCrit(R DMG, const T& CR, const T& CDMG, const T& CDEF) {
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
        static void update_value(const T& CR, const T& CDMG, const T& CDEF) {
            critRate = __cal_possibleCrit(CR, CDEF);
            if (CDMG == 0) { multiplier = FIX_LOWEST_CDMG; }
            else if (CDEF == 0) { multiplier = (std::round((CDMG + f_100) * f_100) * INV_10000) + cal_LOWEST_CDMG; }
            else {
                float half_param = (CDMG * (FIX_LOWEST_EQUAL - FIX_LOWEST_CDMG) * f_100) / CDEF; // number is maxium equal case
                multiplier = (std::round((static_cast<float>(CDMG) - (function::computeY(CDMG, CDEF, half_param)) + f_100) * f_100) * INV_10000) + cal_LOWEST_CDMG;
            }
        }
    };
    class DamageCalculator {
    private:
        static DefenseCalculator defense;
        static DodgeCalculator dodge;
        static CritCalculator crit;

        static int32_t rng_DMG;
        static int32_t swing;
        static constexpr uint8_t DAMAGE_SWING = 20;

    public:
        DamageCalculator() { }
        /**
         * @brief calculate possibleCrit from computeY(CR, FIX_CR_HALF+(CDEF/4))
         * @param DMG damage input
         * @param damage_swing random damage to pos. or neg. (%)
        **/
        template<typename R>
        static R randomDMG(const R& DMG) {
            swing = DMG * DAMAGE_SWING * INV_100;
            return random::getRandomInt(-swing, swing);
        }
        // calculate final damage from every basic stat
        template<typename R, typename T>
        static R calculate(R DMG, const T& AP, const T& DEF, const T& ACC, const T& EVA, const T& CR, const T& CDMG, const T& CDEF) {
            // reset parameter
            dodge.resetCanDodge();
            crit.resetIsCrit();
            // random atk
            rng_DMG = randomDMG(DMG);
            DMG += rng_DMG;
            // calculate damage progess
            DMG = defense.applyDefense(DMG, AP, DEF); // def first
            DMG = dodge.applyDodge(DMG, ACC, EVA); // dodge next
            // if can dodge aviod anything except damage
            if (dodge.getcanDodge()) { return DMG; } 
            else { DMG = crit.applyCrit(DMG, CR, CDMG, CDEF); }
            return DMG;
        }
        // in template please include return type
        template<typename R, typename T1, typename T2>
        static R attack(const T1& attacker, T2& defender) {
            R attackerDMG = combat::DamageCalculator::calculate(
                attacker.getFinalATK(), 
                attacker.getFinalAP(), 
                defender.getFinalDEF(), 
                attacker.getFinalACC(), 
                defender.getFinalEVA(), 
                attacker.getFinalCR(), 
                attacker.getFinalCDMG(), 
                defender.getFinalCDEF()
            );
            defender.setFinalHP(defender.getFinalHP() - attackerDMG);
            return attackerDMG;
        }
    };

    // Static member definitions - Fixed: Properly define all static members
    float DefenseCalculator::reduceDamage = 0.0f;
    float DefenseCalculator::multiplier = 1.0f;
    
    float DodgeCalculator::chanceDodge = 0.0f;
    float DodgeCalculator::reduceDamage = 0.0f;
    bool DodgeCalculator::canDodge = false;
    float DodgeCalculator::multiplier = 1.0f;
    
    float CritCalculator::multiplier = 1.0f;
    float CritCalculator::critRate = 0.0f;
    bool CritCalculator::isCrit = false;
    
    DefenseCalculator DamageCalculator::defense;
    DodgeCalculator DamageCalculator::dodge;
    CritCalculator DamageCalculator::crit;
    int32_t DamageCalculator::rng_DMG = 0;
    int32_t DamageCalculator::swing = 0;
}