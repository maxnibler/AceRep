//Maximillian H Nibler
//max.nibler@gmail.com
//https://github.com/maxnibler/

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <ncurses.h>
#include <unistd.h>
#include "input.h"
#include "screen.h"

bool logging;
bool active;
using namespace std;

int main (int argc, char* argv[]){
  int opt;
  while((opt = getopt(argc, argv, "l")) != -1){
    if (opt == 'l') logging = true;
  }  
  if (logging) openLog(0);
  initscr();
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
  if (logging) closeLog();
  endwin(); 
  return 0;
}
