#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <memory>
#include <unordered_map>

#include "Sorceress.h"
#include "Barbarian.h"
#include "Battle.h"
#include "Player.h"
#include "Monster.h"
#include "FireGoblin.h"
#include "ItemData.h"
#include "Mercenary.h"


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
    shared_ptr<Player> playerPtr;
    if (classChoiceInput == 3) playerPtr = make_shared<Barbarian>(userName, isHardcore);
    else if (classChoiceInput == 7) playerPtr = make_shared<Sorceress>(userName, isHardcore);
    else playerPtr = make_shared<Player>(userName, charactorClass, isHardcore);
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
    
    //ItemDB 메인에 생성
    unordered_map<int, ItemData> itemDB = createItemDB();
    
    shared_ptr<Mercenary> mercenary = make_shared<Mercenary>("도적",12,playerPtr);
    player.companion = mercenary; // Plyaer <--> Mercenary 연결(순환참조)
    cout << "use_count playerPtr 참조 수 : " << playerPtr.use_count() <<endl;
    cout << "use_count mercenary 참조 수 : " << mercenary.use_count() <<endl;
    //서로 참조하고 있어서 소멸자가 나타나지 않음 (count == 0)이면 delete
    
    // --- [ PAGE 3 : 전투 ] ---
    
    int pendingExp = 0;
    vector<unique_ptr<Monster>> monsters ;
    monsters.push_back(make_unique<Monster>("Goblin", 50, 0 ,15 ,0 ,50, 1, vector<int>{101,102,201,301,401} ));
    monsters.push_back(make_unique<FireGoblin>("FireGoblin", 50, 0 ,15 ,0 ,50, 1, vector<int>{101,102,203,301,401}));
    monsters.push_back(make_unique<Monster>("Skeleton", 60, 0 ,20 ,0 ,50, 1 , vector<int>{101,102,201,301,401} ));
    monsters.push_back(make_unique<Monster>("Wraith", 50, 0 ,25 ,0 ,50, 1 , vector<int>{101,102,201,301,401}));
    monsters.push_back(make_unique<Monster>("Ghoul", 70, 0 ,35 ,0 ,120, 1 , vector<int>{101,102,201,301,401}));
    monsters.push_back(make_unique<Monster>("Andariel", 200, 0 ,150 ,0 ,500, 1, vector<int>{101,102,201,301,401}));
    
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
        
        Battle battle(player,*monster, mercenary);
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
            
            int dropItemId = monster->Drop();
            if (dropItemId != -1)
            {
                ItemData& data = itemDB[dropItemId];
                Item dropItem(data.name, data.type);//ItemData-> Item객체 생성
                cout<<"[드롭]" << data.name << " 가 바닥에 떨어졌습니다.\n";
                player.Loot(move(dropItem));//소유권 이전
                
            }
            else
            {
                cout<<"[드롭] 아무것도 드롭되지 않았습니다. \n";
            }
            player.SortInventory();//아이템 획득 후 이름순 정렬
            player.PrintInventory();
            
            player.GainExp(pendingExp);
            player.PrintLevel();
            nextPhase();
        }
    }    
}



