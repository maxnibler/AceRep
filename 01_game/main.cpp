//Maximillian H Nibler
//max.nibler@gmail.com
//https://github.com/maxnibler/

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <ncurses.h>
#include "roll.h"
#include "linkList.h"
#include "hashtable.h"
#include "input.h"
#include "screen.h"

using namespace std;

int main (/*int argc, char* argv[]*/){
  initscr();
<<<<<<< HEAD:main.cpp
  timeout(-1);
  
  initLocation();
  setScreen();
  
  //CursesWindow w(stdscr);
  int c = getch();
  endwin();
  cout << c << endl;
=======
  raw();
  keypad(stdscr, TRUE);
  noecho();
  initLocation();
  setScreen();
  bool active = true;
  while (active)
  refreshScreen();
  endwin();
>>>>>>> 13370e210aea4a305858e4c6825744c00ba69410:01_game/main.cpp
  //getDirection();
  return 0;
}
