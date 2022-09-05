#include <bits/stdc++.h>
using namespace std;
int solve(int n,string s,vector<int> score,int i,int j)
{
    string tmp_str = s.substr(i,j-i+1);
    int mx = INT_MIN;
    for(int k=i;k<j;k++)
    {
        int tmp = solve(n,s,score,i,k)+solve(n,s,score,k+1,j);
        mx = max(tmp,mx);
    }
    return mx;
}
int main()
{
    int T;
    cin>>T;
    for(int t=0; t<T; t++)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int>score(n);
        for(int i=0; i<n; i++)cin>>score[i];
        cout<<solve(n,s,score,1,n);
    }
    return 0;
}