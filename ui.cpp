#include "ui.h"
#include <iostream>

BarGraph::BarGraph() {
	fitScreen = 2;
}

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



void UserInterface::welcomeScreen() {
	cout << " ██╗    ██╗███████╗██╗      ██████╗ ██████╗ ███╗   ███╗███████╗\n";
	cout << " ██║    ██║██╔════╝██║     ██╔════╝██╔═══██╗████╗ ████║██╔════╝\n";
	cout << " ██║ █╗ ██║█████╗  ██║     ██║     ██║   ██║██╔████╔██║█████╗\n";
	cout << " ██║███╗██║██╔══╝  ██║     ██║     ██║   ██║██║╚██╔╝██║██╔══╝\n";
	cout << " ╚███╔███╔╝███████╗███████╗╚██████╗╚██████╔╝██║ ╚═╝ ██║███████╗\n";
	cout << " ╚══╝╚══╝ ╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝\n";

}

void UserInterface::closingScreen() {
	cout << " ██████╗  ██████╗  ██████╗ ██████╗ ██████╗ ██╗   ██╗███████╗██╗\n";
	cout << " ██╔════╝ ██╔═══██╗██╔═══██╗██╔══██╗██╔══██╗╚██╗ ██╔╝██╔════╝██║\n";
	cout << " ██║  ███╗██║   ██║██║   ██║██║  ██║██████╔╝ ╚████╔╝ █████╗  ██║\n";
	cout << " ██║   ██║██║   ██║██║   ██║██║  ██║██╔══██╗  ╚██╔╝  ██╔══╝  ╚═╝\n";
	cout << "╚██████╔╝╚██████╔╝╚██████╔╝██████╔╝██████╔╝   ██║   ███████╗██╗\n";
	cout << "╚═════╝  ╚═════╝  ╚═════╝ ╚═════╝ ╚═════╝    ╚═╝   ╚══════╝╚═╝\n";
}



void UserInterface::clearScreen() {
	cout << string(50, '\n');
}


void DataFormatting::billReminder() {

}



bool inputChecker(string userInput) {
	bool isNum;
	for (int i = 0; i < userInput.length(); i++) {
		if (isdigit(userInput[i])) {
			isNum = true;
		}
		else {
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
	moneyAmounts.push_back(11030); 
	moneyAmounts.push_back(11030);
	moneyAmounts.push_back(30300);

	BarGraph b;

	graphMoney = b.cropData(b.ratioData(moneyAmounts, totalBudget));

	b.printGraph(graphMoney, categoryList, moneyAmounts); 

	cin >> totalBudget;

    return 0;
}
