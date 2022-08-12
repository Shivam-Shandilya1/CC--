#include <bits/stdc++.h>
using namespace std;
bool comp(pair<long long,long long> &a,pair<long long,long long> &b)
{
    return(a.second+a.first>b.second+b.first);
}

int main()
{
    long long n,r;
    cin>>n>>r;
    vector<pair<long long,long long>> pos,neg;

    for(long long i = 0; i < n; i++)
    {
        long long p,q;
        cin>>p;
        cin>>q;
        if(q>=0)pos.push_back({p,q});
        else
        {
            p = max(p,abs(q));
            neg.push_back({p,q});
        }
    }

    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end(),comp);

    long long j = 0;

    while(r>=pos[j].first)
    {
        r+=pos[j].second;
        j++;
    }
    if(j<pos.size())
    {
        cout<<"NO"<<endl;
        return 0;
    }
    j=0;
    while(r>=neg[j].first)
    {
        r+=neg[j].second;
        j++;
    }
    if(j<neg.size())
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    return 0;
}