#include <iostream>
#include <vector>
#include "Date.h"
#include <algorithm>
#include <math.h>

using namespace std;

struct Expense
{
    string name;
    int amount;
    Date date;
    
    //constructor
    Expense(string name, int amount, Date date)
    {
        this->name = name;
        this->amount = amount;
        this->date = date;
    }
    
    //prints expense
    string toString()
    {
        return this->name + "\t$" + to_string(this->amount) + "\t" + this->date.toString();
    }
};

class Category
{
public:
    string name;
    int budgetAmount;
    vector<Expense> expenseVec;
    
    Category(string name, int budgetAmount, vector<Expense> expenseVec)
    {
        this->name = name;
        this->budgetAmount = budgetAmount;
        this->expenseVec = expenseVec;
    }
    
    //prints category and their expenses
    string toString()
    {
        string printCategory;
        printCategory = this->name + "\t$" + to_string(budgetAmount) + "\n";
        
        for(auto expense: expenseVec)
        {
            printCategory += "\t" + expense.toString() + "\n";
        }
        return printCategory;
    }
    
    void sortByExpenseName (bool lowToHigh)
    {
        if (lowToHigh)
        {
            sort(expenseVec.begin(), expenseVec.end(), [](const Expense& a, const Expense& b) -> bool {  return a.name.compare(b.name) < 0; });
        }
        else
        {
            sort(expenseVec.begin(), expenseVec.end(), [](const Expense& a, const Expense& b) -> bool {  return a.name.compare(b.name) > 0; });
        }
    }
    
    void sortByExpenseAmount (bool lowToHigh)
    {
        if (lowToHigh)
        {
            sort(expenseVec.begin(), expenseVec.end(), [](const Expense& a, const Expense& b) -> bool {  return a.amount < b.amount; });
        }
        else
        {
            sort(expenseVec.begin(), expenseVec.end(), [](const Expense& a, const Expense& b) -> bool {  return a.amount > b.amount; });
        }
    }
    
    void sortByExpenseDate (bool lowToHigh)
    {
        if (lowToHigh)
        {
            sort(expenseVec.begin(), expenseVec.end(), [](const Expense& a, const Expense& b) -> bool {  return a.date.compareTo(b.date) < 0; });
        }
        else
        {
            sort(expenseVec.begin(), expenseVec.end(), [](const Expense& a, const Expense& b) -> bool {  return a.date.compareTo(b.date) > 0; });
        }
    }
};

class Budget
{
public:
    vector<Category> categoryVec;
    // total amount of money user has to spend
    double totalBudget;
    /*
     the first percentage vector is the percentages per category
     that the user would like to be spending
     
     the second rPercentage is the real percentages per category that the user is spending based on the expenses
     */
    
    // vector of percentages based on inputed budget amount per category
    vector<int> percentages;
    // vector of percentages based on expenses per category
    vector<int> rPercentages;
    /*
    vector telling user how much money she has left to spend or gone
    over based on budget allowed per category, if value is negative it
    means the user has spent that amount of money over the budget for
    that category, if positive then that is amount left to spend for
    that category.
     */
    vector<int> underOver;
    
    
    
    Budget(vector<Category> categoryVec)
    {
        this->categoryVec = categoryVec;
        calcTotalBudget();
    }
    
    string toString()
    {
        string printBudget;
        
        for(auto category: categoryVec)
        {
            printBudget += category.toString() + "\n\n";
        }
        return printBudget;
    }
    
    //sums total budget of user based on budget amount for each category
    void calcTotalBudget()
    {
        double sum=0;
        for(auto category: categoryVec)
        {
            sum+=category.budgetAmount;
        }
        this->totalBudget=sum;
        
    }
    
    void sortByCategoryName(bool lowToHigh)
    {
        if (lowToHigh)
        {
            sort(categoryVec.begin(), categoryVec.end(), [](const Category& a, const Category& b) -> bool {  return a.name.compare(b.name) < 0; });
        }
        else
        {
            sort(categoryVec.begin(), categoryVec.end(), [](const Category& a, const Category& b) -> bool {  return a.name.compare(b.name) > 0; });
        }
    }
    void sortByCategoryBudget(bool lowToHigh)
    {
        if (lowToHigh)
        {
            sort(categoryVec.begin(), categoryVec.end(), [](const Category& a, const Category& b) -> bool {  return a.budgetAmount < b.budgetAmount; });
        }
        else
        {
            sort(categoryVec.begin(), categoryVec.end(), [](const Category& a, const Category& b) -> bool {  return a.budgetAmount > b.budgetAmount; });
        }
    }
    
    void sortByExpensesName(bool lowToHigh)
    {
        for(auto & category: categoryVec)
        {
            category.sortByExpenseName(lowToHigh);
        }
    }
    
    void sortByExpensesAmount(bool lowToHigh)
    {
        for(auto & category: categoryVec)
        {
            category.sortByExpenseAmount(lowToHigh);
        }
    }
    
    void sortByExpensesDate(bool lowToHigh)
    {
        for(auto & category: categoryVec)
        {
            category.sortByExpenseDate(lowToHigh);
        }
    }
    
    /*
     calculates percent of total budget used by each category based on
    budget amount
     */
    void calculatePercentages()
    {
        for(auto category: categoryVec)
        {
            percentages.push_back(round(100*(category.budgetAmount/totalBudget)));
            
        }
    }
    /*
     calculates percent of total budget used by each category based on
     expenses for that category
     */
    void calculateRPercentages()
    {
        for(auto category: categoryVec)
        {
            double amount=0;
            for(auto expense:category.expenseVec)
            {
                amount+=expense.amount;
            }
            rPercentages.push_back(round(100*(amount/totalBudget)));
            
        }
    }
    
    /*
     calculates amount left to spend or amount gone over in each category
     
     */
    void calcHowMuchLeft()
    {
        int amount;
        for(auto category:categoryVec)
        {
            amount=0;
            for(auto expense: category.expenseVec)
            {
                amount+=expense.amount;
            }
            int left=category.budgetAmount-amount;
            underOver.push_back(left);
            
        }
    }
    
    
   
};
