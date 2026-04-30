#pragma once
#include "Monster.h"
#include "Player.h"
#include "Ringbuffer.h"

class Battle
{
private:
    Player& player;
    Monster& monster;
    shared_ptr<Mercenary> mercenary;//없으면 nullptr
    //string combatMessage;
    Ringbuffer<string> battleLog;//링버퍼를 통해 최근 5개 전투 메세지 출력
    
public:
    Battle(Player& player, Monster& monster, shared_ptr<Mercenary> mercenary = nullptr);
    bool Run();    
};
