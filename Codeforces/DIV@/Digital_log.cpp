#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main()
{
    long long T;
    cin>>T;
    for(long long t=0;t<T;t++)
    {
        long long n;
        cin>>n;
        long long ans = 0;
        vector<long long>a(n),b(n);
        map<long long,long long> ma,mb;
        for(long long i=0;i<n;i++)
        {
            cin>>a[i];
            ma[a[i]]++;
        }
        
        for(long long i=0;i<n;i++)
        {
            cin>>b[i];
            mb[b[i]]++;
        }
        // cout<<"long longITALIZING MAP A"<<endl;
        // for(auto x:ma)cout<<x.first<<" "<<x.second<<endl;
        // cout<<"long longITALIZING MAP B"<<endl;
        // for(auto x:mb)cout<<x.first<<" "<<x.second<<endl;

        for(auto x:ma)
        {
            long long p = x.first;
            
            long long mn = min(ma[p],mb[p]);
            
            ma[p]-=mn;
            mb[p]-=mn;
            
        }


        // cout<<"COMMON ELIMINATION:"<<endl;
        // cout<<"MAP A:"<<endl;
        // for(auto x:ma)cout<<x.first<<" "<<x.second<<endl;
        // cout<<"MAP B:"<<endl;
        // for(auto x:mb)cout<<x.first<<" "<<x.second<<endl;

        for(auto x:ma)
        {
            long long p = x.first;
            if(p>9)
            {
                long long new_num = log10(p)+1;
                ans+=ma[p];
                ma[new_num]+=ma[p];
                ma[p]=0;
            }
        }

        for(auto x:mb)
        {
            long long p = x.first;
            if(p>9)
            {
                long long new_num = log10(p)+1;
                ans+=mb[p];
                mb[new_num]+=mb[p];
                mb[p]=0;
            }
        }

        // cout<<"SINGLE TERM Converted"<<endl;
        // cout<<"MAP A"<<endl;
        // for(auto x:ma)cout<<x.first<<" "<<x.second<<endl;
        // cout<<"MAP B"<<endl;
        // for(auto x:mb)cout<<x.first<<" "<<x.second<<endl;

        for(auto x:ma)
        {
            long long p = x.first;
            long long mn = min(ma[p],mb[p]);
            ma[p]-=mn;
            mb[p]-=mn;
        }

        // cout<<"FINAL STANDING"<<endl;
        // cout<<"MAP A"<<endl;
        // for(auto x:ma)cout<<x.first<<" "<<x.second<<endl;
        // cout<<"MAP B"<<endl;
        // for(auto x:mb)cout<<x.first<<" "<<x.second<<endl;

        for(auto x:ma)if(x.first!=1)ans+=x.second;
        for(auto x:mb)if(x.first!=1)ans+=x.second;

        cout<<ans<<endl;

    }
    return 0;
}