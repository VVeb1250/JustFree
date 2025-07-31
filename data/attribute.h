#pragma once
#include "attribute\basic_stat_attribute.h"
#include "attribute\stat.h"

namespace attribute
{
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