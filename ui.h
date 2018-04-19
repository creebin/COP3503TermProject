#ifndef UI_H
#define UI_H

#include <vector>
#include <string>
using namespace std;

//the class for graphing data received from other parts of the program
class BarGraph {
private:
	int fitScreen;
public:
	BarGraph();
	vector<int> ratioData(vector<int>, int);
	vector<int> cropData(vector<int>);
	void printGraph(vector<int>, vector<string>, vector<int>);
};

//the class responsible for the displays the user is greeted with
class UserInterface
{
public:
	void welcomeScreen();
	void closingScreen();
	void clearScreen();
};

//the class responsible for printing the data from other parts of the program
class DataFormatting
{
public:
	void billReminder();
};

#endif
