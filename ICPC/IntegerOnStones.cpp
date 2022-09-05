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

ll pwr(ll x, ll y, ll p)
{
    ll res = 1;   

    x = x % p; 

    if (x == 0) return 0; 

    while (y > 0)
    {
       
        if (y & 1)
            res = (res*x) % p;

       
        y = y>>1; 
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
        ll ans = pwr(a, val, mod);
        cout << ans << endl;
    }
    else    cout << 1 << endl;
}

int main()
{
  sio();
  ll t=1;
  cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}