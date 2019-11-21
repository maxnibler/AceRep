#include <string>

extern bool active;

class Piece{
 private:
  int          xCoor;
  int          yCoor;
  int          speed;
  int          toX;
  int          toY;
  int          dmg;
  char         rep;
  std::string  status;
  std::string  name;
 public:
  //Set Values
  void         setLocation(int x, int y, char o, std::string n);
  void         moveTowards(int x, int y);
  //Get Values
  std::string  getStatus();
  char         getChar();
  std::string  getName();
  int          getX();
  int          getY();
  int          absDist(Piece* p);
  int          pieceUp(int y);
  int          pieceLeft(int x);
  //Commands
  void         inpMove(char dir);
  void         moveUp();
  void         moveDown();
  void         moveLeft();
  void         moveRight();
  void         moveRU();
  void         moveLU();
  void         moveLD();
  void         moveRD();
  void         wait();
  void         attack(Piece* p);
  void         attackDir();
  void         enemyMove();
};

//bool lineSight(int fX, int fY, int tX, int tY);

void playerMove(Piece* p);

void aiMove(Piece* p);

//int dirOrder(int dir, int ind);

//int findPath(int fromX, int fromY, int toX, int toY);

extern Piece player;
extern Piece enemy;
