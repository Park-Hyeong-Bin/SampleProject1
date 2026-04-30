#pragma once
#include "Monster.h"

class FireGoblin : public Monster
{
private:
    
public:
    FireGoblin(const string& name, const MonsterData& data, int lv = 1);
    
    int Attack() const override;
    string GetAttackMessage() const override{return "[불 휘두르기!]";}
};
