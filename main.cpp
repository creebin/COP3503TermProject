#include <iostream>
#include "Budget.h"

using namespace std;

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


void userMenu() {
	bool validInput = false;
	while (!validInput) {
		string userMenuInput;
		cout << "1. Print\n";
		cout << "2. Change budget amount\n";
		cout << "3. Add expense or transcation\n";
		cout << "4. Delete expense or transaction\n";
		cout << "5. Sort\n";
		cout << "6. Save\n";
		cout << "7. Graph\n";
		cout << "8. Exit\n";
		cin >> userMenuInput;
		bool validInput = inputChecker(userMenuInput);
		if (!validInput) {
			cout << "Invalid input please try again\n";
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

				case 7: 
					//graphMoney = b.cropData(b.ratioData(moneyAmounts, totalBudget));
    					//b.printGraph(graphMoney, categoryList, moneyAmounts);   
					break;
					
				case 8:
					
					closingScreen();
					return;
					
				default: 
					 cout << "Invalid input please try again";
					 validInput = false;

				}
			}

		}
	}

void welcomeMenu() {
	bool validInput = false;
	while (!validInput) {
		string welcomeInput;
		cout << "1. Create New Budget\n";
		cout << "2. Change Existing Budget\n";
		cout << "3. Use Existing Budget\n";
		cout << "4. Exit Program\n";
		cin >> welcomeInput;
		validInput = inputChecker(welcomeInput);
		if (!validInput) {
			cout << "Invalid input please try again\n";
		}
		else {
			int numInput = stoi(welcomeInput);
			switch (numInput) {
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
}



int main(){
    
    vector<Transaction> allTest;
    vector<Transaction> aprilTest;
    vector<Transaction> mayTest;
    
    Budget mainBudget("account.txt);
    //Assign vectors then pass them to necessary sorting functions
    aprilTest = mainBudget.getAprilTransactions();
    mayTest = mainBudget.getMayTransactions();
    myTest = mainBudget.getAllTransactions();
    
    BarGraph b;           
    

    mainBudget.closeFile();
  
return 0;
}
