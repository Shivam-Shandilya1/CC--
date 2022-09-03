#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int t = 0;t<T;t++)
    {
        int n;
        cin>>n;
        vector<int> v;
        int i=0;
        while(n)
        {
            int r = n%10;
            n/=10;
            if(r)v.push_back(r*pow(10,i));
            i++;
        }
        cout<<v.size()<<endl;
        for(int k:v)cout<<k<<" ";
        cout<<endl;
    }
    return 0;
}