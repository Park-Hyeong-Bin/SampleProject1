#include "ItemData.h"

//아이템 추가시 이 파일만 수정하면 됨

unordered_map<int, ItemData> createItemDB()
{
    //100번대는 Consumable
    unordered_map<int, ItemData> db;
    db[101] = {"SmallHealingPotion", ItemType::Consumable};
    db[102] = {"SmallManaPotion", ItemType::Consumable};
    db[103] = {"HealingPotion", ItemType::Consumable};
    db[104] = {"ManaPotion", ItemType::Consumable};
    db[105] = {"LargeHealingPotion", ItemType::Consumable};
    db[106] = {"LargeManaPotion", ItemType::Consumable};
    db[107] = {"OmegaHealingPotion", ItemType::Consumable};
    db[108] = {"OmegaManaPotion", ItemType::Consumable};
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