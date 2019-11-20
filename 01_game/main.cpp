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
#include "input.h"
#include "screen.h"

bool active;
using namespace std;

int main (/*int argc, char* argv[]*/){
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
  initLocation();
  initPieces();
  //cout << findPath
  setScreen();
  active = true;
  while(active){
    refreshScreen();
  }
  endwin(); 
  return 0;
}
