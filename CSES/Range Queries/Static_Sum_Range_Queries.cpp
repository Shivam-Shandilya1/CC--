#include<bits/stdc++.h>
using namespace std;

void build(int low,int high,int ind,vector<int> &v,vector<long long> &seg)
{
    if(low == high)
    {
        seg[ind] = v[low];
        return;
    }
    int mid = (high+low)>>1;
    build(low,mid,2*ind+1,v,seg);
    build(mid+1,high,2*ind+2,v,seg);
    seg[ind] = seg[2*ind+1]+seg[2*ind+2];
}

long long query(int ind,int low,int high,int l,int r,vector<int> &v,vector<long long> &seg)
{
    if(low>r || high<l)return 0;
    if(low>=l && high<=r)
    {
        return seg[ind];
    } 
    int mid = (high+low)>>1;
    long long sum1 = query(2*ind+1,low,mid,l,r,v,seg);
    long long sum2 = query(2*ind+2,mid+1,high,l,r,v,seg);
    return sum1+sum2;
}

int main()
{
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<long long> seg(4*n+1);
    build(0,n-1,0,v,seg);
    for(int i=0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        
        cout<<query(0,0,n-1,a-1,b-1,v,seg)<<endl;
    }
    return 0;
}