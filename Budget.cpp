#include "Budget.h"

//Getter for transaction
string Transaction::getCategory() {
    return category;
}

//Setter for transaction
void Transaction::setCategory(string newCategory) {
    category = newCategory;
}

//Getter for amount
double Transaction::getAmount() {
    return amount;
}

//Setter for amount
void Transaction::setAmount(double newAmount) {
    if (newAmount >= 0) {
        amount = newAmount;
    } else {
        cout << "Invalid amount" << endl;
    }
}

//Getter for date
Date Transaction::getDate() {

    return transactionDate;
}

//Sets the date
void Transaction::setDate(int month, int day, int year) {

    transactionDate.setMonth(month);
    transactionDate.setDay(day);
    transactionDate.setYear(year);
}

//Transaction constructor
Transaction::Transaction() {
    amount = 0;
}

//Takes one line of data from the file and puts it into a Transaction object, then adds those objects to the vector
void Budget::parseFileData() {

    string currentLine;
    string parseHelper;
    Transaction tempTransaction;

    while (fileData.good()) {

        getline(fileData, currentLine);
        //parseHelper is the category at this line
        parseHelper = currentLine.substr(0, currentLine.find(':'));
        tempTransaction.setCategory(parseHelper);
        currentLine.erase(0, currentLine.find('$') + 1);


        //parseHelper is the dollar amount at this line
        parseHelper = currentLine.substr(0, currentLine.find('-'));
        tempTransaction.setAmount(stod(parseHelper));
        currentLine.erase(0, currentLine.find('-') + 2);


        //parseHelper is the month at this line
        parseHelper = currentLine.substr(0, currentLine.find('/'));
        int localMonth = stoi(parseHelper);
        currentLine.erase(0, currentLine.find('/') + 1);


        //parseHelper is the day at this line
        parseHelper = currentLine.substr(0, currentLine.find('/'));
        int localDay = stoi(parseHelper);
        currentLine.erase(0, currentLine.find('/') + 1);


        //parseHelper is the year at this line
        parseHelper = currentLine;
        int localYear = stoi(parseHelper);

        //Sets date vector in tempTransaction
        tempTransaction.setDate(localMonth, localDay, localYear);

        //Adds the transaction to the account
        allTransactions.push_back(tempTransaction);
    }
}

//Gets all the transactions for use in sorting
vector<Transaction> Budget::getAllTransactions() {
    if (!allTransactions.empty()) {
        return allTransactions;
    } else {
        cout << "Error: no transactions" << endl;
    }
}

//Allows a new transaction to be inputted manually
void Budget::addNewTransaction() {
    //Initializes necessary variables to handle the transaction
    Transaction newTransaction;
    string inputCategory;
    string inputDate;
    string parseHelper;
    ofstream newFileData;
    double inputAmount;

    //Gets input from the user
    cout << "Enter the category of the transaction: " << endl;
    cin >> inputCategory;
    newTransaction.setCategory(inputCategory);
    cout << "Enter the amount of the transaction : " << endl;
    cin >> inputAmount;
    newTransaction.setAmount(inputAmount);
    cout << "Enter the date of the transaction (MM/DD/YYYY): " << endl;
    cin >> inputDate;

    //Saves transaction to the file
    newFileData.open(fileName, ios::app);
    newFileData << "\n" << inputCategory << ": $" << inputAmount << " - " << inputDate;

    //Handles user adding dates with 1-digit months and days
    if (inputDate[0] == '0') {
        inputDate.erase(0, 1);
    }

    //Uses parsing code from a previous function to handle the date
    parseHelper = inputDate.substr(0, inputDate.find('/'));
    newTransaction.getDate().setMonth(stoi(parseHelper));
    inputDate.erase(0, inputDate.find('/') + 1);
    if (inputDate[0] == '0') {
        inputDate.erase(0, 1);
    }

    parseHelper = inputDate.substr(0, inputDate.find('/'));
    newTransaction.getDate().setDay(stoi(parseHelper));
    inputDate.erase(0, inputDate.find('/') + 1);

    //parseHelper is the year at this line
    parseHelper = inputDate;
    newTransaction.getDate().setYear(stoi(parseHelper));
    //Adds the transaction to the vector of transactions
    allTransactions.push_back(newTransaction);

}

