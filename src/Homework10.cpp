// Homework10.cpp 
// by Kexin Zheng
// simple role playing game

#include "pch.h"

#include "character.h"
#include "knight.h"
#include "novice.h"
#include "wizard.h"
#include "monster.h"

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std; 

//function prototypes
void createChar(vector<Character*>&);
void printStatus(vector<Character*>&); 
int start(vector<Character*>&);
void restoreHp(vector<Character*>&); 
bool fightEnemy(vector<Character*>&, Monster); 
bool fightBoss(vector<Character*>&);
int characterAttack(vector<Character*>&);
bool loss(vector<Character*>&);
int chooseChar(vector<Character*>&);
void randomItems(vector<Character*>&, Monster); 

int main()
{
	srand(time(0)); 
	//lists of characters
	vector<Character*> team;  
	//player choice
	int choice = 0; 

	cout << "Welcome to the simple role playing game! " << endl;
	cout << "You can build your own team and start a great adventure! " << endl << endl;

	//main menu
	while (choice != 4)
	{
		cout << "Main Menu" << endl; 
		cout << "1 - add a new character to the team" << endl;
		cout << "2 - check the team" << endl; 
		cout << "3 - START THE ADVENTURE!" << endl; 
		cout << "4 - quit" << endl; 
		//player choice
		cout << "Your choice: "; 
		cin >> choice; 
		cout << endl; 
		switch (choice)
		{
			//new character
		case 1: 
			createChar(team); 
			break; 
			//check team
		case 2: 
		{
			if (team.empty())
				cout << "No team member. " << endl; 
			else 
				printStatus(team);
			break;
		}
			//start game
		case 3:
		{
			choice = start(team); //whether or not to quit
			break;
		}
			//quit
		case 4: 
			cout << "Goodbye!" << endl;
			break; 
			//invalid choice
		default: 
			cout << "Pleaes enter a valid choice. " << endl; 
		}
		cout << endl; 
	}

	//free memory
	for (int i = 0; i < team.size(); i++)
	{
		delete team[i];
	}

	cout << "Enter any number to end the game."; 
	cin >> choice; 

	return 0; 
}

//function definitions

//create a new character
void createChar(vector<Character*>& list)
{
	if (list.size() == 3)
		cout << "Your team is full! " << endl; 
	else
	{
		char type;
		string n; //name
		string x; //store additional string data
		//ask for character type and other info
		cout << "Which type of character would you like to create? " << endl;
		cout << "Type in N for novice, K for knight, and any other letter for wizard: ";
		cin >> type;
		cin.ignore();
		cout << "Character name: ";
		getline(cin, n);
		//novice
		if (toupper(type) == 'N')
		{
			list.push_back(new Novice(n, 1));
		}
		//knight
		else if (toupper(type) == 'K')
		{
			cout << "Weapon name: ";
			getline(cin, x);
			list.push_back(new Knight(n, x, 2, 2));
		}
		//wizard
		else
		{
			cout << "Power source (a for arcane, any other letter for divine): ";
			cin >> type;
			//arcane
			if (toupper(type) == 'A')
			{
				list.push_back(new Wizard(n, "arcane", 2));
			}
			//divine
			else
			{
				list.push_back(new Wizard(n, "divine", 5));
			}
		}
		cout << endl << list[(list.size() - 1)]->getName() << " joined the team! " << endl;
	}
}

//check character status
void printStatus(vector<Character*>& list)
{
	for (int i = 0; i < list.size(); i++)
	{
		list[i]->print();
		cout << endl; 
	}
}

