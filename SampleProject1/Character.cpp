#include "Character.h"

Character::Character(int str, int dex, int vit, int eng, int lv)
//외부 입력 값 세팅 초기화
    : strength(str), dexterity(dex), vitality(vit), energy(eng), level(lv),
    fireResist(0), coldResist(0), lightningResist(0), poisonResist(0)
{
    maxHp = vitality * 2; //계산이 필요한 곳
    hp = maxHp;
    maxMp = energy * 2;
    mp = maxMp;
    attackDamage = strength * 0.2f;
    attackSpeed = dexterity * 10.0f;
    
}

void Character::TakeDamage(int damage){
    hp -= damage;
    if (hp < 0) hp = 0;
}

int Character::Attack() const
{
    return (int)attackDamage;
}
