#include <iostream>
#include "Budget.h"

using namespace std;


int main(){
    
    vector<Transaction> allTest;
    vector<Transaction> aprilTest;
    vector<Transaction> mayTest;
    
    Budget mainBudget("account.txt);
    //Assign vectors then pass them to necessary sorting functions
    aprilTest = myBudget.getAprilTransactions();
    mayTest = myBudget.getMayTransactions();
    myTest = myBudget.getAllTransactions();
    
                      
    

    mainAccount.closeFile();
  
return 0;
}
