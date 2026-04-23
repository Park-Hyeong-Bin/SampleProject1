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
    system("cls"); // Windows 전용 화면 지우기
}

// Monster 클래스 
class Monster
{
private:
    int hp, maxHp;
    int attackDamage;
public:
    Monster(int initHp, int atk)
        : hp(initHp), maxHp(initHp), attackDamage(atk)
    {
        cout << "[몬스터 등장!] HP: " << hp << " / ATK: " << attackDamage << '\n';
    }
    ~Monster()
    {
        cout << "[몬스터 소멸!]\n";
    }
    int GetHp() const { return hp; }
    int GetMaxHp() const { return maxHp; }
    int isAlive() const { return hp > 0; }
    void TakeDamage(int damage)
    {
        hp -= damage;
        if (hp <= 0) hp = 0; //음수 방지
    }
    int Attack() const { return attackDamage; }
};

//Player 클래스
class Player
{
private:
    //기본 정보
    string name;
    string characterClass;
    bool isHardcore;

    //기본 능력치
    int strength, dexterity, vitality, energy;

    //파생 능력치
    int level;
    int hp, maxHp;
    int mp, maxMp;
    float attackDamage;
    float attackSpeed;
    double movingSpeed;

    //저항력
    int fireResist, coldResist, lightningResist, poisonResist;

    //인벤토리
    int inventory[5];

public:
    Player(const string& name, const string& characterClass, bool isHardcore)//외부 입력값 세팅 초기화
        :name(name), characterClass(characterClass), isHardcore(isHardcore),//단순 값 초기화
        strength(50), dexterity(50), vitality(50), energy(50),
        level(1), movingSpeed(50),
        fireResist(0), coldResist(0), lightningResist(0), poisonResist(0)
    {
        maxHp = vitality * 2; //계산이 필요한 곳
        hp = maxHp;
        maxMp = energy * 2;
        mp = maxMp;
        attackDamage = strength * 0.2f;
        attackSpeed = dexterity * 10.0f;
        for (int i = 0; i < 5; i++) inventory[i] = 0;
    }

    //Getters
    string GetName() const { return name; }
    string GetCharacterClass() const { return characterClass; }
    bool IsHardcore() const { return isHardcore; }
    int GetStrength() const { return strength; }
    int GetDexterity() const { return dexterity; }
    int GetVitality() const { return vitality; }
    int GetEnergy() const { return energy; }
    int GetLevel() const { return level; }
    double GetMovingSpeed() const { return movingSpeed; }
    float GetFireResist() const { return fireResist; }
    float GetColdResist() const { return coldResist; }
    float GetLightningResist() const { return lightningResist; }
    float GetPoisonResist() const { return poisonResist; }
    float GetAttackDamage() const { return attackDamage; }
    float GetAttackSpeed() const { return attackSpeed; }
    int GetMaxHP() const { return maxHp; }
    int GetHP() const { return hp; }
    int GetMaxMP() const { return maxMp; }
    int GetMP() const { return mp; }

    int* GetInventory() { return inventory; }

    //기능(함수)
    bool isAlive() const { return hp > 0; }
    
    void TakeDamage(int damage)
    {
        hp -= damage;
        if (hp < 0) hp = 0;
    }
    
    int Attack() const { return (int)attackDamage; }
    int CriticalAttack() const { return (int)(attackDamage * 2); }

    void PreviewCritical() const
    {
        float preview = attackDamage * 2;
        cout << "크리티컬 예상 데미지: " << preview << '\n';
    }
    
    void PrintLevel() const
    {
        cout << "현재 레벨: " << level << '\n';
    }

    // 객체지향에 맞춰 캐릭터 내부에 레벨업 기능 추가
    void LevelUp() 
    {
        level++;
        // 레벨업 시 체력 회복 등의 보너스를 넣어도 좋아!
    }
};

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

    // --- [ PAGE 3 : Battle ] ---
    Monster goblin(60, 10);
    int action;

    cout << "            (  ` - '  )  \n";
    cout << "             )       (   \n";
    cout << "            (  o   o  )  < GRRRRR!!\n";
    cout << "             )   ^   (   \n";
    cout << "            (   ---   )  \n";
    cout << "             '-------'   \n";
    cout << "[SYSTEM] A Goblin appeared!\n";

    while (goblin.isAlive() && player.isAlive()) {
        cout << "\n[ Goblin: " << goblin.GetHp() << " HP ] vs [ " << userName << ": " << player.GetHP() << " HP ]\n";
        cout << "1. Attack! | 2. Bash Attack! | 3. Run! \nAction: ";
        cin >> action;

        if (action == 1) {
            int dmg = player.Attack();
            goblin.TakeDamage(dmg);
            cout << ">> You dealt " << dmg << " damage!\n";
            
        }
        else if (action == 2) {
            player.PreviewCritical();
            int critDmg = player.CriticalAttack();
            goblin.TakeDamage(critDmg);
            cout << ">> 크리티컬 히트! " << critDmg << " 데미지!\n";
        }
        else {
            cout << ">> You missed your chance!\n";
        }

        if (goblin.isAlive()) {
            player.TakeDamage(goblin.Attack());
            cout << ">> Goblin counter-attacked! (-" << goblin.Attack() << " HP)\n";
        }
    }

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
        cout << "   VICTORY! You defeated the Goblin!           \n";
        cout << "************************************************\n";

        nextPhase();
        
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
        cout << "        경험치를 획득합니다!           \n";
        cout << "************************************************\n";
        player.LevelUp();
        player.PrintLevel();
    
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

    return 0;
}
