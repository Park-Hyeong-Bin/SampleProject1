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

    /*
    cout << "hp 변수의 값" << hp << "\n"; 
    cout << "hp 변수의 주소 값" << &hp << "\n"; //변수의 주소값 출력 & 앰퍼센트 연산자 사용

    system("pause"); // 
    int* ptr = &hp;
    cout << "ptr == &hp 변수의 값" << ptr << "\n";
    cout << "*ptr 값" << *ptr << "\n";

    *ptr = 200;
    cout << "hp 변수의 값" << hp << "\n";
    cout << "*ptr 값" << *ptr << "\n";
    system("pause"); // 
    */
    /*
    int* ptr2 = nullptr;//포인터 초기화
    cout << "*ptr2 값" << *ptr2 << "\n";
    */

    /*
    //변수와 포인터의 크기확인
    cout << "sizeof(int)" << sizeof(int) << "\n";
    cout << "sizeof(int*)" << sizeof(int*) << "\n";
    cout << "sizeof(double)" << sizeof(double) << "\n";
    cout << "sizeof(double*)" << sizeof(double*) << "\n";
    cout << "sizeof(char*)" << sizeof(char*) << "\n";

    //포인터 연산(+1 = 자료형 메모리 크기만큼 이동)
    cout << "ptr :" << ptr << "\n";
    cout << "ptr+1(주소값에 +1) :" << ptr + 1 << "\n";
    cout << "ptr+2 :" << ptr + 2 << "\n";
    system("pause");
    */


    //배열에 포인트를 주었을 경우
    int score[5] = { 85,92,78,46,50 };
    cout << " score[0] : " << score[0] << "\n";
    cout << " & score[0] : " << &score[0] << "\n";
    cout << " score[1] : " << score[1] << "\n";
    cout << " & score[1] : " << &score[1] << "\n";
    cout << " score[2] : " << score[2] << "\n";
    cout << " & score[2] : " << &score[2] << "\n";
    cout << " score[3] : " << score[3] << "\n";
    cout << " & score[3] : " << &score[3] << "\n";
    cout << " score[4] : " << score[4] << "\n";
    cout << " & score[4] : " << &score[4] << "\n";
    system("pause");
    
    cout << "score : " << score << "\n";//배열 이름
    cout << "&score[0] : " << &score[0] << "\n";//첫 원소 주소
    cout << "score[2] : " << score[2] << "\n";//인덱스로 접근
    cout << "*(score+2) : " << *(score+2) << "\n";// 포인터 연산

    //형변환의 예외 상황
    cout << "sizeof(score) : " << sizeof(score) << "\n";
    cout << "sizeof(score[0]) : " << sizeof(score[0]) << "\n";
    cout << "sizeof(score)/sizeof(score[0]) : " << sizeof(score)/sizeof(score[0]) << "\n";
    system("pause");
    
    
    //형변환의 예외 상황2
    cout << "score : " << score << "\n";//시작주소
    cout << "score+1 : " << score + 1 << "\n";//시작주소가 원소를 가리켜서 다음원소의 주소값을 가리킴
    cout << "&score : " << &score << "\n";//시작주소
    cout << "&score+1 : " << &score + 1 << "\n";//주소로 접근해서 다음 배열을 가리키게됨

    system("pause");
    nextPhase();
    //for 반복문을 통한 배열 순환
    int* sPtr = score;
    for (int i = 0; i < 5;i++) {
        cout << "score[" << i << "]의 주소와 값\n";
        cout << "주소 : " << sPtr << "\n";
        cout << " 값  : " << *sPtr << "\n";
        sPtr++;
    }

    system("pause");

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
    cout << "  FIRE  : "<< fireResist <<" | COLD :" << coldResist <<"\n";
    cout << "  LIGHT : "<< lightningResist <<" | POSION : "<< poisonResist <<"\n";
    cout << "  DMG   : " << attackDamage << " | HARDCORE: " << (isHardcore ? "ON" : "OFF") << "\n";
      cout << "================================================\n";

    nextPhase();

    // --- [ PAGE 3 : Battle ] ---
    float goblinHP = 30;
    int action;

    cout << "            (  ` - '  )  \n";
    cout << "             )       (   \n";
    cout << "            (  o   o  )  < GRRRRR!!\n";
    cout << "             )   ^   (   \n";
    cout << "            (   ---   )  \n";
    cout << "             '-------'   \n";
    cout << "[SYSTEM] A Goblin appeared!\n";

    while (goblinHP > 0 && hp > 0) {
        cout << "\n[ Goblin: " << goblinHP << " HP ] vs [ " << userName << ": " << hp << " HP ]\n";
        cout << "1. Attack! | 2. Run! \nAction: ";
        cin >> action;

        if (action == 1) {
            goblinHP -= attackDamage;
            cout << ">> You dealt " << attackDamage << " damage!\n";
            if (goblinHP > 0) {
                hp -= 30;
                cout << ">> Goblin counter-attacked! (-30 HP)\n";
            }
        }
        else {
            cout << ">> You missed your chance!\n";
            hp -= 30;
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

        srand((unsigned int)time(NULL));
        for (int i = 1; i <= 3; i++) {
            string items[] = { "Gold", "Health Potion", "Old Sword", "Shield" };
            cout << "  Looting... found: [" << items[rand() % 4] << "]\n";
        }
    }

    return 0;
}