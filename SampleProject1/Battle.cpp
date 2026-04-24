#include "Battle.h"
#include <iostream>

Battle::Battle(Player& player, Monster& monster)
    : player(player), monster(monster), combatMessage("[시스템] 전투 시작!") {}

bool Battle::Run()
{
    int action;
    
    while (monster.isAlive() && player.isAlive()) {
        cout << "\n[ Goblin: " << monster.GetHP() << " HP ] vs [ " << player.GetName() << ": " << player.GetHP() << " HP ]\n";
        cout << "1. Attack! | 2. Bash Attack! | 3. Run! \nAction: ";
        cin >> action;

        if (action == 1) {
            int dmg = player.Attack();
            monster.TakeDamage(dmg);
            cout << ">> You dealt " << dmg << " damage!\n";
            
        }
        else if (action == 2) {
            player.PreviewCritical();
            int critDmg = player.CriticalAttack();
            monster.TakeDamage(critDmg);
            cout << ">> 크리티컬 히트! " << critDmg << " 데미지!\n";
        }
        else {
            cout << ">> You missed your chance!\n";
        }

        if (monster.isAlive()) {
            player.TakeDamage(monster.Attack());
            cout << ">> Goblin counter-attacked! (-" << monster.Attack() << " HP)\n";
        }
    }
    return player.isAlive();
}