#include <bits/stdc++.h>
using namespace std;
int solve(string s)
{
    int cnt = 0;
    for(int i=0;i<s.size();i++)
    {
          if((s[i]>'a' &&  s[i]<'z') || (s[i]>'A' &&  s[i]<'Z') || (s[i]>'0' &&  s[i]<'9'))
          {
            while((s[i]>'a' &&  s[i]<'z') || (s[i]>'A' &&  s[i]<'Z') || (s[i]>'0' &&  s[i]<'9'))
            {
                i++;
            }
            cnt++;
          }
    }
    return cnt;
}
int main()
{
    string s = "  This   is a Test .  Okay!";
    
    cout<<solve(s);
    return 0;
}
