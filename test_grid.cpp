#include "data\grid\combat_area.h"
#include "data\attribute\stat.h"
#include "util\calculate.h"

#define dorandom(a,b) random::getRandomInt(0, a - 1), random::getRandomInt(0, b - 1)

int main(int argc, char const *argv[])
{
    int a = 8, b = 8;
    system("cls");
    combat_area space = combat_area<attribute::stat>(a,b);
    attribute::stat player = attribute::stat("player", 100, 50);
    attribute::stat enemy1 = attribute::stat("1enemy", 100, 50);
    attribute::stat enemy2 = attribute::stat("2enemy", 100, 50);
    attribute::stat enemy3 = attribute::stat("3enemy", 100, 50);
    attribute::stat enemy4 = attribute::stat("4enemy", 100, 50);
    attribute::stat enemy5 = attribute::stat("5enemy", 100, 50);
    attribute::stat enemy6 = attribute::stat("6enemy", 100, 50);
    space.add(player, dorandom(a, b));
    space.add(enemy1, dorandom(a, b));
    space.add(enemy2, dorandom(a, b));
    space.add(enemy3, dorandom(a, b));
    space.add(enemy4, dorandom(a, b));
    space.add(enemy5, dorandom(a, b));
    space.add(enemy6, dorandom(a, b));
    space.tostring();
    return 0;
}
