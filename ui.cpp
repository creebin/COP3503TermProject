#include"ui.h"
#include<vector>
#include <string>
#include <iostream>
using namespace std;

class BarGraph
{
private:
	vector<string> categoryNames;
	vector<int> moneyAmount;
	int totalBudget;
	const int fitScreen = 2;
public:
	vector<int> ratioData(vector<int>, int);
	vector<int> cropData(vector<int>);
	void printGraph(vector<int>, vector<string>, vector<int>);
};

vector<int> BarGraph::ratioData(vector<int> money, int budget) {
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

vector<int> BarGraph::cropData(vector<int> money) {
	int listLength = money.size();
	for (int i = 0; i < listLength; i++) {
		money[i] = money[i] / fitScreen;
	}
	return money;
}

void BarGraph::printGraph(vector<int> money, vector<string> category, vector<int> moneyOriginal) {
	int listLengthCat = category.size();
	int listLengthMon = money.size();
	const int maxBarLength = 50;

	for (int i = 0; i < 100; i++) {
		cout << "-";
	}

	cout << endl;
	for (int i = 0; i < 43; i++) {
		cout << " ";
	}
	cout << "BAR GRAPH\n" << endl;

	int digits = 0;
	for (int i = 0; i < listLengthMon; i++) {
		int tempDigits = 0;
		int moneyCopy = moneyOriginal[i];
		while (moneyCopy != 0) {
			moneyCopy = moneyCopy / 10;
			tempDigits++;
		}
		if (tempDigits > digits) {
			digits = tempDigits;
		}
		else {
			continue;
		}
	}


	for (int i = 0; i < listLengthCat; i++) {
		int currentDigits = 0;
		string currentCat = category[i];
		int moneyAmount = money[i];
		int counter = 0;

		int moneyCopy = moneyOriginal[i];

		while (moneyCopy != 0 || moneyCopy > 1) {
			moneyCopy = moneyCopy / 10;
			currentDigits++;
		}

		while (counter < moneyAmount) {
			cout << "|";
			counter++;

			if (counter == moneyAmount) {
				cout << " " << moneyOriginal[i];
			}
		}

		if (moneyAmount == 0) {
			if (moneyOriginal[i] != 0) {
				cout << "| " << moneyOriginal[i];
				counter = counter + 2;
			}
			else {
				cout << moneyOriginal[i];
			}
			counter++;
		}

		if (counter < maxBarLength) {
			for (int i = 0; i < (maxBarLength - counter); i++) {
				cout << " ";
			}
		}
		if (currentDigits != digits) {
			for (int i = 0; i < digits; i++) {
				cout << " ";
			}
			cout << "  " << currentCat << endl;
		}
		if (currentDigits == digits) {
			cout << " " << currentCat << endl;
		}
	}

	for (int i = 0; i < 100; i++) {
		cout << "-";
	}

	cout << endl;

}

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
	vector<string> categoryList;
	vector<int> moneyAmounts;

	vector<int> graphMoney;
	int totalBudget;

	totalBudget = 52360;
	categoryList.push_back("Morgage");
	categoryList.push_back("Food");
	categoryList.push_back("Transportation");
	moneyAmounts.push_back(11030); //30300 in proportion to 50 is 
	moneyAmounts.push_back(11030);
	moneyAmounts.push_back(30300);

	BarGraph b;

	graphMoney = b.cropData(b.ratioData(moneyAmounts, totalBudget));

	b.printGraph(graphMoney, categoryList, moneyAmounts); 

	cin >> totalBudget;
    return 0;
}
