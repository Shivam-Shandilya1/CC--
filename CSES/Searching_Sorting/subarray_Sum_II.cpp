#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    vector<int> nums(n);
    for(int i = 0;i < n;i++)cin>>nums[i];
    unordered_map<long long int, int> mp;
    mp[0] = 1;
    long long int ans = 0;
    long long int sum = 0;
    for(int i = 0;i < n ;i ++)
    {
        sum += nums[i];
        ans += (mp[sum - x]);
        mp[sum]++;
    }
    cout<<ans<<endl;
    return 0 ;
}