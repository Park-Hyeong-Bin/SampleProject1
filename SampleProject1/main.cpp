#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <memory>

#include "Sorceress.h"
#include "Barbarian.h"
#include "Battle.h"
#include "Player.h"
#include "Monster.h"
#include "FireGoblin.h"


using namespace std;

// 화면을 지우고 다음 진행을 위해 멈추는 함수
void nextPhase() {
    cout << "\n[Press Enter to Continue...]";
    cin.ignore(100, '\n');
    cin.get();
    system("cls"); // Windows 전용 화면 지우기
}

int main()
{
    string userName;
    string charactorClass;
    int classChoiceInput;
    char hardcoreInput;
    bool isHardcore = false;
    
    // --- [ PAGE 1 : 캐릭터 생성 ] ---
    system("cls || clear");
    cout << "################################################\n";
    cout << "#                                              #\n";
    cout << "#        WELCOME TO THE DIABLO WORLD           #\n";
    cout << "#                                              #\n";
    cout << "################################################\n\n";
    cout << "Input your name : ";
    cin >> userName;

    cout << "\nSelect your Class:\n";
    cout << " 1.Amazon  2.Assassin  3.Barbarian  4.Druid\n";
    cout << " 5.Necro   6.Paladin   7.Sorceress  8.Warlock\n";
    cout << "Choice: ";
    cin >> classChoiceInput;

    switch (classChoiceInput) {
    case 1: charactorClass = "Amazon"; break;
    case 2: charactorClass = "Assassin"; break;
    case 3: charactorClass = "Barbarian"; break;
    case 4: charactorClass = "Druid"; break;
    case 5: charactorClass = "Necro"; break;
    case 6: charactorClass = "Paladin"; break;
    case 7: charactorClass = "Sorceress"; break;
    case 8: charactorClass = "Warlock"; break;
    default: charactorClass = "Unknown"; break;
    }

    cout << "Enable Hardcore Mode? (1) Yes, (2) No: ";
    cin >> hardcoreInput;
    if (hardcoreInput == '1') {
        isHardcore = true;
        cout << "[System] Hardcore mode enabled. Death is permanent\n";
    }
    else {
        isHardcore = false;
        cout << "[System] Standard mode enabled.\n";
    }
    
    
    system("cls || clear");
    
    nextPhase();
    //Player 객체 생성
    unique_ptr<Player> playerPtr;
    if (classChoiceInput == 3) playerPtr = make_unique<Barbarian>(userName, isHardcore);
    else if (classChoiceInput == 7) playerPtr = make_unique<Sorceress>(userName, isHardcore);
    else playerPtr = make_unique<Player>(userName, charactorClass, isHardcore);
    Player& player = *playerPtr;

    // --- [ PAGE 2 : Status ] ---
    cout << "================================================\n";
    cout << "             CHARACTER INFORMATION              \n";
    cout << "================================================\n";
    cout << "  NAME  : " << player.GetName() << "\n";
    cout << "  CLASS : " << player.GetCharacterClass() << " | LVL: " << player.GetLevel() << "\n";
    cout << "  HP    : " << player.GetMaxHP() << " | MP: " << player.GetMaxMP() << "\n";
    cout << "  STR   : " << player.GetStrength() << " | DEX : " << player.GetDexterity() << "\n";
    cout << "  VIT   : " << player.GetVitality() << " | ENG: " << player.GetEnergy() << "\n";
    cout << "  REGIST\n";
    cout << "  FIRE  : " << player.GetFireResist() << " | COLD :" << player.GetColdResist() << "\n";
    cout << "  LIGHT : " << player.GetLightningResist() << " | POISON : " << player.GetPoisonResist() << "\n";
    cout << "  DMG   : " << player.GetAttackDamage() << " | HARDCORE: " << (player.IsHardcore() ? "ON" : "OFF") << "\n";
    cout << "================================================\n";

    nextPhase();
    // --- [ PAGE 3 : 전투 ] ---
    
    int pendingExp = 0;
    vector<unique_ptr<Monster>> monsters ;
    monsters.push_back(make_unique<Monster>("Goblin", 50, 0 ,15 ,0 ,50));
    monsters.push_back(make_unique<FireGoblin>("FireGoblin", 50, 0 ,15 ,0 ,50));
    monsters.push_back(make_unique<Monster>("Skeleton", 60, 0 ,20 ,0 ,50));
    monsters.push_back(make_unique<Monster>("Wraith", 50, 0 ,25 ,0 ,50));
    monsters.push_back(make_unique<Monster>("Ghoul", 70, 0 ,35 ,0 ,120));
    monsters.push_back(make_unique<Monster>("Andariel", 200, 0 ,150 ,0 ,500));
    
    for (auto& monster : monsters)
    {
        if (!player.isAlive()) break;
        
        cout << "            (  ` - '  )  \n";
        cout << "             )       (   \n";
        cout << "            (  o   o  )  < GRRRRR!!\n";
        cout << "             )   ^   (   \n";
        cout << "            (   ---   )  \n";
        cout << "             '-------'   \n";
        cout << "[시스템] "<< monster->GetName() <<"이(가) 나타났습니다!\n";
        
        Battle battle(player,*monster);
        battle.Run();
        
        if (!player.isAlive()) {
            cout << "  _______      ___      .___  ___.  _______ \n";
            cout << " /  _____|    /   \\     |   \\/   | |   ____|\n";
            cout << "|  |  __     /  ^  \\    |  \\  /  | |  |__   \n";
            cout << "|  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|  \n";
            cout << "|  |__| |  /  _____  \\  |  |  |  | |  |____ \n";
            cout << " \\______| /__/     \\__\\ |__|  |__| |_______|\n";
            cout << "\n";
            cout << "  ______   ____    ____  _______ .______  \n";
            cout << " /  __  \\  \\   \\  /   / |   ____||   _  \\ \n";
            cout << "|  |  |  |  \\   \\/   /  |  |__   |  |_)  |\n";
            cout << "|  |  |  |   \\      /   |   __|  |      / \n";
            cout << "|  `--'  |    \\    /    |  |____ |  |\\  \\--.\n";
            cout << " \\______/      \\__/     |_______|| _| `.___|\n";
        }
        else {
            cout << "************************************************\n";
            cout << monster->GetName() <<" 와의 전투에서 승리하셨습니다!           \n";
            cout << "************************************************\n";

            nextPhase();
            
            //몬스터 처치-> 아이템드롭 -> move로 소유권 이전
            unique_ptr<Item> dropItem = monster->Drop();
            if (dropItem)
            {
                cout<<"[드롭]" << dropItem->name << " 가 바닥에 떨어졌습니다.\n";
                player.Loot(move(dropItem));//소유권 이전
                cout<<"[로그] dropItem nullptr?" << (dropItem == nullptr ? "Yes" : "No") << endl;
            }
            else
            {
                cout<<"[드롭] 아무것도 드롭되지 않았습니다. \n";
            }
            player.PrintInventory();
            
            player.GainExp(pendingExp);
            player.PrintLevel();
            nextPhase();
        }
    }    
}



