#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int n,k;
        cin>>n>>k;
        int cnt = k/(n-1);
        int rem = k%(n-1);
        if(rem==0)
        {
            cout<<n*(cnt-1)+n-1<<endl;
        }
        else
        {
            cout<<n*(cnt)+rem<<endl;
        }
    }
    return 0;
}