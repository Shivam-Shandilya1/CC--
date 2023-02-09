#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &locations,vector<int> &movedFrom,vector<int> &movedTo)
{
    map<int,int> m;
    for(int k:locations)
    {
        m[k]++;
    }
    for(int i=0;i<movedFrom.size();i++)
    {
        if(m[movedFrom[i]])
        {
            m[movedFrom[i]]--;
            if(m[movedFrom[i]]==0)m.erase(movedFrom[i]);
            m[movedTo[i]]++;
        }
    }
    vector<int> res;
    for(auto it:m)res.push_back(it.first);
    return res;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> locations(n),movedFrom(m),movedTo(m);
    for(int i=0;i<n;i++)cin>>locations[i];
    for(int i=0;i<m;i++)cin>>movedFrom[i];
    for(int i=0;i<m;i++)cin>>movedTo[i];
    vector<int> res = solve(locations,movedFrom,movedTo);
    for(int k:res)cout<<k<<" ";
    cout<<endl;
    return 0;
}