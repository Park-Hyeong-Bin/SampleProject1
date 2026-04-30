#include "MonsterData.h"


//몬스터 밸런스 조정시, 이파일만 수정하면 됨

 unordered_map<string, MonsterData> CreateMonsterDB()
{
    unordered_map<string, MonsterData> db;
    
     db["Goblin"] = {50,0,15,0, 50,{103,201,301,401}};
     db["FireGoblin"] = { 50, 0 ,15 ,0 ,50, {103,203,301}};
     db["Skeleton"] = {60,0,20,0, 50,{103,204,301,401}};
     db["Wraith"] = {50,0,25,0, 50,{103,205,402}};
     db["Ghoul"] = {70,0,35,0, 50,{103,302,402}};
     db["Andariel"] = {200,0,35,0, 50,{101,303,401}};
     db["Dragon"] = {500,0,150,0, 50,{101,201,401}};
    
     return db;
}

