#include <iostream>
#include "Adventurer.h"
#include "Enemy.h"
#include "Hut.h"
#include "Island.h"
#include "Weapon.h"
#include "Load.h"

using namespace std;

class MenuHandler{

private:
Enemy* badMain;
Adventurer* mainCharacter;

public:
MenuHandler(){
  mainCharacter = new Adventurer("John", 0, 0, Weapon("Fists",15));//Default Adventurer
  badMain = new Enemy("Bob", rand() % 10, 100); //initialze Enemy (Bob will be changed to Crab upon first fight)
}
void startMenu();
void menu1();
};