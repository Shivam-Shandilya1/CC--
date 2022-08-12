#include<bits/stdc++.h>
using namespace std;

void build(int ind,int low,int high,vector<int> &v, vector<long long> &seg)
{
    if(low==high)
    {
        seg[ind] = v[low];
        return;
    }

    int mid = (low+high)>>1;
    build(2*ind+1,low,mid,v,seg);
    build(2*ind+2,mid+1,high,v,seg);
    seg[ind] = seg[2*ind+1]+seg[2*ind+2];
}

long long query(int ind,int low,int high,int l,int h,vector<int> &v,vector<long long> &seg)
{
    if(low>h || high<l)return 0;
    if(low>=l && high<=h) return seg[ind];
    int mid = (high+low)>>1;
    long long sum1 = query(2*ind+1,low,mid,l,h,v,seg);
    long long sum2 = query(2*ind+2,mid+1,high,l,h,v,seg);
    return sum1+sum2;
}

void update(int ind,int i,int val,int low,int high,vector<int> &v,vector<long long> &seg)
{
    if(low==high)
    {
        seg[ind] = val;
        return;
    }

    int mid = (high+low)>>1;

    if(i<=mid)
    {
        update(2*ind+1,i,val,low,mid,v,seg);
    }else
    {
        update(2*ind+2,i,val,mid+1,high,v,seg);
    }
    seg[ind] = seg[2*ind+1]+seg[2*ind+2];
}

int main()
{
    int n,q;

    cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];

    vector<long long> seg(4*n+1);
    build(0,0,n-1,v,seg);

    for(int i=0;i<q;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==2)
        {
            cout<<query(0,0,n-1,b-1,c-1,v,seg)<<endl;
        }else
        {
            update(0,b-1,c,0,n-1,v,seg);
        }
    }
    return 0;
}