#include <iostream>
#include <vector>
#include "Date.h"
#include <algorithm>

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

        Budget(vector<Category> categoryVec)
        {
            this->categoryVec = categoryVec;
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

};
