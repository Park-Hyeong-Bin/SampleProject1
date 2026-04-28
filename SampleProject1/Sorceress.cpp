#include "Sorceress.h"

Sorceress::Sorceress(const string& name, bool isHardcore)
    :Player(name,"Sorceress",isHardcore, ){}

int Sorceress::Attack() const
{
    return energy*2;
}
