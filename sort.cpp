#include <algorithm>
#include <math.h>
#include "Budget.cpp"

using namespace std;

struct Expense
{
    string name;
    int amount;
    Date date;

    //prints expense
    string toString()
    {
        return this->name + "\t$" + to_string(this->amount) + "\t" + this->date.toString();
    }

    //sets everything
    void setExpenseName(string Expensename)
    {
        name = Expensename;
    }

    void setExpenseAmount(int expenseAmount)
    {
        amount = expenseAmount;
    }

    void setExpenseDate(Date expenseDate)
    {
        date = expenseDate;
    }

};

class Category
{
public:
    string name;
    int budgetAmount;
    vector<Expense> expenseVec;
    int percent;

    void setbudgetAmount(int x)
    {
        budgetAmount = x;
    }

    void setCategoryName(string catName)
    {
        name = catName;
    }

    void setPercentAmount(int x){
        percent=x;
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

class BudgetManipulation
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

    //vector to get how much the budget is for each category
    vector<Quota> quotaVec;

    vector<Transaction> transactionVec;

    //
    Budget myBudget = Budget("account.txt");


    BudgetManipulation(vector<Quota> quotaVec)
    {
        this->quotaVec = myBudget.getAllQuotas();
        this->transactionVec = myBudget.getAllTransactions();
        setCategories();
        setQuotas();
        setExpenses();
        calcTotalBudget();
        calculatePercentages();

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

    void setCategories()
    {
        for(auto transactions: transactionVec)
        {
            string categoryName = transactions.getCategory();
            if(find(categoryVec.begin(), categoryVec.end(), categoryName) != categoryVec.end())
            {
                Category category = Category();
                category.setCategoryName(categoryName);
                //makes new category
                categoryVec.push_back(category);
            }
        }
    }

    void setCatPercent(){
        for(int i=0;i<=percentages.size();i++){
            categoryVec[i].percent=percentages[i];
        }

    }

    void setExpenses()
    {
        for(auto transactions: transactionVec)
        {
            string categoryName = transactions.getCategory();
            string expenseName = transactions.getName();
            int expenseAmount = transactions.getAmount();
            Date expenseDate = transactions.getDate();

            Expense expense = Expense();
            expense.setExpenseName(expenseName);
            expense.setExpenseAmount(expenseAmount);
            expense.setExpenseDate(expenseDate);

            Category compareCategory = categoryVec[0];
            int position = 0;

            while(categoryName != compareCategory.name)
            {
                position++;

                //sets compare category to the correct category to add expense to
                compareCategory = categoryVec[position];
            }

            //fills the expenseVec in all the categories
            compareCategory.expenseVec.push_back(expense);
        }
    }

    void setQuotas()
    {
        for(auto & category:categoryVec){
            category.setbudgetAmount(quotaVec.front().getSpendLimit());
        }
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

    void sortByCategoryPercentage(bool lowToHigh)
    {
        if (lowToHigh)
        {
            sort(categoryVec.begin(), categoryVec.end(), [](const Category& a, const Category& b) -> bool {  return a.percent < b.percent; });
        }
        else
        {
            sort(categoryVec.begin(), categoryVec.end(), [](const Category& a, const Category& b) -> bool {  return a.percent > b.percent; });
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