#include <string>
#include "charStack.h"
#define HEIGHT 26
#define WIDTH 78

extern charStack location[WIDTH][HEIGHT];
//extern charStack test[5][5];

void initLocation();

char getSymbol(int x, int y);

void setScreen();

void printMessage(std::string mess);

void refreshScreen();
