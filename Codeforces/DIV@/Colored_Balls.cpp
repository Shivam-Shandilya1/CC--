#include <bits/stdc++.h>
using namespace std;
int solve(int n,vector<int> cnt)
{
    priority_queue<pair<int,int>> q;
    for(int i=0;i<n;i++)q.push({cnt[i],i});
    while(q.size()>=2)
    {
        auto it = q.top();
        q.pop();
        // cout<<it.first<<" "<<it.second<<endl;
        if(!q.empty())
        {
            auto it2 = q.top();
            q.pop();
            if(it2.first>1)q.push({it2.first-1,it2.second});
            // cout<<it2.first<<" "<<it2.second<<endl;
        }
        if(it.first>1)q.push({it.first-1,it.second});
        
    }
    return q.top().second;
}
int main()
{
    int T;
    cin>>T;
    for(int t =0;t<T;t++)
    {
        int n;
        cin>>n;
        vector<int> cnt(n);
        for(int i=0;i<n;i++)cin>>cnt[i];
        cout<<solve(n,cnt)+1<<endl;
    }
    return 0;
}