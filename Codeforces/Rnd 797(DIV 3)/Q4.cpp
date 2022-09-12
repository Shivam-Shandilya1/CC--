#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int n,k;
        cin>>n>>k;
        vector<char> col(n);
        for(int i=0;i<n;i++)
        {
            cin>>col[i];
        }
        int ans;
        int cnt = 0;
        for(int i=0;i<k;i++)
        {
            if(col[i]=='W')cnt++;
        }
        ans = cnt;
        for(int i=0;i<n-k+1;i++)
        {
            ans = min(cnt,ans);
            if(col[i]=='W')cnt--;
            if(col[i+k]=='W')cnt++;
        }
        cout<<ans<<endl;
    }
    return 0;
}