<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

// int solve(vector<int> &coins,int x,int n)
// {
//     if(x==0)return 1;
//     if(x<0 || n<=0)return 0;
//     return solve(coins,x-coins[n-1],n)+solve(coins,x,n-1);
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

    vector<vector<long long>> dp(n+1,vector<long long>(x+1,0));
    for(int i=0;i<=n;i++)dp[i][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=x;j++)
        {
           dp[i][j]+=dp[i-1][j]%mod;
           if(j>=coins[i-1])
           {
            dp[i][j] += (dp[i][j-coins[i-1]])%mod;
           }
        }
    }
    cout<<dp[n][x]%mod;
    return 0;
=======
#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

// int solve(vector<int> &coins,int x,int n)
// {
//     if(x==0)return 1;
//     if(x<0 || n<=0)return 0;
//     return solve(coins,x-coins[n-1],n)+solve(coins,x,n-1);
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

    vector<vector<long long>> dp(n+1,vector<long long>(x+1,0));
    for(int i=0;i<=n;i++)dp[i][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=x;j++)
        {
           dp[i][j]+=dp[i-1][j]%mod;
           if(j>=coins[i-1])
           {
            dp[i][j] += (dp[i][j-coins[i-1]])%mod;
           }
        }
    }
    cout<<dp[n][x]%mod;
    return 0;
>>>>>>> ac692f2be99fee60a2c70d2afe7883dc73991ee6
}