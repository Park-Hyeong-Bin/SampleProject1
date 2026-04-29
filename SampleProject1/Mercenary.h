#pragma once
#include <memory>
#include <string>
#include "Player.h"

using namespace std;

class Mercenary
{
public:
    string name;
    int attackDamage;
    weak_ptr<Player> owner; 
    
    
    Mercenary(const string& name, int atk, shared_ptr<Player> owner);
    ~Mercenary();
    
    int Attack() const {return attackDamage;}
    bool IsOwnerAlive(){return owner.expired();}//주인이 살아있는 지 확인
    
};
