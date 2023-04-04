#include <bits/stdc++.h>
using namespace std;

int numberOfIdealInt(int low,int high)
{
    
    vector<int> dp(high+1,0);
    dp[1] = 1;
    dp[3] = 1;
    dp[5] = 1;

    for(int i = 6;i<=high;i++)
    {
        if(i%3==0)
        {
            dp[i] = dp[i/3];
        }else if(i%5 == 0)
        {
            dp[i] = dp[i/5];
        }
    }

    int sum = 0;
    for(int i=low;i<=high;i++)sum+=dp[i];
    return sum;
}

int main()
{
    int low,high;
    cin>>low>>high;
    cout<<numberOfIdealInt(low,high)<<endl;
    return 0;
}