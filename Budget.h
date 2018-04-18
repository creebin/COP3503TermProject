
#ifndef BUDGET_BUDGET_H
#define BUDGET_BUDGET_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Date.h"

using namespace std;
//Transaction class to group the data together
class Transaction {
private:
    //Member variables
    string name;
    string category;
    double amount;
    Date transactionDate;

public:
    //Member functions
    string getCategory();

    void setCategory(string newCategory);

    double getAmount();

    void setAmount(double newAmount);

    Date getDate();

    void setDate(int month, int day, int year);

    Transaction();
};

//Bank account class to group the transactions together
class Budget {
private:
    ifstream fileData;
    string fileName;
    vector<Transaction> allTransactions;
public:

    void parseFileData();

    vector<Transaction> getAllTransactions();

    void addNewTransaction();
    
    void createBudget();

    void changeBudget();

    void closeFile();

    explicit Budget(string inputName);
};

#endif //BUDGET_BUDGET_H
