#pragma once

#include <string>
using namespace std; 

//character class (base class) 

class Character
{
protected: 
	string name; 
	int hp; 
	int xp; 
	int level; 
	int nextLv;
	int maxHp;

public: 
	//constructors
	Character(); 
	Character(string, int, int); 
	//set functions
	void setName(string); 
	void setHp(int); 
	void setXp(int); 
	void setLevel(int); 
	void setNextLv(int); 
	void setMaxHp(int); 
	//get functions
	string getName() { return name; }
	int getHp() { return hp; }
	int getXp() { return xp; }
	int getLevel() { return level; }
	int getNextLv() { return nextLv; }
	int getMaxHp() { return maxHp; }
	//others
	virtual void print() = 0; 
	virtual int getAttack() = 0; 
	virtual void updateXp(int) = 0; 
	virtual void updataHp(int) = 0; 
	void heal(); 
};