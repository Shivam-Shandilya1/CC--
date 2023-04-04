#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &v,int i,int sum,int cnt)
{
    if(i<=0)
    {
        if(cnt == 0)return 0;
        if(sum%cnt==0)return 1;
        return 0;
    }
    return solve(v,i-1,sum+v[i-1],cnt+1)+solve(v,i-1,sum,cnt);
}
int main()
{
    vector<int> v= {4,5};
    int n = v.size();
    cout<<"Ans: ";
    cout<<solve(v,n,0,0)<<endl;
    return 0;
}
