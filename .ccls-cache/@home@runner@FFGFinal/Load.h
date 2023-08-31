#include <iostream>
#include <fstream>
#include <math.h>
#include "Enemy.h"
#include "Adventurer.h"
#include "Island.h"


using namespace std;

class Load{

private:
Adventurer* slayerSave;
Enemy* badGuySave;
Island saver;

public:
Load(Adventurer* x, Enemy* y): saver(x,y){ //initiliaze pointers to saver class respectively
  slayerSave = x;
  badGuySave = y;
}
void saveProgress();
void uploadProgress();
void deleteOldStats();
};