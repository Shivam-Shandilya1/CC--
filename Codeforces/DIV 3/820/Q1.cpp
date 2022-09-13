#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int x = a-1;
        int y = abs(b-c)+(c-1);
        if(x<y)cout<<1<<endl;
        else if(x==y)cout<<3<<endl;
        else cout<<2<<endl;
    }
    return 0;
}