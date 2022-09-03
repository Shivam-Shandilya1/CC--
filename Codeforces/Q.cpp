#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int n;
        cin>>n;
        map<string,vector<int>> m;
        vector<string> s1,s2,s3;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            s1.push_back(s);
        }
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            s2.push_back(s);
        }
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            s3.push_back(s);
        }
        
        for(string s:s1)m[s].push_back(0);
        for(string s:s2)m[s].push_back(1);
        for(string s:s3)m[s].push_back(2);
        vector<int> v(3,0);
        for(auto it:m)
        {
            if(it.second.size()== 1)v[it.second[0]]+=3;
            if(it.second.size()== 2)
            {
                v[it.second[0]]+=1;
                v[it.second[1]]+=1;
            }
        }
        for(int k:v)cout<<k<<" ";
        cout<<endl;
    }
return 0;
}