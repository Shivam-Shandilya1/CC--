#include <bits/stdc++.h>
using namespace std;

int solve(string s,int n,int x)
{
    priority_queue<int> q;
    int ans = 0;
    int tmp = 0;
    for(char c:s)
    {
        if(c=='1')
        {
            if(tmp)
            {
                q.push(tmp);
                tmp = 0;
            }
            ans++;
        }
        else
        {
            tmp++;
        }
        
    }

    while(!q.empty() && x)
    {
        if(x>=(2*q.top()+1))
        {
            x-=(2*q.top()+1);
            ans+=q.top();
            q.pop();
        }else
        {
            int k = q.top()-1;
            q.pop();
            q.push(k);
        }
    }

    return ans;
}

int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int N,X;
        cin>>N>>X;
        string S;
        cin>>S;
        cout<<solve(S,N,X)<<endl;
    }
    return 0;
}