//Closes the file
void Budget::closeFile() {
    fileData.close();
}

//Creates a new budget file
void Budget::createBudget() {
    //Keeps track of the user's input
    string budgetName;
    int userSpending;
    //Creates a new text file to hold the budget
    cout << "Choose a name for your new budget" << endl;
    cin >> budgetName;
    budgetName.append(".txt");
    ofstream budgetFile(budgetName);
    //Allows the user to choose how much they want to spend
    cout << "How much do you want to spend on housing?" << endl;
    cin >> userSpending;
    budgetFile << "Housing | " << userSpending << endl;
    cout << "How much do you want to spend on entertainment?" << endl;
    cin >> userSpending;
    budgetFile << "Entertainment | " << userSpending << endl;
    cout << "How much do you want to spend on food?" << endl;
    cin >> userSpending;
    budgetFile << "Food | " << userSpending << endl;
    cout << "How much do you want to spend on transportation?" << endl;
    cin >> userSpending;
    budgetFile << "Transportation | " << userSpending << endl;
    cout << "How much do you want to spend on medical expenses?" << endl;
    cin >> userSpending;
    budgetFile << "Medical | " << userSpending << endl;
    cout << "How much do you want to spend on clothing?" << endl;
    cin >> userSpending;
    budgetFile << "Clothing | " << userSpending << endl;
    cout << "How much do you want to spend on insurance?" << endl;
    cin >> userSpending;
    budgetFile << "Insurance | " << userSpending << endl;
    cout << "How much do you want to spend on utilities?" << endl;
    cin >> userSpending;
    budgetFile << "Utilities | " << userSpending << endl;
    cout << "How much do you want to spend on things not listed above?" << endl;
    cin >> userSpending;
    budgetFile << "Other | " << userSpending << endl;
    //Closes the file after writing to it
    budgetFile.close();
}

//Changes an existing Budget file
void Budget::changeBudget() {
    string budgetName;
    int userChoice;
    string editCategory;
    string parseHelper;
    size_t categoryFinder;

    //Takes in the name of the user's budget and checks if it exists
    cout << "What is your existing budget called?" << endl;
    cin >> budgetName;
    budgetName.append(".txt");
    fstream budgetFile;
    budgetFile.open(budgetName);
    if (!budgetFile) {
        cout << "Budget not found" << endl;
    }
    //Lets the user select what they want to change
    cout << "Which category do you want to change?" << endl;
    cout << "1. Housing" << endl;
    cout << "2. Entertainment" << endl;
    cout << "3. Food" << endl;
    cout << "4. Transportation" << endl;
    cout << "5. Medical" << endl;
    cout << "6. Clothing" << endl;
    cout << "7. Insurance" << endl;
    cout << "8. Utilities" << endl;
    cout << "9. Other" << endl;
    cin >> userChoice;
    switch (userChoice) {
        case 1:
            editCategory = "Housing";
            break;
        case 2:
            editCategory = "Entertainment";
            break;
        case 3:
            editCategory = "Food";
            break;
        case 4:
            editCategory = "Transportation";
            break;
        case 5:
            editCategory = "Medical";
            break;
        case 6:
            editCategory = "Clothing";
            break;
        case 7:
            editCategory = "Insurance";
            break;
        case 8:
            editCategory = "Utilities";
            break;
        case 9:
            editCategory = "Other";
            break;
        default:
            cout << "Invalid selection" << endl;
    }
    cout << "How much do you want to spend on " << editCategory << endl;
    cin >> userChoice;

    //Copies all lines except the one to be changed to a temporary file
    ofstream tempFile;
    tempFile.open("tempFile.txt", ios::app);
    while (budgetFile.good()) {
        getline(budgetFile, parseHelper);
        categoryFinder = parseHelper.find(editCategory);
        if (categoryFinder == string::npos) {
            tempFile << parseHelper << endl;
            continue;
        }
        //Writes edit to the temporary file
        tempFile << editCategory << " | " << userChoice << endl;
    }
    //Closes the files
    budgetFile.close();
    tempFile.close();
    //Replaces the old budget with the new one and renames them
    remove(budgetName.c_str());
    rename("tempFile.txt", budgetName.c_str());

}

//Budget constructor
Budget::Budget(string inputName) {
    fileData.open(inputName);
    fileName = inputName;
