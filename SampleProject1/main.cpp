#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// 화면을 지우고 다음 진행을 위해 멈추는 함수
void nextPhase() {
    cout << "\n[Press Enter to Continue...]";
    cin.ignore(100, '\n');
    cin.get();
    system("cls"); // Windows 전용 화면 지우기 (Mac/Linux는 "clear")
}

// Call by Value
void PreviewCritical(float attackDamage) {
    attackDamage *= 2;

    cout <<"예상 크리티컬 데미지 : " << attackDamage << "\n";// 복사본만 두배

}
/*
void LevelUp(int* level) {
    (*level)++;
}
*/

void LevelUpRef(int& level) {
    level++;
}

//const 참조자 : 복사 비용 절약 + 원본 수정 차단
void PrintLevel(const int& level) {
    cout << "현재 레벨은 " << level << "입니다.\n";
}

//Call by Ref 참조자 전달
void ApplyCriticalDamage(int& goblinHp, float attackDamage) {
    int criticalDamage = attackDamage * 2; // 치명타는 2배의 데미지
    goblinHp -= criticalDamage; // 원본 goblinHp를 직접 감소
}

// Monster 클래스 
class Monster
{
private:
    int hp, maxHp;
    int attackdamage;
    
    public:
    Monster(int initHp, int atk) : hp(initHp), maxHp(initHp), attackdamage(atk)
    {
        cout << "[몬스터 등장] Hp :" << hp << " / ATK: "<< attackdamage << endl;
    }
    ~Monster()
    {
        cout << "[몬스터소멸!]\n"; // 소멸자 확인용 로그
    }
    int GetHp() const{ return hp; }
    int GetMaxHp() const{ return maxHp; }
    bool isAlive() const {return hp > 0;}
    void TakeDamage(int damage)
    {
        hp -= damage;
        if (hp < 0 ) hp = 0;
    }
    int Attack() const{ return attackdamage; }
};


int main() {
    char userName[50];
    string charactorClass;
    int classChoiceInput;
    int hardcoreinput;

    int level = 1, hp = 100, mp = 100;
    float strength = 50, dexterity = 50;
    float attackDamage = strength * 0.2;
    float vitality = 50;
    float energy = 50;
    int fireResist = 0;
    int lightningResist = 0;
    int coldResist = 0;
    int poisonResist = 0;
    bool isHardcore = false;

    int gameInventory[5] = { 0,0,0,0,0 };
    
    // --- [ PAGE 1 : Intro ] ---
    system("cls");
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
    case 3: charactorClass = "Barbarian"; break;
    case 7: charactorClass = "Sorceress"; break;
    default: charactorClass = "Warrior"; break;
    }

    cout << "\nHardcore Mode? (1: Yes / 2: No): ";
    cin >> hardcoreinput;
    isHardcore = (hardcoreinput == 1);
    
    nextPhase();


    // --- [ PAGE 2 : Status ] ---
    cout << "================================================\n";
    cout << "             CHARACTER INFORMATION              \n";
    cout << "================================================\n";
    cout << "  NAME  : " << userName << "\n";
    cout << "  CLASS : " << charactorClass << " | LVL: " << level << "\n";
    cout << "  HP    : " << hp << " | MP: " << mp << "\n";
    cout << "  STR   : " << strength << " | DEX : " << dexterity << "\n";
    cout << "  REGIST\n";
    cout << "  FIRE  : " << fireResist << " | COLD :" << coldResist << "\n";
    cout << "  LIGHT : " << lightningResist << " | POSION : " << poisonResist << "\n";
    cout << "  DMG   : " << attackDamage << " | HARDCORE: " << (isHardcore ? "ON" : "OFF") << "\n";
    cout << "================================================\n";

    nextPhase();

    // --- [ PAGE 3 : Battle ] ---
    //생성자 호출
    Monster goblin(60,10);
    
    int goblinHP = 60;
    int action;

    cout << "            (  ` - '  )  \n";
    cout << "             )       (   \n";
    cout << "            (  o   o  )  < GRRRRR!!\n";
    cout << "             )   ^   (   \n";
    cout << "            (   ---   )  \n";
    cout << "             '-------'   \n";
    cout << "[SYSTEM] A Goblin appeared!\n";

    while (goblin.isAlive() && hp > 0) {
        cout << "\n[ Goblin: " << goblin.GetHp() << " HP ] vs [ " << userName << ": " << hp << " HP ]\n";
        cout << "1. Attack! | 2. Bash Attck! |3. Run! \nAction: ";
        cin >> action;

        if (action == 1) {
            goblin.TakeDamage((int)attackDamage);
            cout << ">> You dealt " << attackDamage << " damage!\n";
            if (goblin.isAlive()) {
                hp -= goblin.Attack();
                cout << ">> Goblin counter-attacked! (-30 HP)\n";
            }
        }
        else if(action == 2){
            PreviewCritical(attackDamage);
            goblin.TakeDamage((int)attackDamage*2);
            cout << ">> 크리티컬 히트!" << to_string((int)attackDamage * 2) << "\n";
            
            if (goblin.isAlive()) {
                hp -= goblin.Attack();
                cout << ">> Goblin counter-attacked! (-30 HP)\n";
            }
        }
        else {
            cout << ">> You missed your chance!\n";
            hp -= goblin.Attack();
        }
    }

    nextPhase();

    // --- [ PAGE 4 : Result ] ---
    if (hp <= 0) {
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
        cout << "   VICTORY! You defeated the Goblin!           \n";
        cout << "************************************************\n";


        //포인터로 인벤토리에 랜덤 숫자 저장
        int* invPtr = gameInventory; // invPtr -> gameInventory 시작주소 [0];

        for (int i = 1; i <= 3; i++) {
            *invPtr = rand() % 4 + 1;
            invPtr++;
        }

        //포인터 순회로 인벤토리 출력(5칸)
        invPtr = gameInventory; //invPtr 처음으로 리셋
        int slot = 0;

        //레벨업
        cout << "************************************************\n";
        cout << "   경험치를 획득합니다!           \n";
        cout << "************************************************\n";
        LevelUpRef(level);
        PrintLevel(level);

        //아이템 루팅
        cout << "************************************************\n";
        cout << "   아이템을 획득합니다!           \n";
        cout << "************************************************\n";
        while (invPtr < gameInventory + 5) {
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

    return 0;
}