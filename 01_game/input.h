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
  void         setLocation(int x, int y, char o);
  void         setStats(int s, int d, std::string n);
  void         moveTowards(int x, int y);
  //Get Values
  std::string  getStatus();
  std::string  getName();
  char         getChar();
  int          getX();
  int          getY();
  int          absDist(Piece* p);
  int          pieceUp(int y);
  int          pieceLeft(int x);
  //Commands
  void         inpMove(char dir);
  void         moveDir(int dir);
  void         wait();
  void         attack(Piece* p);
  void         attackDir();
  void         enemyMove();
};

void playerTurn(Piece* p);

void aiTurn(Piece* p);

extern Piece player;
extern Piece enemy;
