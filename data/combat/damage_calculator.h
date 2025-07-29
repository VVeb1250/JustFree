#pragma once
#include "defense_calculator.h"
#include "dodge_calculator.h"
#include "crit_calculator.h"

class DamageCalculator {
    private:
        int32_t rng_DMG;
        int32_t swing;

        static constexpr uint8_t DAMAGE_SWING = 20;

    public:
        DefenseCalculator defense;
        DodgeCalculator dodge;
        CritCalculator crit;

        DamageCalculator() { }
        /**
         * @brief calculate possibleCrit from computeY(CR, FIX_CR_HALF+(CDEF/4))
         * @param DMG damage input
         * @param damage_swing random damage to pos. or neg. (%)
        **/
        template<typename R>
        R randomDMG(const R& DMG) {
            swing = DMG * DAMAGE_SWING * INV_100;
            return random::getRandomInt(-swing, swing);
        }
        // calculate final damage from every basic stat
        template<typename R, typename T>
        R calculate(R DMG, const T& AP, const T& DEF, const T& ACC, const T& EVA, const T& CR, const T& CDMG, const T& CDEF) {
            // reset parameter
            dodge.resetCanDodge();
            crit.resetIsCrit();
            // random atk
            rng_DMG = randomDMG(DMG);
            DMG += rng_DMG;
            // calculate damage progess
            DMG = defense.apply(DMG, AP, DEF); // def first
            DMG = dodge.apply(DMG, ACC, EVA); // dodge next
            // if can dodge aviod anything except damage
            if (dodge.getcanDodge()) { return DMG; } 
            else { DMG = crit.apply(DMG, CR, CDMG, CDEF); }
            return DMG;
        }
        // in template please include return type
        template<typename R, typename T1, typename T2>
        R attack(const T1& attacker, T2& defender) {
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