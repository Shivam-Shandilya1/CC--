#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tno;
    cin>>tno;
    for(int i=0;i<tno;i++)
    {
        unsigned long long p,q;
        cin>>p>>q;
        cout<<"Case #"<<i+1<<": ";
        unsigned long long cnt = 0;
        for(unsigned long long j=p;j<=q;j++){
            unsigned long long k=j,pro=1,sum=0;
            while(k>0 && pro!=0)
            {    
                pro*=(k%10); 
                sum+=(k%10);
                k/=10;
            }
            if(sum==0 || pro==0)cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}