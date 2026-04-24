#include "Player.h"
#include <iostream>
#include <string>

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
        for(int i = 0; i < 5; i++) inventory[i] = 0;
    
    
}






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
