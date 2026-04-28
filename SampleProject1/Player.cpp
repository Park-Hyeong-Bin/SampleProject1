#include "Player.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Player::Player(const string& name, const string& characterClass, bool isHardcore)//외부 입력값 세팅 초기화
        :Character(50,50,50,50,1),
        name(name), characterClass(characterClass), isHardcore(isHardcore),
        exp(0),expToNextLevel(50)//단순 값 초기화
{
        maxHp = vitality * 2; //계산이 필요한 곳
        hp = maxHp;
        maxMp = energy * 2;
        mp = maxMp;
        attackDamage = strength * 0.2f;
        attackSpeed = dexterity * 10.0f;
        
}



Player::Player(const string& name, const string& characterClass, bool isHardcore,
    int str, int dex, int vit, int eng)
        :Character(str,dex,vit,eng,1), exp(0), expToNextLevel(50) {}


void Player::PreviewCritical() const{
    float preview = attackDamage * 2;
    cout << "크리티컬 예상 데미지: " << preview << '\n';
}

void Player::PrintLevel() const{
    cout << "현재 레벨: " << level << '\n';
}

void Player::LevelUp(){ level++;}

void Player::GainExp(int amount)
{
    exp += amount;
    if (exp >= expToNextLevel)
    {
        exp -= expToNextLevel;
        level++;
        expToNextLevel *= level * 50;
        cout << "[레벨 업!] Level: " << level << '\n';
    }
}

void Player::Loot(int count)
{
    cout<<"아이템 루팅중..."<<'\n';
    
    //count가 아이템을 vector에 추가
    cout << "************************************************\n";
    cout << "        아이템을 획득합니다! \n";
    cout << "************************************************\n";
    system("pause");
    system("cls");
    cout << "************************************************\n";
    cout << "         현재 내 인벤토리 \n";
    cout << "************************************************\n";
    for (int i = 0; i < count; i++)
    {
        //랜덤 숫자 1개씩 인벤토리 벡터에 넣음
        inventory.push_back(rand()%4 + 1);
    }
        
    for (int i = 0; i < inventory.size(); i++)
    {
        string itemName;
        if (inventory[i]== 1) itemName = "골드";
        else if (inventory[i] == 2) itemName = "회복 포션";
        else if (inventory[i] == 3) itemName = "무기";
        else if (inventory[i] == 4) itemName = "갑옷";
        else itemName = "None";
        cout << "> Slot" << to_string(i+1) << "[" << itemName << "]\n";
    }    
}
 