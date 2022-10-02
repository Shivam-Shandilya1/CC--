#include <bits/stdc++.h>
using namespace std;


void solve()
{
    long long n;
    cin >> n;
   vector<long long> v(n);
    for(int i = 0;i<n;i++)cin >> v[i];
    long long j = - 1;
    long long cnt = 0;
    if(n == 1)
    {
        cout << 0 << endl;
        return;
    }
    vector<pair<int, int> > v1;
    if(v[0] % 2 == v[n - 1] % 2)
    {
        v[0] = v[n - 1];
        v1.push_back({1, n});
        cnt++;
    }
    if(v[0] % 2)
    {
        for(int i = 1; i < n; i++)
        {
            if(v[i] % 2 ==  0)
            {
                v[i] = v[0];
                v1.push_back({1, i + 1});
                cnt++;
            }
        }
        
        for(int i = 0;i<n;i++)
        {
            if(v[i] != v[0])
            {
                v1.push_back({i + 1, n});
                cnt++;
            }
        }
        cout << cnt << endl;
        for(int i = 0;i<v1.size();i++)
        {
            cout << v1[i].first << " " << v1[i].second << endl;
        }
    }
    else
    {
        for(int i = 1; i < n; i++)
        {
            if(v[i] % 2)
            {
                v[i] = v[0];
                v1.push_back({1, i + 1});
                cnt++;
            }
        }
        
        for(int i = 0;i<n;i++)
        {
            if(v[i] != v[0])
            {
                v1.push_back({i + 1, n});
                cnt++;
            }
        }
        cout << cnt << endl;
        for(int i = 0;i<v1.size();i++)
        {
            cout << v1[i].first << " " << v1[i].second << endl;
        }
    }
}
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
long long t=1;
cin>>t;
while(t--)
{
    solve();
}
return 0;}