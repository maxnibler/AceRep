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
#define PSIZE 41

int order[] = {1, 2, 3, 6, 9, 8, 7, 4};

int dirOrder(int dir, int ind){
  int start, i, neg = 1;
  for (i = 0; i < 8; i++){
    if (order[i] == dir) start = i;
  }
  if ((ind % 2) == 1) neg = -1;
  i = start + (neg * (ind / 2));
  if (i < 0) i += 8;
  i = i % 8;
  return order[i];
}

int getDirection(int fromX, int fromY, int toX, int toY){
  int up = 8, upL = 7, upR = 9, r = 6, l = 4, downL = 1,
    down = 2, downR = 3, x = toX-fromX, y = toY-fromY;
  if (x == 0){
    if (y == 0) return 0;
    if (y < 0)  return up;
    if (y > 0)  return down;
  }else if (x < 0){
    if (y == 0) return l;
    if (y < 0)  return upL;
    if (y > 0)  return downL;
  }else if (x > 0){
    if (y == 0) return r;
    if (y < 0)  return upR;
    if (y > 0)  return downR;
  }
  return -1;
}

int loadPath(int fromX, int fromY, int toX, int toY,
	     int path[PSIZE],int depth, bool V[WIDTH][HEIGHT]){
  int dir = getDirection(fromX, fromY, toX, toY);
  //Path found
  if (dir == 0){
    return 0;
  }
  //Redundant movement check
  if (V[fromX][fromY]) return -1;
  V[fromX][fromY] = true;
  //Move out of bounds check
  if (fromX == -1 || fromY == -1 || fromX == WIDTH || fromY == HEIGHT)
    return -1;
  //Search too deep
  if (depth == 30) return -1;
  //Path blocked
  if (lookSym(fromX,fromY) != '.' && lookSym(fromX,fromY) != 'G') {
    return -1;
  }
  int trydir, found;
  for (int i = 1; i < 9; i++){
    trydir = dirOrder(dir, i);
    path[depth] = trydir;
    switch(trydir){
    case 1 :
      found = loadPath(fromX-1,fromY+1,toX,toY,path,depth+1,V);
      break;
    case 2 :
      found = loadPath(fromX,fromY+1,toX,toY,path,depth+1,V);
      break; 
    case 3 :
      found = loadPath(fromX+1,fromY+1,toX,toY,path,depth+1,V);
      break;
    case 4 :
      found = loadPath(fromX-1,fromY,toX,toY,path,depth+1,V);
      break;
    case 6 :
      found = loadPath(fromX+1,fromY,toX,toY,path,depth+1,V);
      break;
    case 7 :
      found = loadPath(fromX-1,fromY-1,toX,toY,path,depth+1,V);
      break;
    case 8 :
      found = loadPath(fromX,fromY-1,toX,toY,path,depth+1,V);
      break;
    case 9 :
      found = loadPath(fromX+1,fromY-1,toX,toY,path,depth+1,V);
      break;
    }
    if (found == 0) {
      return 0;
    }
  }
  return -1;
}
  

int findPath(int fromX, int fromY, int toX, int toY){
  int path[PSIZE];
  bool Visited[WIDTH][HEIGHT];
  for (int i = 0; i < WIDTH; i++){
    for (int j = 0; j < HEIGHT; j++){
      Visited[i][j] = false;
    }
  }
  int step = loadPath(fromX,fromY,toX,toY,path,0,Visited);
  if (step != -1)
    return path[0];
  else return 0;
}
  
bool lineSight(int fromX, int fromY, int toX, int toY){
  int y = (toY-fromY), x = (toX-fromX);
  int y2 = y*y; int x2 = x*x; int sqt = sqrt(x2+y2);
  if (sqt > PSIZE) return false;
  bool xHigh = (abs(x) >abs(y));
  int yInc = 0, xInc = 0, high, slope;
  if (y != 0) yInc = y / abs(y);
  if (x != 0) xInc = x / abs(x);
  int newX = fromX, newY = fromY;
  char sym;
  if (xHigh){
    high = x;
    if (y == 0) slope = high+1;
    else slope = abs(x)/abs(y);
    for (int i = 0; i < high-1; i++){
      newX += xInc;
      if ((i % slope) == 0) newY += yInc;
      sym = lookSym(newX,newY);
      if (sym != '.') return false;
    }
  }else{
    high = y;
    if (x == 0) slope = high+1;
    else slope = abs(y)/abs(x);
    for (int i = 0; i < high-1; i++){
      newY += yInc;
      if ((i % slope) == 0) newX += xInc;
      sym = lookSym(newX,newY);
      if (sym != '.') return false;
    }
  }
  return true;
}
    
      
  
  
  
