#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x,n;
    cin>>x>>n;
    vector<int> nums(n);
    for(int i = 0;i<n;i++)cin>>nums[i];
    set<int> v = {0,x};
    vector<int> res;
    multiset<int> vis;
    vis.insert(x);
    for(int i = 0;i<n;i++)
    {
        auto idx = v.lower_bound(nums[i]);
        int k = *idx;
        if(idx != v.begin())
        {
            advance(idx,-1) ;
            int k2 = *idx;
            int diff = k - k2;
            auto it = vis.find(diff);
            vis.erase(it);
            vis.insert(k - nums[i]);
            vis.insert(nums[i] - k2);
            v.insert(nums[i]);
        }
        res.push_back(*vis.rbegin());
        // for(auto it:vis)cout<<(it)<<" ";
        // cout<<endl;
    }
    for(int k:res)cout<<k<<" ";
    cout<<endl;
    return 0;
}