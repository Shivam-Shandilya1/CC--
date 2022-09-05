#include<bits/stdc++.h>
using namespace std;
void sio(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

typedef long long ll;
#define mod 1000000007
#define pb push_back
#define MP make_pair
#define mod2 998244353
#define forn(i,n) for(int i=0;i<(n);i++)
#define vll vector<ll>
#define forr(i,n) for(ll i=n-1;i>=0;i--)
ll power(ll x, ll y, ll p)
{
    ll res = 1;     // Initialize result

    x = x % p; // Update x if it is more than or
                // equal to p

    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
void solve()
{
    ll a, n;
    cin >> a >> n;
    if(a > 0)
    {
        ll val = (n) / 2;
        ll ans = power(a, val, mod);
        cout << ans << endl;
    }
    else    cout << 1 << endl;
}
int main(){
  sio();
ll t=1;
cin>>t;
while(t--)
{
    solve();
}
return 0;}



  



  


