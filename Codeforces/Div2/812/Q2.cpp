#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int n,x,y;
        cin>>n>>x>>y;
        if((x==0 && y==0)||(x!=0 && y!=0)||((n-1)%max(x,y)>min(x,y)))
        {
            cout<<-1<<endl;
            continue;
        }else
        {
            int p = max(x,y),q=1;
            for(int i=1;i<=n-1;i++)
            {
                if(p==0)
                {
                    q=i+1;
                    p = max(x,y);
                }
                cout<<q<<" "; 
                p--;
            } 
            cout<<endl;  
        }
    }
    return 0;
}