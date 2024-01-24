#include <bits/stdc++.h>
using namespace std;
int solve2(int n,vector<int> v)
{
    int x = -1;
    bool a = false;
    for(int i=0;i<n-1;i++)
    {
        if(v[i]<=v[i+1])continue;
        else
        {
            a = true;
            x = (v[i]+v[i+1])/2;
            x = ((v[i]+v[i+1])%2==0)?x:x+1;
            bool f =true;
            for(int j=0;j<n-1;j++)
            {
                if(abs(v[j]-x)<=abs(v[j+1]-x))continue;
                else 
                {
                    f = false;
                    break;
                }
            }
            if(f)return x;
        }
    }
    return (a)?-1:0;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    cout<<solve2(n,v)<<endl;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}