//Maximillian H Nibler
//max.nibler@gmail.com
//https://github.com/maxnibler/

#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <ncurses.h>
#include "input.h"
#include "screen.h"
#define DNUM 4

using namespace std;

void Piece::setLocation(int x, int y, char o){
  xCoor = x;
  yCoor = y;
  rep = o;
  location[x][y] = o;
}

void Piece::horMove(int dist){
  if (xCoor + dist < 1 || xCoor + dist >= WIDTH-1) return;
  prevX = xCoor;
  xCoor = (xCoor + dist) % WIDTH;
}

void Piece::verMove(int dist){
  if (yCoor + dist < 2 || yCoor + dist >= HEIGHT-1) return;
  prevY = yCoor;
  yCoor = (yCoor + dist) % HEIGHT;
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
  location[xCoor][yCoor] = '-';
  if (dir == 'w') this->verMove(-1);
  if (dir == 'a') this->horMove(-1);
  if (dir == 's') this->verMove(1);
  if (dir == 'd') this->horMove(1);
  location[xCoor][yCoor] = rep;
}

char getDirection(){
  char dir = getch();
  switch(dir){
    case 'w' : return dir;
    case 'a' : return dir;
    case 's' : return dir;
    case 'd' : return dir;
    case 'p' : {
      active = false;
      return dir;
    }
  }
  return getDirection();
}
