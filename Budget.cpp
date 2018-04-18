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

//Budget constructor
Budget::Budget(string inputName) {
    fileData.open(inputName);
    fileName = inputName;
