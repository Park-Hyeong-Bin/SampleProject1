#include "Mercenary.h"

#include <iostream>

Mercenary::Mercenary(const string& name, int atk, shared_ptr<Player> owner)
    :  name(name), attackDamage(atk), owner(owner)
{
    std::cout << "[용병 고용]"<< name <<"이(가) 합류 했습니다." << endl;
}
Mercenary::~Mercenary()
{
    cout<<"[용병 소멸]" << name << "\n";
}