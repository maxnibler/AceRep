//Maximillian H Nibler
//max.nibler@gmail.com
//https://github.com/maxnibler/

#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <ncurses.h>
#include "input.h"
#define DNUM 4

using namespace std;

void Piece::setLocation(int x, int y, char o){
  xCoor = x;
  yCoor = y;
  rep = o;
}

void Piece::horMove(int dist){
  xCoor += dist;
}

void Piece::verMove(int dist){
  yCoor -= dist;
}

int Piece::getY(){
  return yCoor;
}

int Piece::getX(){
  return xCoor;
}

char Piece::getChar(){
  return rep;
}

void Piece::move(){
  char dir = getDirection();
  if (dir == 'w') this->verMove(1);
  if (dir == 'a') this->horMove(-1);
  if (dir == 's') this->verMove(-1);
  if (dir == 'd') this->horMove(1);
}

char getDirection(){
  char dir = getch();
  switch(dir){
    case 'w' : return dir;
    case 'a' : return dir;
    case 's' : return dir;
    case 'd' : return dir;
    case 'p' : {
      endwin();
    }
  }
  return getDirection();
}
