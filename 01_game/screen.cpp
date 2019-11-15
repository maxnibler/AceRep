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
  player.setLocation(30, 10, 'O', "Player");
  enemy.setLocation(10, 10, 'X', "Enemy");
  moveTo(30, 10, 'O');
  moveTo(10,10,'X');
}

void initLocation(){
  for (int i = 0; i < WIDTH; i++){
    for (int j = 0; j < HEIGHT; j++){
      if (i == 0 || i == WIDTH - 1){
	location[i][j].setBase('#');
      }else if (j == 1 || j == HEIGHT - 1){
	location[i][j].setBase('#');
      }else{
	location[i][j].setBase('-');
      }
    }
  }
}

char getSymbol(int x, int y){
  return location[x][y].pop();
}

char lookSym(int x, int y){
  return location[x][y].peek();
}

void setScreen(){
  move(0,0);
  for (int i = 1; i < HEIGHT; i++){
    for (int j = 0; j < WIDTH; j++){
      move(i,j);
      addch(lookSym(j,i));
    }
  }
  refresh();
}

void clearMessage(){
  mvprintw(0,1, "");
  for (int i = 0; i < WIDTH-2; i++){
    printw(" ");
  }
}

void printMessage(string mess){
  clearMessage();
  mvprintw(0,1, "%s", mess.c_str());
}

void refreshScreen(){
  aiMove(&enemy);
  playerMove(&player);
  setScreen();
  printMessage(player.getStatus());
}



