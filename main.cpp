//Maximillian H Nibler
//max.nibler@gmail.com
//https://github.com/maxnibler/

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <curses.h>
#include "roll.h"
#include "linkList.h"
#include "hashtable.h"
#include "input.h"
#include "screen.h"

using namespace std;

int main (/*int argc, char* argv[]*/){
  initscr();
  timeout(-1);
  
  initLocation();
  setScreen();
  
  //CursesWindow w(stdscr);
  int c = getch();
  endwin();
  cout << c << endl;
  //getDirection();
  return 0;
}
