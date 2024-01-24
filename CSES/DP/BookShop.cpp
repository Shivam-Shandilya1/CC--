<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

// int solve(int n,int x,vector<int> &price,vector<int> &pages)
// {
//     if(x<=0 || n<=0)return 0;
//     if(x<price[n-1])return solve(n-1,x,price,pages);
//     return max(solve(n-1,x-price[n-1],price,pages)+pages[n-1],solve(n-1,x,price,pages));
// }

int main() 
{
    int n,x;
    cin>>n>>x;
    vector<int> price,pages;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        price.push_back(k);
    }
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        pages.push_back(k);
    }

    vector<vector<int>> dp(n+1,vector<int> (x+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=x;j++)
        {
            if(j<price[i-1])dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j-price[i-1]]+pages[i-1],dp[i-1][j]);
        }
    }
    cout<<dp[n][x];
    return 0;
=======
#include<bits/stdc++.h>
using namespace std;

// int solve(int n,int x,vector<int> &price,vector<int> &pages)
// {
//     if(x<=0 || n<=0)return 0;
//     if(x<price[n-1])return solve(n-1,x,price,pages);
//     return max(solve(n-1,x-price[n-1],price,pages)+pages[n-1],solve(n-1,x,price,pages));
// }

int main() 
{
    int n,x;
    cin>>n>>x;
    vector<int> price,pages;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        price.push_back(k);
    }
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        pages.push_back(k);
    }

    vector<vector<int>> dp(n+1,vector<int> (x+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=x;j++)
        {
            if(j<price[i-1])dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j-price[i-1]]+pages[i-1],dp[i-1][j]);
        }
    }
    cout<<dp[n][x];
    return 0;
>>>>>>> ac692f2be99fee60a2c70d2afe7883dc73991ee6
}