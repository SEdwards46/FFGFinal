#pragma once
#include <iostream>
#include <string>
#include "Enemy.h"

using namespace std;

class Weapon{

private:
string weaponName;
int weaponDamage;

public:
Weapon(string weaponName = "Fists", int weaponDamage = 15){ //Default weapon. Assign passed in values with this
  this->weaponName = weaponName;
  this->weaponDamage = weaponDamage;
}
string getWeaponName();
int getWeaponDamage();
void attack(Enemy* enemy);
};