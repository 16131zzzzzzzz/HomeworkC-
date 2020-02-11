#include<iostream>
#include<string>
using namespace std;

class Date
{
    private:
    int month;
    int year;
    int day;

    public:
    explicit Date( int yearIn, int monthIn, int dayIn);
    int getYear();
    int getMonth();
    int getDay();
    void setMonth( int );
    void setYear( int );
    void setDay( int );
    void displayDate();
};

Date::Date( int yearIn, int monthIn, int dayIn)
{
    year = yearIn;
    if(1 <= monthIn && monthIn <= 12)
    {
        month = monthIn;
    }
    else
    {
        month = 1;
    }
    day = dayIn;
}

int Date::getDay()
{
    return day;
}

int Date::getMonth()
{
    return month;
}

int Date::getYear()
{
    return year;
}

void Date::setDay( int dayC )
{
    day = dayC;
}

void Date::setMonth( int monthC )
{
   if(1 <= monthC && monthC <= 12)
    {
        month = monthC;
    }
    else
    {
        month = 1;
    }
}

void Date::setYear( int yearC )
{
    year = yearC;
}

void Date::displayDate()
{
    cout << month << "/" << day << "/" << year << endl;
}

int main()
{
    Date date1(2019,10,2);
    date1.displayDate();
    Date date2(2018,20,30);
    date2.displayDate();
    date2.setYear(2000);
    date2.displayDate();
    date1.setMonth(30);
    date1.displayDate();
}