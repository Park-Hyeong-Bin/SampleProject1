#pragma once
#include <unordered_map>

#include "Item.h"

struct ItemData
{
    string name;
    ItemType type;
};

unordered_map<int, ItemData> createItemDB();