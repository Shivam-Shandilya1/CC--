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
        void putEntry(int value);
        int operator[](int day);
        Logbook operator +(const Logbook &rightLogbook);
        vector<int> operator % (const Logbook &rightLogbook);
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

void Logbook::putEntry(int value)
{
    for(int i=1;i<daysInMonth+1;i++)
        entries[i] = value;
}

int Logbook::operator [] (int day)
{
    if(day>daysInMonth)
        return 0;
    else
        return entries[day];
}

Logbook Logbook::operator + (const Logbook &rightLogbook)
{
    Logbook L(logMonth,logYear);
    if(rightLogbook.daysInMonth == daysInMonth)
    {
        for(int i=1;i<daysInMonth+1;i++)
        {
            L.entries[i] = rightLogbook.entries[i] + entries[i];
        }
    }
    return L;
}

vector<int> Logbook::operator % (const Logbook &rightLogbook)
{
    vector<int> v;
    for(int i=1;i<daysInMonth+1;i++)
    {
        if(find(v.begin(),v.end(),entries[i])==v.end())
            v.push_back(entries[i]);
    }
    for(int i=1;i<rightLogbook.daysInMonth+1;i++)
    {
        if(find(v.begin(),v.end(),rightLogbook.entries[i])==v.end())
            v.push_back(rightLogbook.entries[i]);
    }
    return v;
}

int main() 
{
    Logbook testLogbook(2, 2020);
    Logbook testLogbook2(2, 2020);
    for(int i=1;i<=29;i++) 
    {
        testLogbook.putEntry(i);
        testLogbook2.putEntry(i+1);
    }
    cout<<testLogbook[5]<<endl;
    Logbook additionLogbook = testLogbook + testLogbook2;
    cout<<additionLogbook[29]<<endl;
    vector<int> combinedUniqueEntries = testLogbook % testLogbook2;
    sort(combinedUniqueEntries.begin(), combinedUniqueEntries.end());
    cout<<combinedUniqueEntries.front()<<" "<<combinedUniqueEntries.back()<<std::endl;
}
