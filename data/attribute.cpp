// Example header file structure
// filepath: d:\Practice\GameWithCpp\include\attribute.h
// #pragma once

#include <iostream>
#include <cstdint>
#include <cmath>
#include "../util/calculate.cpp"
#include <iostream>

namespace attribute
{
    using namespace std;
    // Pre-calculate constant divisions
    constexpr float INV_100 = 1.0f / 100.0f; // round to 0.01 
    constexpr float INV_10000 = 1.0f / 10000.0f; // round to 0.0001
    constexpr float f_10 = 10.0f;
    constexpr float f_100 = 100.0f;
    constexpr float f_10000 = 10000.0f;

    /**
    * @param HP
    * @param ATK
    * @param AP, DEF
    * @param ACC, EVA
    * @param CR, CDMG, CDEF
    * @brief basic stat that have in base, percent and final
     */
    class basic_stat_attribute
    {
    protected:
        int64_t Final_HP, Final_MAX_HP;
        uint32_t Final_ATK;
        uint16_t Final_AP, Final_DEF;
        uint16_t Final_ACC, Final_EVA;
        uint16_t Final_CR, Final_CDMG, Final_CDEF;
        uint32_t HP;
        uint32_t ATK;
        uint16_t AP, DEF;
        uint16_t ACC, EVA;
        uint16_t CR, CDMG, CDEF;
        uint16_t HP_percent;
        uint16_t ATK_percent;
        uint16_t AP_percent, DEF_percent;
        uint16_t ACC_percent, EVA_percent;
        uint16_t CR_percent, CDMG_percent, CDEF_percent;
    public:
        basic_stat_attribute() : 
            HP(100), ATK(5), 
            AP(0), DEF(0), 
            ACC(0), EVA(0), 
            CR(0), CDMG(0), CDEF(0), 
            HP_percent(0), ATK_percent(0), 
            AP_percent(0),  DEF_percent(0), 
            ACC_percent(0),  EVA_percent(0), 
            CR_percent(0),  CDMG_percent(0), CDEF_percent(0) 
            { set_all_Final_stat(); }
        basic_stat_attribute(int64_t hp, uint32_t atk) : 
        HP(hp), ATK(atk), 
        AP(0), DEF(0), 
        ACC(0), EVA(0), 
        CR(0), CDMG(0), CDEF(0), 
        HP_percent(0), ATK_percent(0), 
        AP_percent(0), DEF_percent(0), 
        ACC_percent(0), EVA_percent(0), 
        CR_percent(0), CDMG_percent(0), CDEF_percent(0) 
        { set_all_Final_stat(); }
        basic_stat_attribute(uint32_t hp, uint32_t atk, 
            uint16_t ap, uint16_t def, 
            uint16_t acc, uint16_t eva, 
            uint16_t cr, uint16_t cdmg, uint16_t cdef) :
            HP(hp), ATK(atk), 
            AP(ap), DEF(def), 
            ACC(acc), EVA(eva), 
            CR(cr), CDMG(cdmg), CDEF(cdef), 
            HP_percent(0), ATK_percent(0),
            AP_percent(0), DEF_percent(0), 
            ACC_percent(0), EVA_percent(0), 
            CR_percent(0), CDMG_percent(0), CDEF_percent(0) 
            { set_all_Final_stat(); }
        
        int64_t get_Final_HP() const { return Final_HP; }
        int64_t get_Final_MAX_HP() const { return Final_MAX_HP; }
        uint32_t get_Final_ATK() const { return Final_ATK; }
        uint16_t get_Final_AP() const { return Final_AP; }
        uint16_t get_Final_DEF() const { return Final_DEF; }
        uint16_t get_Final_ACC() const { return Final_ACC; }
        uint16_t get_Final_EVA() const { return Final_EVA; }
        uint16_t get_Final_CR() const { return Final_CR; }
        uint16_t get_Final_CDMG() const { return Final_CDMG; }
        uint16_t get_Final_CDEF() const { return Final_CDEF; }

