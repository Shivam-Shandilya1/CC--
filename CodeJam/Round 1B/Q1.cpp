#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main()
{
    ull t;
    cin >> t;
    for (ull tc = 1; tc <= t; ++tc) 
    {
        deque<ull> q;
        ull N;
        cin>>N;
        for(ull j = 0; j < N; j++)
        {
            ull k;
            cin>>k;
            q.push_back(k);
        }
        
        ull maxm = 0,res = 0;
        while(q.size()!=0)
        {
            if(q.front()<q.back())
            {
                if(maxm<=q.front())
                {
                    maxm = q.front();
                    res++;
                }
                q.pop_front();
            }else
            {
                if(maxm<=q.back())
                {
                    maxm = q.back();
                    res++;
                }
                q.pop_back();                
            }
        }
        cout<<"Case #"<<tc<<": "<<res<<endl;
    }
    return 0;
}