#include <bits/stdc++.h>
using namespace std;
void dfs(string &s,string &cur,int i,int cnt)
{
    
    cur.append(1,'0');
    dfs(s,cur,i+1,cnt);
    cur.back()='1';
    dfs(s,cur,i+1,cnt+1);
    cur.pop_back();
}

bool valid(string &s,string &cur)
{
    int j=0;
    for(int i=0;i<s.size();i++) 
    {
        if(s[i]=='?')
        {
            s[i]=cur[j];
            j++;
        }
    }

}

bool checkPalindrome(string &s)
{
    for(int i=0;i<s.size();i++)
    {
        
    }
}

int main()
{
    int tno;
    cin>>tno;
    for(int i=0;i<tno;i++)
    {
        int len;
        cin>>len;
        string str;
        cin>>str;
        str.reserve(len);
        cout<<"Case #"<<i+1<<": ";

    }
return 0;
}