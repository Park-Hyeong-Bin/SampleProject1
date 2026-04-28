#pragma once
#include <string>

#include "Player.h"

class Sorceress :  public Player
{
public:
    Sorceress(const string& name, bool isHardcore);
    
    int Attack() const override;
    string GetAttackMessage() const override{return "[Icebolt!]";}
        
};
