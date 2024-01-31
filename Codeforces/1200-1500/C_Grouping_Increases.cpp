#include <bits/stdc++.h>
using namespace std;
int solve(int n,vector<int> &a)
{
    int b1 = INT_MAX,b2 = INT_MAX;
    int ans = 0;
    for(int i = 0;i<n;i++)
    {
        if(a[i] <= min(b1,b2) || a[i]>max(b1,b2))
        {
            if(a[i]>max(b1,b2))ans++;
            if(b1<b2)b1 = a[i];
            else b2 = a[i];
        }else if(a[i] > min(b1,b2) && a[i] <= max(b1,b2))
        {
            if(b1>b2)b1 = a[i];
            else b2 = a[i];
        }
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i = 0;i<n;i++)cin>>a[i];
        cout<<solve(n,a)<<endl;
    }
}