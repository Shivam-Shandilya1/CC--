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
        int longestConsecutiveSubsequence();
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

int Logbook::longestConsecutiveSubsequence()
{
    sort(entries.begin(),entries.end());
    int a = entries[1];
    int temp=0,ans=0;
    if(a!=0)
    {
        for(int i=1;i<daysInMonth;)
        {
            temp=1;
            for(int j=i+1;j<daysInMonth+1;j++)
            {
                if(entries[j] != entries[i]+j-i)
                {
                    i=j;
                    break;
                }
                else
                    temp++;
            }
            if(temp>ans)
                ans=temp;
        }
    }
    return ans;
}
int main() 
{
    Logbook testLogbook(2, 2020);
    for(int i=1;i<=29;i+=4) 
        testLogbook.putEntry(i, i+5);
    if(testLogbook.hasTargetBeenReached(160)) 
        cout<<"YES\n";
    if(testLogbook.hasTargetBeenReached(120)) 
        cout<<"NO\n";
    for(int i=1;i<=29;i++)
    {
        if(i%2==0) 
            testLogbook.putEntry(i,i/2);
        else 
            testLogbook.putEntry(i,i+100);
    }
    cout<<"Longest Consecutive Subsequence is of length:"<<testLogbook.longestConsecutiveSubsequence()<<endl;
}

