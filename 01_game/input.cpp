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
  name = n;
}

void Piece::moveUp(int dis){
  verMove(-dis);
}

void Piece::moveDown(int dist){
  verMove(dist);
}

void Piece::moveLeft(int dist){
  horMove(-dist);
}

void Piece::moveRight(int dist){
  horMove(dist);
}

void Piece::horMove(int dist){
  int newCoor = xCoor+dist;
  if (lookSym(newCoor, yCoor) != '-'){
    status = name+"'s movement was blocked";
  }else{
    status = "";
    from_to(xCoor, yCoor, newCoor, yCoor);
    xCoor = newCoor;
  }
}

void Piece::verMove(int dist){
  int newCoor = yCoor+dist;
  if (lookSym(xCoor, newCoor) != '-'){
    status = name+"'s movement was blocked";
  }else{
    status = "";
    from_to(xCoor, yCoor, xCoor, newCoor);
    yCoor = newCoor;
  }
}

string Piece::getStatus(){
  return status;
}

char Piece::getChar(){
  return rep;
}

void Piece::inpMove(char dir){
  if (dir == 'w') moveUp(1);
  if (dir == 'a') moveLeft(1);
  if (dir == 's') moveDown(1);
  if (dir == 'd') moveRight(1);
  // printMessage("Player coordinates "
  //       +to_string(xCoor)+" "+to_string(yCoor));
}

void Piece::enemyMove(){
  int upDiff = player.pieceUp(yCoor),
    leftDiff = player.pieceLeft(xCoor);
  //if (abs(upDiff)+abs(leftDiff) <= 1) moveTo(xCoor,yCoor,rep);
  if (abs(upDiff) > abs(leftDiff) && upDiff < 0) {
    moveUp(1);
  }else if (abs(upDiff) > abs(leftDiff) && upDiff > 0){
    moveDown(1);
  }else if (abs(upDiff) < abs(leftDiff) && leftDiff > 0){
    moveRight(1);
  }else if (abs(upDiff) < abs(leftDiff) && leftDiff < 0){
    moveLeft(1);
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

