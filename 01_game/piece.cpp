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
#include "logging.h"

using namespace std;

/*------------------------
|   Value Calculations   |
------------------------*/

int Piece::pieceUp(int y){
  return yCoor - y;
}

int Piece::pieceLeft(int x){
  return xCoor - x;
}

int Piece::absDist(Piece* p){
  int x = p->pieceLeft(xCoor);
  int y = p->pieceUp(yCoor);
  x *= x; y *= y;
  int ret = sqrt(x+y);
  return ret;
}

/*------------------
|    Set Values    |
------------------*/

void Piece::setLocation(int x, int y, char o, string n){
  xCoor = x;
  yCoor = y;
  rep = o;
  name = n;
  speed = 1;
  dmg = 1;
}

/*----------------------
|    Value Returns     |
----------------------*/

string Piece::getName(){
  return name;
}

string Piece::getStatus(){
  return status;
}

char Piece::getChar(){
  return rep;
}

int Piece::getX(){
  return xCoor;
}

int Piece::getY(){
  return yCoor;
}

/*---------------------------
|    Positional Commands    |
---------------------------*/

void Piece::wait(){
  from_to(xCoor, yCoor, xCoor, yCoor);
}

void Piece::moveUp(){
  int newCoor = yCoor - speed;
  if (lookSym(xCoor, newCoor) != '.'){
    status = name+"'s movement was blocked";
  }else{
    from_to(xCoor, yCoor, xCoor, newCoor);
    yCoor = newCoor;
  }
}

void Piece::moveDown(){
  int newCoor = yCoor + speed;
  if (lookSym(xCoor, newCoor) != '.'){
    status = name+"'s movement was blocked";
  }else{
    from_to(xCoor, yCoor, xCoor, newCoor);
    yCoor = newCoor;
  }
}

void Piece::moveLeft(){
  int newX = xCoor - speed;
  if (lookSym(newX, yCoor) != '.'){
    status = name+"'s movement was blocked";
  }else{
    from_to(xCoor, yCoor, newX, yCoor);
    xCoor = newX;
  }
}

void Piece::moveRight(){
  int newX = xCoor + speed;
  if (lookSym(newX, yCoor) != '.'){
    status = name+"'s movement was blocked";
  }else{
    from_to(xCoor, yCoor, newX, yCoor);
    xCoor = newX;
  }
}

void Piece::moveRU(){
  int newY = yCoor - speed;
  int newX = xCoor + speed;
  if (lookSym(newX, newY) != '.'){
    status = name+"'s movement was blocked";
  }else{
    from_to(xCoor, yCoor, newX, newY);
    xCoor = newX;
    yCoor = newY;
  }
}

void Piece::moveLU(){
  int newY = yCoor - speed;
  int newX = xCoor - speed;
  if (lookSym(newX, newY) != '.'){
    status = name+"'s movement was blocked";
  }else{
    from_to(xCoor, yCoor, newX, newY);
    xCoor = newX;
    yCoor = newY;
  }
}

void Piece::moveLD(){
  int newY = yCoor + speed;
  int newX = xCoor - speed;
  if (lookSym(newX, newY) != '.'){
    status = name+"'s movement was blocked";
  }else{
    from_to(xCoor, yCoor, newX, newY);
    xCoor = newX;
    yCoor = newY;
  }
}

void Piece::moveRD(){
  int newY = yCoor + speed;
  int newX = xCoor + speed;
  if (lookSym(newX, newY) != '.'){
    status = name+"'s movement was blocked";
  }else{
    from_to(xCoor, yCoor, newX, newY);
    xCoor = newX;
    yCoor = newY;
  }
}

void Piece::inpMove(char dir){
  if (logging){
    string logs = name+" moves:";
    logString(logs);
  }
  if (dir == '8') moveUp();
  if (dir == '4') moveLeft();
  if (dir == '2') moveDown();
  if (dir == '6') moveRight();
  if (dir == '7') moveLU();
  if (dir == '9') moveRU();
  if (dir == '1') moveLD();
  if (dir == '3') moveRD();
  if (dir == '5') wait();    
}

/*-------------------------
|     Combat Commands     |
-------------------------*/

void Piece::attack(Piece* p){
  if (logging){
    string logs = name+" attacks: "+p->getName();
    logString(logs);
  }
  status = name+" attacks "+p->getName()+" for "
    +to_string(dmg)+" damage.";
}




    
