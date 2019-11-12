//Maximillian H Nibler
//max.nibler@gmail.com
//https://github.com/maxnibler/

#include <string>
#include <iostream>
#include <ncurses.h>
#include "screen.h"
#include "input.h"
#define HEIGHT 20
#define WIDTH 60
using namespace std;

char location[WIDTH][HEIGHT];

Piece player;

void initLocation(){
  for (int i = 0; i < WIDTH; i++){
    for (int j = 0; j < HEIGHT; j++){
       if (i == 0 || i == WIDTH - 1){
	location[i][j] = '#';
      }else if (j == 0 || j == HEIGHT - 1){
        location[i][j] = '#';
      }else{
	location[i][j] = '-';
      }
      player.setLocation(30, 10, 'O');
      mvprintw(player.getX(), player.getY(), "%c", player.getChar());
    }
  }
  refresh();
}

char getSymbol(int x, int y){
  return location[x][y];
}

void setScreen(){
  for (int i = 0; i < HEIGHT; i++){
    for (int j = 0; j < WIDTH; j++){
      mvprintw(i,j, "%c", getSymbol(j,i));
    }
  }
}

void refreshScreen(){
  player.move();
  mvprintw(player.getY(), player.getX(), "%c", player.getChar());
  refresh();
}

