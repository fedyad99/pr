#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;
enum class ItemType {
    SWORD,
    BOW,
    SPELL
};
enum Element {
    FIRE,
    EARTH,
    AIR,
    WATER
};
struct SWORD {
    int damage;
};
struct BOW {
    int damage;
    int charge_time;
    double distance;
};
struct SPELL {
    int damage;
    Element element;
    double distance;
};
union DROP{
    SWORD sword;
    SPELL spell;
    BOW bow;
};
struct Item {
    ItemType type;
    union DROP drop;
};
Item getRandomItem() {  // Создаёт и возвращает предмет со случайными характеристиками
    Item temp;
    
    int random = rand() % 3;
    switch (random){
    case (int)ItemType::SWORD: temp.type = ItemType::SWORD; break;
    case (int)ItemType::BOW: temp.type = ItemType::BOW; break;
    case (int)ItemType::SPELL: temp.type = ItemType::SPELL; break;
    }
    switch (temp.type){
    case ItemType::SWORD:
        temp.drop.sword.damage = rand() % 801 + 500;
        break;
    case ItemType::BOW:
        temp.drop.bow.damage = rand() % 501 + 250;
        temp.drop.bow.charge_time = rand() % 251 + 100;
        temp.drop.bow.distance = rand() % 151 +20;
        break;
    case ItemType::SPELL:
        temp.drop.spell.damage = rand() % 501 + 250;
        switch (rand() % 4) {
        case AIR: temp.drop.spell.element = AIR; break;
        case EARTH: temp.drop.spell.element = EARTH; break;
        case WATER: temp.drop.spell.element = WATER; break;
        case FIRE: temp.drop.spell.element = FIRE; break;
        }
        temp.drop.spell.distance = rand() % 51 + 20;
        break;
    }
    return temp;
}
    
void printItem(Item loot) {  // Выводит на экран информацию о предмете
    switch (loot.type){
    case ItemType::SWORD: 
        cout << "---SWORD---" << endl;
        cout << "Damage: " << loot.drop.sword.damage << endl;
        cout << endl;
        break;
    case ItemType::BOW: 
        cout << "---BOW---" << endl;
        cout << "Damage: " << loot.drop.bow.damage << endl;
        cout << "Charge Time: " << loot.drop.bow.charge_time << endl;
        cout << "Distance: " << loot.drop.bow.distance << endl;
        cout << endl;
        break;
    case ItemType::SPELL: 
        cout << "---SPELL---" << endl;
        cout << "Damage: " << loot.drop.spell.damage << endl;
        switch (loot.drop.spell.element){
        case AIR: cout << "Element: Air" << endl; break;
        case EARTH: cout << "Element: Earth" << endl; break;
        case FIRE: cout << "Element: Fire" << endl; break;
        case WATER: cout << "Element: Water" << endl; break;
        }        
        cout << "Distance: " << loot.drop.spell.distance << endl;
        cout << endl;
        break;
    }
}
int main(){
    srand(time(0));
    Item items[5];
    for (int i = 0; i < 5; i++) items[i] = getRandomItem();
    for (int i = 0; i < 5; i++) printItem(items[i]);
    system("pause");
    return 0;
}
