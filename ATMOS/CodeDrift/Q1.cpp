#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n,m;
    cin>>n>>m;
    map<int,int> h;
    for(int i = 0;i<n;i++)
    {
        int k;
        cin>>k;
        h[k]++;
    }
    vector<int> t(m);
    for(int i = 0;i<m;i++)cin>>t[i];
    // sort(h.begin(),h.end());
    // vector<int> vis(n,0);
    vector<int> ans;
    for(int i = 0;i<m;i++)
    {
        auto it = h.upper_bound(t[i]);
        if(it == h.begin())ans.push_back(-1);
        else
        {
            advance(it,-1);
            // cout<<it->first<<":"<<it->second<<endl;
            it->second --;
            ans.push_back(it->first);
            if(it->second == 0)h.erase(it);
        }
    }
    for(int k:ans)cout<<k<<" ";
    cout<<endl;
    return 0;
}
