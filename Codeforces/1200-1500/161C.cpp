#include <bits/stdc++.h>
using namespace std;

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
        vector<long long int> prefL(n,0),prefR(n,0);
        int prev = INT_MAX;
        for(int i = 1;i<n;i++)
        {
            prefL[i] = prefL[i-1];
            if(prev < a[i] - a[i-1])prefL[i] += (a[i] - a[i-1]);
            else prefL[i]++;
            prev = a[i] - a[i-1];
        }
        prev = INT_MAX;
        for(int i = n-2;i>=0;i--)
        {
            prefR[i] = prefR[i+1];
            if(prev < a[i+1] - a[i])prefR[i] += (a[i+1] - a[i]);
            else prefR[i]++;
            prev = a[i+1] - a[i];
        }
        // cout<<"PrefL:";
        // for(int i = 0;i<n;i++)cout<<prefL[i]<<" ";
        // cout<<endl;
        int m;
        cin>>m;
        for(int i = 0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            if(x<y)cout<<prefL[y-1] - prefL[x-1]<<endl;
            else cout<<prefR[y-1] - prefR[x-1]<<endl;
        }
    }
    return 0;
}