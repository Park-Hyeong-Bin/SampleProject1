#include "Monster.h"
#include <iostream>
#include <string>

using namespace std;


Monster:: Monster(const string& name, int str, int dex, int vit, int en, int expReward, int lv)
    :Character(str, dex, vit, en, lv), name(name),expReward(expReward)
{
}