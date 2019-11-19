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
  char temp = getSymbol(xInit, yInit);
  moveTo(xDest, yDest, temp);
}

void moveTo(int x, int y, char rep){
  location[x][y].push(rep);
}

void initPieces(){
  player.setLocation(30, 10, '@', "Player");
  enemy.setLocation(10, 10, 'G', "Goblin");
  moveTo(30, 10, '@');
  moveTo(10,10,'G');
}

void initLocation(){
  for (int i = 0; i < WIDTH; i++){
    for (int j = 0; j < HEIGHT; j++){
      if (i == 0 || i == WIDTH - 1){
	location[i][j].setBase(' ');
      }else if (j == 1 || j == HEIGHT - 1){
	location[i][j].setBase(' ');
      }else{
	location[i][j].setBase('.');
      }
    }
  }
  makeWall(true,40,5,6);
  makeWall(true,WIDTH-1,0,HEIGHT);
  makeWall(false,0,HEIGHT-1,WIDTH);
  makeWall(false,0,2,WIDTH);
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

char getSymbol(int x, int y){
  return location[x][y].pop();
}

char lookSym(int x, int y){
  return location[x][y].peek();
}

void setScreen(){
  move(0,0);
  for (int i = 2; i < HEIGHT; i++){
    for (int j = 0; j < WIDTH; j++){
      move(i,j);
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
  aiMove(&enemy);
  playerMove(&player);
  printMessage(0, enemy.getStatus());
  printMessage(1, player.getStatus());
  setScreen();
}
