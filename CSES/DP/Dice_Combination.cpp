<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;

long long solve(int n)
{
    if(n<0)return 0;
    if(n==0)return 1;

    long long k=0;
    for(int i=1;i<=6;i++)
    {
        if(n<i)continue;
        k += solve(n-i);
    }
    return k;
}

int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,0);

    dp[0]=1;

    for(int i=1;i<=n;i++)
    {
        long long k=0;
        for(int j=1;j<=6;j++)
        {
            if(i<j)continue;
            k+=dp[i-j];
            k = k%mod;
        }
        dp[i]=k%mod;
    }

    cout<<(dp[n]%mod);
    return 0;
=======
#include<bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;

long long solve(int n)
{
    if(n<0)return 0;
    if(n==0)return 1;

    long long k=0;
    for(int i=1;i<=6;i++)
    {
        if(n<i)continue;
        k += solve(n-i);
    }
    return k;
}

int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,0);

    dp[0]=1;

    for(int i=1;i<=n;i++)
    {
        long long k=0;
        for(int j=1;j<=6;j++)
        {
            if(i<j)continue;
            k+=dp[i-j];
            k = k%mod;
        }
        dp[i]=k%mod;
    }

    cout<<(dp[n]%mod);
    return 0;
>>>>>>> ac692f2be99fee60a2c70d2afe7883dc73991ee6
}