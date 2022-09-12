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
        vector<int> v(3,0);
        int p = n/3,r = n%3;
        v[0] = p-1;
        v[1] = p;
        v[2] = p+1;
        int i = 2;
        while(r)
        {
            v[i]++;
            r--;
            i--;
            if(i<0)i = 2;
        }
        cout<<v[1]<<" "<<v[2]<<" "<<v[0]<<endl;
    }
    return 0;
}