#pragma once

#include "character.h"

//novice class

class Novice : public Character
{
private: 
	int luck; 
public: 
	//Constructors
	Novice();
	Novice(string, int); //name and luck
	//set functions
	void setLuck(int);
	//get functions
	int getLuck() { return luck; }
	//others
	void print();
	int getAttack();
	void updateXp(int);
	void updataHp(int);
};