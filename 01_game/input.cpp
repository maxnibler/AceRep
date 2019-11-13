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

int Piece::pieceUp(int y){
  return yCoor - y;
}

int Piece::pieceLeft(int x){
  return xCoor - x;
}

void Piece::setLocation(int x, int y, char o, string n){
  xCoor = x;
  yCoor = y;
  rep = o;
  location[x][y].push(o);
  name = n;
}

void Piece::horMove(int dist){
  location[xCoor][yCoor].pop();
  if (xCoor + dist < 1 || xCoor + dist >= WIDTH-1) return;
  prevX = xCoor;
  xCoor = (xCoor + dist) % WIDTH;
  location[xCoor][yCoor].push(rep);
}

void Piece::verMove(int dist){
  location[xCoor][yCoor].pop();
  if (yCoor + dist < 2 || yCoor + dist >= HEIGHT-1) return;
  prevY = yCoor;
  yCoor = (yCoor + dist) % HEIGHT;
  location[xCoor][yCoor].push(rep);
}

string Piece::getStatus(){
  return status;
}

char Piece::getChar(){
  return rep;
}

void Piece::inpMove(char dir){
  if (dir == 'w') verMove(-1);
  if (dir == 'a') horMove(-1);
  if (dir == 's') verMove(1);
  if (dir == 'd') horMove(1);
  printMessage("Player coordinates "
	       +to_string(xCoor)+" "+to_string(yCoor));
}

void Piece::enemyMove(){
  int upDiff = player.pieceUp(yCoor),
    leftDiff = player.pieceLeft(xCoor);
  if (abs(upDiff) == 1 && abs(leftDiff) == 1)return;
  if (abs(upDiff) > abs(leftDiff)) {
    verMove(upDiff/abs(upDiff));
  }else{
    horMove(leftDiff/abs(leftDiff));
  }
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

