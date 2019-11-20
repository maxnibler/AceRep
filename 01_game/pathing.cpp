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
#define PSIZE 20

int testArray[10][10];
int path[PSIZE];
int order[] = {1, 2, 3, 6, 9, 8, 7, 4};


void loadArray(){
  int load;
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      if (roll(6) == 1){
	load = 2;
      }else{
	load = 1;
      }
      testArray[i][j] = load;
    }
  }
}

int oppositeDir(int dir){
  int start, i, opp;
  for (i = 0; i < 8; i++){
    if (order[i] == dir) start = i;
  }
  opp = order[(start+4) % 8];
  //cout << "Opp of " << dir << "is " << opp << endl;
  return opp;
}

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

void printpath(){
  int i;
  for (i = 0; i < 10; i++){
    cout << "[ ";
    for (int j = 0; j < 10; j++){
      cout << testArray[j][i] << ' ';
    }
    cout << "]\n";
  }
  i = 0;
  cout << "Path: ";
  while (i < PSIZE){
    cout << path[i++] << " ";
  }
  cout << endl;
}

int getDirection(int fromX, int fromY, int toX, int toY){
  int up = 8, upL = 7, upR = 9, r = 6, l = 4, downL = 1,
    down = 2, downR = 3, x = toX-fromX, y = toY-fromY;
  //printf("X diff: %d, Y diff: %d\n", x, y);
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


void findPath(int fromX, int fromY, int toX, int toY){
  bool Visited[10][10];
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      Visited[i][j] = false;
    }
  }
  loadPath(fromX,fromY,toX,toY,0,Visited);
}

int loadPath
(int fromX, int fromY, int toX, int toY, int depth, bool V[10][10]){
  int dir = getDirection(fromX, fromY, toX, toY);
  //cout << "Destination in dir: " << dir << endl;
  if (dir == 0){
    return 0;
  }
  if (V[fromX][fromY]) return -1;
  V[fromX][fromY] = true;
  if (fromX == -1 || fromY == -1 || fromX == 10 || fromY == 10)
    return -1;
  if (depth == 19) return -1;
  if (testArray[fromX][fromY] == 2) {
    //printf("Coordinates: %d, %d blocked.\n", fromX, fromY);
    return -1;
  }
  int trydir, found;
  for (int i = 1; i < 9; i++){
    trydir = dirOrder(dir, i);
    path[depth] = trydir;
    //if (oppositeDir(trydir) == path[depth-1]){
    //}else{
    switch(trydir){
    case 1 :
      found = loadPath(fromX-1,fromY+1,toX,toY,depth+1,V);
      break;
    case 2 :
      found = loadPath(fromX,fromY+1,toX,toY,depth+1,V);
      break;
    case 3 :
      found = loadPath(fromX+1,fromY+1,toX,toY,depth+1,V);
      break;
    case 4 :
      found = loadPath(fromX-1,fromY,toX,toY,depth+1,V);
      break;
    case 6 :
      found = loadPath(fromX+1,fromY,toX,toY,depth+1,V);
      break;
    case 7 :
      found = loadPath(fromX-1,fromY-1,toX,toY,depth+1,V);
      break;
    case 8 :
      found = loadPath(fromX,fromY-1,toX,toY,depth+1,V);
      break;
    case 9 :
      found = loadPath(fromX+1,fromY-1,toX,toY,depth+1,V);
      break;
      //}
    }
    //cout << "Trying direction: " << trydir <<
    //  " at depth: " << depth << " found: " << found << endl;
    if (found == 0) {
      return 0;
    }
  }
  return -1;
}
  
  
//bool lineOfSight(int fromX, int fromY, int toX, int toY){
  
