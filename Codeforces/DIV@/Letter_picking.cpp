#include <bits/stdc++.h>
using namespace std;

void solve(string s,vector<int> &v,int i,int j,int trn)
{
    if(i>j)return;
    char c_b = s[i],c_e = s[j];
    if(c_b<c_e)
    {
        // cout<<"B:"<<c_b<<" "<<trn<<endl;
        // s.erase(s.begin());
        v[trn]+=c_b;
        solve(s,v,i+1,j,1-trn);
    }else
    {
        // cout<<"E:"<<c_e<<" "<<trn<<endl;
        // s.erase(s.begin()+s.size()-1);
        v[trn]+=c_e;
        solve(s,v,i,j-1,1-trn);
    }
    
}

int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        string s;
        cin>>s;
        vector<int> v(2,0);
        solve(s,v,0,s.size()-1,0);
        for(int k:v)cout<<k<<" ";
        cout<<endl;
        if(v[0]<v[1])cout<<"Alice"<<endl;
        if(v[0]==v[1])cout<<"Draw"<<endl;
        if(v[0]>v[1])cout<<"Bob"<<endl;
    }
    return 0;
}