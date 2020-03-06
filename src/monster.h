#pragma once

#include <string>
#include <iostream>
using namespace std; 

//monster class

class Monster
{
private: 
	string name; 
	int ac; 
	int level; 
	int hp; 
public: 
	//Constructors
	Monster(); 
	Monster(string, int, int, int); //name, ac, level, hp
	//set functions
	void setName(string);
	void setAc(int);
	void setLevel(int);
	void setHp(int);
	//get functions
	string getName() { return name; }
	int getAc() { return ac; }
	int getLevel() { return level; }
	int getHp() { return hp; }
	//others
	void updateHp(int); 
};