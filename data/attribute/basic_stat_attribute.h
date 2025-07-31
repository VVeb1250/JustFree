#pragma once
#include <iostream>
#include <cstdint>
#include <cmath>
#include "..\..\util\calculate.h"
#include "..\..\util\validator.h"

namespace attribute
{
    using namespace std;
    using namespace constants;
    /**
    * @param HP
    * @param ATK
    * @param AP, DEF
    * @param ACC, EVA
    * @param CR, CDMG, CDEF
    * @brief basic stat that have in base, percent and final
     */
    class basic_stat_attribute {
    protected:
        struct BaseStats {
            uint32_t HP = 100;
            uint32_t ATK = 5;
            uint16_t AP = 0, DEF = 0;
            uint16_t ACC = 0, EVA = 0;
            uint16_t CR = 0, CDMG = 0, CDEF = 0;
        } base;

        struct FinalStats {
            int64_t HP, MAX_HP;
            uint64_t ATK;
            uint16_t AP, DEF;
            uint16_t ACC, EVA;
            uint16_t CR, CDMG, CDEF;
        } final;

        struct Percentages {
            uint16_t HP = 0;
            uint16_t ATK = 0;
            uint16_t AP = 0;
            uint16_t DEF = 0;
            uint16_t ACC = 0;
            uint16_t EVA = 0;
            uint16_t CR = 0;
            uint16_t CDMG = 0;
            uint16_t CDEF = 0;
        } percent;
        
    public:
        basic_stat_attribute() : base(), final(), percent() { setAllFinalStat(); }
        basic_stat_attribute(uint32_t HP, uint32_t ATK) : base(), final(), percent() {
            base.HP = HP, base.ATK = ATK;
            setAllFinalStat();
        }
        basic_stat_attribute(uint32_t hp, uint32_t atk, 
            uint16_t ap, uint16_t def, 
            uint16_t acc, uint16_t eva, 
            uint16_t cr, uint16_t cdmg, uint16_t cdef) : 
            base(), final(), percent() {
                base.HP = hp, base.ATK = atk, 
                base.AP = ap, base.DEF = def, 
                base.ACC = acc, base.EVA = eva, 
                base.CR = cr, base.CDMG = cdmg, base.CDEF = cdef; 
                setAllFinalStat(); 
            }

        #pragma region Getter_Final_BaseStats
        int64_t getFinalHP() const { return final.HP; }
        int64_t getFinalMAX_HP() const { return final.MAX_HP; }
        uint32_t getFinalATK() const { return final.ATK; }
        uint16_t getFinalAP() const { return final.AP; }
        uint16_t getFinalDEF() const { return final.DEF; }
        uint16_t getFinalACC() const { return final.ACC; }
        uint16_t getFinalEVA() const { return final.EVA; }
        uint16_t getFinalCR() const { return final.CR; }
        uint16_t getFinalCDMG() const { return final.CDMG; }
        uint16_t getFinalCDEF() const { return final.CDEF; }
        #pragma endregion
        #pragma region Getter_Base_BaseStats
        uint32_t getHP() const { return base.HP; }
        uint32_t getATK() const { return base.ATK; }
        uint16_t getAP() const { return base.AP; }
        uint16_t getDEF() const { return base.DEF; }
        uint16_t getACC() const { return base.ACC; }
        uint16_t getEVA() const { return base.EVA; }
        uint16_t getCR() const { return base.CR; }
        uint16_t getCDMG() const { return base.CDMG; }
        uint16_t getCDEF() const { return base.CDEF; }
        #pragma endregion
        #pragma region Getter_percent_BaseStats
        uint16_t getHP_percent() const { return percent.HP; }
        uint16_t getATK_percent() const { return percent.ATK; }
        uint16_t getAP_percent() const { return percent.AP; }
        uint16_t getDEF_percent() const { return percent.DEF; }
        uint16_t getACC_percent() const { return percent.ACC; }
        uint16_t getEVA_percent() const { return percent.EVA; }
        uint16_t getCR_percent() const { return percent.CR; }
        uint16_t getCDMG_percent() const { return percent.CDMG; }
        uint16_t getCDEF_percent() const { return percent.CDEF; }
        #pragma endregion
        
        #pragma region Setter_Final_BaseStats
        void setFinalHP() { final.HP = base.HP + (base.HP * percent.HP * INV_100); setFinalMAX_HP(); }
        void setFinalMAX_HP() { final.MAX_HP = final.HP; }
        void setFinalATK() { final.ATK = base.ATK + (base.ATK * percent.ATK * INV_100); }
        void setFinalAP() { final.AP = base.AP + (base.AP * percent.AP * INV_100); }
        void setFinalDEF() { final.DEF = base.DEF + (base.DEF * percent.DEF * INV_100); }
        void setFinalACC() { final.ACC = base.ACC + (base.ACC * percent.ACC * INV_100); }
        void setFinalEVA() { final.EVA = base.EVA + (base.EVA * percent.EVA * INV_100); }
        void setFinalCR() { final.CR = base.CR + (base.CR * percent.CR * INV_100); }
        void setFinalCDMG() { final.CDMG = base.CDMG + (base.CDMG * percent.CDMG * INV_100); }
        void setFinalCDEF() { final.CDEF = base.CDEF + (base.CDEF * percent.CDEF * INV_100); }
        void setAllFinalStat() {
            setFinalHP();
            setFinalATK();
            setFinalAP();
            setFinalDEF();
            setFinalACC();
            setFinalEVA();
            setFinalCR();
            setFinalCDMG();
            setFinalCDEF();
        }
        #pragma endregion

