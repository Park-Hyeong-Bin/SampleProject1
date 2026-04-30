#include "Player.h"

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Item.h"

using namespace std;

Player::Player(const string& name, const string& characterClass, bool isHardcore)//외부 입력값 세팅 초기화
        :Character(50,50,50,50,1),
        name(name), characterClass(characterClass), isHardcore(isHardcore),
        exp(0),expToNextLevel(50)//단순 값 초기화
{
        maxHp = vitality * 2; //계산이 필요한 곳
        hp = maxHp;
        maxMp = energy * 2;
        mp = maxMp;
        attackDamage = (float)strength * 0.2f;
        attackSpeed = (float)dexterity / 10.0f;
        movingSpeed = (double)dexterity / 30.0f;
    
        inventory.reserve(6); //재할당에 다른 복사(Reallocation)를 방지하기 위해서 미리 capacity확보
}

Player::Player(const string& name, const string& characterClass, bool isHardcore,
    int str, int dex, int vit, int eng)
        : name(name), characterClass(characterClass), isHardcore(isHardcore), Character(str, dex, vit, eng, 1), exp(0), expToNextLevel(50)
{
        inventory.reserve(6);
}

Player::~Player()
{
    cout<<"[플레이어 소멸]"<<endl;
}

void Player::PreviewCritical() const{
    float preview = attackDamage * 2;
    cout << "크리티컬 예상 데미지: " << preview << '\n';
}

int Player::CriticalAttack() const
{
    return (int)(attackDamage * 2);
}

void Player::PrintLevel() const{
    cout << "현재 레벨: " << level << '\n';
}

void Player::LevelUp(){ level++;}

void Player::GainExp(int amount)
{
    exp += amount;
    if (exp >= expToNextLevel)
    {
        exp -= expToNextLevel;
        level++;
        expToNextLevel = level * 50;
        cout << "[레벨 업!] Level: " << level << '\n';
    }
}

void Player::Loot(Item item)
{
    cout << "[획득]" << item.name << endl;
    inventory.emplace_back(move(item)); // Item을 인벤토리 안으로 직접 이동
    cout << "인벤토리 size" << inventory.size() << endl;
    cout << "인벤토리 capacity" << inventory.capacity() << endl;
}

bool Player::UseItem(const string& itemName)
{
    auto it = find_if(inventory.begin(), inventory.end(), 
        [&itemName](const Item& item){ return item.name == itemName; });
    
    if (it != inventory.end())
    {
        if (it->type == ItemType::Consumable)
        {
            Heal(maxHp);
        }
        inventory.erase(it);
        it = inventory.erase(it);//erase 후 유효한 iterator반환
        cout << "인벤토리 size" << inventory.size() << endl;
        cout << "인벤토리 capacity" << inventory.capacity() << endl;
        return true;
    }
    return false;
}

void Player::PrintInventory() const
{
    //인벤토리 출력
    // 인벤토리 출력
    cout << "==================================================\n";
    cout << "||" << left << setw(46) << "          INVENTORY" << "||\n";
    cout << "==================================================\n";
    
    // count개 아이템을 vector에 추가
    for (int i = 0; i < inventory.size(); i++)
    {
        string typeStr;
        if (inventory[i].type == ItemType::Weapon) typeStr = "Weapon";
        else if (inventory[i].type == ItemType::Armor) typeStr = "Armor";
        else typeStr = "Consumable";
        cout << " > Slot " << i << " < [" << inventory[i].name <<"]\n";
    }
}

void Player::SortInventory()
{
    sort(//<algorithm> 정렬 함수 사용
        inventory.begin(), inventory.end(),//범위 지정
        [](const Item& a, const Item& b)//3번째 인자 람다식으로 기준 설정
        {
            return a.name<b.name;//a가 b보다 앞에오면 true -> 오름 차순 정렬
        }
        );
    cout <<"[인벤토리] 이름 정렬 완료.\n";
}
