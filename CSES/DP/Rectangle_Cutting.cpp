<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
int main() 
{
    int a,b;
    cin>>a>>b;

    vector<vector<int>> dp(a+1,vector<int>(b+1,0));

    for(int i=1;i<=b;i++)dp[1][i] = i-1;
    for(int i=1;i<=a;i++)dp[i][1] = i-1;

    for(int i=2;i<=a;i++)
    {        for(int j=2;j<=b;j++)
        {
            if(i==j)dp[i][j]=0;
            else
            {
                int mn = INT_MAX;
                for(int k=1;k<j;k++)
                {
                    mn = min(dp[i][k]+dp[i][j-k]+1,mn);
                }
                for(int k=1;k<i;k++)
                {
                    mn = min(dp[k][j]+dp[i-k][j]+1,mn);
                }

                dp[i][j] = mn;
            }
            
        }
    }

    cout<<dp[a][b]<<endl;
    return 0;
=======
#include<bits/stdc++.h>
using namespace std;
int main() 
{
    int a,b;
    cin>>a>>b;

    vector<vector<int>> dp(a+1,vector<int>(b+1,0));

    for(int i=1;i<=b;i++)dp[1][i] = i-1;
    for(int i=1;i<=a;i++)dp[i][1] = i-1;

    for(int i=2;i<=a;i++)
    {        for(int j=2;j<=b;j++)
        {
            if(i==j)dp[i][j]=0;
            else
            {
                int mn = INT_MAX;
                for(int k=1;k<j;k++)
                {
                    mn = min(dp[i][k]+dp[i][j-k]+1,mn);
                }
                for(int k=1;k<i;k++)
                {
                    mn = min(dp[k][j]+dp[i-k][j]+1,mn);
                }

                dp[i][j] = mn;
            }
            
        }
    }

    cout<<dp[a][b]<<endl;
    return 0;
>>>>>>> ac692f2be99fee60a2c70d2afe7883dc73991ee6
}