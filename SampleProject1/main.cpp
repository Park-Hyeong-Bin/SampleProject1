#include <iostream>
#include <string>
#include <cstdlib>

#include "Battle.h"
#include "Character.h"
#include "Player.h"
#include "Monster.h"


using namespace std;

// 화면을 지우고 다음 진행을 위해 멈추는 함수
void nextPhase() {
    cout << "\n[Press Enter to Continue...]";
    cin.ignore(100, '\n');
    cin.get();
    system("cls"); // Windows 전용 화면 지우기
}




int main() {
    string userName;
    string charactorClass;
    int classChoiceInput;
    char hardcoreInput;
    bool isHardcore = false;
    
    // --- [ PAGE 1 : Intro ] ---
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
    Player player(userName, charactorClass, isHardcore);

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

    int pendingExp = 0;
    {
        // --- [ PAGE 3 : Battle ] ---
    
        Monster goblin(50,0,15,0,50);
    
        int action;

        cout << "            (  ` - '  )  \n";
        cout << "             )       (   \n";
        cout << "            (  o   o  )  < GRRRRR!!\n";
        cout << "             )   ^   (   \n";
        cout << "            (   ---   )  \n";
        cout << "             '-------'   \n";
        cout << "[SYSTEM] A Goblin appeared!\n";

        Battle battle(player,goblin);
        battle.Run();

        nextPhase();

        // --- [ PAGE 4 : Result ] ---
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
            cout << "   전투에서 승리하셨습니다!           \n";
            cout << "************************************************\n";

            nextPhase();
            pendingExp = goblin.GetExpReward(); // 몬스터 객체 소멸 전 경험치 저장
        
            // 아이템 저장
            int* invPtr = player.GetInventory();
            for (int i = 1; i <= 3; i++) {
                *invPtr = rand() % 4 + 1;
                invPtr++;
            }
        
            invPtr = player.GetInventory(); //invPtr 처음으로 리셋
            int slot = 0;

            // 레벨업
            cout << "************************************************\n";
            cout << "        경험치를 획득합니다!"<< to_string(pendingExp) <<"exp \n";
            cout << "************************************************\n";
            player.GainExp(pendingExp);
    
            // 아이템 루팅 출력
            cout << "************************************************\n";
            cout << "        아이템을 획득합니다!           \n";
            cout << "************************************************\n";
            while (invPtr < player.GetInventory() + 5) {
                string itemName;
                if (*invPtr == 1) itemName = "골드";
                else if (*invPtr == 2) itemName = "회복 포션";
                else if (*invPtr == 3) itemName = "무기";
                else if (*invPtr == 4) itemName = "갑옷";
                else itemName = "None";
                cout << "> Slot" << slot << "[" << itemName << "]\n";
                invPtr++;
                slot++;
            }
        }
    }

    return 0;
}
