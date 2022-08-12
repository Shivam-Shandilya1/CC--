#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S,F;
    int TestCaseCount;
    cin>>TestCaseCount;
    for(int i=0;i<TestCaseCount;i++)
    {
        int sum = 0,minm = INT_MAX;
        cin>>S>>F;
        for(int j=0;j<S.size();j++)
        {
            for(int k=0;k<F.size();k++)
            {
                int l,t,tl;
                if((int)S[j]<=(int)F[k]){
                    t = (int)S[j]+26;
                    tl = (int)F[k];
                }else
                {
                    t = (int)F[k]+26;
                    tl = (int)S[j];
                }
                l = min(abs(t-tl),abs(S[j]-F[k]));
               
                if(minm>=l)
                {
                    minm = l;
                }
            }
            sum+=minm;
            minm = INT_MAX;
        }
        cout<<"Case #"<<i+1<<": "<<sum<<endl;
        sum = 0;
        
    }
return 0;
}