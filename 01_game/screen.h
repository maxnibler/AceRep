#include <string>
#include "charStack.h"
#define HEIGHT 26
#define WIDTH 78

extern charStack location[WIDTH][HEIGHT];
//extern charStack test[5][5];

void from_to(int xInit, int yInit, int xDest, int yDest);

void moveTo(int x, int y, char rep);

void initLocation();

char getSymbol(int x, int y);

char lookSym(int x, int y);

int makeWall(bool vert, int x, int y, int len);

void clearMessage(int row);

void initPieces();

void setScreen();

void printMessage(std::string mess);

void refreshScreen();
