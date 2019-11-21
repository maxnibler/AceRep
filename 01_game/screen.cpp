//Maximillian H Nibler
//max.nibler@gmail.com
//https://github.com/maxnibler/

#include <iostream>
#include <ncurses.h>
#include "screen.h"
#include "input.h"

using namespace std;

charStack location[WIDTH][HEIGHT];

Piece player;
Piece enemy;

void from_to(int xInit, int yInit, int xDest, int yDest){
  if (logging){
    string logs;
    logs = "  <"+to_string(xInit)+", "+to_string(yInit)+"> to <"
      +to_string(xDest)+", "+to_string(yDest)+">\n";
    logString(logs);
  }
  char temp = getSymbol(xInit, yInit);
  moveTo(xDest, yDest, temp);
}

void moveTo(int x, int y, char rep){
  location[x][y].push(rep);
}

void initPieces(){
  player.setLocation(40, 15, '@');
  player.setStats(1,1,"Player");
  enemy.setLocation(10, 10, 'G');
  enemy.setStats(1,1,"Goblin");
  enemy.moveTowards(11,11);
  moveTo(40, 15, '@');
  moveTo(10,10,'G');
}

void initLocation(){
  for (int i = 0; i < WIDTH; i++){
    for (int j = 0; j < HEIGHT; j++){
      if (i == 0 || i == WIDTH - 1){
	location[i][j].setBase('#');
      }else if (j == 0 || j == HEIGHT - 1){
	location[i][j].setBase('#');
      }else{
	location[i][j].setBase(' ');
      }
    }
  }
  makeRoom(35,10,45,20);
  makeRoom(5,5,15,15);
  makePath(10,15,10,18);
  makePath(10,18,35,18);
}

int makeWall(bool vert, int x, int y, int len){
  if (x < 0 || y < 0) return -1;
  if (vert){
    if (y+len > HEIGHT) return -1;
    for (int i = 0; i < len; i++){
      location[x][y+i].setBase('|');
    }
  }else{
    if (x+len > WIDTH) return -1;
    for (int i = 0; i < len; i++){
      location[x+i][y].setBase('-');
    }
  }
  return 0;
}    

int makeRoom(int x1, int y1, int x2, int y2){
  makeWall(1,x1,y1+1,y2-y1);
  makeWall(0,x1,y1,x2-x1+1);
  makeWall(1,x2,y1+1,y2-y1);
  makeWall(0,x1,y2,x2-x1+1);
  for (int i = x1+1; i < x2; i++){
    for (int j = y1+1; j < y2; j++){
      location[i][j].setBase('.');
    }
  }
  return 0;
}

int makePath(int x1, int y1, int x2, int y2){
  if (x1 != x2 && y1 != y2) return -1;
  else if (x1 != x2){
    for (int i = 0; i <= (x2-x1); i++){
      location[x1+i][y1].setBase('.');
    }
  }else{
    for (int i = 0; i <= (y2-y1); i++){
      location[x1][y1+i].setBase('.');
    }
  }
  return 0;
}

char getSymbol(int x, int y){
  return location[x][y].pop();
}

char lookSym(int x, int y){
  return location[x][y].peek();
}

void setScreen(){
  move(0,0);
  for (int i = 0; i < HEIGHT; i++){
    for (int j = 0; j < WIDTH; j++){
      move(i+2,j);
      addch(lookSym(j,i));
    }
  }
  refresh();
}

void clearMessage(int row){
  mvprintw(row,0, "");
  for (int i = 0; i < WIDTH-2; i++){
    printw(" ");
  }
}

void printMessage(int row, string mess){
  clearMessage(row);
  mvprintw(row, 1, "%s", mess.c_str());
}

void refreshScreen(){
  aiTurn(&enemy);
  playerTurn(&player);
  printMessage(0, enemy.getStatus());
  printMessage(1, player.getStatus());
  setScreen();
}






