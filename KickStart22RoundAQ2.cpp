#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test = 0;
    cin>>test;
    
    for(int i=0;i<test;i++)
    {
        string s;
        cin>>s;
        cout<<"Case #"<<i+1<<": ";
        vector<int> v;
        int sum = 0;
        for(int i=0;i<s.size();i++)
        {
            v.push_back(s[i]-'0');
            sum+=(s[i]-'0');
        }
        int re = sum%9;
        int rem = 9-re;
        if(sum%9==0)
        {
            v.insert(v.begin()+1,0);
        }else
        {
            int k=v.size();
            for(int j=0;j<v.size();j++)
            {
                if(v[j]>rem)
                {
                    k=j;
                    break;
                }
            }
            v.insert(v.begin()+k,rem);
        }
        for(int p:v)cout<<p;
        cout<<endl;
    }
    return 0;
}