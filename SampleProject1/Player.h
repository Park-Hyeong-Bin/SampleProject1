#pragma once
#include <string>

using namespace std;

class Player
{
private:
    //기본 정보
    string name;
    string characterClass;
    bool isHardcore;

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

    //인벤토리
    int inventory[5];

public:
    Player(const string& name, const string& characterClass, bool isHardcore);//외부 입력값 세팅 초기화
        

    //Getters
    string GetName() const { return name; }
    string GetCharacterClass() const { return characterClass; }
    bool IsHardcore() const { return isHardcore; }
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
    int* GetInventory() { return inventory; }

    //기능(함수)
    bool isAlive() const { return hp > 0; }
    void TakeDamage(int damage);
    int Attack() const { return (int)attackDamage; }
    int CriticalAttack() const { return (int)(attackDamage * 2); }
    void PreviewCritical() const;
    void PrintLevel() const;

    // 객체지향에 맞춰 캐릭터 내부에 레벨업 기능 추가
    void LevelUp();   
};
