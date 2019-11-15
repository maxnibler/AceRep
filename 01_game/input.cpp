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
  speed = 1;
}

void Piece::moveUp(){
  verMove(-speed);
}

void Piece::moveDown(){
  verMove(speed);
}

void Piece::moveLeft(){
  horMove(-speed);
}

void Piece::moveRight(){
  horMove(speed);
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
  if (dir == 'w') moveUp();
  if (dir == 'a') moveLeft();
  if (dir == 's') moveDown();
  if (dir == 'd') moveRight();
}

void Piece::enemyMove(){
  int upDiff = player.pieceUp(yCoor),
    leftDiff = player.pieceLeft(xCoor);
  if (abs(upDiff) > abs(leftDiff) && upDiff < 0) {
    moveUp();
  }else if (abs(upDiff) > abs(leftDiff) && upDiff > 0){
    moveDown();
  }else if (abs(upDiff) < abs(leftDiff) && leftDiff > 0){
    moveRight();
  }else if (abs(upDiff) < abs(leftDiff) && leftDiff < 0){
    moveLeft();
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

