#pragma once

#include "character.h"

#include <string>
using namespace std;

//knight class

class Knight : public Character
{
private: 
	string wName;
	int wPower; 
	int armor; 
public: 
	//Constructors
	Knight(); 
	Knight(string, string, int, int); //name, weapon name, weapon power, and armor
	//set functions
	void setWName(string);
	void setWPower(int);
	void setArmor(int);
	//get functions
	string getWName() { return wName; }
	int getWPower() { return wPower; }
	int getArmor() { return armor; }
	//others
	void print();
	int getAttack();
	void updateXp(int); 
	void updataHp(int);
};