#include "pch.h"

#include "wizard.h"

#include <iostream>
#include <iomanip>
using namespace std;

Wizard::Wizard()
{
	pSource = "none"; 
	magic = 0; 
}

Wizard::Wizard(string n, string s, int m) : Character(n, 100, 100)
{
	pSource = s; 
	magic = m; 
}

//set functions
void Wizard::setSource(string s)
{
	pSource = s;
}

void Wizard::setMagic(int m)
{
	magic = m;
}

//others

//print wizard info
void Wizard::print()
{
	cout << "Name: " << setw(20) << left << name << "Power source: " << pSource << endl;
	cout << setw(26) << left << "Type: Wizard" << "Magic: " << magic << endl;
	cout << "Level: " << level << endl;
	cout << "HP: " << hp << "/" << maxHp << endl;
}

//attack
int Wizard::getAttack()
{
	cout << name << " attacks using the mysterious " << pSource << " magic! " << endl;
	return 10 + rand() % 11 + magic;

}

//add experience
void Wizard::updateXp(int gain)
{
	xp += (gain - 2);
	cout << name << " gained " << (gain - 2) << " experience points! " << endl;
	while (xp >= nextLv)
	{
		//update status
		level += 1;
		xp -= nextLv;
		nextLv += 12;
		maxHp += 8;
		magic += 3;
		cout << name << " leveled up and is now level " << level << "! " << endl;
	}
}

//update hp
void Wizard::updataHp(int damage)
{
	hp -= (damage - (magic / (damage)));
	cout << name << " experiences " << damage << " points of damage! " << endl;
	if (hp < 1)
	{
		hp = 0;
		cout << name << " faints! " << endl;
	}
	else if (hp < 20)
		cout << name << " is backing off from the enemy due to low HP. " << endl;
}
