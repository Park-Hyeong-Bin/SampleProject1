#pragma once

class Character
{
protected:
    //기본 능력치
    int strength, dexterity, vitality, energy;

    //파생 능력치
    int level;
    int hp, maxHp;
    int mp, maxMp;
    float attackDamage;
    float attackSpeed;
    double movingSpeed;
    
    //저항력
    int fireResist, coldResist, lightningResist, poisonResist;
    
    public:
     Character(int str, int dex, int vit, int eng, int lv);
     virtual ~Character(){}//가상 소멸자: 자식 소멸까지 안전하게 호출
    
    //Getter
    int GetStrength() const { return strength; }
    int GetDexterity() const { return dexterity; }
    int GetVitality() const { return vitality; }
    int GetEnergy() const { return energy; }
    int GetLevel() const { return level; }
    double GetMovingSpeed() const { return movingSpeed; }
    float GetFireResist() const { return fireResist; }
    float GetColdResist() const { return coldResist; }
    float GetLightningResist() const { return lightningResist; }
    float GetPoisonResist() const { return poisonResist; }
    float GetAttackDamage() const { return attackDamage; }
    float GetAttackSpeed() const { return attackSpeed; }
    int GetMaxHP() const { return maxHp; }
    int GetHP() const { return hp; }
    int GetMaxMP() const { return maxMp; }
    int GetMP() const { return mp; }
    
    //기능(함수)
    bool isAlive() const { return hp > 0;}
    void TakeDamage(int damage);
    virtual int Attack() const;
  
};