        #pragma region Setter_Final_BaseStats
        template<typename T>
        void reduceFinalHP(const T& DMG, default_location) { 
            validator::not_exceed<decltype(final.HP)>("DMG", DMG, sent_location);
            final.HP = final.HP - static_cast<decltype(final.HP)>(DMG);
        }
        template<typename T>
        void setFinalHP(const T& HP, default_location) { 
            validator::non_negative("HP", HP, sent_location);
            validator::not_exceed<decltype(final.HP)>("HP", HP, sent_location);
            final.HP = static_cast<decltype(final.HP)>(HP); 
            setFinalMAX_HP();
        }
        template<typename T>
        void setFinalATK(const T& ATK, default_location) {  
            validator::non_negative("ATK", ATK, sent_location);
            validator::not_exceed<decltype(final.ATK)>("ATK", ATK, sent_location);
            final.ATK = static_cast<decltype(final.ATK)>(ATK);
        }
        template<typename T>
        void setFinalAP(const T& AP, default_location) {  
            validator::non_negative("AP", AP, sent_location);
            validator::not_exceed<decltype(final.AP)>("AP", AP, sent_location);
            final.AP = static_cast<decltype(final.AP)>(AP);
        }
        template<typename T>
        void setFinalDEF(const T& DEF, default_location) {  
            validator::non_negative("DEF", DEF, sent_location);
            validator::not_exceed<decltype(final.DEF)>("DEF", DEF, sent_location);
            final.DEF = static_cast<decltype(final.DEF)>(DEF);
        }
        template<typename T>
        void setFinalACC(const T& ACC, default_location) {  
            validator::non_negative("ACC", ACC, sent_location);
            validator::not_exceed<decltype(final.ACC)>("ACC", ACC, sent_location);
            final.ACC = static_cast<decltype(final.ACC)>(ACC);
        }
        template<typename T>
        void setFinalEVA(const T& EVA, default_location) {  
            validator::non_negative("EVA", EVA, sent_location);
            validator::not_exceed<decltype(final.EVA)>("EVA", EVA, sent_location);
            final.EVA = static_cast<decltype(final.EVA)>(EVA);
        }
        template<typename T>
        void setFinalCR(const T& CR, default_location) {  
            validator::non_negative("CR", CR, sent_location);
            validator::not_exceed<decltype(final.CR)>("CR", CR, sent_location);
            final.CR = static_cast<decltype(final.CR)>(CR);
        }
        template<typename T>
        void setFinalCDMG(const T& CDMG, default_location) {  
            validator::non_negative("CDMG", CDMG, sent_location);
            validator::not_exceed<decltype(final.CDMG)>("CDMG", CDMG, sent_location);
            final.CDMG = static_cast<decltype(final.CDMG)>(CDMG);
        }
        template<typename T>
        void setFinalCDEF(const T& CDEF, default_location) {  
            validator::non_negative("CDEF", CDEF, sent_location);
            validator::not_exceed<decltype(final.CDEF)>("CDEF", CDEF, sent_location);
            final.CDEF = static_cast<decltype(final.CDEF)>(CDEF);
        }
        #pragma endregion
        #pragma region Setter_Base_BaseStats
        template<typename T>
        void setHP(const T& HP, default_location) {  
            validator::non_negative("HP", HP, sent_location);
            validator::not_exceed<decltype(base.HP)>("HP", HP, sent_location);
            base.HP = static_cast<decltype(base.HP)>(HP);
        }
        template<typename T>
        void setATK(const T& ATK, default_location) {  
            validator::non_negative("ATK", ATK, sent_location);
            validator::not_exceed<decltype(base.ATK)>("ATK", ATK, sent_location);
            base.ATK = static_cast<decltype(base.ATK)>(ATK);
        }
        template<typename T>
        void setAP(const T& AP, default_location) {  
            validator::non_negative("AP", AP, sent_location);
            validator::not_exceed<decltype(base.AP)>("AP", AP, sent_location);
            base.AP = static_cast<decltype(base.AP)>(AP);
        }
        template<typename T>
        void setDEF(const T& DEF, default_location) {  
            validator::non_negative("DEF", DEF, sent_location);
            validator::not_exceed<decltype(base.DEF)>("DEF", DEF, sent_location);
            base.DEF = static_cast<decltype(base.DEF)>(DEF);
        }
        template<typename T>
        void setACC(const T& ACC, default_location) {  
            validator::non_negative("ACC", ACC, sent_location);
            validator::not_exceed<decltype(base.ACC)>("ACC", ACC, sent_location);
            base.ACC = static_cast<decltype(base.ACC)>(ACC);
        }
        template<typename T>
        void setEVA(const T& EVA, default_location) {  
            validator::non_negative("EVA", EVA, sent_location);
            validator::not_exceed<decltype(base.EVA)>("EVA", EVA, sent_location);
            base.EVA = static_cast<decltype(base.EVA)>(EVA);
        }
        template<typename T>
        void setCR(const T& CR, default_location) {  
            validator::non_negative("CR", CR, sent_location);
            validator::not_exceed<decltype(base.CR)>("CR", CR, sent_location);
            base.CR = static_cast<decltype(base.CR)>(CR);
        }
        template<typename T>
        void setCDMG(const T& CDMG, default_location) {  
            validator::non_negative("CDMG", CDMG, sent_location);
            validator::not_exceed<decltype(base.CDMG)>("CDMG", CDMG, sent_location);
            base.CDMG = static_cast<decltype(base.CDMG)>(CDMG);
        }
        template<typename T>
        void setCDEF(const T& CDEF, default_location) {  
            validator::non_negative("CDEF", CDEF, sent_location);
            validator::not_exceed<decltype(base.CDEF)>("CDEF", CDEF, sent_location);
            base.CDEF = static_cast<decltype(base.CDEF)>(CDEF);
        }
        #pragma endregion
        #pragma region Setter_percent_BaseStats
        template<typename T>
        void setHP_percent(const T& _percent, default_location) {  
            validator::non_negative("HP percent", _percent, sent_location);
            validator::not_exceed<decltype(percent.HP)>("HP percent", _percent, sent_location);
            percent.HP = static_cast<decltype(percent.HP)>(_percent);
        }
        template<typename T>
        void setATK_percent(const T& _percent, default_location) {  
            validator::non_negative("ATK percent", _percent, sent_location);
            validator::not_exceed<decltype(percent.ATK)>("ATK percent", _percent, sent_location);
            percent.ATK = static_cast<decltype(percent.ATK)>(_percent);
        }
        template<typename T>
        void setAP_percent(const T& _percent, default_location) {  
            validator::non_negative("AP percent", _percent, sent_location);
            validator::not_exceed<decltype(percent.AP)>("AP percent", _percent, sent_location);
            percent.AP = static_cast<decltype(percent.AP)>(_percent);
        }
        template<typename T>
        void setDEF_percent(const T& _percent, default_location) {  
            validator::non_negative("DEF percent", _percent, sent_location);
            validator::not_exceed<decltype(percent.DEF)>("DEF percent", _percent, sent_location);
            percent.DEF = static_cast<decltype(percent.DEF)>(_percent);
        }
        template<typename T>
        void setACC_percent(const T& _percent, default_location) {  
            validator::non_negative("ACC percent", _percent, sent_location);
            validator::not_exceed<decltype(percent.ACC)>("ACC percent", _percent, sent_location);
            percent.ACC = static_cast<decltype(percent.ACC)>(_percent);
        }
        template<typename T>
        void setEVA_percent(const T& _percent, default_location) {  
            validator::non_negative("EVA percent", _percent, sent_location);
            validator::not_exceed<decltype(percent.EVA)>("EVA percent", _percent, sent_location);
            percent.EVA = static_cast<decltype(percent.EVA)>(_percent);
        }
        template<typename T>
        void setCR_percent(const T& _percent, default_location) {  
            validator::non_negative("CR percent", _percent, sent_location);
            validator::not_exceed<decltype(percent.CR)>("CR percent", _percent, sent_location);
            percent.CR = static_cast<decltype(percent.CR)>(_percent);
        }
        template<typename T>
        void setCDMG_percent(const T& _percent, default_location) {  
            validator::non_negative("CDMG percent", _percent, sent_location);
            validator::not_exceed<decltype(percent.CDMG)>("CDMG percent", _percent, sent_location);
            percent.CDMG = static_cast<decltype(percent.CDMG)>(_percent);
        }
        template<typename T>
        void setCDEF_percent(const T& _percent, default_location) {  
            validator::non_negative("CDEF percent", _percent, sent_location);
            validator::not_exceed<decltype(percent.CDEF)>("CDEF percent", _percent, sent_location);
            percent.CDEF = static_cast<decltype(percent.CDEF)>(_percent);
        }
        #pragma endregion
        
        void toString() {
            cout << "hp:" << base.HP << " atk:" << base.ATK << endl;
            cout << "ap:" << base.AP << " def:" << base.DEF << " acc:" << base.ACC << " eva:" << base.EVA 
            << " cr:" << base.CR << " cdmg:" << base.CDMG << " cdef:" << base.CDEF << endl; 
        }
    };
}