//start game
int start(vector<Character*>& list)
{
	//not enough member
	if (list.size() < 3)
	{
		cout << "You need 3 members in your team! " << endl;
		return 0; 
	}
	//ready to start
	else
	{
		//explanation/openning
		cout << "A team of adventurers traveled to a small yet wealthy kingdom " << endl;
		cout << "and accidentally discovered that an evil force near by is about to take over the kingdom and its resources" << endl; 
		cout << "so that the villains can eventually conquer the entire world! " << endl << endl; 
		cout << "And of course, the heroic adventurers would not allow this to happen. " << endl; 
		cout << "They decided to defeat the evil leader and eliminate any chance for him to gain power. " << endl << endl; 
		cout << "Now, it is your time to help the team to become stronger and destroy the enemies before they attack the kingdom!" << endl << endl; 
		bool run = true; //run loop
		int time = 15; //time limit
		int cho; //player choice
		//menu
		while (run)
		{
			//display time left
			cout << "You have " << time << " days left to take action before the enemies implement their plan. " << endl; 
			cout << "You can only do one thing each day (except for checking stats). " << endl; 
			cout << "What would you do today? " << endl << endl; 
			//choices
			cout << "1. Wandering around the enemies' territory" << endl; 
			cout << "2. Rest" << endl; 
			cout << "3. Check Character Stats" << endl; 
			cout << "4. Confront the Final Boss" << endl; 
			cout << "5. Quit" << endl; 
			cout << "Your choice: "; 
			cin >> cho; 
			cout << endl; 
			switch (cho)
			{
				//explore
			case 1: 
			{
				//list of monster
				Monster enemy[3] = { Monster("Troglodyte", 10, 2, 10), Monster("Orc Warrior", 15, 3, 15), Monster("Black Dragon", 20, 4, 20) };
				//randomly choose an enemy
				int e = rand() % 3;
				cout << "The team decided to wander around near the enemies's base in the forest to gain more information. " << endl; 
				cout << "Suddenly, an enemy seems to approach the team! " << endl; 
				//losing the battle (bad ending 1)
				if (fightEnemy(list, enemy[e]))
				{
					cout << endl << "Sadly, the adventurers didn't even make it to the final battle. " << endl;
					cout << "After all of them fainted, the adventurers were left in the forest alone until they die. " << endl;
					cout << "Now, there is no one to stop the evil force, and the poor adventurers will never be remembered. " << endl << endl;
					cout << "GAME OVER" << endl;
					run = false;
				}
				break;
			}
			//rest (heal)
			case 2: 
			{
				cout << "The team decided to take a break. " << endl; 
				cout << "Everyone's HP is restored to maximum! " << endl; 
				restoreHp(list); 
				break; 
			}
				//check stats
			case 3: 
			{
				printStatus(list); 
				time += 1; 
				break; 
			}
				//fight boss
			case 4: 
			{
				cout << "Now, it is the time to eliminate the evil force once and for all. " << endl; 
				cout << "The adventurers carefully and quietly enter the enemies' base and find the boss' room without disturbing the other enemies. " << endl;
				cout << "However, the evil leader already predicted their invasion and is fully prepared to strike them down. " << endl << endl; 
				cout << "An epic battle is about to begin. " << endl << endl; 
				//losing the final battle (bad ending 2)
				if (fightBoss(list))
				{
					cout << endl << "Unfortunately, the adventurers didn't win the final battle. " << endl;
					cout << "After all of them lost the ability to fight, the evil boss brutally ended their lives. " << endl;
					cout << "Now, there is no one to stop him, and the heroes' sacrifice will never be remembered. " << endl << endl; 
					cout << "GAME OVER" << endl; 
				}
				//win (happy ending)
				else
				{
					cout << endl << "After a long battle, the adventurers finally won. " << endl; 
					cout << "Now, the enemies are locked up in the dungeon, " << endl; 
					cout << "and those heroes who saved the world will be praised and remembered forever. " << endl << endl;
					cout << "THE END" << endl; 
				}
				run = false; 
				break; 
			}
				//quit
			case 5: 
			{
				cout << "You decided to quit the game. " << endl; 
				cout << "Now, no one will know the fate of the adventurers and the kingdom. " << endl << endl; 
				cout << "Goodbye! " << endl; 
				run = false; 
				break; 
			}
				//invalid choice
			default:
			{
				cout << "You didn't choose any of the valid choices. " << endl; 
				cout << "So, the team wasted 1 day doing random things instead. " << endl; 
			}
			}

			time -= 1; 
			//time up (bad ending 3)
			if (time == 0 && run == true)
			{
				cout << endl << "Now, it's too late." << endl << endl; 
				cout << "After 15 days, the evil force takes over the kingdom and enslaved everyone there. " << endl; 
				cout << "With the abundant resources, the enemies are now invincible. " << endl; 
				cout << "As time passes by, everyone's peaceful life will soon come to an end. " << endl << endl; 
				cout << "GAME OVER" << endl << endl;
				run = false; 
			}
			cout << endl; 
		}
		return 4; 
	}
}

//restore HP
void restoreHp(vector<Character*>& list)
{
	for (int i = 0; i < list.size(); i++)
	{
		list[i]->heal(); 
	}
}

