#include <string>

extern bool active;

class Piece{
 private:
  int xCoor;
  int yCoor;
  int speed;
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
  int pieceUp(int y);
  int pieceLeft(int x);
  void wait();
};

void playerMove(Piece* p);

void aiMove(Piece* p);

char getInput();

char getInp();

char getDir();

extern Piece player;
extern Piece enemy;
