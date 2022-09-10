#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int n;
        cin>>n;
        if(n%2==0)
        {
            for(int i=n-2;i>=1;i--)
            {
                cout<<i<<" ";
            }
            cout<<n-1<<" "<<n<<endl;
        }else
        {
            cout<<1<<" "<<2<<" "<<3<<" ";
            for(int i=n-2;i>=4;i--)
            {
                cout<<i<<" ";
            }   
            cout<<n-1<<" "<<n<<endl;
        }
    }
    return 0;
}