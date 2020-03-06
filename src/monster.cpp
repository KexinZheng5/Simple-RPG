#include "pch.h"

#include "monster.h"

//constructor
Monster::Monster()
{
	name = "none";
	ac = level = hp = 0; 
}
Monster::Monster(string n, int a, int l, int h) 
{
	name = n;
	ac = a; 
	level = l; 
	hp = h; 
}

//set functions
void Monster::setName(string n)
{
	name = n;
}
void Monster::setAc(int a)
{
	ac = a;
}
void Monster::setLevel(int l)
{
	level = l;
}
void Monster::setHp(int h)
{
	hp = h;
}

//update hp
void Monster::updateHp(int damage)
{
	hp -= damage;
	cout << name << " experiences " << damage << " points of damage! " << endl;
	if (hp < 1)
	{
		cout << name << " is defeated! " << endl;
	}
}