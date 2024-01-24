#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &x)
{
    int n = x.size();
    vector<int> idxes(n);
    for(int i = 0;i<n;i++)idxes[x[i]-1] = i;
    int i = 0,ans = 0;
    while(i<n)
    {
        while(i+1<n && idxes[i] <= idxes[i+1])
        {
            i++;
        }
        ans++;
        i++;
    }
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> x(n);
    for(int i = 0;i<n;i++)cin>>x[i];
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        swap(x[a-1],x[b-1]);
        cout<<solve(x)<<endl;
    }
    return 0;
}