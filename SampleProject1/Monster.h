#pragma once
#include <string>
#include "Character.h"
#include "Item.h"
#include <memory>
#include <vector>

using namespace std;

class Monster : public Character
{
private:
    string name;
    int expReward;
    vector<int> dropPool; // 몬스터가 드롭 가능한 아이템 ID 목록
    
public:
    Monster(const string& name, int str, int dex, int vit, int eng, int expReward, int lv = 1, vector<int> dropPool = {});
    
    
    
    int GetExpReward() const { return expReward; }
    string GetName() const { return name; }
    
    virtual string GetAttackMessage() const{return "";}
    int Drop() const; //몬스터 처치시 아이템이 드롭
};

