#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;

    vector<int> ans(n);
    ans[0]=1;

    for(int i=1;i<n-1;i++)
    {
        if(s[i]==s[i-1])
        {
            ans[i] = ans[i-1];
        }else
        {
            ans[i] = i+1;
        }
    }

    for(int i=0;i<ans.size()-1;i++)cout<<ans[i]<<" ";
    cout<<endl;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}