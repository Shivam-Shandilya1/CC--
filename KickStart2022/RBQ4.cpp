#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
typedef long long ll;


int main()
{
    ll t;
    cin >> t;
    for (ll tc = 1; tc <= t; ++tc) 
    {
        
        long double R,A,B;
        cin >> R >> A >> B;
        long double area = 0;
        ll cnt = 0;
        while(R != 0)
        {
            area += (M_PI)*(R*R);
            if(cnt%2 == 0)
            {
                R = R*A;
            }else
            {
                R = floor(R/B);
            }
            cnt++;
        }
        cout<<"Case #"<<tc<<": "<<fixed<<setprecision(6)<<area<<endl;
    }
    return 0;
}