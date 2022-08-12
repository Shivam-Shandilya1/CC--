#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
int main()
{
    ull t;
    cin >> t;
    for (ull tc = 1; tc <= t; ++tc) 
    {
        ull res = 0,cnt = 0,N=0,D=0,k = 0,p=0,start = 0,end,maxend = 0,maxstart = 0,maxcnt = 0;
        vector<ull> v,v1;
        cin>>N>>D;
        for(ull i = 0;i<N;i++)
        {
            ull in;
            cin>>in;
            v.push_back(in);
        }
        k = v[0];
        
        for(ull i = 0;i<N;i++)
        {
            if(v[i] == k)cnt++;
            else
            {
                if(p==0)
                {
                    while(v[i]!=k)
                    {
                        cnt++;
                        i++;
                    }  
                    p++;
                    i--;
                }
                else
                {
                end = i;
                if(maxcnt<cnt)
                {
                    maxstart = start;
                    maxend = i;
                    for(ull j=maxstart;j<maxend;j++)
            {
                res++;
                v[j] = k;
            }
            
                }
                cnt = 1;
                start = i;
                k = v[i];
                }
            }
        }
        cout<<"Case #"<<tc<<": "<<res<<endl;
    }
    return 0;
}