#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int n;
        cin>>n;
        vector<int> s(n),f(n);
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>f[i];
        }
        vector<int> d(n);
        d[0] = f[0]-s[0];
        for(int i=1;i<n;i++)
        {
            d[i] = f[i]-max(s[i],f[i-1]);
        }
        for(int k:d)cout<<k<<" ";
        cout<<endl;
    }
    return 0;
}