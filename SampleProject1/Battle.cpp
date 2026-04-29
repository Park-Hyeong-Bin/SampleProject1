#include "Battle.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "Mercenary.h"

Battle::Battle(Player& player, Monster& monster, shared_ptr<Mercenary> mercenary)
    : player(player), monster(monster), mercenary(mercenary),combatMessage("[시스템] 전투 시작!") {}

bool Battle::Run()
{
    int action;
    if (mercenary)
    {
        auto ownerPtr = mercenary->owner.lock();
        if (ownerPtr)
        {
            cout << "[" << mercenary->name << "]" << ownerPtr->GetName()<<"님을 위해 싸우겠습니다." << endl;
        }
    }
    while (monster.isAlive() && player.isAlive()) {
        
        int monsterHP = monster.GetHP();
        int playerHP = player.GetHP();
        
        int mBarCnt = (monsterHP*20)/monster.GetMaxHP();
        int pBarCnt = (playerHP*20)/player.GetMaxHP();
        
        string mBar = string(mBarCnt, '=') + string(20-mBarCnt, '-');
        string pBar = string(pBarCnt, '=') + string(20-pBarCnt, '-');
        
        // 체력 게이지와 이전 턴의 결과를 함께 출력
        cout << "==================================================\n";
        cout << "|| 몬스터   [" << mBar << "] " << left << setw(12) << monsterHP << "||\n";
        cout << "|| 플레이어 [" << pBar << "] " << left << setw(12) << playerHP << "||\n";
        cout << "==================================================\n";
        cout << combatMessage << "\n";
        cout << "--------------------------------------------------\n";
        cout << ">> 1. Attack\n>> 2. Bash Attack\n Select Action : ";
        cin >> action;

        if (action == 1) {
            monster.TakeDamage(player.Attack()); //객체 스스로 데미지 처리
            combatMessage = "=>" + player.GetAttackMessage() + "당신은 " + monster.GetName() + "을(를) 공격했습니다!(데미지 :" + to_string(player.Attack()) + ")";
            
            if (mercenary && monster.isAlive())
            {
                int mercDmg = mercenary->Attack();
                monster.TakeDamage(mercDmg);
                combatMessage = "=>" + mercenary->name + "이(가) " + monster.GetName() + "을(를) 공격했습니다!(데미지 :" + to_string(mercDmg) + ")";
            }
            
            if (monster.isAlive())
            {
                player.TakeDamage(monster.Attack());
                combatMessage += "\n=>" + monster.GetAttackMessage() + monster.GetName() + " 이(가) 당신을 공격합니다! (데미지: " + to_string(monster.Attack()) + ")";
            }
        }
        else if (action == 2) {
            monster.TakeDamage(player.CriticalAttack()); //객체 스스로 데미지 처리
            combatMessage = "=>" + player.GetAttackMessage() + "당신은 " + monster.GetName() + "을(를) 공격했습니다!(데미지 :" + to_string(player.Attack()) + ")";
            
            if (monster.isAlive())
            {
                player.TakeDamage(monster.Attack());
                combatMessage += "\n=>" + monster.GetAttackMessage() + monster.GetName() + " 이(가) 당신을 공격합니다! (데미지: " + to_string(monster.Attack()) + ")";
            }
        }
        else {
            cin.clear();
            cin.ignore(100, '\n');
            player.TakeDamage(monster.Attack());
            combatMessage += "=> 존재하지 않는 공격입니다!\n =>" + monster.GetAttackMessage() + monster.GetName() + " 이(가) 당신을 공격합니다! (데미지: " + to_string(monster.Attack()) + ")";
        }
        
        system("cls");
    }
    return player.isAlive();
}