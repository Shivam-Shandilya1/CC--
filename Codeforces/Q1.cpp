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
        string s1,s2;
        cin>>s1>>s2;
        
        vector<vector<int>> v(2,vector<int>(n,0));

        vector<int> col(2,0);
        for(int i=0;i<n;i++)
        {
            if(s1[i]=='R')v[0][i]=1;
            else v[0][i] = 0;
        }
        
        for(int i=0;i<n;i++)
        {
            if(s2[i]=='R')v[1][i]=1;
            else v[1][i] = 0;
        }

        bool f = false;
        for(int i=0;i<n;i++)
        {
            if(v[0][i]!=v[1][i])
            {
                cout<<"NO"<<endl;
                f = true;
                break;
            }
        }
        if(!f)cout<<"YES"<<endl;
    }

    return 0;
}