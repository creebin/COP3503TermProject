#include"ui.h"
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
	int totalBudget;
	const int fitScreen = 2;

public:
	vector<int> ratioData(vector<int>,int);//what inputs, and should it output a vector or smth? should it be completely fleshed out up here since won't change?
	vector<int> cropData(vector<int>);//should be completely fleshed out up here?
	void printGraph(vector<int>, vector<string>);
};

vector<int> Graphs::ratioData(vector<int> money, int budget) {
	vector<int> newMoney;
	int listLength = money.size();
	for (int i = 0; i < listLength; i++) {
		double moneyRatio = money[i];
		moneyRatio = (moneyRatio / budget) * 100;
		if ((moneyRatio + .5) >= (int(moneyRatio) + 1)) {
			moneyRatio = int(moneyRatio) + 1; //HOW TO PREVENT THE WARNING TODO
			newMoney.push_back(moneyRatio);
		}
		else {
			moneyRatio = int(moneyRatio); //HOW TO PREVENT THE WARNING TODO
			newMoney.push_back(moneyRatio);
		}
	}
	return newMoney;
}

vector<int> Graphs::cropData(vector<int> money) {
	int listLength = money.size();
	for (int i = 0; i < listLength; i++) {
		money[i] = money[i] / fitScreen;
	}
	return money;
}

class BarGraph : public Graphs 
{
public:
	void printGraph(vector<int> money,vector<string> category, vector<int> moneyOriginal) 
	{
		int listLengthCat = category.size();
		int listLengthMon = money.size();
		const int maxBarLength = 50;

		for (int i = 0; i < 100; i++) {
			cout << "-";
		}

		cout << endl;

		for (int i = 0; i < listLengthCat; i++) {
			string currentCat = category[i];
			int moneyAmount = money[i];
			int counter = 0;
			while (counter < moneyAmount) {
				cout << "|";
				counter++;

				if (counter == (moneyAmount - 1)) {
					cout << " " << moneyOriginal[i];
					
					
					int digits = 0;
					int moneyCopy = moneyOriginal[i];

					while (moneyCopy != 0) {
						moneyCopy = moneyCopy / 10;
						digits++;
					}

					for (int i = 0; i < digits; i++) {
						counter++;
					}
				}
			}

			if (counter < maxBarLength) {
				for (int i = 0; i < (maxBarLength - counter); i++) {
					cout << " ";
				}
				cout << " " << currentCat << endl;
			}
			else {
				cout << " " << currentCat << endl;
			}
		}

		for (int i = 0; i < 100; i++) {
			cout << "-";
		}

		cout << endl;

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

void UserInterface::welcomeMenu(){
    bool validInput = false;
    while(!validInput) {
        string welcomeInput;
        cout << "1. Create New Budget\n";
        cout << "2. Change Existing Budget\n";
        cout << "3. Use Existing Budget\n";
        cout << "4. Exit Program\n";
        cin >> welcomeInput;
        validInput = inputChecker(welcomeInput);
        if(!validInput){
            cout << "Invalid input please try again\n";
        }
        else{
            int numInput = stoi(welcomeInput);
            switch(numInput){
                case 1:
                    break;

                case 2:
                    break;

                case 3:
                    break;

                case 4:
                    break;

                default:
                    cout << "Invalid input please try again";
                    validInput = false;
        }
    }


}
void UserInterface::welcomeScreen(){
   cout <<" ██╗    ██╗███████╗██╗      ██████╗ ██████╗ ███╗   ███╗███████╗\n";
    cout <<" ██║    ██║██╔════╝██║     ██╔════╝██╔═══██╗████╗ ████║██╔════╝\n";
    cout <<" ██║ █╗ ██║█████╗  ██║     ██║     ██║   ██║██╔████╔██║█████╗\n";
    cout <<" ██║███╗██║██╔══╝  ██║     ██║     ██║   ██║██║╚██╔╝██║██╔══╝\n";
    cout <<" ╚███╔███╔╝███████╗███████╗╚██████╗╚██████╔╝██║ ╚═╝ ██║███████╗\n";
    cout <<" ╚══╝╚══╝ ╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝\n";

}
void UserInterface::closingScreen() {
    cout <<" ██████╗  ██████╗  ██████╗ ██████╗ ██████╗ ██╗   ██╗███████╗██╗\n";
    cout <<" ██╔════╝ ██╔═══██╗██╔═══██╗██╔══██╗██╔══██╗╚██╗ ██╔╝██╔════╝██║\n";
    cout <<" ██║  ███╗██║   ██║██║   ██║██║  ██║██████╔╝ ╚████╔╝ █████╗  ██║\n";
    cout <<" ██║   ██║██║   ██║██║   ██║██║  ██║██╔══██╗  ╚██╔╝  ██╔══╝  ╚═╝\n";
    cout <<"╚██████╔╝╚██████╔╝╚██████╔╝██████╔╝██████╔╝   ██║   ███████╗██╗\n";
    cout <<"╚═════╝  ╚═════╝  ╚═════╝ ╚═════╝ ╚═════╝    ╚═╝   ╚══════╝╚═╝\n";
}

void UserInterface::userMenu() {
    bool validInput = false;
    while(!validInput) {
        string userMenuInput;
        cout << "1. Print\n";
        cout << "2. Change budget amount\n";
        cout << "3. Add expense or transcation\n";
        cout << "4. Delete expense or transaction\n";
        cout << "5. Sort\n";
        cout << "6. Save\n";
        cout << "7. Exit\n";
        cin >> userMenuInput;
        bool validInput = inputChecker(userMenuInput);
        if (!validInput) {
        cout >> "Invalid input please try again\n";
        }
        else {
            int numInput = stoi(userMenuInput);
            switch (numInput) {
                case 1:

                break;

                case 2:

                break;

                case 3:

                    break;

                case 4:

                    break;

                case 5:

                    break;

                case 6:
                    break;

                case 7: {
                    closingScreen();
                    return 0;
                }
                default:
                    cout << "Invalid input please try again";
                    validInput = false;

            }
        }

        }
    }
}


void UserInterface::clearScreen() {
    cout << string(50, '\n');
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



bool inputChecker(string userInput) {
    bool isNum;
    for (int i = 0; i < userInput.length(); i++) {
        if (isdigit(userInput[i])) {
            isNum = true;
        } else {
            isNum = false;
        }
    }
    return isNum;
}



int main()
{
    vector<string> categoryList;
	vector<int> moneyAmounts;

	vector<int> graphMoney;
	int totalBudget;

	totalBudget = 52360;
	categoryList.push_back("Morgage");
	categoryList.push_back("Food");
	categoryList.push_back("Transportation");
	moneyAmounts.push_back(30300); //30300 in proportion to 50 is 
	moneyAmounts.push_back(11030);
	moneyAmounts.push_back(11030);

	BarGraph b;

	graphMoney = b.cropData(b.ratioData(moneyAmounts, totalBudget));

	for (int i = 0; i < graphMoney.size(); i++) {
		cout << graphMoney[i] << " ";
	}
	cout << endl;
	b.printGraph(graphMoney, categoryList, moneyAmounts); //TODO: Looks bad if bar graph at max capacity, categories unaligned bc of digit size. Find max size by 50+category character amount + digits of number amount?

	cin >> totalBudget;
    return 0;
}
