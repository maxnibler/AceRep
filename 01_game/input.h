#include <string>

extern bool active;

class Piece{
 private:
  int xCoor;
  int yCoor;
  int speed;
  int toX;
  int toY;
  int dmg;
  char rep;
  std::string status;
  std::string name;
 public:
  void setLocation(int x, int y, char o, std::string n);
  std::string getStatus();
  char getChar();
  std::string getName();
  void inpMove(char dir);
  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();
  void moveRU();
  void moveLU();
  void moveLD();
  void moveRD();
  void attack(Piece* p);
  void attackDir();
  int absDist(Piece* p);
  void enemyMove();
  int getX();
  int getY();
  int pieceUp(int y);
  int pieceLeft(int x);
  void wait();
  void moveTowards(int x, int y);
};

bool lineSight(int fX, int fY, int tX, int tY);

void playerMove(Piece* p);

void aiMove(Piece* p);

char getInput();

char getInp();

char getDir();

int dirOrder(int dir, int ind);
void printpath();
int findPath(int fromX, int fromY, int toX, int toY);

extern Piece player;
extern Piece enemy;
