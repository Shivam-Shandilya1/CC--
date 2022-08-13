#include<bits/stdc++.h>
using namespace std;

void store(map<int,int> &v1,vector<int> &v,int n,int sum)
{
    if(n<=0)
    {
        v1[sum]++;
        return;
    }
    
    store(v1,v,n-1,sum+v[n-1]);
    store(v1,v,n-1,sum);
}

int main() 
{
    int n,x;
    cin>>n>>x;

    int sz1 = n/2,sz2 = n-n/2;

    vector<int> v1(sz1);
    vector<int> v2(sz2);

    for(int i=0;i<sz1;i++)cin>>v1[i];
    for(int i=0;i<sz2;i++)cin>>v2[i];

    vector<long long> sum1,sum2;
    for(int i=0;i<(1<<sz1);i++)
    {
        long long sum = 0;
        for(int j=0;j<sz1;j++)
        {
            if(i && (1<<j))
            {
                sum+=v1[j];
            }
        }
        sum1.push_back(sum);
    }

    for(int i=0;i<(1<<sz2);i++)
    {
        long long sum = 0;
        for(int j=0;j<sz2;j++)
        {
            if(i && (1<<j))
            {
                sum+=v2[j];
            }
        }
        sum2.push_back(sum);
    }

    sort(sum1.begin(),sum1.end());
    sort(sum2.begin(),sum2.end());

    long long ans = 0;
    for(long long s:sum1)
    {
        ans+= upper_bound(sum2.begin(),sum2.end(),x-s)-lower_bound(sum2.begin(),sum2.end(),x-s);
    }

    cout<<ans<<endl;
    return 0;
}