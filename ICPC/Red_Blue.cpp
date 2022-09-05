#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define pb push_back
#define MP make_pair
#define mod2 998244353
#define forn(i,n) for(int i=0;i<(n);i++)
#define vll vector<ll>
#define forr(i,n) for(ll i=n-1;i>=0;i--)
void solve()
{
    ll n;
    cin >> n;
    vll v;
    string s;
    cin >> s;
    
    ll a;
    forn(i,n)
    {
        cin >> a;
        v.pb(a);
    }
    ll ans = 0;
    ll ok = -1;
    ll ind = 0;
    if(s[0] == 'B')
    {
        cout << -1 << endl;
        return;
    }
    while(ind < n)
    {     
        if(s[ind] == 'B')
        {
            ans++;
            for(int i = ind; i <= min(ok, n - 1); i++)  s[i] = 'R';
            if(s[ind] == 'B')
            {
                cout << -1 << endl;
                return;
            }
            else
            {
                ok = 0;
                ok = max(ok, v[ind] + ind);
            }
        }
        else if (s[ind] == 'R')
        {
            ok = max(ok, v[ind] + ind);
        }
        ind++;
    }
    cout << ans << endl;
}
int main(){
  
ll t=1;
cin>>t;
while(t--)
{
    solve();
}
return 0;}