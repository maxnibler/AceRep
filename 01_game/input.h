#include <string>

extern bool active;

class Piece{
 private:
  int xCoor;
  int prevX;
  int yCoor;
  int prevY;
  char rep;
  std::string status;
  std::string name;
  void horMove(int dist);
  void verMove(int dist);
 public:
  void setLocation(int x, int y, char o, std::string n);
  std::string getStatus();
  char getChar();
  void inpMove(char dir);
  void enemyMove();
};

void playerMove(Piece* p);

void aiMove(Piece* p);

char getInput();

extern Piece player;
