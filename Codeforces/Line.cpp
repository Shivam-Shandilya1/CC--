#include <bits/stdc++.h>
using namespace std;

long long solve(string s,long long k,long long &l,long long &r,long long &sum)
{
    long long mid = (l+r)>>1;
    while(k>0 && l<=mid && r>=mid) 
    {
        long long k1 = l,k2 = s.size()-1-r;

        while(l<=mid && s[l]!='L')
        {
            l++;
        }

        k1 = s.size()-1-l;

        while(r>=mid && s[r]!='R')
        {
            r--;
        }

        k2 = r;

        if(k1>=k2)
        {
            sum-=l;
            sum+=(k1);
            k--;
            l++;
        }else
        {
            sum-=(s.size()-1-r);
            sum+=(k2);
            k--;
            r--;
        }
    }

    // while(l<=mid && k>0)
    // {
    //     sum-=l;
    //     sum+=(s.size()-1-l);
    //     k--;
    //     l++;
    // }
    // while(r>=mid && k>0)
    // {
    //     sum-=(s.size()-1-r);
    //     sum+=r;
    //     k--;
    //     r--;
    // }
    return sum;
}

int main()
{
    long long T;
    cin>>T;
    for(long long t = 0;t<T;t++)
    {
        long long n;
        cin>>n;
        string s;
        cin>>s;
        vector<long long> ans;
        long long sum=0;
        for(long long i=0;i<n;i++)
        {
            if(s[i]=='L')
            {
                sum+=i;
            }else
            {
                sum+=(n-1-i);
            }
            
        }
        
        long long l = 0,r = s.size()-1;
        for(long long k = 1;k<=n;k++)
        {

            ans.push_back(solve(s,1,l,r,sum));
        }

        for(long long k:ans)cout<<k<<" ";
        cout<<endl;
    }
    return 0;
}