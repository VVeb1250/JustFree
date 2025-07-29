// Example header file structure
// filepath: d:\Practice\GameWithCpp\include\attribute.h

#include <iostream>
#include <cstdint>
#include <cmath>
#include "../util/calculate.cpp"

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
            uint32_t ATK;
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
        basic_stat_attribute(int64_t HP, uint32_t ATK) : base(), final(), percent() {
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

        uint32_t getHP() const { return base.HP; }
        uint32_t getATK() const { return base.ATK; }
        uint16_t getAP() const { return base.AP; }
        uint16_t getDEF() const { return base.DEF; }
        uint16_t getACC() const { return base.ACC; }
        uint16_t getEVA() const { return base.EVA; }
        uint16_t getCR() const { return base.CR; }
        uint16_t getCDMG() const { return base.CDMG; }
        uint16_t getCDEF() const { return base.CDEF; }

        uint16_t getHP_percent() const { return percent.HP; }
        uint16_t getATK_percent() const { return percent.ATK; }
        uint16_t getAP_percent() const { return percent.AP; }
        uint16_t getDEF_percent() const { return percent.DEF; }
        uint16_t getACC_percent() const { return percent.ACC; }
        uint16_t getEVA_percent() const { return percent.EVA; }
        uint16_t getCR_percent() const { return percent.CR; }
        uint16_t getCDMG_percent() const { return percent.CDMG; }
        uint16_t getCDEF_percent() const { return percent.CDEF; }

        void setFinalHP() { this->final.HP = base.HP + (base.HP * percent.HP * INV_100); setFinalMAX_HP(); }
        void setFinalMAX_HP() { final.MAX_HP = this->final.HP; }
        void setFinalATK() { this->final.ATK = base.ATK + (base.ATK * percent.ATK * INV_100); }
        void setFinalAP() { this->final.AP = base.AP + (base.AP * percent.AP * INV_100); }
        void setFinalDEF() { this->final.DEF = base.DEF + (base.DEF * percent.DEF * INV_100); }
        void setFinalACC() { this->final.ACC = base.ACC + (base.ACC * percent.ACC * INV_100); }
        void setFinalEVA() { this->final.EVA = base.EVA + (base.EVA * percent.EVA * INV_100); }
        void setFinalCR() { this->final.CR = base.CR + (base.CR * percent.CR * INV_100); }
        void setFinalCDMG() { this->final.CDMG = base.CDMG + (base.CDMG * percent.CDMG * INV_100); }
        void setFinalCDEF() { this->final.CDEF = base.CDEF + (base.CDEF * percent.CDEF * INV_100); }
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

        void setFinalHP(int64_t HP) { this->final.HP = HP; }
        void setFinalATK(uint32_t ATK) { this->final.ATK = ATK; }
        void setFinalAP(uint16_t AP) { this->final.AP = AP; }
        void setFinalDEF(uint16_t DEF) { this->final.DEF = DEF; }
        void setFinalACC(uint16_t ACC) { this->final.ACC = ACC; }
        void setFinalEVA(uint16_t EVA) { this->final.EVA = EVA; }
        void setFinalCR(uint16_t CR) { this->final.CR = CR; }
        void setFinalCDMG(uint16_t CDMG) { this->final.CDMG = CDMG; }
        void setFinalCDEF(uint16_t CDEF) { this->final.CDEF = CDEF; }

        void setHP(uint32_t HP) { this->base.HP = HP; }
        void setATK(uint32_t ATK) { this->base.ATK = ATK; }
        void setAP(uint16_t AP) { this->base.AP = AP; }
        void setDEF(uint16_t DEF) { this->base.DEF = DEF; }
        void setACC(uint16_t ACC) { this->base.ACC = ACC; }
        void setEVA(uint16_t EVA) { this->base.EVA = EVA; }
        void setCR(uint16_t CR) { this->base.CR = CR; }
        void setCDMG(uint16_t CDMG) { this->base.CDMG = CDMG; }
        void setCDEF(uint16_t CDEF) { this->base.CDEF = CDEF; }

        void setHP_percent(uint32_t percent) { this->percent.HP = percent; }
        void setATK_percent(uint32_t percent) { this->percent.ATK = percent; }
        void setAP_percent(uint16_t percent) { this->percent.AP = percent; }
        void setDEF_percent(uint16_t percent) { this->percent.DEF = percent; }
        void setACC_percent(uint16_t percent) { this->percent.ACC = percent; }
        void setEVA_percent(uint16_t percent) { this->percent.EVA = percent; }
        void setCR_percent(uint16_t percent) { this->percent.CR = percent; }
        void setCDMG_percent(uint16_t percent) { this->percent.CDMG = percent; }
        void setCDEF_percent(uint16_t percent) { this->percent.CDEF = percent; }

        void toString() {
            cout << "hp:" << base.HP << " atk:" << base.ATK << endl;
            cout << "ap:" << base.AP << " def:" << base.DEF << " acc:" << base.ACC << " eva:" << base.EVA 
            << " cr:" << base.CR << " cdmg:" << base.CDMG << " cdef:" << base.CDEF << endl; 
        }
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
            : basic_stat_attribute(hp, atk, ap, def, acc, eva, cr, cdmg, cdef), name(name) { }

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
}