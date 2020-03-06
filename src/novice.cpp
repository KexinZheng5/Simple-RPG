#include "pch.h"

#include "novice.h"

#include <iostream>
#include <iomanip>
using namespace std;


//Constructors
Novice::Novice()
{
	luck = 1; 
}
Novice::Novice(string n, int l) : Character(n, 80, 80)
{
	luck = l; 
}

//set functions
void Novice::setLuck(int l)
{
	luck = l;
}

//others

//print novice info
void Novice::print()
{
	cout << "Name: " << setw(20) << left << name << "Luck: " << luck << endl;
	cout << "Type: Novice" << endl;
	cout << "Level: " << level << endl;
	cout << "HP: " << hp << "/" << maxHp << endl;
}

//attack
int Novice::getAttack()
{
	cout << name << " attacks randomly! " << endl;
	return 1 + rand() % 10 + luck;
}

//update xp
void Novice::updateXp(int gain)
{
	xp += gain;
	cout << name << " gained " << gain << " experience points! " << endl;
	while (xp >= nextLv)
	{
		//update status
		level += 1;
		xp -= nextLv;
		nextLv += 10;
		maxHp += 10;
		luck += (3 + rand() % 3);
		cout << name << " leveled up and is now level " << level << "! " << endl;
	}
}

//reduce hp
void Novice::updataHp(int damage)
{
	hp -= damage;
	cout << name << " experiences " << damage << " points of damage! " << endl;
	if (hp < 1)
	{
		hp = 0;
		cout << name << " faints! " << endl;
	}
	else if (hp < 20)
		cout << name << " is shivering and trying to escape due to low HP. " << endl;
}
