#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; //number of customers
    cin>>n;
    vector<pair<int,int>> v;
    for(int i = 0;i<n;i++)
    {
        int a,b; //a:arrival time b:leaving time
        cin>>a>>b;
        v.push_back({a,0}); // use 0 to indicate arrival of guest in vector v
        v.push_back({b,1});
    }
    sort(v.begin(),v.end());
    int sum = 0;
    int ans = 0;
    for(int i = 0;i<(int)v.size();i++)
    {
        if(v[i].second == 0)sum++;
        else if(v[i].second == 1) sum--;
        ans = max(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}