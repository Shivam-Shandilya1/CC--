#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    bool flag = true;
    cin>>T;
    
    for(int i=0;i<T;i++)
    {
        unsigned long long C = INT_MAX,M = INT_MAX,Y = INT_MAX,K = INT_MAX;
        
        unsigned long long minC = INT_MAX,minM=INT_MAX,minY=INT_MAX,minK=INT_MAX;
        flag = true;
        unsigned long long FC = 1000000,AC=FC;
        for(int j=0;j<3;j++)
        {
            AC = 0;
            cin>>C>>M>>Y>>K;
            
            minC = (minC>=C)?C:minC;
            minM = (minM>=M)?M:minM;
            minY = (minY>=Y)?Y:minY;
            minK = (minK>=K)?K:minK;
            AC = C+M+Y+K;
            if(AC < FC)flag = false;
        }
        unsigned long long sum = 0;
        sum += (minC+minM+minY+minK);

        if(sum<1000000)flag = false;
        cout<<"Case #"<<i+1<<": ";
        if(flag)
        {
            if(sum==1000000)cout<<minC<<" "<<minM<<" "<<minY<<" "<<minK<<endl;
            else
            {
                unsigned long long ans = 0;
                if(ans<1000000)
                {
                    ans+=minC;
                    if(ans<1000000)cout<<minC<<" ";
                    else cout<<1000000-(ans-minC)<<" ";
                }else
                {
                    cout<<1000000-ans<<" ";
                }
                if(ans<1000000)
                {
                    ans+=minM;
                    if(ans<1000000)cout<<minM<<" ";
                    else cout<<1000000-(ans-minM)<<" ";
                }else
                {
                    cout<<"0 ";
                }
                if(ans<1000000)
                {
                    ans+=minY;
                    if(ans<1000000)cout<<minY<<" ";
                    else cout<<(1000000-(ans-minY))<<" ";
                }
                else
                {
                    cout<<"0 ";
                }
                if(ans<1000000)
                {
                    ans+=minK;
                    if(ans<1000000)cout<<minK<<" ";
                    else cout<<1000000-(ans-minK)<<" ";
                }else
                {
                    cout<<"0 ";
                }
                cout<<endl;
            }
        }
        else cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}