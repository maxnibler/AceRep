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
  int x1 = 9, x2 = 8, y1 = 9, y2 = 0;
  loadArray();
  printf("Finding path from %d, %d to %d, %d\n",
	 x1, y1, x2, y2);
  findPath(x1,y1,x2,y2);
  printpath();
  /*initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
  initLocation();
  initPieces();
  setScreen();
  active = true;
  while(active){
    refreshScreen();
  }
  endwin();*/
  return 0;
}
