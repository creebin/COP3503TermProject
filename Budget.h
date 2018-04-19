
#ifndef BUDGET_BUDGET_H
#define BUDGET_BUDGET_H

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include "Date.h"
#include "Quota.h"

using namespace std;

//Transaction class to group the data together
class Transaction {
private:
    //Member variables
    string transactionName;
    string categoryName;
    double transactionAmount;
    Date transactionDate;
    bool reOccuring;

public:
    //Member functions
    string getName();

    void setName(string newName);

    string getCategory();

    void setCategory(string newCategory);

    double getAmount();

    void setAmount(double newAmount);

    Date getDate();

    void setDate(int month, int day, int year);

    bool getOccurance();

    void setOccurance(bool reOccuring);

    Transaction();
};

//Bank account class to group the transactions together
class Budget {
private:
    ifstream fileData;
    string fileName;
    vector<Transaction> allTransactions;
    vector<Transaction> aprilTransactions;
    vector<Transaction> mayTransactions;
    vector<Quota> allQuotas;
    deque<Transaction> reminders;

    void parseQuotaData(string quotaName);
    void parseTransactionData();    
    void updateReOccurance();    
    void updateReminders();
    vector<Transaction> removeReoccurance(vector<Transaction> input);
    void checkReOccurance(Transaction input);
    Date lastDate();

public:

    vector<Transaction> getAllTransactions();

    vector<Transaction> getAprilTransactions();

    vector<Transaction> getMayTransactions();

    vector<Quota> getAllQuotas();
    
    deque<Transaction> getReminders();

    void addNewTransaction();

    void deleteTransaction();

    void saveTransactions(vector<Transaction> saveVector);

    void createBudget();

    void changeBudget();

    void useBudget();

    void closeFile();

    explicit Budget(string inputName);
    
};

#endif //BUDGET_BUDGET_H
