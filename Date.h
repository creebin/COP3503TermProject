#ifndef GROUPPROJECT_DATE_H
#define GROUPPROJECT_DATE_H
#include <string>

using namespace std;

struct Date
{
    Date(int month, int day, int year);
    Date(Date const & newDate);
    Date();
    int month;
    int day;
    int year;
    string toString();
    int compareTo(Date other)const;
};
#endif //GROUPPROJECT_DATE_H