        uint32_t get_HP() const { return HP; }
        uint32_t get_ATK() const { return ATK; }
        uint16_t get_AP() const { return AP; }
        uint16_t get_DEF() const { return DEF; }
        uint16_t get_ACC() const { return ACC; }
        uint16_t get_EVA() const { return EVA; }
        uint16_t get_CR() const { return CR; }
        uint16_t get_CDMG() const { return CDMG; }
        uint16_t get_CDEF() const { return CDEF; }

        uint16_t get_HP_percent() const { return HP_percent; }
        uint16_t get_ATK_percent() const { return ATK_percent; }
        uint16_t get_AP_percent() const { return AP_percent; }
        uint16_t get_DEF_percent() const { return DEF_percent; }
        uint16_t get_ACC_percent() const { return ACC_percent; }
        uint16_t get_EVA_percent() const { return EVA_percent; }
        uint16_t get_CR_percent() const { return CR_percent; }
        uint16_t get_CDMG_percent() const { return CDMG_percent; }
        uint16_t get_CDEF_percent() const { return CDEF_percent; }

        void set_Final_HP() { this->Final_HP = HP + (HP * HP_percent * INV_100); set_Final_MAX_HP(); }
        void set_Final_MAX_HP() { Final_MAX_HP = this->Final_HP; }
        void set_Final_ATK() { this->Final_ATK = ATK + (ATK * ATK_percent * INV_100); }
        void set_Final_AP() { this->Final_AP = AP + (AP * AP_percent * INV_100); }
        void set_Final_DEF() { this->Final_DEF = DEF + (DEF * DEF_percent * INV_100); }
        void set_Final_ACC() { this->Final_ACC = ACC + (ACC * ACC_percent * INV_100); }
        void set_Final_EVA() { this->Final_EVA = EVA + (EVA * EVA_percent * INV_100); }
        void set_Final_CR() { this->Final_CR = CR + (CR * CR_percent * INV_100); }
        void set_Final_CDMG() { this->Final_CDMG = CDMG + (CDMG * CDMG_percent * INV_100); }
        void set_Final_CDEF() { this->Final_CDEF = CDEF + (CDEF * CDEF_percent * INV_100); }
        void set_all_Final_stat() {
            set_Final_HP();
            set_Final_ATK();
            set_Final_AP();
            set_Final_DEF();
            set_Final_ACC();
            set_Final_EVA();
            set_Final_CR();
            set_Final_CDMG();
            set_Final_CDEF();
        }

        void set_Final_HP(int64_t HP) { this->Final_HP = HP; }
        void set_Final_ATK(uint32_t ATK) { this->Final_ATK = ATK; }
        void set_Final_AP(uint16_t AP) { this->Final_AP = AP; }
        void set_Final_DEF(uint16_t DEF) { this->Final_DEF = DEF; }
        void set_Final_ACC(uint16_t ACC) { this->Final_ACC = ACC; }
        void set_Final_EVA(uint16_t EVA) { this->Final_EVA = EVA; }
        void set_Final_CR(uint16_t CR) { this->Final_CR = CR; }
        void set_Final_CDMG(uint16_t CDMG) { this->Final_CDMG = CDMG; }
        void set_Final_CDEF(uint16_t CDEF) { this->Final_CDEF = CDEF; }

        void set_HP(uint32_t HP) { this->HP = HP; }
        void set_ATK(uint32_t ATK) { this->ATK = ATK; }
        void set_AP(uint16_t AP) { this->AP = AP; }
        void set_DEF(uint16_t DEF) { this->DEF = DEF; }
        void set_ACC(uint16_t ACC) { this->ACC = ACC; }
        void set_EVA(uint16_t EVA) { this->EVA = EVA; }
        void set_CR(uint16_t CR) { this->CR = CR; }
        void set_CDMG(uint16_t CDMG) { this->CDMG = CDMG; }
        void set_CDEF(uint16_t CDEF) { this->CDEF = CDEF; }

