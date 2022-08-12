#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
void solve(vector<int> &v,int m,int n,int &cnt)
{
    if(n==0)
    {
        bool flag = true;
        for(int k:v)if(k==0)flag = false;
        if(flag)
        {
            cnt++;
            cnt = cnt%mod;
        }
        return;
    }

    if(v[n-1]==0)
    {
        int li;
        if(n>=2)li = v[n-2];
        else li = v[0];
        int ri;
        if(n<v.size())ri = v[n];
        else ri = v[v.size()-1];
        if(ri!=0){
        for(int i=ri-1;i<=ri+1;i++)
        {
            if(i>=1 && i<=m)
            {
               if(li!=0)
               {
                if(i>=li-1 && i<=li+1)
                {
                    v[n-1]=i;
                    solve(v,m,n-1,cnt);
                    v[n-1]=0;
                }
               }else
               {
                v[n-1]=i;
                solve(v,m,n-1,cnt);
                v[n-1] = 0;
               }
            }
        }
        }else
        {
            for(int i=1;i<=m;i++)
            {
                if(li!=0)
               {
                if(i>=li-1 && i<=li+1)
                {
                    v[n-1]=i;
                    solve(v,m,n-1,cnt);
                    v[n-1]=0;
                }
               }else
               {
                v[n-1]=i;
                solve(v,m,n-1,cnt);
                v[n-1] = 0;
               }
            }
        }
    }else
    {
        solve(v,m,n-1,cnt);
    }

    return;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }

    int cnt = 0;

    // solve(v,m,n,cnt);

    vector<int> dp(n+1,0);

    for(int i=1;i<=n;i++)
    {
        
    }

    cnt = cnt%mod;
    cout<<cnt;
    return 0;
}