#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int t =0;t<T;t++)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(auto &it:v)cin>>it;
        int turn = 0;
        deque<int> q;
        for(int k:v)q.push_back(k);
        int sumA = 0,sumB = 0,prev=0,moves = 0;
        while(!q.empty())
        {
            int sum=0;
            while(sum<prev)
            {
                if(!turn)
                {
                    sum+=q.front();
                    q.pop_front();
                }else
                {
                    sum+=q.back();
                    q.pop_back();
                }
            }
            if(!turn)
            {
                sumA = sum;
            }else sumB = sum;
            turn = 1-turn;
            moves++;
            prev = sum;
        }
        cout<<moves<<endl;
        cout<<sumA<<endl;
        cout<<sumB<<endl;
    }
}