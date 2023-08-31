#include "Hut.h"

Hut::Hut(Adventurer* w){
  guy = w;
}


Hut::Hut(){  //populate weapons 
  weapons.push_back(Weapon("Stick", 20));
  weapons.push_back(Weapon("Hammer", 30));
  weapons.push_back(Weapon("Bow", 40));
  weapons.push_back(Weapon("Sword", 50));
}

void Hut::display(){ //Show name damage number and price for weapons and coconuts 
 cout << "Welcome to the Hut!" << endl;
 cout << "Here are the available weapons: " << endl;
    for (int i = 0; i < weapons.size(); i++) {
     cout << (i + 1) << ") " << weapons[i].getWeaponName() << " - " << 
     weapons[i].getWeaponDamage() <<  " damage - " << weaponPrices[i] << " coins" << endl;
    }
 cout << "Here are the available coconuts: " << endl;
    for (int i = 0; i < 4; i++) {
     cout << (i + 1) << ") " << coconuts[i] << " - +" << (i + 1) * 10 << " health - " << 
     coconutPrices[i] << " coins" << endl;
    }
}
  

bool Hut::buyWeapon(int choice, Adventurer* shopper){ 
 int price = weaponPrices[choice - 1]; //-1 because starts at 0
   if (shopper->getCoins() < price) {
       cout << "You don't have enough coins to buy that." << endl;
       return false;
    }
      shopper->setCoins(shopper->getCoins() - price);//change coins 
      shopper->setCurrentWeapon(weapons[choice - 1]);//change weapon
      cout << "You bought a " << weapons[choice - 1].getWeaponName() << " for " << price << 
      "coins." << endl;
      return true;
}

bool Hut::buyCoconut(int choice, Adventurer* shopper){
  if (choice < 1 || choice > 4) {
        cout << "Invalid choice." << endl;
        return false;
      }
      int price = coconutPrices[choice - 1];
      if (shopper->getCoins() < price) {
        cout << "You don't have enough coins to buy that." << endl;
        return false;
      }
      shopper->setCoins(shopper->getCoins() - price);
      shopper->setHealth(shopper->getHealth() + (choice * 10));
      cout << "You bought a " << coconuts[choice - 1] << " for " << price << " coins." << endl;
      return true;
}
