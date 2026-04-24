#pragma once
#include "Monster.h"
#include "Player.h"
#include <string>

using namespace std;

class Battle
{
private:
    Player& player;
    Monster& monster;
    string combatMessage;
    
public:
    Battle(Player& player, Monster& monster);
    bool Run();
    
    
    Battle();
    
};
