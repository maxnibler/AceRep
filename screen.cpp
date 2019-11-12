//Maximillian H Nibler
//max.nibler@gmail.com
//https://github.com/maxnibler/

#include <string>
#include <iostream>
#include "screen.h"
#include <curses.h>
#define HEIGHT 20
#define WIDTH 60
using namespace std;

char location[WIDTH][HEIGHT];

void initLocation(){
  for (int i = 0; i < WIDTH; i++){
    for (int j = 0; j < HEIGHT; j++){
      location [i][j] = '-';
    }
  }
}

char getSymbol(int x, int y){
  return location[x][y];
}

void setScreen(){
  initscr();
  timeout(-1);
  for (int i = 0; i < HEIGHT; i++){
    for (int j = 0; j < WIDTH; j++){
      if (i == 0 || i == HEIGHT - 1){
	cout << '#';
      }else if (j == 0 || j == WIDTH - 1){
	cout << '#';
      }else{
	cout << getSymbol(j, i);
      }
    }
    cout << endl;
  }
}