        void set_HP_percent(uint32_t percent) { this->HP_percent = percent; }
        void set_ATK_percent(uint32_t percent) { this->ATK_percent = percent; }
        void set_AP_percent(uint16_t percent) { this->AP_percent = percent; }
        void set_DEF_percent(uint16_t percent) { this->DEF_percent = percent; }
        void set_ACC_percent(uint16_t percent) { this->ACC_percent = percent; }
        void set_EVA_percent(uint16_t percent) { this->EVA_percent = percent; }
        void set_CR_percent(uint16_t percent) { this->CR_percent = percent; }
        void set_CDMG_percent(uint16_t percent) { this->CDMG_percent = percent; }
        void set_CDEF_percent(uint16_t percent) { this->CDEF_percent = percent; }

        void toString() {
            cout << "hp:" << HP << " atk:" << ATK << endl;
            cout << "ap:" << AP << " def:" << DEF << " acc:" << ACC << " eva:" << EVA 
            << " cr:" << CR << " cdmg:" << CDMG << " cdef:" << CDEF << endl; 
        }
    };
    
    class advance_stat_attribute {
        uint16_t SPD;
    };

    class stat : public basic_stat_attribute {
    public:
        string name;

        stat() : basic_stat_attribute(), name("") { }
        
        stat(string name) : basic_stat_attribute(), name(name) { }
        
        stat(string name, int64_t hp, uint32_t atk) 
            : basic_stat_attribute(hp, atk), name(name) { }
        
        stat(string name, uint32_t hp, uint32_t atk, 
            uint16_t ap, uint16_t def, 
            uint16_t acc, uint16_t eva, 
            uint16_t cr, uint16_t cdmg, uint16_t cdef)
            : basic_stat_attribute(hp, atk, ap, def, acc, eva, cr, cdmg, cdef),
              name(name) { }

        void toString() {
            cout << name << " ;; ";
            basic_stat_attribute::toString();
        }
    };

    // Physical Attributes
    // |   ชื่อ          | ย่อ | รายละเอียด                                          |
    // | ------------- | --- | ------------------------------------------------ |
    // | **Strength**  | STR | พลังโจมตีของอาวุธระยะประชิด / น้ำหนักที่สามารถถือได้          |
    // | **Dexterity** | DEX | ความเร็วโจมตี, ความแม่นยำ, การหลบหลีก                   |
    // | **Agility**   | AGI | ความเร็วเคลื่อนที่, หลบหลีก, โจมตีหลายครั้ง                 |
    // | **Endurance** | END | พลังชีวิต, ความเหนื่อยล้า, การต้านทานสถานะ                |
    int STR, DEX, AGI, END;

    // Tactical & Magic Combat Attributes
    // | ชื่อ             | ย่อ | รายละเอียด                                                |
    // | ---------------- | --- | ---------------------------------------------------- |
    // | **Intelligence** | INT | พลังเวท, จำนวนมานา, ความสามารถเรียนรู้เวทใหม่                 |
    // | **Wisdom**       | WIS | ต้านทานเวท, ฟื้นฟูมานา, การควบคุมเวทขั้นสูง                    |
    // | **Willpower**    | WIL | ต้านสภาวะจิต (fear, charm), ฟื้นพลังใจในสถานการณ์วิกฤต        |
    // | **Focus**        | FCS | ลดโอกาสถูกขัดขวางขณะร่ายเวท, เพิ่มโอกาสติด Critical Magic    |
    int INT, WIS, WIL, FCS;

    // Combat Mechanics Attributes
    // | ชื่อ                    | ย่อ  | รายละเอียด                                     |
    // | --------------------- | --- | -------------------------------------------- |
    // | **Accuracy**          | ACC | โอกาสโจมตีโดนเป้าหมาย (สำคัญกับระยะไกลและเวท)       |
    // | **Evasion**           | EVA | โอกาสหลบหลีกการโจมตีของศัตรู                      |
    // | **Critical Rate**     | CR  | โอกาสโจมตีแบบ Critical Hit (เพิ่มดาเมจแบบพิเศษ)   |
    // | **Critical Defence**  | CDEF| ลดโอกาสการโดนโจมตีแบบ Critical Hit             |
    // | **Critical Damage**   | CDMG | ค่าคูณของดาเมจเมื่อเกิด Critical (เช่น ×1.5, ×2)    |
    // | **Block / Parry**     | BPR | โอกาสป้องกัน/เบี่ยงเบนการโจมตี                      |
    // | **Armor Penetration** | APN | ความสามารถทะลุเกราะ ลดการลดดาเมจของศัตรู            |
    // | **Speed**             | SPD | ความเร็วในการโจมตี, ส่งผลต่อจำนวนครั้งต่อเทิร์น           |
    int ACC, EVA, CR, CDEF, CDMG, BPR, APN, SPD;
    
