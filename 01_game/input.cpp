//Maximillian H Nibler
//max.nibler@gmail.com
//https://github.com/maxnibler/

#include <ncurses.h>
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

void Piece::attackDir(){
  char dir = getDir(), sym;
  int aX, aY;
  if (dir == '1'){ aX = xCoor-1; aY = yCoor+1; }
  if (dir == '2'){ aX = xCoor;   aY = yCoor+1; }
  if (dir == '3'){ aX = xCoor+1; aY = yCoor+1; }
  if (dir == '4'){ aX = xCoor-1; aY = yCoor;   }
  if (dir == '6'){ aX = xCoor+1; aY = yCoor;   }
  if (dir == '7'){ aX = xCoor-1; aY = yCoor-1; }
  if (dir == '8'){ aX = xCoor;   aY = yCoor-1; }
  if (dir == '9'){ aX = xCoor+1; aY = yCoor-1; }
  sym = lookSym(aX, aY);
  if (sym == '.') status = name+" swings and misses!";
  if (sym == 'G') attack(&enemy);
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
