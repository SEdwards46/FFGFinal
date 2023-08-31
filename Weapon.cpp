#include "Weapon.h"

string Weapon::getWeaponName(){
  return weaponName;
}

int Weapon::getWeaponDamage(){
  return weaponDamage;
}

void Weapon::attack(Enemy* enemy){
  enemy->getAttacked(weaponDamage);
}