#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

// int solve(vector<vector<char>> &grid,int n,int i,int j)
// {
//     if(grid[i][j]=='*') return 0;
//     if(i==n-1 && j==n-1)return 1;
//     else if(i==n-1)return solve(grid,n,i,j+1);
//     else if(j==n-1)return solve(grid,n,i+1,j);
//     return solve(grid,n,i+1,j)+solve(grid,n,i,j+1);
// }

int main() 
{
    int n;
    cin>>n;
    vector<vector<char>> grid;
    for(int i=0;i<n;i++)
    {
        vector<char> s;
        for(int j=0;j<n;j++)
        {
            char c;
            cin>>c;
            s.push_back(c);
        }
        grid.push_back(s);
    }

    vector<vector<long long>> dp(n+1,vector<long long> (n+1,0));

   if(grid[n-1][n-1]=='.')dp[n][n]=1;
   else return  0;
   for(int i=n-1;i>=0;i--)
   {
    if(grid[i-1][n-1]=='.')dp[i][n] = dp[i+1][n];
    if(grid[n-1][i-1]=='.')dp[n][i] = dp[n][i+1];
   }


    for(int i=n-1;i>=1;i--)
    {
        for(int j=n-1;j>=1;j--)
        {
            if(grid[i-1][j-1]=='.')
            {
                dp[i][j] = (dp[i+1][j]%mod+dp[i][j+1]%mod)%mod;
            }
        }
    }

    // cout<<solve(grid,n,0,0);

    cout<<dp[1][1]%mod;

    return 0;
}