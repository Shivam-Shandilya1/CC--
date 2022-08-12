#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main()
{
    int T,N;
    vector<ull> AN1,AN2;
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>> N;
        for(int j = 0; j < N; j++)
        {
            ull k;
            cin>>k;
            AN1.push_back(k);
        }
        for(int j = 0; j < N; j++)
        {
            ull k;
            cin>>k;
            AN1.push_back(k);
        }
        int sum = 0;
        sort(AN1.begin(),AN1.end());
        ull s1=0,s2 =AN1.size()-1;
        
    }

    return 0;
}