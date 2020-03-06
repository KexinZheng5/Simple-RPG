#include "pch.h"

#include "knight.h"

#include <iostream>
#include <iomanip>
using namespace std;

//Constructors
Knight::Knight()
{
	wName = "none";
	wPower = 0;
	armor = 1;
}

Knight::Knight(string n, string w, int p, int a) : Character(n, 120, 120)
{
	wName = w; 
	wPower = p; 
	armor = a; 
}

//set functions
void Knight::setWName(string n)
{
	wName = n; 
}

void Knight::setWPower(int p)
{
	wPower = p; 
}

void Knight::setArmor(int a)
{
	armor = a; 
}
//others

//print knight info
void Knight::print()
{
	cout << "Name: " << setw(20) << left << name << "Weapon name: " << wName << endl; 
	cout << setw(26) << left << "Type: Knight" << "Weapon power: " << wPower << endl; 
	cout << "Level: " << setw(19) << left << level << "Armor: " << armor << endl;
	cout << "HP: " << hp << "/" << maxHp << endl;
}

//attack
int Knight::getAttack()
{
	cout << name << " attacks with the powerful " << wName << "! " << endl; 
	return 10 + rand() % 11 + wPower; 
}

//add experience
void Knight::updateXp(int gain)
{
	xp += (gain - 1);
	cout << name << " gained " << (gain - 1) << " experience points! " << endl;
	while (xp >= nextLv)
	{
		//update status
		level += 1;
		xp -= nextLv;
		nextLv += 15;
		maxHp += 15;
		armor += 1; 
		wPower += 1; 
		cout << name << " leveled up and is now level " << level << "! " << endl;
	}
}

//reduce hp
void Knight::updataHp(int damage)
{
	hp -= (damage - armor);
	cout << name << " experiences " << damage << " points of damage! " << endl;
	if (hp < 1)
	{
		hp = 0;
		cout << name << " faints! " << endl;
	}
	else if (hp < 20)
		cout << name << " is feeling uncomfortable due to low HP. " << endl;
}
