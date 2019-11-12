#include <string>
#define HEIGHT 26
#define WIDTH 78

extern char location[WIDTH][HEIGHT];

void initLocation();

char getSymbol(int x, int y);

void setScreen();

void printMessage(std::string mess);

void refreshScreen();
