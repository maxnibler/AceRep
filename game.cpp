#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include "hashtable.h"
using namespace std;

int superSeed;

class Stats {
  public:
  Stats (int);
  int statArr[15];
  int inventory[10];
  int* healthCurr = &statArr[0];
  int* healthMax = &statArr[1];
  int* stamCurr = &statArr[2];
  int* stamMax = &statArr[3];
  int* manaCurr = &statArr[4];
  int* manaMax = &statArr[5];
  int* con = &statArr[6];
  int* dex = &statArr[7];
  int* str = &statArr[8];
  int* intl = &statArr[9];
  int* wis = &statArr[10];
  int* cha = &statArr[11];
  int* luck = &statArr[12];
  int* ac = &statArr[13];
  int* level = &statArr[14];
  bool alive;

  int statInc(int stat){statArr[stat]++; return statArr[stat];}
  int statDec(int stat){statArr[stat]--; return statArr[stat];}
};

class Weapon {
public:
  Weapon();
  int damage;
  int statSyn;
  string damageType;
  string name;
  int trait;
  int cost;
  int rarity;
};

class Armor {
public:
  Armor();
  int armorRate;
  int statSyn;
  string name;
  int trait;
};

int roll(int max){
  int ret = rand() % max + 1;
  return ret;
}

int roll(int min, int max){
  int ret = rand() % (max - min + 1) + min;
  return ret;
}

bool saveThrow(int stat, int comp){
  int mod = (stat - 10) / 2;
  int die = roll(20);
  cout << mod << " " << die << "\n";
  return die + mod >= comp;
}

int statSheet(Stats prof){
  printf("Health: %d/%d\n", *prof.healthCurr, *prof.healthMax);
  printf("Stamina: %d/%d\n", *prof.stamCurr, *prof.stamMax);
  printf("Mana: %d/%d\n", *prof.manaCurr, *prof.manaMax);
  printf("Charisma: %d\n", *prof.cha);
  printf("Dexterity: %d\n", *prof.dex);
  printf("Luck: %d\n", *prof.luck);
  printf("Strength: %d\n", *prof.str);
  printf("Constitution: %d\n", *prof.con);
  printf("Intelligence: %d\n", *prof.intl);
  printf("Wisdom: %d\n", *prof.wis);
  printf("AC: %d\n", *prof.ac);
 return 0;
}

Stats::Stats(int a){
  statArr[0] = roll(100); //Max Health
  statArr[1] = statArr[0]; //Current Health
  statArr[2] = roll(100); //Max Stamina
  statArr[3] = statArr[2]; //Current Stamina
  statArr[4] = roll(100); //Max Mana
  statArr[5] = statArr[4]; //Current Mana 
  statArr[6] = roll(5,9); //Constitution
  statArr[7] = roll(5,9); //Dexterity
  statArr[8] = roll(5,9); //Strength
  statArr[9] = roll(5,9); //Intelligence
  statArr[10] = roll(5,9); //Wisdom
  statArr[11] = roll(5,9); //Charisma
  statArr[12] = roll(5,9); //Luck
  statArr[13] = 10; //Armor
  statArr[14] = 1;
  alive = true;  
}


int main(){
  string inp, line;
  int numb, wat;
  int *nani;
  cout << "Pick a number\n";
  getline(cin, inp);
  stringstream(inp) >> superSeed;
  srand(superSeed);
  Stats player(10);
  statSheet(player);
  ifstream weaponFile;
  weaponFile.open("Weapons.txt", ios::in);
  while(getline(weaponFile, line)){
    cout << line << "\n";}
  weaponFile.close();
}
