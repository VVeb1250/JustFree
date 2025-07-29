#include "data\attribute.cpp"
#include "data\combat.cpp"
#include <algorithm>
#include <iostream>

#define doRandom random::getRandomInt(base, floor)
#define randomHP doRandom * random::getRandomFloat4f(10, 50)
#define randomATK doRandom * random::getRandomFloat4f(1, 5)



int main() {
    system("cls");

    int base = 0;
    int floor = 1000;
    using namespace attribute;
    using namespace combat;
    using namespace std;

    vector<uint32_t> array(8);
    generate(array.begin(), array.end(), [&]() {
        return doRandom;
    });
    // uint32_t hp, uint32_t atk, 
    // uint16_t ap, uint16_t def, 
    // uint16_t acc, uint16_t eva, 
    // uint16_t cr, uint16_t cdmg, uint16_t cdef
    stat player = stat("Player", floor + randomHP, randomATK);
    stat enemy = stat("Enemy", floor + randomHP, randomATK);
    
    player.setAP(doRandom);
    player.setDEF(doRandom);
    player.setACC(doRandom);
    player.setEVA(doRandom);
    player.setCR(doRandom >> 1);
    player.setCDMG(doRandom);
    player.setCDEF(doRandom);
    player.setAllFinalStat();
    player.toString();
    
    enemy.setAP(doRandom);
    enemy.setDEF(doRandom);
    enemy.setACC(doRandom);
    enemy.setEVA(doRandom);
    enemy.setCR(doRandom >> 1);
    enemy.setCDMG(doRandom);
    enemy.setCDEF(doRandom);
    enemy.setAllFinalStat();
    enemy.toString();

    cout << endl;

    bool playerTurn = true;
    bool enemyTurn = false;
    uint32_t turn = 0;
    while (player.getFinalHP() > 0 && enemy.getFinalHP() > 0) {
        cout << "turn - " << ++turn << endl;
        if (playerTurn) {
            playerTurn = false;
            enemyTurn = true;
            // next plan make this write shorter
            cout << player.name << " Dealt : " << DamageCalculator::attack<uint32_t>(player, enemy) << (DodgeCalculator::getcanDodge() ? " --dodge" : "        ") << (CritCalculator::getisCrit() ? " crit!!" : "       ") << "           .. ";
            cout << enemy.name << "  : " << enemy.getFinalHP() << "/" << enemy.getFinalMAX_HP() << " [" << static_cast<float>((enemy.getFinalHP()) * 100) / enemy.getFinalMAX_HP() << "%]" << endl;
            continue;
        }
        if (enemyTurn) {
            playerTurn = true;
            enemyTurn = false;
            cout << enemy.name << " Dealt  : " << DamageCalculator::attack<uint32_t>(enemy, player) << (DodgeCalculator::getcanDodge() ? " --dodge" : "        ") << (CritCalculator::getisCrit() ? " crit!!" : "       ") << "           ,, ";
            cout << player.name << " : " << player.getFinalHP() << "/" << player.getFinalMAX_HP() << " [" << static_cast<float>((player.getFinalHP()) * 100) / player.getFinalMAX_HP() << "%]" << endl;
            continue;
        }
    }
    if (player.getFinalHP() > 0) {
        cout << endl << player.name << " win" << endl;
    }
    if (enemy.getFinalHP() > 0) {
        cout << endl << enemy.name << " win" << endl;
    }
    // int max = 50000;
    // int amount = 25;
    // for (int i = 0; i < max; i += max / amount) {
    //     for (int j = 0; j < max; j += max / amount) {
    //         crit::__cal_criticaldamage(100, i, j);
    //         cout << crit::multiplyer << " ";
    //     } cout << endl;
    // }
}
