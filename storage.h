#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
#ifndef STORAGE_STORAGE_H
#define STORAGE_STORAGE_H

#endif //STORAGE_STORAGE_H

//Transaction class to group the data together
class Transaction {
private:
    //The date is stored in this way to allow flexibility in sorting.
    //You can choose to work with the date vector directly or sort the components individually
    string category;
    double amount;
    int day;
    int month;
    int year;
    vector<int> date;
public:
    //Each member variable has a getter and setter
    string getCategory();

    void setCategory(string newCategory);

    double getAmount();

    void setAmount(double newAmount);

    vector<int> getDate();

    void setDate();

    int getDay();

    void setDay(int newDay);

    int getMonth();

    void setMonth(int newMonth);

    int getYear();

    void setYear(int newYear);

    Transaction() {
        amount = 0;
        day = 1;
        month = 1;
        year = 1;
    };
};

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
vector<int> Transaction::getDate() {
    return date;
}

//Clears any previous information in the vector and sets a new date
void Transaction::setDate() {
    date.clear();
    date.push_back(month);
    date.push_back(day);
    date.push_back(year);
}

//Getter for day
int Transaction::getDay() {
    return day;
}

//Checks if day is valid and sets it
void Transaction::setDay(int newDay) {
    if (newDay >= 1 && newDay <= 31) {
        day = newDay;
    } else {
        cout << "Invalid Day" << endl;
    }
}

//Getter for month
int Transaction::getMonth() {
    return month;
}

//Checks if month is valid and sets it
void Transaction::setMonth(int newMonth) {
    if (newMonth >= 1 && newMonth <= 12) {
        month = newMonth;
    } else {
        cout << "Invalid Month" << endl;
    }
}

//Getter for year
int Transaction::getYear() {
    return year;
}

//Checks if year is valid and sets it
void Transaction::setYear(int newYear) {
    if (newYear >= 1) {
        year = newYear;
    } else {
        cout << "Invalid Year" << endl;
    }
}


//Bank account class to group the transactions together
class BankAccount {
private:
    ifstream fileData;
    string fileName;
    vector<Transaction> allTransactions;
public:

    void parseFileData();

    vector<Transaction> getAllTransactions();

    void addNewTransaction();

    void closeFile();

    explicit BankAccount(string inputName) {
        fileData.open(inputName);
        fileName = inputName;
    }
};

//Takes one line of data from the file and puts it into a Transaction object, then adds those objects to the vector
void BankAccount::parseFileData() {

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
        tempTransaction.setMonth(stoi(parseHelper));
        currentLine.erase(0, currentLine.find('/') + 1);
        //parseHelper is the day at this line
        parseHelper = currentLine.substr(0, currentLine.find('/'));
        tempTransaction.setDay(stoi(parseHelper));
        currentLine.erase(0, currentLine.find('/') + 1);
        //parseHelper is the year at this line
        parseHelper = currentLine;
        tempTransaction.setYear(stoi(parseHelper));
        //Sets date vector in tempTransaction
        tempTransaction.setDate();
        //Adds the transaction to the account
        allTransactions.push_back(tempTransaction);
    }
}

//Gets all the transactions for use in sorting
vector<Transaction> BankAccount::getAllTransactions() {
    if (!allTransactions.empty()) {
        return allTransactions;
    } else {
        cout << "Error: no transactions" << endl;
    }
}

//Allows a new transaction to be inputted manually
void BankAccount::addNewTransaction() {
    Transaction newTransaction;
    string inputCategory;
    string inputDate;
    string parseHelper;
    ofstream newFileData;
    double inputAmount;
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
    newTransaction.setMonth(stoi(parseHelper));
    inputDate.erase(0, inputDate.find('/') + 1);
    if (inputDate[0] == '0') {
        inputDate.erase(0, 1);
    }
    parseHelper = inputDate.substr(0, inputDate.find('/'));
    newTransaction.setDay(stoi(parseHelper));
    inputDate.erase(0, inputDate.find('/') + 1);
    //parseHelper is the year at this line
    parseHelper = inputDate;
    newTransaction.setYear(stoi(parseHelper));
    //Adds the transaction to the vector of transactions
    allTransactions.push_back(newTransaction);

}

//Closes the file
void BankAccount::closeFile() {
    fileData.close();
}
