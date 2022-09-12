#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long T;
    cin>>T;
    for(long long t=0;t<T;t++)
    {
        long long n,k;
        cin>>n>>k;
        vector<long long> goods(n);
        vector<long long> rem(n);
        long long ans = 0;
        for(long long i=0;i<n;i++)
        {
            cin>>goods[i];
            ans+=(goods[i]/k);
            rem[i]=goods[i]%k;
        }
        sort(rem.begin(),rem.end());
        long long l = 0,r=n-1;
        while(l<r)
        {
            if((rem[l]+rem[r])/k)
            {
                ans+=(rem[l]+rem[r])/k;
                l++;
                r--;
            }else
            {
                l++;
            } 
        }

        cout<<ans<<endl;
    }
    return 0;
}