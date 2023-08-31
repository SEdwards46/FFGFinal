#pragma once 
#include <iostream>
#include <string>
#include "Enemy.h"
#include "Weapon.h"

using namespace std;

class Adventurer{

private:
string name;
int health;
int coins;
Weapon currentWeapon;

public:
Adventurer(string name, int health, int coins, Weapon currentWeapon);
string getName();
int getHealth();
int getCoins();
Weapon getCurrentWeapon();
void setName(string name);
void getHit(int enemyDamage);
void setHealth(int health);
void setCoins(int coins);
void useWeapon(Enemy* s);
void setCurrentWeapon(Weapon weapon);
void show();
void showStats();
};