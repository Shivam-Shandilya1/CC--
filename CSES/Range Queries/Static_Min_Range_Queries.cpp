#include<bits/stdc++.h>
using namespace std;

void build(int ind,int low,int high,vector<int> &v,vector<int> &seg)
{
    if(low==high)
    {
        seg[ind]=v[low];
        return;
    }

    int mid = (low+high)>>1;
    build(2*ind+1,low,mid,v,seg);
    build(2*ind+2,mid+1,high,v,seg);
    seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
}

int query(int ind,int low,int high,int l,int r, vector<int> &v, vector<int> &seg)
{
    if(low>r || high<l)return INT_MAX;
    if(low>=l && high<=r)return seg[ind];
    int mid = (low+high)>>1;
    int mn1 = query(2*ind+1,low,mid,l,r,v,seg);
    int mn2 = query(2*ind+2,mid+1,high,l,r,v,seg);
    return min(mn1,mn2);
}
int main()
{
    int n,q;
    cin>>n>>q;

    vector<int> v(n);

    for(int i=0;i<n;i++)cin>>v[i];
    
    vector<int> seg(4*n+1);
    build(0,0,n-1,v,seg);
    for(int i=0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<query(0,0,n-1,a-1,b-1,v,seg)<<endl;
    }

    return 0;
}