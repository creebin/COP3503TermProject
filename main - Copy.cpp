#include "Date.h"
#include "budget.cpp"
#include <iostream>

using namespace std;

//declares function
void choiceFour(Budget* budget);
void sortCategories(Budget* budget);
void sortExpenses(Budget* budget);
bool selectSortOrder();

int main()
{
    //for testing
    Expense shirt ("ross", 25, Date(5, 13, 2012));
    Expense shoes ("target", 55, Date(5, 14, 2012));
    Expense pants ("sears", 45, Date(6, 11, 2012));
    Expense underwear ("walmart", 5, Date(5, 11, 2014));
    Expense chipotle ("chiptle", 11, Date(4, 11, 2018));
    Expense pizza ("pizza", 8, Date(3, 11, 2016));
    Expense culvers ("culvers", 12, Date(5, 11, 2015));
    Expense bento ("Bento", 13, Date(5, 11, 2014));

    vector<Expense> clothingExpenses{shirt, shoes, pants, underwear};
    vector<Expense> foodExpenses{chipotle, pizza, culvers, bento};
    Category clothing ("Clothing", 500, clothingExpenses);
    Category food ("Food", 800, foodExpenses);

    vector<Category> allCategories{clothing, food};

    //what storage group passes to me
    Budget* budget = new Budget(allCategories);

    int choice;
    while (true)
    {

        //menu options
        cout << "1.\n"
                "2.\n"
                "3. print\n"
                "4. sort\n"
                "5. exit\n";
        cin >> choice;

        if (choice == 1)
        {

        }
        else if (choice == 2)
        {

        }
        else if (choice == 3)
        {
            cout << budget->toString();
        }
        else if (choice == 4)
        {
            choiceFour(budget);
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Please enter a number from the menu." << endl;
        }
    }
    delete budget;
};

//implements function
void choiceFour(Budget* budget)
{
    int choice;
    while (true)
    {
        cout << "\nWhat do you want to sort?\n"
                "1. Categories\n"
                "2. Expenses\n"
                "3. Back\n";
        cin >> choice;

        if(choice == 1)
        {
            sortCategories(budget);
            break;
        }
        else if (choice == 2)
        {
            sortExpenses(budget);
            break;
        }
        else if (choice == 3)
        {
            break;
        }
        else //loops back to submenu
        {
            cout << "Please enter a number from the menu." << endl;
        }
    }
};

void sortCategories(Budget* budget)
{
    int choice;
    while(true)
    {
        cout << "\nHow do you want to sort categories?\n"
                "1. Name\n"
                "2. Budget Amount\n"
                "3. Back\n";
        cin >> choice;

        if(choice == 1)
        {
            bool lowToHigh = selectSortOrder();
            budget->sortByCategoryName(lowToHigh); //lowToHigh false which actually makes it highToLow
            break;
        }
        else if(choice == 2)
        {
            bool lowToHigh = selectSortOrder();
            budget->sortByCategoryBudget(lowToHigh);
            break;
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            cout << "Please enter a number from the menu." << endl;
        }
    }
};

void sortExpenses(Budget* budget)
{
    int choice;
    while(true)
    {
        cout << "\nHow do you want to sort expenses?\n"
                "1. Name\n"
                "2. Expense Amount\n"
                "3. Date\n"
                "4. Back\n";
        cin >> choice;

        if(choice == 1)
        {
            bool lowToHigh = selectSortOrder();
            budget->sortByExpensesName(lowToHigh);
            break;

        }
        else if(choice == 2)
        {
            bool lowToHigh = selectSortOrder();
            budget->sortByExpensesAmount(lowToHigh);
            break;
        }
        else if (choice == 3)
        {
            bool lowToHigh = selectSortOrder();
            budget->sortByExpensesDate(lowToHigh);
            break;
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Please enter a number from the menu." << endl;
        }
    }
}

bool selectSortOrder()
{
    int choice;
    while(true)
    {
        cout << "\nWhich order do you want to sort in?\n"
                "1. Low to High\n"
                "2. High to low\n"
                "4. Back\n";
        cin >> choice;

        if(choice == 1)
        {
            return true;
        }
        else if(choice == 2)
        {
            return false;
        }
        else if(choice == 3)
        {
            break;
        }
        else
        {
            cout << "Please enter a number from the menu." << endl;
        }
    }
}