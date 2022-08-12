#include <bits/stdc++.h>
using namespace std;
typedef long long ull;

int main()
{
    ull t;
    cin >> t;
    for (ull tc = 1; tc <= t; ++tc) 
    {
        ull N,P;
        cin>>N>>P;
        ull T = 0;
        ull res = 0; 
        priority_queue<ull,vector<ull>,greater<int>> q;
        
        for(ull i = 0; i < N; i++)
        {
            
            for(ull j = 0; j < P;j++)
            {
                ull k;
                cin>>k;
                
                q.push(k);
                cout<<q.top()<<" ";
            }
            cout<<endl;

            while(!q.empty())
            {
                if(q.top()>T)
                {
                    res+=(q.top()-T);
                    T = q.top();
                }else if(q.top()<T)
                {
                    res+=(T-q.top());
                    T = q.top();
                }
                q.pop();
            }
            
            cout<<res<<endl;
        }
        cout<<"Case #"<<tc<<": "<<res<<endl;
    }
    return 0;
}