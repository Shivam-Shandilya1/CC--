#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
// int solve(vector<int> &coins,int x)
// {
//     if(x==0)return 1;
//     if(x<0)return 0;
//     int k=0;
//     for(int i=0;i<coins.size();i++)
//     {
//         if(x>=coins[i])
//         {
//             k+=solve(coins,x-coins[i]);
//         }
//     }
//     return k;
// }
int main()
{
    int n,x;
    cin>>n>>x;
    vector<int> coins;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        coins.push_back(k);
    }

    vector<long long> dp(x+1,0);
    dp[0]=1;

    for(int i=1;i<=x;i++)
    {
        long long k=0;
    for(int j=0;j<coins.size();j++)
    {
        if(i>=coins[j])
        {
            k+=dp[i-coins[j]];
            k= k%mod;
        }
    }
    dp[i] = k%mod;
    }

    cout<<dp[x]%mod;
    return 0;
}