    // Social / Utility Attributes
    // | Attribute         | Abbr | Description                                    |
    // | ----------------- | ---- | ---------------------------------------------- |
    // | **Luck**          | LCK  | Influences loot drops, crits, random events.   |
    // | **Barter**        | BRT  | Better trade prices, faster negotiations.      |
    // | **Influence**     | INF  | Reputation with factions, party loyalty.       |
    // | **Craftsmanship** | CFT  | Determines quality of forged items or potions. |
    // | **Stealth**       | STL  | Avoid enemy detection, boosts sneak attacks.   |
    // | **Affinity**      | AFF  | Relationship with creatures, NPCs, items.      |
    int LCK, BRT, INF, CFT, STL, AFF;
     
    /**
     * @brief using DEF, AP
     * @param reduceDamage in %
     * @param multiplyer x0.---- for final damage
     */ 
    namespace defense {
        static float reduceDamage = NAN;
        static float multiplyer = NAN;
        constexpr uint_fast16_t FIX_HALF_DEF = 1000; // point thta reduce damage 50%
        // caluculate reduce damage from computeY(DEF, FIX_HALF_DEF+AP)
        template<typename T>
        float __cal_reducedamage(const T& AP, const T& DEF) {
            return (std::round(function::computeY(DEF, FIX_HALF_DEF + AP) * f_10000)) * INV_10000;
        }
        // complete defense calcilator
        template<typename R, typename T>
        R cal_defense(R DMG, const T& AP, const T& DEF) {
            reduceDamage = __cal_reducedamage(AP, DEF);
            multiplyer = (f_100 - reduceDamage) * INV_100;
            return multiplyer * DMG;
        }
        /**
         * @brief update defense value
         * @param reduceDamage in %
         * @param multiplyer x0.---- for cal final damage
         */
        template<typename T>
        void update_value(const T& AP, const T& DEF) {
            reduceDamage = __cal_reducedamage(AP, DEF);
            multiplyer = (f_100 - reduceDamage) * INV_100;
        }
    }
    /**
     * @brief using ACC, EVA
     * @param chanceDodge in %
     * @param reduceDamage in %
     * @param canDodge true or false
     * @param multiplyer x0.---- for final damage
     */ 
    namespace dodge {
        static float multiplyer = NAN; 
        static float reduceDamage = NAN; 
        static float chanceDodge = NAN; 
        constexpr float EVA_multiply = 1.5f; // make acc less effect for balance
        // mininum damage reduce and maxinum damage recive if can dodge in percent  
        constexpr uint_fast16_t FIX_HALF_DODGE = 100; // stat in 50%
        constexpr uint_fast8_t MIN_reducedamage = 45; // in percent
        constexpr uint_fast8_t MAX_reducedamage = 10; // in percent
        static bool canDodge = NAN; 
        
