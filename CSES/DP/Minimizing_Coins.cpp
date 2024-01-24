<<<<<<< HEAD
#include<bits/stdc++.h>

using namespace std;

// long long solve(vector<int> &coins,int x,int n)
// {
//     if(x==0)return 0;
//     if(x<0 || n<=0)return INT_MAX;
//     if(x<coins[n-1])return solve(coins,x,n-1);
//     return min(1+solve(coins,x-coins[n-1],n),solve(coins,x,n-1));
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

    vector<long long> dp(x+1,1e9);

    dp[0]=0;

    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>=coins[j])
            {
                dp[i] = min(1+dp[i-coins[j]],dp[i]);
            }
        }
    }

    cout<<((dp[x]==1e9)?-1:dp[x])<<endl;
    return 0;
=======
#include<bits/stdc++.h>

using namespace std;

// long long solve(vector<int> &coins,int x,int n)
// {
//     if(x==0)return 0;
//     if(x<0 || n<=0)return INT_MAX;
//     if(x<coins[n-1])return solve(coins,x,n-1);
//     return min(1+solve(coins,x-coins[n-1],n),solve(coins,x,n-1));
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

    vector<long long> dp(x+1,1e9);

    dp[0]=0;

    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>=coins[j])
            {
                dp[i] = min(1+dp[i-coins[j]],dp[i]);
            }
        }
    }

    cout<<((dp[x]==1e9)?-1:dp[x])<<endl;
    return 0;
>>>>>>> ac692f2be99fee60a2c70d2afe7883dc73991ee6
}