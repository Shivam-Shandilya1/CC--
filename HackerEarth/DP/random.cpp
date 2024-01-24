// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int SumL(vector<int> &a,int k,int i)
{
    vector<int> v = a;
    if(v[i] == v[i+1])i++;
    int ans = v[i];
    while(i>=1 && k)
    {
        int addon = min(k,v[i-1] - v[i]);
        k-=addon;
        v[i] = v[i] + addon;
        if(k && v[i-1] == v[i])
        {
            v[i-1]++;
            k--;
            ans = max(ans,v[i-1]);
        }
        ans = max(ans,v[i]);
        i--;
    }
    return ans;
}
int SumR(vector<int> &a,int k,int i)
{
    vector<int> v = a;
    int ans = v[i];
    i--;
    while(i>=0 && k)
    {
        // cout<<i<<" "<<k<<endl;
        int addon = min(k,v[i+1] - v[i] + 1);
        k-=addon;
        v[i] = v[i] + addon;
        ans = max(ans,v[i]);
        i--;
    }
    return ans;
}
int sol(int n,vector<int> &a,int k)
{
    int i = 0;
    vector<pair<int,int>> v;
    while(i < n-1)
    {
        int si = i;
        while(i+1<n && a[i] <= a[i+1])
        {
            i++;
        }
        if(si!=i)v.push_back({si,i});
        i++;
    }
    int ans = 0;
    // cout<<v.size()<<endl;
    // for(int i = 0;i<v.size();i++)
    // {
    //     cout<<v[i].first<<" "<<v[i].second<<endl;
    // }
    for(int j = 0;j < (int)v.size();j++)
    {
        // cout<<v[j].first<<" "<<v[j].second<<":";
        int op1 = SumL(a,k,v[j].first);
        // cout<<op1<<" ";
        int op2 = SumR(a,k,v[j].second);
        // cout<<op2<<endl;
        ans = max(op1,op2);
    }
    return ans;
}
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i = 0;i<n;i++)cin>>a[i];
        for(int k:a)cout<<k<<" ";
        cout<<endl;
        cout<<sol(n,a,k)<<endl;
    }
    return 0;
}