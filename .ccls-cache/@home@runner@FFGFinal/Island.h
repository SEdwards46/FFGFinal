#pragma once
#include <iostream>
#include "Adventurer.h"
#include "Enemy.h"
#include "Hut.h"

using namespace std;

class Load;

class Island{

private:
Adventurer* slayer;
Enemy* badGuy;
int numKills = 0;
Hut store;
//int naturalValue;

public:
Island(Adventurer* e, Enemy* b);
void fight();
void naturalProb();
void setNumKills(int kills);
int getNumKills();
void combatMenu1();
void deadMenu1();
};