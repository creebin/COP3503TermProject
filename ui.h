//header
#include <iostream>
#include<vector>




class Graphs
{
private:
    vector<string> categoryNames;
    vector<int> moneyAmount;
    int totalBudget;
    const int fitScreen = 2;

public:
    vector<int> ratioData(vector<int>,int);//what inputs, and should it output a vector or smth? should it be completely fleshed out up here since won't change?
    vector<int> cropData(vector<int>);//should be completely fleshed out up here?
    void printGraph(vector<int>, vector<string>);
};


class PieGraph : public Graphs
{
public:
    void printGraph()
    {

    }
};

class UserInterface
{
public:
    void welcomeMenu(); //do they want to create a new budget or use an existing budget?
    void closingScreen();
    void userMenu();
    //if choose sort->sorting menu in sorting
    //take in input
    void clearScreen();
    void inputChecker(string);

};

