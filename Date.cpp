#include "Date.h"

using namespace std;

//constructor
Date::Date(int month, int day, int year)
{
    this->month = month;
    this->day = day;
    this->year = year;
}

//constructor that passes an already existing Date and copies existing values into new Date object
Date::Date(Date const & newDate)
{
    this->month = newDate.month;
    this->day = newDate.day;
    this->year = newDate.year;
}

//returns Date as a string
string Date::toString()
{
   return to_string(this->month) + "/" + to_string(this->day) + "/" + to_string(this->year);
}

Date::Date()
{
    this->month = 1;
    this->day = 1;
    this->year = 1;
}

int Date::compareTo(Date other)const
{
    if (this->year == other.year && this->month == other.month && this->day == other.day)
    {
        return 0;
    }

    if (this->year > other.year)
    {
        return 1;
    }
    else if (this->year == other.year && this->month > other.month)
    {
        return 1;
    }
    else if (this->year == other.year && this->month == other.month && this->day > other.day)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

