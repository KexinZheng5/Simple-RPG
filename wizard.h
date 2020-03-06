#pragma once

#include "character.h"

#include <string>
using namespace std; 

//wizard class

class Wizard : public Character
{
private: 
	string pSource; 
	int magic; 
public: 
	Wizard();
	Wizard(string, string, int); //name, power source, and magic
	//set functions
	void setSource(string);
	void setMagic(int);
	//get functions
	string getSource() { return pSource; }
	int getMagic() { return magic; }
	//others
	void print();
	int getAttack();
	void updateXp(int);
	void updataHp(int);
};