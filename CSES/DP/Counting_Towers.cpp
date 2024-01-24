<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int main()
{
    int t;
    cin>>t;

    int n = 1e6;
    vector<vector<long long>> dp(n+2,vector<long long>(2,0));
    dp[n+1][0] = dp[n+1][1]=1;

    for(int i=n;i>=2;i--)
    {
        long long op1 = (dp[i+1][1]+dp[i+1][0])%mod;
        long long op2 = dp[i+1][0];
        long long op3 = 2*(dp[i+1][0])%mod;
        long long op4 = dp[i+1][1];
        dp[i][0] = (op1+op2+op3)%mod;
        dp[i][1] = (op1+op4)%mod;
    }

    for(int i=0;i<t;i++)
    {
        int q;
        cin>>q;
        

        cout<<(dp[1e6+2-q][1]+dp[1e6+2-q][0])%mod<<endl;
    }
    

    return 0;
=======
#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int main()
{
    int t;
    cin>>t;

    int n = 1e6;
    vector<vector<long long>> dp(n+2,vector<long long>(2,0));
    dp[n+1][0] = dp[n+1][1]=1;

    for(int i=n;i>=2;i--)
    {
        long long op1 = (dp[i+1][1]+dp[i+1][0])%mod;
        long long op2 = dp[i+1][0];
        long long op3 = 2*(dp[i+1][0])%mod;
        long long op4 = dp[i+1][1];
        dp[i][0] = (op1+op2+op3)%mod;
        dp[i][1] = (op1+op4)%mod;
    }

    for(int i=0;i<t;i++)
    {
        int q;
        cin>>q;
        

        cout<<(dp[1e6+2-q][1]+dp[1e6+2-q][0])%mod<<endl;
    }
    

    return 0;
>>>>>>> ac692f2be99fee60a2c70d2afe7883dc73991ee6
}