        // calculate possible dodge from ACC / EVA
        template<typename T>
        float __cal_possibleDodge(const T& ACC, const T& EVA) {
            float new_EVA = EVA * EVA_multiply;
            if (ACC >= new_EVA) { return 0.0f; }
            float temp = std::round(static_cast<float>(ACC) * f_10000 / new_EVA) * INV_100;
            return f_100 - (temp + (std::round(function::computeY(f_100-temp, FIX_HALF_DODGE, new_EVA) * f_100) * INV_100));
        }
        // call randomSuscess to return canDodge or not
        bool __cal_canDodge(float possibleDodge) {
            return random::randomSuscess(possibleDodge);
        }
        /**
         * @brief calculate reducedamage from possibleDodge and have damage floor
         * @param MIN_reducedamage higest damage can take(%)
         * @param MAX_reducedamage lowest damage can take(%)
         * @return total damage reduce in percent
         */
        float __cal_reducedamage(float possibleDodge) {
            multiplyer = (((f_100 - possibleDodge) - MIN_reducedamage) * INV_100);
            multiplyer = multiplyer + function::computeY(
                possibleDodge / ((f_100 / (MAX_reducedamage + MIN_reducedamage)) * f_100), possibleDodge, multiplyer
            );
            return std::round((f_100 - (multiplyer * f_100)) * f_10000) * INV_10000;
        }
        /**
         * @brief complete dodge damage calculator
         */
        template<typename R, typename T>
        R cal_dodge(R DMG, const T& ACC, const T& EVA) {
            chanceDodge = __cal_possibleDodge(ACC, EVA);
            canDodge = __cal_canDodge(chanceDodge);
            if (canDodge) {
                reduceDamage =  __cal_reducedamage(chanceDodge);
                return std::round(multiplyer * DMG);
            } else { return DMG; }
        }
        /**
         * @brief update dodge value
         * @param chanceDodge in %
         * @param reduceDamage in %
         * @param multiplyer x0.---- for cal final damage
         */
        template<typename T>
        void update_value(const T& ACC, const T& EVA) {
            chanceDodge = __cal_possibleDodge(ACC, EVA);
            reduceDamage =  __cal_reducedamage(chanceDodge);
            multiplyer = (((f_100 - chanceDodge) - MIN_reducedamage) * INV_100);
            multiplyer = multiplyer + function::computeY(
                chanceDodge / ((f_100 / (MAX_reducedamage + MIN_reducedamage)) * f_100), chanceDodge, multiplyer
            );
        }
        /**
         * @brief reset dodge paramiter
         * @param canDodge to false
         */
        void resetCanDodge() { canDodge = false; }
    }
    /**
     * @brief using CR, CDMG, CDEF 
     * @param critRate in %
     * @param isCrit true or false
     * @param multiplyer lowest x1, highest x655.35
     */
    namespace crit {
        static float multiplyer = NAN;
        static float critRate = NAN;
        constexpr float FIX_LOWEST_CDMG = 1.5f; // mininum multiplyer if it crit
        constexpr float FIX_LOWEST_EQUAL = 2.0f; // mininum multiplyer if CDMG and CDEF is equal
        constexpr float cal_LOWEST_CDMG = FIX_LOWEST_CDMG - 1.0f;
        constexpr uint_fast16_t FIX_CR_HALF = 500; // stat of cr to make 50% crit
        static bool isCrit = NAN;

