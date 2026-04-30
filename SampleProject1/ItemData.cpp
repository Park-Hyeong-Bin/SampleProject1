#include "ItemData.h"

//아이템 추가시 이 파일만 수정하면 됨

unordered_map<int, ItemData> createItemDB()
{
    //100번대는 Consumable
    unordered_map<int, ItemData> db;
    db[101] = {"Small Healing Potion", ItemType::Consumable};
    db[102] = {"Small Mana Potion", ItemType::Consumable};
    db[103] = {"Healing Potion", ItemType::Consumable};
    db[104] = {"Mana Potion", ItemType::Consumable};
    db[105] = {"Large Healing Potion", ItemType::Consumable};
    db[106] = {"Large Mana Potion", ItemType::Consumable};
    db[107] = {"Omega Healing Potion", ItemType::Consumable};
    db[108] = {"Omega Mana Potion", ItemType::Consumable};
    db[109] = {"Elixir", ItemType::Consumable};
    db[110] = {"PowerElixir", ItemType::Consumable};
    
    //200번대는 Weapon
    db[201] = {"OldSword", ItemType::Weapon};
    db[202] = {"OldHammer", ItemType::Weapon};
    db[203] = {"OldStaff", ItemType::Weapon};
    db[204] = {"OldShortSword", ItemType::Weapon};
    db[205] = {"OldSpear", ItemType::Weapon};
    
    //300번대는 Armor
    db[301] = {"OldLeatherArmor", ItemType::Armor};
    db[302] = {"LeatherArmor", ItemType::Armor};
    db[301] = {"IronArmor", ItemType::Armor};
    
    
    //400번대는 ETC
    
    db[401] = {"Gold", ItemType::ETC};
    
    return db;
}