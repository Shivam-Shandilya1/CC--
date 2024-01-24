#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0;i<n;i++)cin>>nums[i];
    sort(nums.begin(),nums.end());
    vector<long long int> preSum(nums.begin(),nums.end());
    for(int i = 1;i<n;i++)preSum[i] = preSum[i-1] + nums[i];
    if(nums[0]!=1)
    {
        cout<<1<<endl;
        return 0;
    }
    for(int i = 1;i<n;i++)
    {
        if(nums[i] > preSum[i-1]+1)
        {
            cout<<preSum[i-1]+1<<endl;
            return 0;
        }
    }
    cout<<preSum[n-1]+1<<endl;
    return 0;
}