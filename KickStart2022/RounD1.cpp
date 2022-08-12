#include <bits/stdc++.h>
using namespace std;
int helper(int Ns,int N, vector<int> &A,int Ms,int M, vector<int> &B,int K)
{
    if(N<=Ns || M<=Ms || K<=0)
    {
        return 0;
    }
    
    return max({helper(Ns,N-1,A,Ms,M,B,K-1)+A[N-1],helper(Ns,N,A,Ms,M-1,B,K-1)+B[M-1],helper(Ns+1,N,A,Ms,M,B,K-1)+A[Ns],helper(Ns,N,A,Ms+1,M,B,K-1)+B[Ms]});
}
int main()
{
    int T;
    cin>>T;
    for(int tc= 0; tc<T; tc++)
    {
        int N;
        cin>>N;
        vector<int> A;
        for(int i=0;i<N;i++)
        {
            int p;
            cin>>p;
            A.push_back(p); ;
        }
        
        int M;
        cin>>M;
        vector<int> B;
        for(int i=0;i<M;i++)
        {
            int p;
            cin>>p;
            B.push_back(p); ;
        }

        int K;
        cin>>K;
        cout<<"Case #"<<tc+1<<": "<<helper(0,N,A,0,M,B,K)<<endl;
    }
    return 0;
}