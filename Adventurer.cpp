#include "Adventurer.h"


//Assigning each passed in variable
Adventurer::Adventurer(string name, int health, int coins, Weapon currentWeapon){
  this->name = name;
  this->health = health;
  this->coins = coins;
  this->currentWeapon = currentWeapon;
}

string Adventurer::getName(){
  return name;
}

int Adventurer::getHealth(){
  return health;
}

void Adventurer::setHealth(int health){
  this->health = health;
}

int Adventurer::getCoins(){
  return coins;
}

void Adventurer::setCoins(int coins){
  this->coins = coins;
}

void Adventurer::setName(string name){
  this->name = name;
}

Weapon Adventurer::getCurrentWeapon(){
  return currentWeapon;
}

void Adventurer::setCurrentWeapon(Weapon weapon){
  currentWeapon = weapon;
}

//Attack enemy passed in, call method from weapons class
void Adventurer::useWeapon(Enemy* s){
  currentWeapon.attack(s);
}

//lower health by enemy damage 
void Adventurer::getHit(int enemyDamage){
  health -= enemyDamage;
}

void Adventurer::show(){
  cout << "Your health: " << health << endl;
}

void Adventurer::showStats(){
  cout << "Name: " << name << endl;
  cout << "Health: " << health << endl;
  cout << "Coins: " << coins << endl;
}

