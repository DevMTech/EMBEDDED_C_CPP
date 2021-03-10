#include<iostream>
//#include<cstddef> // NULL
using namespace std;

struct Players
{
	int skill;
	string name;
};

Players getNewPlayer()
{
	struct Players newPlayer;
	newPlayer.name = "DummyName";
	newPlayer.skill = NULL;
	
	return newPlayer;
}

Players setNameSkill(Players p)
{
	p.name = "Sachin";
	p.skill = 15;
	return p;
}

int main()
{
	struct Players pArr[5];
	
	int i = 2;
	
	pArr[i].name = "Dravid";
	pArr[i].skill = 10;
	
	cout<< pArr[i].name << " " << pArr[i].skill;
	

	Players p1 = getNewPlayer();
	
	cout<< "\n" << p1.name << " " << p1.skill; 
	
	p1 = setNameSkill(p1);
	
	cout<< "\n" << p1.name << " " << p1.skill; 
	
}
