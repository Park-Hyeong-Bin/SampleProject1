#pragma once
#include <string>
#include "Character.h"
#include "Item.h"
#include <memory>

using namespace std;

class Monster : public Character
{
private:
    string name;
    int expReward;
    
public:
    Monster(const string& name, int str, int dex, int vit, int eng, int expReward, int lv = 1);
    virtual ~Monster();//소멸자 체크용
    
    
    int GetExpReward() const { return expReward; }
    string GetName() const { return name; }
    
    virtual string GetAttackMessage() const{return "";}
    virtual unique_ptr<Item> Drop() const; //몬스터 처치시 아이템이 드롭
};

