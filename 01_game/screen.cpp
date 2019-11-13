//Maximillian H Nibler
//max.nibler@gmail.com
//https://github.com/maxnibler/

#include <iostream>
#include <ncurses.h>
#include "screen.h"
#include "input.h"

using namespace std;

charStack location[WIDTH][HEIGHT];
//charStack test[5];
Piece player;
Piece enemy;

void initLocation(){
  initscr();
  for (int i = 0; i < WIDTH; i++){
    for (int j = 0; j < HEIGHT; j++){
      if (i == 0 || i == WIDTH - 1){
	location[i][j].push('#');
      }else if (j == 1 || j == HEIGHT - 1){
	location[i][j].push('#');
      }else{
	//location[i][j] = '-';// charStack
      }
      player.setLocation(30, 10, 'O', "Player");
      enemy.setLocation(10, 10, 'X', "Enemy");
    }
  }
  refresh();
}

char getSymbol(int x, int y){
  return location[x][y].peek();
}

void setScreen(){
  for (int i = 1; i < HEIGHT; i++){
    for (int j = 0; j < WIDTH; j++){
      mvprintw(i,j, "%c", getSymbol(j,i));
    }
  }
  mvprintw(0,0, "[");
  mvprintw(0,WIDTH-1, "]");
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
  //printMessage(player.getStatus());
  refresh();
}



