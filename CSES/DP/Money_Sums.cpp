#include<bits/stdc++.h>
using namespace std;

// int solve(vector<int> &coins,int n,int sum,vector<int> &v)
// {
//     if(n==0)
//     {
//         if(sum!=0 && find(v.begin(),v.end(),sum)==v.end())
//         {
//             v.push_back(sum);
//             return 1;
//         }
//         return 0;
//     }

//     return solve(coins,n-1,sum+coins[n-1],v)+solve(coins,n-1,sum,v);
// }

int main()
{
    int n;
    cin>>n;

    vector<int> coins(n);

    int sum = 0;

    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
        sum+=coins[i];
    }

   vector<vector<int>> dp(n+1,vector<int> (sum+1,0));
   vector<int> v;
   vector<int> visited(sum+1,false);
   for(int i=0;i<=n;i++)dp[i][0] = 1;
   
   for(int i=1;i<=n;i++)
   {
    for(int j=1;j<=sum;j++)
    {
        if(j>=coins[i-1])dp[i][j] = dp[i-1][j-coins[i-1]]||dp[i-1][j];
        else dp[i][j] = dp[i-1][j];
        if(dp[i][j])
        {
            if(!visited[j])
            {
                v.push_back(j);
                visited[j] = true;
            }
        }
    }
   }

   cout<<v.size()<<endl;
   sort(v.begin(),v.end());
   for(int k:v)cout<<k<<" ";
    return 0;
}