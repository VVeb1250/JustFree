#include "data/attribute.cpp"
#include <algorithm>
#include <iostream>

#define doRandom random::getRandomInt(base, floor)
#define randomHP doRandom * random::getRandomFloat(10, 50)
#define randomATK doRandom * random::getRandomFloat(1, 5)



int main() {
    system("cls");

    int base = 0;
    int floor = 1000;
    using namespace attribute;
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
    
    player.set_AP(doRandom);
    player.set_DEF(doRandom);
    player.set_ACC(doRandom);
    player.set_EVA(doRandom);
    player.set_CR(doRandom >> 1);
    player.set_CDMG(doRandom);
    player.set_CDEF(doRandom);
    player.set_all_Final_stat();
    player.toString();
    
    enemy.set_AP(doRandom);
    enemy.set_DEF(doRandom);
    enemy.set_ACC(doRandom);
    enemy.set_EVA(doRandom);
    enemy.set_CR(doRandom >> 1);
    enemy.set_CDMG(doRandom);
    enemy.set_CDEF(doRandom);
    enemy.set_all_Final_stat();
    enemy.toString();

    cout << endl;

    bool playerTurn = true;
    bool enemyTurn = false;
    uint32_t turn = 0;
    while (player.get_Final_HP() > 0 && enemy.get_Final_HP() > 0) {
        cout << "turn - " << ++turn << endl;
        if (playerTurn) {
            playerTurn = false;
            enemyTurn = true;
            // next plan make this write shorter
            cout << player.name << " Dealt : " << DealtDamage::attack<uint32_t>(player, enemy) << (dodge::canDodge ? " --dodge" : "        ") << (crit::isCrit ? " crit!!" : "       ") << "           .. ";
            cout << enemy.name << "  : " << enemy.get_Final_HP() << "/" << enemy.get_Final_MAX_HP() << " [" << static_cast<float>((enemy.get_Final_HP()) * 100) / enemy.get_Final_MAX_HP() << "%]" << endl;
            continue;
        }
        if (enemyTurn) {
            playerTurn = true;
            enemyTurn = false;
            cout << enemy.name << " Dealt  : " << DealtDamage::attack<uint32_t>(enemy, player) << (dodge::canDodge ? " --dodge" : "        ") << (crit::isCrit ? " crit!!" : "       ") << "           ,, ";
            cout << player.name << " : " << player.get_Final_HP() << "/" << player.get_Final_MAX_HP() << " [" << static_cast<float>((player.get_Final_HP()) * 100) / player.get_Final_MAX_HP() << "%]" << endl;
            continue;
        }
    }
    if (player.get_Final_HP() > 0) {
        cout << endl << player.name << " win" << endl;
    }
    if (enemy.get_Final_HP() > 0) {
        cout << endl << enemy.name << " win" << endl;
    }
    
}