        /**
         * @brief calculate possibleCrit from computeY(CR, FIX_CR_HALF+(CDEF/4))
         * @param FIX_CR_HALF stat of cr to make 50% crit
         */
        template<typename T>
        float __cal_possibleCrit(const T& CR, const T& CDEF) {
            return std::round(function::computeY(CR, FIX_CR_HALF) * f_100) * INV_100; // + (static_cast<float>(CDEF) / 4)
        }
        // call randomSuscess to return canCrit or not
        bool __cal_canCrit(const float& possibleCrit) {
            return random::randomSuscess(possibleCrit);
        }
        /**
         * @brief calculate damage and multiplyer from CDMG and can take lower from CDEF
         * @param FIX_LOWEST_EQUAL higest multiply if CDMG and CDEF is equal
         * @return total damage that multiplyed
         */
        template<typename R, typename T>
        R __cal_criticaldamage(R DMG, const T& CDMG, const T& CDEF) {
            if (CDMG == 0) { multiplyer = FIX_LOWEST_CDMG; return DMG; }
            if (CDEF == 0) {
                multiplyer = (std::round((CDMG + f_100) * f_100) * INV_10000) + cal_LOWEST_CDMG;
                return std::round(multiplyer * DMG);
            }
            // old : use half_param = CDMG, but crit landing high damage even have high CDEF
            float half_param = (CDMG * (FIX_LOWEST_EQUAL - FIX_LOWEST_CDMG) * f_100) / CDEF; // number is maxium equal case
            multiplyer = (std::round((static_cast<float>(CDMG) - (function::computeY(CDMG, CDEF, half_param)) + f_100) * f_100) * INV_10000) + cal_LOWEST_CDMG;
            return std::round(multiplyer * DMG);
        }
        // complete crit damage calculator 
        template<typename R, typename T>
        R cal_crit(R DMG, const T& CR, const T& CDMG, const T& CDEF) {
            critRate = __cal_possibleCrit(CR, CDEF);
            isCrit = __cal_canCrit(critRate);
            if (isCrit) {
                return __cal_criticaldamage(DMG, CDMG, CDEF);
            } else { return DMG; }
        }
        /**
         * @brief update crit value
         * @param critRate in %
         * @param multiplyer lowest x1, highest x655.35
         */
        template<typename T>
        void update_value(const T& CR, const T& CDMG, const T& CDEF) {
            critRate = __cal_possibleCrit(CR, CDEF);
            if (CDMG == 0) { multiplyer = FIX_LOWEST_CDMG; }
            else if (CDEF == 0) { multiplyer = (std::round((CDMG + f_100) * f_100) * INV_10000) + cal_LOWEST_CDMG; }
            else {
                float half_param = (CDMG * (FIX_LOWEST_EQUAL - FIX_LOWEST_CDMG) * f_100) / CDEF; // number is maxium equal case
                multiplyer = (std::round((static_cast<float>(CDMG) - (function::computeY(CDMG, CDEF, half_param)) + f_100) * f_100) * INV_10000) + cal_LOWEST_CDMG;
            }
        }
        /**
         * @brief reset crit paramiter
         * @param isCrit to false
         */
        void resetIsCrit() { isCrit = false; }
    }
    // calculate all damage
    namespace DealtDamage {
        static int_fast32_t rng_DMG = 0.0;
        static int_fast32_t swing = 0;
        constexpr uint_fast8_t damage_swing = 20; // in %
        /**
         * @brief calculate possibleCrit from computeY(CR, FIX_CR_HALF+(CDEF/4))
         * @param DMG damage input
         * @param damage_swing random damage to pos. or neg. (%)
        **/
        template<typename R>
        R randomDMG(const R& DMG) {
            swing = DMG * (damage_swing * INV_100);
            return random::getRandomInt(-swing, swing);
        }
        // calculate final damage from every basic stat
        template<typename R, typename T>
        R calculate(R DMG, const T& AP, const T& DEF, const T& ACC, const T& EVA, const T& CR, const T& CDMG, const T& CDEF) {
            // reset parameter
            dodge::resetCanDodge();
            crit::resetIsCrit();
            // random atk
            rng_DMG = randomDMG(DMG);
            DMG += rng_DMG;
            // calculate damage progess
            DMG = defense::cal_defense(DMG, AP, DEF); // def first
            DMG = dodge::cal_dodge(DMG, ACC, EVA); // dodge next
            // if can dodge aviod anything except damage
            if (dodge::canDodge) { return DMG; } 
            else { DMG = crit::cal_crit(DMG, CR, CDMG, CDEF); }
            return DMG;
        }
        using namespace attribute;
        // in template please include return type
        template<typename R, typename T1, typename T2>
        R attack(const T1& attacker, T2& defender) {
            R attackerDMG = DealtDamage::calculate(
                attacker.get_Final_ATK(), 
                attacker.get_Final_AP(), 
                defender.get_Final_DEF(), 
                attacker.get_Final_ACC(), 
                defender.get_Final_EVA(), 
                attacker.get_Final_CR(), 
                attacker.get_Final_CDMG(), 
                defender.get_Final_CDEF()
            );
            defender.set_Final_HP(defender.get_Final_HP() - attackerDMG);
            return attackerDMG;
        }
    }
    
    namespace speed {
        // max ~65000
        constexpr uint16_t FIX_HALF_SPD = 5000; // stat of spd that make 50%
        template <typename T>
        uint_fast16_t __cal_speed(const T& SPD) {
            float x = function::computeY(SPD, FIX_HALF_SPD);
            int y = 1000 - std::round(x * f_10);
            std::cout << SPD << " ";
            std::cout << x << " ";
            std::cout << y << endl;
            return y;
        }
    }
}