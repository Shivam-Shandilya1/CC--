#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        string ans;
        for(int i=n-1;i>=0;i--)
        {
            int c = 96;
            int k = s[i]-'0';
            if(k!=0)
            {
                int p = c+k;
                ans.push_back((char)p);
            }else
            {
                i--;
                int p1 = s[i]-'0';
                i--;
                p1 += (s[i]-'0')*10;
                p1+=c;
                ans.push_back((char)p1);
            }
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
    return 0;
}