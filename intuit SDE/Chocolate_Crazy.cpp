#include<bits/stdc++.h>
using namespace std;

bool isprime(int n)
{
    if(n==1)return false;
    int i = 2;
    while(i<=sqrt(n))
    {
        if(n%i==0)return false;
        i++;
    }
    return true;
}
int dif_prime(int n)
{
    if(n<=1)return 2-n;
    int prime = n;
    bool found = false;
    while(!found)
    {
        prime++;
        if(isprime(prime))found = true;
    }

    return prime-n;
}
int cnt_prime(int n)
{
    int count = 0;
    for(int i=1;i<n;i++)
    {
        if(isprime(i)==true)
        {
            count++;
        }
    }
    return count;
}

long long special_move(int n)
{
    if(isprime(n))
    {
        int pr_cnt = cnt_prime(n);
        int nxt_pr = dif_prime(n);
        int sum = pr_cnt+nxt_pr;

        int stp = 0;
        
        while(true)
        {
            stp+=(sum%10);
            sum/=10;
            if(stp<10 && sum==0)break;
            if(sum==0)
            {
                sum = stp;
                stp = 0;
            }
        }
        return stp;
    }

    return INT_MAX;
}

long long solve(int N,int L,int M,vector<bool> &mine,int indx,int cnt)
{
    cout<<"Indx:"<<indx<<endl;
    if(indx>N || indx<=0)return INT_MAX;
    if(indx==N)return cnt;
    long long x = solve(N,L,M,mine,indx+1,cnt+1);
    cout<<"X:"<<x<<endl;
    long long y = solve(N,L,M,mine,indx+2,cnt+1);
    cout<<"Y:"<<y<<endl;
    long long z = special_move(indx);
    long long s = solve(N,L,M,mine,indx+z,cnt+1);
    cout<<"S:"<<s<<endl;
    
    return min({x,y,s});
}

int main()
{
    int N;
    cin>>N;
    int L;
    cin>>L;
    int M;
    cin>>M;
    vector<bool> mine(N+1,0);
    vector<int> mines(M,0);
    for(int i=0;i<M;i++)
    {
        cin>>mines[i];
        mine[mines[i]]=1;
    }
    cout<<special_move(3)<<endl;
    cout<<solve(N,L,M,mine,1,0)<<endl;
    return 0;
}