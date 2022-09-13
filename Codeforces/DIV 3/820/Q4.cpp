#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
void solve()
{
    ll n; 
    cin >> n;
    vll v, v1;
    for(int i=0;i<n;i++)
    {
        ll temp;
        cin >> temp;
        v.push_back(temp);
    }
    for(int i=0;i<n;i++)
    {
        ll temp;
        cin >> temp;
        v1.push_back(temp);
    }
    for(int i=0;i<n;i++)  v1[i] -= v[i];
    sort(v1.rbegin(), v1.rend());
    ll i = 0;
    ll j = n - 1;
    ll ans = 0;
    while(i < j)
    {
        if(v1[i] + v1[j] >= 0)
        {
            ans++;
            i++;
            j--;
        }
        else    j--;
    }
    cout << ans << endl;
}
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
ll t=1;
cin>>t;
while(t--)
{
    solve();
}
return 0;}
// int main()
// {
//     long long T;
//     cin>>T;
//     for(long long t=0;t<T;t++)
//     {
//         long long n;
//         cin>>n;

//         vector<long long> x(n),y(n);

//         for(long long i=0;i<n;i++)cin>>x[i];
//         for(long long i=0;i<n;i++)cin>>y[i];
//         vector<int>pos,neg;
//         int cnt_Zero = 0;
//         for(int i=0;i<n;i++)
//         {
//             int dif = x[i]-y[i];
//             if(dif>0)pos.push_back(dif);
//             else if(dif<0) neg.push_back(dif);
//             else cnt_Zero++;
//         }

//     }
//     return 0;
// }