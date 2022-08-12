#include <bits/stdc++.h>
using namespace std;

class Logbook 
{
    private:
        int logMonth;
        int logYear;
        int daysInMonth;
        std::vector<int> entries;

        // private function to find whether current year is a leap year or not
        bool isLeapYear(int year);

    public:
        // constructor
        Logbook(int month, int year);

        // Adding entries
        void putEntry(int day, int value);

        // Get details of the Logbook
        int getEntry(int day);
        int getDaysInMonth();
        int getMonth();
        int getYear();
        bool hasTargetBeenReached(int target);
        void putEntry(int value);
        bool hasTargetBeenReached(int target,int check_day);
};

bool Logbook::isLeapYear(int year)
{
    if(year%4==0)
    {
        if(year%100==0)
        {
            if(year%400==0) 
                return true;
            else 
                return false;
        }
        else 
        return true;
    }
    else 
        return false;
}

Logbook::Logbook(int month, int year) 
{
    logMonth = month;
    logYear = year;
    std::vector<int> daysList = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(month==2 && isLeapYear(logYear)==true) 
        daysInMonth = 29;
    else
        daysInMonth = daysList[logMonth-1];

    entries.resize(daysInMonth+1, 0);
}

void Logbook::putEntry(int day, int value) 
{
    entries[day] = value;
}

int Logbook::getEntry(int day) 
{
    return entries[day];
}

int Logbook::getMonth() 
{
    return logMonth;
}

int Logbook::getYear() 
{
    return logYear;
}

int Logbook::getDaysInMonth() 
{
    return daysInMonth;
}

bool Logbook::hasTargetBeenReached(int target)
{
    int sum=0;
    if(accumulate(entries.begin(),entries.end(),sum)>=target)
        return true;
    else
        return false;
}

void Logbook::putEntry(int value)
{
    for(int i=1;i<daysInMonth+1;i++)
        entries[i] = value;
}

bool Logbook::hasTargetBeenReached(int target,int check_day)
{
    if(check_day>daysInMonth)
        return false;
    else
    {
        int sum=0;
        if(accumulate(entries.begin(),entries.begin() + check_day,sum)>=target)
            return true;
        else
            return false;
    }
}

int main() 
{
    Logbook testLogbook(2, 2020);
    for(int i=1;i<=29;i+=4) 
        testLogbook.putEntry(i, i+5);
    cout<<testLogbook.getEntry(3)<<endl;
    testLogbook.putEntry(10);
    cout<<testLogbook.getEntry(3)<<endl;
    cout<<endl;
    for(int i=1;i<=29;i+=4) 
        testLogbook.putEntry(i, i+5);
    if(testLogbook.hasTargetBeenReached(160)) 
        cout<<"YES\n";
    if(testLogbook.hasTargetBeenReached(160, 10)) 
        cout<<"NO\n";
    if(testLogbook.hasTargetBeenReached(30, 10)) 
        cout<<"YES\n";
}




