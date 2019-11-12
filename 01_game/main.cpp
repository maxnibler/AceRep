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
  raw();
  keypad(stdscr, TRUE);
  noecho();
  initLocation();
  setScreen();
  bool active = true;
  while (active)
  refreshScreen();
  endwin();
  //getDirection();
}