//fight enemy
bool fightEnemy(vector<Character*>& list, Monster m)
{
	//attacked character
	int a; 
	//continue the fighting loop
	bool loop = true; 
	//player choice
	int ch; 
	cout << "The enemy is getting closer and closer. " << endl; 
	cout << "It is the " << m.getName() << "! " << endl << endl; 
	while (loop)
	{	
		//choices
		cout << "Enemy HP: " << m.getHp() << endl; 
		cout << "What would you do? " << endl << endl;
		cout << "1. fight" << endl; 
		cout << "2. flee" << endl;
		cout << "3. check character stats" << endl; 
		cout << "Your choice: ";
		cin >> ch; 
		cout << endl; 
		//select the character to attack
		a = chooseChar(list); 
		switch (ch)
		{
			//fight
		case 1: 
		{
			//fight
			m.updateHp(characterAttack(list));
			//the enemy lose
			if (m.getHp() < 1)
			{
				randomItems(list, m);
				return false;
			}
			//else, keep attack
			cout << endl << m.getName() << " attacks! " << endl << endl;
			list[a]->updataHp(m.getAc());
			//the team lose
			if (loss(list))
				return true;
			break;
		}
			//flee
		case 2: 
		{
			cout << "The team decided to run away while they can. " << endl; 
			cout << "Although they didn't gain anything from the battle, at least they are all alive. " << endl; 
			return false; 
		}
			break;
			//check character stats
		case 3: 
		{
			printStatus(list); 
		}
			break; 
			//invalid choice
		default: 
		{
			cout << "You didn't choose any of the valid choices. " << endl;
			cout << "So, the adventurers did nothing while the " << m.getName() << " attacks. " << endl << endl;
			list[a]->updataHp(m.getAc() * 2);
			//the team lose
			if (loss(list))
				return true;
		}
		}
		cout << endl; 
	}
}

//fight boss
bool fightBoss(vector<Character*>& list)
{
	Monster boss("The Stereotypical Boss", 30, 20, 350);
	int a; //attacked character
	//continue the fighting loop
	bool loop = true;
	//player choice
	int ch;
	cout << boss.getName() << " is ready to attack! " << endl; 
	cout << "There is no running away now. " << endl << endl; 
	while (loop)
	{
		//choices
		cout << "Boss HP: " << boss.getHp() << endl;
		cout << "What would you do? " << endl << endl;
		cout << "1. fight" << endl;
		cout << "2. check character stats" << endl;
		cout << "Your choice: ";
		cin >> ch;
		cout << endl; 
		//select the character to attack
		a = chooseChar(list);
		switch (ch)
		{
			//fight
		case 1:
			//fight
			boss.updateHp(characterAttack(list));
			//the enemy lose
			if (boss.getHp() < 1)
				return false;
			//random special attack (more likely to occur when boss HP is low)
			if (rand() % (boss.getHp() / 4) == 0)
			{
				cout << endl << boss.getName() << " laughs wickedly and uses a special attack! " << endl << endl;
				list[a]->updataHp(boss.getAc() + 10);
			}
			//normal attack
			else
			{
				cout << endl << boss.getName() << " laughs wickedly and attacks! " << endl << endl;
				list[a]->updataHp(boss.getAc());
			}
			//the team lose
			if (loss(list))
				return true;
			break;
		//check character stats
		case 2:
		{
			printStatus(list);
		}
		break;
		//invalid choice
		default:
		{
			cout << "You didn't choose any of the valid choices. " << endl;
			cout << "So, the adventurers did nothing while " << boss.getName() << " attacks. " << endl << endl;
			list[a]->updataHp(boss.getAc() * 3);
			//the team lose
			if (loss(list))
				return true;
		}
		}
		cout << endl;
	}
}

//characters' attack
int characterAttack(vector<Character*>& list)
{
	//total damage
	int total = 0; 
	//add all character's damage
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->getHp() > 0)
		{
			total = list[i]->getAttack(); 
		}
	}
	cout << endl; 
	return total; 
}

//check if all character have 0 hp
bool loss(vector<Character*>& list)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->getHp() > 0)
		{
			return false; 
		}
	}
	return true; 
}

//choose the character with the lowest hp to attack
int chooseChar(vector<Character*>& list)
{
	//store smallest and comparing values
	int smallest = 0; 
	int compare = 0; 
	//for each hp
	for (int i = 0; i < list.size(); i++)
	{
		//hp must > 0
		if (list[i]->getHp() > 0)
		{
			//first valid hp/smaller hp comparing to the previous smallest
			if (compare == 0 || list[i]->getHp() < compare)
			{
				//update
				smallest = i;
				compare = list[i]->getHp(); 
			}
		}
	}
	return smallest; 
}

//won battle and having chances of receive item after battle
void randomItems(vector<Character*>& list, Monster m)
{
	cout << endl << "You won! " << endl << endl; 
	int exp = 5; 
	//chance of getting xp potion
	if (rand() % 3 == 0)
	{
		cout << "The team got an experience potion from the enemy. " << endl;
		cout << "Everyone gains double XP! " << endl << endl;
		exp *= 2;
	}
	//chance of getting healing potion
	else if (rand() % 2 == 0)
	{
		cout << "The team got a healing potion from the enemy. " << endl; 
		cout << "Everyone's HP is restored to maximum! " << endl << endl; 
		restoreHp(list); 
	}
	//update xp
	for (int i = 0; i < list.size(); i++)
	{
		list[i]->updateXp(m.getLevel() * exp); 
	}
}