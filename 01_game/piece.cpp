//Maximillian H Nibler
//max.nibler@gmail.com
//https://github.com/maxnibler/

#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <fstream>
#include <ncurses.h>
#include <math.h>
#include "input.h"
#include "screen.h"
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

void Piece::setLocation(int x, int y, char o){
  xCoor = x;
  yCoor = y;
  rep = o;
}

void Piece::setStats(int s, int d, string n){
  name = n;
  speed = s;
  dmg = d;
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

void Piece::moveDir(int dir){
  int newX = xCoor, newY = yCoor;
  if (logging){
    string logs = "In direction: "+to_string(dir)+"\n";
    logString(logs);
  }
  if (dir == 1){
    newX = xCoor-speed;
    newY = yCoor+speed;
  }else if (dir == 2){
    newX = xCoor;
    newY = yCoor+speed;
  }else if (dir == 3){
    newX = xCoor+speed;
    newY = yCoor+speed;
  }else if (dir == 4){
    newX = xCoor-speed;
    newY = yCoor;
  }else if (dir == 6){
    newX = xCoor+speed;
    newY = yCoor;
  }else if (dir == 7){
    newX = xCoor-speed;
    newY = yCoor-speed;
  }else if (dir == 8){
    newX = xCoor;
    newY = yCoor-speed;
  }else if (dir == 9){
    newX = xCoor+speed;
    newY = yCoor-speed;
  }else if (dir == 5){
    newX = xCoor;
    newY = yCoor;
    if (logging){
      string logs = name+" Stays in place\n";
      logString(logs);
    }
  }
  if (lookSym(newX, newY) != '.'){
    if (dir != 5 && dir != 0)
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
  const char* d = new char(dir);
  moveDir(atoi(d));   
}

/*-------------------------
|     Combat Commands     |
-------------------------*/

void Piece::attack(Piece* p){
  if (logging){
    string logs = name+" attacks: "+p->getName()+"\n";
    logString(logs);
  }
  status = name+" attacks "+p->getName()+" for "
    +to_string(dmg)+" damage.";
}




    
