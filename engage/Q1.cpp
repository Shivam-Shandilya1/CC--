#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool check_string(string str)
{
    map<char,int> m;
    for(int i = 0;i<str.size();i++)
    {
        if(m[str[i]]==0)
        {
            if(i==0)
            {
                m[str[i]]++;
                i++;
            }
            
       while(str[i]==str[i-1])
       {
           m[str[i]]++;
           i++;
       }
       if(i==0)i--;
        }else
        {
            return false;
        }
    }
     return true;
}
int main()
{
    ll t;
    cin >> t;
    for (ll tc = 1; tc <= t; ++tc) 
    {
        ll N;
        cin>>N;
        priority_queue<string,vector<string>,greater<int>> q;
        for(ll i = 0; i < N;i++)
        {
            string str;
            cin>>str;
            q.push(str);
        }
        string res;
        while(!q.empty())
        {
            res.append(q.top());
            q.pop();
        }
        cout<<res<<endl;
        if(!check_string(res))res = "IMPOSSIBLE";
        cout<<"Case #"<<tc<<": "<<res<<endl;;
    }
    return 0;
}