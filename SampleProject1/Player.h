#pragma once
#include <string>
#include <vector>
#include "Character.h"


using namespace std;

class Player : public Character
{
private:
    //Player 고유정보
    string name;
    string characterClass;
    bool isHardcore;
    
    //경험치
    int exp, expToNextLevel;

    //인벤토리
    vector<int> inventory;
    
    
    
public:
    Player(const string& name, const string& characterClass, bool isHardcore);//외부 입력값 세팅 초기화

    //Getters
    string GetName() const { return name; }
    string GetCharacterClass() const { return characterClass; }
    bool IsHardcore() const { return isHardcore; }
    int GetExp() const { return exp; }
    int GetExpToNextLevel() const { return expToNextLevel; }
    vector<int> GetInventory() { return inventory; }

    //기능(함수)
    int CriticalAttack() const { return (int)(attackDamage * 2); }
    void PreviewCritical() const;
    void PrintLevel() const;
    void LevelUp();
    void GainExp(int amount);
    void Loot(int count = 3);
    virtual string GetAttackMessage() const{return "";}
    
protected:
    Player(const string& name, const string& characterClass, bool isHardcore, int str, int dex, int vit, int eng);//외부 입력값 세팅 초기화

    
    
};
