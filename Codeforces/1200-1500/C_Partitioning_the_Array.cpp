#include <bits/stdc++.h>
using namespace std;
vector<int> findFactors(int n)
{
    vector<int> ans;
    for(int i = 1;i <n ;i ++)
    {
        if(n%i == 0)ans.push_back(i);
    }
    return ans;
}
int solve(int N,vector<int> &a)
{
    vector<int> factors = findFactors(n);
    // cout<<"Factors: ";
    // for(int k:factors)cout<<k<<" ";
    // cout<<endl;
    int ans = 1;
    for(int k:factors)
    {
        int hcf = 0;
        for(int j = 0; j+k<n;j++)
        {
            hcf = __gcd(hcf,abs(a[j+k] - a[j]));
            if(hcf == 1)break;
        }
        ans += (hcf != 1);
    }
    return ans;
}
int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i = 0;i<n;i++)cin>>a[i];
        cout<<solve(n,a)<<endl;
    }
    return 0;
}