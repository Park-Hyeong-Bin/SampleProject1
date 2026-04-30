#include <iostream>
#include <ostream>
#include <unordered_map>
#include "ItemData.h"
#include "MonsterData.h"
using namespace std;

class GameInstance
{
private:
    GameInstance()
    {
        cout << "[GameInstance] *** 생성자 호출 됨 *** (this = "<< this << endl;
        itemDB = createItemDB();
        monsterDB = CreateMonsterDB();
    }
    
    ~GameInstance()
    {
        cout << "[GameInstance] *** 소멸자 호출 됨 *** (this = "<< this << endl;
    }
    
    // 복사/이동 금지 - 2번째 이상 객체 생성을 원천 차단
    GameInstance(const GameInstance&) = delete;
    GameInstance& operator=(const GameInstance&) = delete;
    
public:
    // 지역 정적 변수 - 함수 최초 호출 시 1번만 생성
    static GameInstance& GetGameInstance()
    {
        static GameInstance instance;
        return instance;
    }
    
    unordered_map<int, ItemData> itemDB;
    unordered_map<string, MonsterData> monsterDB;
};