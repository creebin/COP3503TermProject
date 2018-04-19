#ifndef UI_H
#define UI_H

#include <vector>
#include <string>
using namespace std;

class BarGraph {
private:
	int fitScreen;
public:
	BarGraph();
	vector<int> ratioData(vector<int>, int);
	vector<int> cropData(vector<int>);
	void printGraph(vector<int>, vector<string>, vector<int>);
};

class UserInterface
{
public:
	void welcomeMenu(); //do they want to create a new budget or use an existing budget?
	void welcomeScreen();
	void closingScreen();
	void userMenu();
	//if choose sort->sorting menu in sorting
	//take in input
	void clearScreen();

};

class DataFormatting
{
private:
public:
	//what do they want printed -> function. Categories printed nearly? What's remaining in the budget as a 'battery' graph?
	void billReminder();
};

bool inputChecker(string);

#endif
