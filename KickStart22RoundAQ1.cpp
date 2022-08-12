#include <bits/stdc++.h>
using namespace std;
bool checkSubSequence(string &I,string &P)
{
    int i=0,j=0;
    while(j<P.size() && i<I.size())
    {
        if(I[i]==P[j])
        {
            j++;
            i++;
        }
        else
        {
            j++;
        } 
    }
    if(i==I.size())return true;
    else return false;
}
int main()
{
    int test_case = 0;
    cin>>test_case;
    map<char,vector<int>> m,m1;
    for(int i=0;i<test_case;i++)
    {
        bool flag = true;
        string I,P;
        cin>>I>>P;
        cout<<"Case #"<<i+1<<": ";
        if(checkSubSequence(I,P))
        {
            cout<<P.size()-I.size()<<endl;
        }else
        {
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
}