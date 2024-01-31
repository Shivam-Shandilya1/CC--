#include <bits/stdc++.h>
using namespace std;
long long int solve(int n,map<int,int> &mp)
{
    long long int ans = 0;
    long long int sum = 0;
    for(auto it:mp)
    {
        int l = it.second;
        if(l > 2)
        {
            ans += ((1LL*l*(l-1)*(l-2))/6);
        }
        if(l > 1)
        {
            ans += ((1LL*l*(l-1))/2)*sum;
        }
        sum+=it.second;
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
        map<int,int> mp;
        for(int i = 0;i<n;i++)
        {
            int input;
            cin>>input;
            mp[input]++;
        }
        cout<<solve(n,mp)<<endl;
    }
}