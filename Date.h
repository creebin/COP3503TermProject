#ifndef GROUPPROJECT_DATE_H
#define GROUPPROJECT_DATE_H
#include <string>

struct Date {

    int month;
    int day;
    int year;

    Date(int month, int day, int year);

    Date(Date const &newDate);

    Date();

    string toString();

    int compareTo(Date other) const;

    int getDay();

    int getMonth();

    int getYear();

    void setDay(int newDay);

    void setMonth(int newMonth);

    void setYear(int newYear);
};


#endif //GROUPPROJECT_DATE_H
