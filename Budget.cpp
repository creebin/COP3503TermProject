#include "Budget.h"

//Getter for transactionName
string Transaction::getName() {
    return transactionName;
}

//Setter for transactionName
void Transaction::setName(string newName) {
    transactionName = newName;
}

//Getter for transaction
string Transaction::getCategory() {
    return categoryName;
}

//Setter for transaction
void Transaction::setCategory(string newCategory) {
    categoryName = newCategory;
}

//Getter for transactionAmount
double Transaction::getAmount() {
    return transactionAmount;
}

//Setter for transactionAmount
void Transaction::setAmount(double newAmount) {
    if (newAmount >= 0) {
        transactionAmount = newAmount;
    } else {
        cout << "Invalid transactionAmount" << endl;
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
    transactionAmount = 0;
}

//Takes one line of data from the file and puts it into a Transaction object, then adds those objects to the vector
void Budget::parseTransactionData() {

    string currentLine;
    string parseHelper;
    Transaction tempTransaction;

    while (fileData.good()) {

        getline(fileData, currentLine);
        //parseHelper is the categoryName at this line
        parseHelper = currentLine.substr(0, currentLine.find(' '));
        tempTransaction.setCategory(parseHelper);
        currentLine.erase(0, currentLine.find('|') + 2);

        //parseHelper is the transactionName at this line
        parseHelper = currentLine.substr(0, currentLine.find('$'));
        tempTransaction.setName(parseHelper);
        currentLine.erase(0, currentLine.find('$') + 1);

        //parseHelper is the dollar transactionAmount at this line
        parseHelper = currentLine.substr(0, currentLine.find(' '));
        tempTransaction.setAmount(stod(parseHelper));
        currentLine.erase(0, currentLine.find('|') + 2);

        //parseHelper is the month at this line
        parseHelper = currentLine.substr(0, currentLine.find('/'));
        //Checks if there is an extra zero before converting parseHelper to an int
        if (parseHelper[0] == '0') {
            parseHelper.erase(0, 1);
        }
        int localMonth = stoi(parseHelper);
        currentLine.erase(0, currentLine.find('/') + 1);

        //parseHelper is day at this line
        parseHelper = currentLine.substr(0, currentLine.find('/'));
        if (parseHelper[0] == '0') {
            parseHelper.erase(0, 1);
        }
        int localDay = stoi(parseHelper);
        currentLine.erase(0, currentLine.find('/') + 1);
        //Sets the transaction date
        int localYear = stoi(currentLine);
        tempTransaction.setDate(localMonth, localDay, localYear);
        //Adds the transaction to the budget
        allTransactions.push_back(tempTransaction);
        //Adds the transaction to its respective month
        if (localMonth == 4) {
            aprilTransactions.push_back(tempTransaction);
        }
        if (localMonth == 5) {
            mayTransactions.push_back(tempTransaction);
        }
    }
}

//Parses an existing budget file to get the user's spending limit
void Budget::parseQuotaData(string quotaName) {

    string currentLine;
    string parseHelper;
    Quota tempQuota;

    //Opens the existing budget file
    ifstream quotaFile;
    quotaFile.open(quotaName);
    //Parses through the budget file and puts the data into allQuotas
    while (quotaFile.good()) {

        getline(quotaFile, currentLine);

        //parseHelper is the categoryName at this line
        parseHelper = currentLine.substr(0, currentLine.find(' '));
        tempQuota.setCategory(parseHelper);
        currentLine.erase(0, currentLine.find('|') + 2);

        //parseHelper is the spending limit at this line
        tempQuota.setSpendLimit(stoi(currentLine));
        allQuotas.push_back(tempQuota);
    }
    //Closes the file
    quotaFile.close();

}

//Gets all the transactions for use in sorting
vector<Transaction> Budget::getAllTransactions() {
    if (!allTransactions.empty()) {
        return allTransactions;
    } else {
        cout << "Error: no transactions" << endl;
    }
}

vector<Transaction> Budget::getAprilTransactions() {
    if (!aprilTransactions.empty()) {
        return aprilTransactions;
    } else {
        cout << "Error: no April transactions" << endl;
    }
}

vector<Transaction> Budget::getMayTransactions() {
    if (!mayTransactions.empty()) {
        return mayTransactions;
    } else {
        cout << "Error: no May transactions" << endl;
    }
}

vector<Quota> Budget::getAllQuotas() {
    if (!allQuotas.empty()) {
        return allQuotas;
    } else {
        cout << "Error: no quotas" << endl;
    }
}

//Allows a new transaction to be inputted manually
void Budget::addNewTransaction() {
    //Initializes necessary variables to handle the transaction
    Transaction newTransaction;
    string inputString;
    string parseHelper;
    ofstream newFileData;
    int userChoice;
    double inputAmount;

    //Gets input from the user
    cout << "Enter the transactionName of the transaction: " << endl;
    cin >> inputString;
    newTransaction.setName(inputString);
    cout << "Select the categoryName of the transaction: " << endl;
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
            newTransaction.setCategory("Housing");
            break;
        case 2:
            newTransaction.setCategory("Entertainment");
            break;
        case 3:
            newTransaction.setCategory("Food");
            break;
        case 4:
            newTransaction.setCategory("Transportation");
            break;
        case 5:
            newTransaction.setCategory("Medical");
            break;
        case 6:
            newTransaction.setCategory("Clothing");
            break;
        case 7:
            newTransaction.setCategory("Insurance");
            break;
        case 8:
            newTransaction.setCategory("Utilities");
            break;
        case 9:
            newTransaction.setCategory("Other");
            break;
        default:
            cout << "Invalid selection" << endl;
    }
    cout << "Enter the transactionAmount of the transaction : " << endl;
    cin >> inputAmount;
    newTransaction.setAmount(inputAmount);
    cout << "Enter the date of the transaction (MM/DD/YYYY): " << endl;
    cin >> inputString;

    //Saves transaction to the file
    newFileData.open(fileName, ios::app);
    newFileData << "\n" << newTransaction.getCategory() << " | " << newTransaction.getName() << ": $" << inputAmount
                << " | " << inputString;

    //Handles user adding dates with 1-digit months and days
    if (inputString[0] == '0') {
        inputString.erase(0, 1);
    }

    //Uses parsing code from a previous function to handle the date
    parseHelper = inputString.substr(0, inputString.find('/'));
    newTransaction.getDate().setMonth(stoi(parseHelper));
    inputString.erase(0, inputString.find('/') + 1);
    if (inputString[0] == '0') {
        inputString.erase(0, 1);
    }

    parseHelper = inputString.substr(0, inputString.find('/'));
    newTransaction.getDate().setDay(stoi(parseHelper));
    inputString.erase(0, inputString.find('/') + 1);

    //parseHelper is the year at this line
    parseHelper = inputString;
    newTransaction.getDate().setYear(stoi(parseHelper));
    //Adds the transaction to the vector of transactions
    allTransactions.push_back(newTransaction);

}
//Allows a transaction to be deleted
void Budget::deleteTransaction() {
    string inputName;
   // size_t nameFinder;
    cout << "What transaction should be deleted?" << endl;
    cin >> inputName;
    for (int i = 0; i < allTransactions.size(); i++) {
        if(allTransactions[i].getName().find(inputName) != string::npos){
            cout << "Found it" << endl;
        }else{
            cout << "Didn't find it " << endl;
        }
    }
}
//Saves sorted Transactions
void Budget::saveTransactions(vector<Transaction> saveVector) {
    fileData.close();
    ofstream saveFile(fileName);
    //Writes content from the vector into the file
    for (int i = 0; i < saveVector.size() - 1; i++) {
        saveFile << saveVector[i].getCategory() << " | " << saveVector[i].getName() << " $"
                 << saveVector[i].getAmount() << " | " << saveVector[i].getDate().toString() << endl;
    }
    //Prevents an extra newline character at the end of the file
    saveFile << saveVector[saveVector.size() - 1].getCategory() << " | " << saveVector[saveVector.size() - 1].getName()
             << " $"
             << saveVector[saveVector.size() - 1].getAmount() << " | "
             << saveVector[saveVector.size() - 1].getDate().toString();
    saveFile.close();
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
    cout << "Choose a transactionName for your new budget" << endl;
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
    budgetFile << "Other | " << userSpending;
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

    //Takes in the transactionName of the user's budget and checks if it exists
    cout << "What is your existing budget called?" << endl;
    cin >> budgetName;
    budgetName.append(".txt");
    fstream budgetFile;
    budgetFile.open(budgetName);
    if (!budgetFile) {
        cout << "Budget not found" << endl;
    }
    //Lets the user select what they want to change
    cout << "Which categoryName do you want to change?" << endl;
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
        if (editCategory == "Other") {
            tempFile << editCategory << " | " << userChoice;
        } else {
            tempFile << editCategory << " | " << userChoice << endl;
        }
    }
    //Closes the files
    budgetFile.close();
    tempFile.close();
    //Replaces the old budget with the new one and renames them
    remove(budgetName.c_str());
    rename("tempFile.txt", budgetName.c_str());

}
//Allows the user to use an existing budget
void Budget::useBudget() {
    string budgetName;
    cout << "What is your existing budget called?" << endl;

    cin >> budgetName;
    budgetName.append(".txt");
    fstream budgetFile;
    budgetFile.open(budgetName);
    if (!budgetFile) {
        cout << "Budget not found" << endl;
    }
    parseQuotaData(budgetName);
}

//Budget constructor
Budget::Budget(string inputName) {
    fileData.open(inputName);
    fileName = inputName;
    parseTransactionData();

}