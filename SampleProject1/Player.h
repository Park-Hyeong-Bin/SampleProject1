#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Character.h"
#include "Item.h"


using namespace std;

class Mercenary; //전방 선언

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
    vector<Item> inventory;

public:
    //생성자
    Player(const string& name, const string& characterClass, bool isHardcore);//외부 입력값 세팅 초기화
    
    //소멸자
    virtual ~Player();
    
protected:
    //생성자
    Player(const string& name, const string& characterClass, bool isHardcore,
        int str, int dex, int vit, int eng);//외부 입력값 세팅 초기화
        
public:
    //Getters
    string GetName() const { return name; }
    string GetCharacterClass() const { return characterClass; }
    bool IsHardcore() const { return isHardcore; }
    int GetExp() const { return exp; }
    int GetExpToNextLevel() const { return expToNextLevel; }
    
    shared_ptr<Mercenary> companion;
    
    //기능(함수)
    int CriticalAttack() const ;
    virtual string GetAttackMessage() const {return "";}
    void PreviewCritical() const;
    void PrintLevel() const;
    void LevelUp();
    void GainExp(int amount);
    void Loot(Item item); // 소유권 이전을 통한 아이템 획득
    void PrintInventory() const;//인벤토리 전체 출력
    
    
};
