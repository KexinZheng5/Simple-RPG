#include "pch.h"

#include "character.h"

#include <iostream>
using namespace std; 

//constructors
Character::Character()
{
	name = "none";
	hp = 0; 
	xp = 0;
	level = 1; 
	nextLv = 10; 
	maxHp = 0; 
}

Character::Character(string NAME, int HP, int MHP)
{
	name = NAME; 
	hp = HP; 
	maxHp = MHP; 
	xp = 0;
	level = 1;
	nextLv = 10;
}

//set functions
void Character::setName(string n)
{
	name = n; 
}

void Character::setHp(int h)
{
	hp = h; 
}

void Character::setXp(int x)
{
	xp = x; 
}

void Character::setLevel(int l)
{
	level = l;
}

void Character::setNextLv(int next)
{
	nextLv = next; 
}

void Character::setMaxHp(int mx)
{
	maxHp = mx; 
}

//gain hp
void Character::heal()
{
	hp = maxHp; 
}