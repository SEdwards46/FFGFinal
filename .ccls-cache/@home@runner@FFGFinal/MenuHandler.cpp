#include "MenuHandler.h"


void MenuHandler::startMenu(){ 
  string characterName;
  cout << "Welcome to the Island FFG Game! " << endl;
  cout << "To start, tell me your name " << endl;
  cin >> characterName;
  mainCharacter->setName(characterName); //take input and set as name 
  cout << "Got it. Thank you " << mainCharacter->getName() << endl;
  mainCharacter->setHealth(100); //set stating health and coins 
  mainCharacter->setCoins(100);
  menu1();
}


void MenuHandler::menu1(){ //Options after initilzation 
  Load load(mainCharacter, badMain);
  Island fightingPlace(mainCharacter, badMain);
  int decision;
  cout << " What would you like to do now? " << endl;
  cout << " 1.Fight " << endl;
  cout << " 2.Show current Stats " << endl;
  cout << " 3.Save " << endl;
  cout << " 4.Quit " << endl;
  cin >> decision;
  cout << endl;
  switch(decision){
    case 1:
    fightingPlace.fight();
    break;
    case 2:
    mainCharacter->showStats();
    menu1();
    break;
    case 3:
    load.saveProgress();
    menu1();
    break;
    case 4:
    cout << "Thanks for playing " << endl;
    delete mainCharacter;
    delete badMain;
    return;
    default:
    cout << "Invalid choice" << endl;
    break;
  }
}
