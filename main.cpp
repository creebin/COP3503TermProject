#include <iostream>
#include <fstream>
#include <vector>
#include "storage.h"
using namespace std;


int main(){
    
    vector<Transaction> sampleSort;
    string inputFile;
    cout << "Please enter the name of the Bank Account File: " << endl;
    cin >> inputFile;
    BankAccount mainAccount(inputFile);
    mainAccount.parseFileData();
    sampleSort = mainAccount.getAllTransactions();

    mainAccount.addNewTransaction();

    mainAccount.closeFile();
  
return 0;
}
