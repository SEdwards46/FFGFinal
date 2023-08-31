#include "Load.h"


void Load::saveProgress(){
  deleteOldStats(); 
  ofstream outFile("saveFile.txt"); 
  if(outFile.is_open()){//while open input all current stats
   outFile << slayerSave->getName() << endl;
   outFile << slayerSave->getHealth() << endl;
   outFile << slayerSave->getCoins() << endl;
   outFile << slayerSave->getCurrentWeapon().getWeaponName() << endl;
   outFile << slayerSave->getCurrentWeapon().getWeaponDamage() << endl;
   outFile << saver.getNumKills() << endl;
   outFile.close();
   cout << "Progress saved" << endl;
  }
  else{
    cout << "Error saving Progress" << endl;
  }
}

void Load::uploadProgress(){ //read file, update all stats to current stats
  ifstream inFile("saveFile.txt");
  string name, weaponName;
  int health, coins, weaponDamage, numKills;
  if (inFile.is_open()) {
    inFile >> name >> health >> coins >> weaponName >> weaponDamage >> numKills;
    slayerSave->setName(name);
    slayerSave->setHealth(health);
    slayerSave->setCoins(coins);
    slayerSave->setCurrentWeapon(Weapon(weaponName,weaponDamage));
    saver.setNumKills(numKills);
        cout << "Progress loaded successfully!" << endl;
    } else {
        cout << "Error uploading progress." << endl;
    }
}


void Load::deleteOldStats(){ //clear file with trunc
  ofstream outFile("saveFile", ios::trunc);
  outFile.close();
}