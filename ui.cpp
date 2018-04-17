// ui.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>

//ui/formatting stuff
#include <iostream>
using namespace std;

class Graphs
{
private:
	vector<string> categoryNames;
	vector<int> moneyAmount;

public:
	void ratioData(vector<int>);//what inputs, and should it output a vector or smth? should it be completely fleshed out up here since won't change?
	void cropData(vector<int>);//should be completely fleshed out up here?
	void printGraph();
};

void Graphs::ratioData(vector<int> money) {

}

void Graphs::cropData(vector<int> money) {

}

class BarGraph : public Graphs 
{
public:
	void printGraph() 
	{
	}
};

class PieGraph : public Graphs 
{
public:
	void printGraph() 
	{

	}
};

class UserInterface
{
public:
	void welcomeMenu(); //do they want to create a new budget or use an existing budget?
	void closingScreen();
	void userMenu();
	//if choose sort->sorting menu in sorting
	//take in input
	void clearScreen();

};

void UserInterface::welcomeMenu() {

}

void UserInterface::closingScreen() {

}

void UserInterface::userMenu() {

}

void UserInterface::clearScreen() {

}

class DataFormatting
{
private:
	string cat1;
public:
	//what do they want printed -> function. Categories printed nearly? What's remaining in the budget as a 'battery' graph?
	void billReminder();
};

void DataFormatting::billReminder() {

}

int main()
{
    return 0;
}
