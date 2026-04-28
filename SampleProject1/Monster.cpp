#include "Monster.h"

#include <chrono>
#include <iostream>
#include <string>

using namespace std;


Monster:: Monster(const string& name, int str, int dex, int vit, int eng, int expReward, int lv)
    :Character(str, dex, vit, eng, lv), name(name),expReward(expReward)
{
    cout << "[몬스터 생성]" << name << endl;
}

Monster::~Monster()
{
    cout << "[몬스터 소멸]" << name << endl;
}

unique_ptr<Item> Monster::Drop() const
{
    if (rand() % 2 == 0) return nullptr;//일반 몬스터는 절반 확률로 드롭 없음
    
    int roll = rand() % 3; // 0,1,2중
    if (roll == 0)
    {
        return make_unique<Item>("Short Sword", ItemType::Weapon);
    }
    else if (roll == 1)
    {
        return make_unique<Item>("Leather Armor", ItemType::Armor);
    }
    else
    {return make_unique<Item>("Healing Potion", ItemType::Consumable);}
}
