#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        unsigned long long N;
        cin>>N;
        priority_queue<unsigned long long,vector<unsigned long long>,greater<unsigned long long>> sides;
        for(unsigned long long i=0;i<N;i++)
        {
            unsigned long long p;
            cin>>p;
            sides.push(p);
        }
        unsigned long long cnt = 1;
        while(!sides.empty())
        {
            if(sides.top()>=cnt)
            {
                cnt++;
            }
            sides.pop();
        }
        cout<<"Case #"<<i+1<<": "<<cnt-1<<endl;
    }
    return 0;
}