//Maximillian H Nibler
//max.nibler@gmail.com
//https://github.com/maxnibler/

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <ncurses.h>
#include <math.h>
#include "input.h"
#include "screen.h"
#include "roll.h"

using namespace std;

char getInput(){
  char c = getch();
  switch(c){
    case '8' : return c;
    case '4' : return c;
    case '2' : return c;
    case '6' : return c;
    case '5' : return c;
    case '7' : return c;
    case '9' : return c;
    case '1' : return c;
    case '3' : return c;
    case '+' : return c;
    case 'p' : {
      active = false;
      return c;
    }
  }
  return getInput();
}

char getDir(){
  char c = getch();
  switch(c){
    case '8' : return c;
    case '4' : return c;
    case '2' : return c;
    case '6' : return c;
    case '7' : return c;
    case '9' : return c;
    case '1' : return c;
    case '3' : return c;
  }
  return getInput();
}

void playerMove(Piece* p){
  char dir = getInput();
  if (dir == '+'){
    p->attackDir();
  }else
  p->inpMove(dir);
}

void aiMove(Piece* p){
  p->enemyMove();
}
