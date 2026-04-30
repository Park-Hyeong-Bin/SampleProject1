#pragma once
#include "Monster.h"

class FireGoblin : public Monster
{
private:
    
public:
    FireGoblin(const string& name, int str, int dex, int vit, int eng, int expReward, int lv = 1, vector<int>dropPool = {});
    
    int Attack() const override;
    string GetAttackMessage() const override{return "[불 휘두르기!]";}
};
