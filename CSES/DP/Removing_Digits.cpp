#include<bits/stdc++.h>
using namespace std;
// long long solve(int n)
// {
//     if(n==0)return 0;
//     vector<int> digits;

//     int p = n;

//     while(p)
//     {
//         digits.push_back(p%10);
//         p/=10;
//     }
    
//     long long mn = INT_MAX;

//     for(int i=0;i<digits.size();i++)
//     {
        
//         if(n>=digits[i] && digits[i]!=0)
//         {
//             mn = min(1+solve(n-digits[i]),mn);
//         }
//     }

//     digits.clear();
//     return mn;
// }
int main() 
{
    int n;
    cin>>n;
    // cout<<solve(n);

    vector<long long> dp(n+1,INT_MAX);
    dp[0] = 0;

    for(int i=1;i<=n;i++)
    {
        vector<int> digits;
        
        int p = i;

    while(p)
    {
        digits.push_back(p%10);
        p/=10;
    }
    
    long long mn = INT_MAX;

    for(int j=0;j<digits.size();j++)
    {
        
        if(i>=digits[j] && digits[j]!=0)
        {
            mn = min(1+dp[i-digits[j]],mn);
        }
    }

    digits.clear();
    dp[i]=mn;
    }

    cout<<dp[n];
    return 0;
}