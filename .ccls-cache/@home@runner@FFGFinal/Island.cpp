#include "Island.h"
#include "Load.h"

Island::Island(Adventurer* e, Enemy* b){
  slayer = e;
  badGuy = b;
}

void Island::fight(){
  int numHits = 0; //initialize hits 
  if(getNumKills() <= 3){ //determine type based off of numKills, change every 3
    badGuy->setType("Crab");
  }
  else if(getNumKills() > 3 && numKills <= 6){
    badGuy->setType("Scorpian");
  }
  else if(getNumKills() > 6 && numKills <= 9){
    badGuy->setType("Monkey");
  }
  else{
    cout << "Woah! Congrats you defeated all the enemies and won the game! " << endl; //win
    return;
  }
  naturalProb(); // Call the naturalProb function to determine if a natural event occurs during the fight
  cout << "You are fighting a " << badGuy->getType() << "!" << endl;
  while(slayer->getHealth() > 0 && badGuy->getEnemyHealth() > 0){ //While both are alive fight
    slayer->getHit(badGuy->attack()); //Enemy hit
    slayer->useWeapon(badGuy); //Adventurer hit
    numHits++; //track hits
  }
  if(slayer->getHealth() <= 0){ //If dead show health for both and menu
    slayer->show();
    badGuy->showEnemy();
    deadMenu1();
  }
  else if(badGuy->getEnemyHealth() <= 0){ //if adventurer kills 
    slayer->show();
    cout << "You killed the " << badGuy->getType() << " in " << numHits << " hits." << endl;
    setNumKills(getNumKills());
    numKills++; //track number of kills
    cout << "Number of Kills " << getNumKills() << endl;
    slayer->setCoins(slayer->getCoins() + (100/numHits)); //More coins less hits 
    badGuy->setEnemyDamage(badGuy->attack() + (numKills * 2)); //Enemy gets stronger the more killed
    badGuy->setEnemyHealth(100 + (numKills * 10)); //Enemy gets more health the more killed
    combatMenu1();
 }
}

void Island::naturalProb(){ //1 in 10 chance of getting hit by natural disaster; takes away half health 
  int naturalValue;
  int randomChance = 1 + rand() % 10;
  if(randomChance == 2){
    naturalValue = slayer->getHealth() / 2;
    slayer->setHealth(slayer->getHealth() - naturalValue);
    if(badGuy->getType() == "Crab"){
      cout << "You got hit by a Tidal Wave! You lost half your health" << endl;
    }
    else if(badGuy->getType() == "Scorpian"){
      cout << "You got hit by a Sandstorm! You lost half your health" << endl;
    }
    else if(badGuy->getType() == "Monkey"){
      cout << "You got hit by a Monsoon! You lost half your health" << endl;
    }
    }
  else{
    naturalValue = 0;
    slayer->setHealth(slayer->getHealth() - naturalValue);
  }
}

int Island::getNumKills(){
  return numKills;
}

void Island::setNumKills(int kills){
  numKills = kills;
}

void Island::combatMenu1(){ //Gives options after enemy is killed
  Load hey(slayer,badGuy);
      cout << "What now?" << endl;
      cout << "1.Keep Fighting " << endl;
      cout << "2.Show current Stats " << endl;
      cout << "3.Save " << endl;
      cout << "4.Go to Store " << endl;
      cout << "5.Quit " << endl;
      int choice;
      cin >> choice;
      cout << endl;
      switch(choice){
      case 1:
      fight();
      break;
      case 2:
      slayer->showStats();
      combatMenu1();
      break;
      case 3:
      hey.saveProgress();
      combatMenu1();
      break;
      case 4:
      store.display();
      char pick;
      int num;
      cout << "Buy a weapon or coconut(w/c)? Which one(#)?" << endl; //Determine what they want to buy
      cin >> pick;
      cin >> num;
      if(pick == 'w'){
        store.buyWeapon(num, slayer);
      }
      else if(pick == 'c'){
        store.buyCoconut(num, slayer);
      }
      combatMenu1();
      case 5:
      cout <<"Thanks for playing " << endl;
      return;
      default:
      cout << "Invalid choice" << endl;
      break;
  }
}

void Island::deadMenu1(){ //gives options after adventurer is killed
  int dieChoice;
  Load bye(slayer,badGuy);
  cout << "Sucks that you died, but you can always play again " << endl;
  cout << "Do you want to start a new game(1) pick up from last save point(2)?" << endl;
  cin >> dieChoice;
  if(dieChoice == 1){
    cout << "Cool, just hit run to start a new game " << endl;
    return;
  }
  else if(dieChoice == 2){
    bye.uploadProgress();
    combatMenu1();
  }
  else{
    cout << "Invalid selection " << endl;
    return;
  }
}


