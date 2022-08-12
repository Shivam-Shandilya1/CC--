#include <bits/stdc++.h>
using namespace std;
int main()
{
    int TestCaseNo,Candy_Bag,Students;
    vector<int> candy,result;
    cin>>TestCaseNo;
    for(int i=0;i<TestCaseNo;i++)
    {
        cin>>Candy_Bag>>Students;
        for(int i=0;i<Candy_Bag;i++)
        {
            int k;
            cin>>k;
            candy.push_back(k);
        }
        int res=0;
        for(int k:candy)res+=k;
        result.push_back(res%Students);
        candy.clear();
    }
    for(int i=0;i<TestCaseNo;i++)
    {
        cout<<"Case #"<<i+1<<": ";
        cout<<result[i]<<endl;
    }
    return 0;
}