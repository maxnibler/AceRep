//Maximillian H Nibler
//max.nibler@gmail.com
//https://github.com/maxnibler/

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <ncurses.h>
#include "input.h"
#include "screen.h"
#include "roll.h"
#define DNUM 4

using namespace std;

void Piece::setLocation(int x, int y, char o, string n){
  xCoor = x;
  yCoor = y;
  rep = o;
  location[x][y] = o;
  name = n;
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

string Piece::getStatus(){
  return status;
}

char Piece::getChar(){
  return rep;
}

void Piece::inpMove(char dir){
  location[xCoor][yCoor] = '-';
  if (dir == 'w') verMove(-1);
  if (dir == 'a') horMove(-1);
  if (dir == 's') verMove(1);
  if (dir == 'd') horMove(1);
  printMessage("Player coordinates "
	       +to_string(xCoor)+" "+to_string(yCoor));
  location[xCoor][yCoor] = rep;
}

void Piece::enemyMove(){
  location[xCoor][yCoor] = '-';
  int face = roll(4);
  switch(face){
    case 1 : verMove(-1);
    case 2 : verMove(1);
    case 3 : horMove(-1);
    case 4 : horMove(1);
  }
  location[xCoor][yCoor] = rep;
}

char getInput(){
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
  return getInput();
}

void playerMove(Piece* p){
  char dir = getInput();
  p->inpMove(dir);
}

void aiMove(Piece* p){
  p->enemyMove();
}

