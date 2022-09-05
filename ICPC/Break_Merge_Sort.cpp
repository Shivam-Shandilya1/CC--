#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> v1,vector<int> v2)
{
    int i=0,j=0;
    vector<int> v3;
    while(i<v1.size() && j<v2.size())
    {
        if(v1[i]<v2[j])
        {
            v3.push_back(v1[i]);
            i++;
        }
        else
        {
            v3.push_back(v2[j]);
            j++;
        }
    }

    if(i<v1.size())
    {
        v3.push_back(v1[i]);
        i++;
    }
    if(j<v2.size())
    {
        v3.push_back(v2[j]);
        j++;
    }
    return v3;
}

int solve(int N,vector<vector<int>> &g)
{
    priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>> q;
    for(vector<int> v:g)q.push({v.size(),v});
    int cost = 0;
    while(q.size()>1)
    {
        vector<int> v1 = q.top().second;
        q.pop();
        vector<int> v2 = q.top().second;
        q.pop();
        vector<int> v3 = merge(v1,v2);
        q.push({v3.size(),v3});
        cost+=(v3.size());
    }
    return cost;
}

int main()
{
    int T;
    cin>>T;

    for(int t=0;t<T;t++)
    {
        
        int N;
        cin>>N;
        vector<vector<int>> g;
        for(int i=0;i<N;i++)
        {
            int sz;
            cin>>sz;
            vector<int> v;
            bool isSort = true;
            for(int i=0;i<sz;i++)
            {
                int k;
                cin>>k;
                if(i>=1 && k<v[i-1])
                {
                   g.push_back(v);
                   v.clear();sz=sz-i+1;
                }else
                {
                    v.push_back(k);
                }
                
            }
            
            g.push_back(v);
        }
        
        cout<<solve(N,g);
    }

    return 0;
}