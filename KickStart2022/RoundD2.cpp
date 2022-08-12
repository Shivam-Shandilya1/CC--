#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b);
 
// To compute x raised to power y under modulo m
int power(int x, unsigned int y, unsigned int m);
 
// Function to find modular inverse of a under modulo m
// Assumption: m is prime
int modInverse(int a, int m)
{
    int g = gcd(a, m);
    if (g != 1)return -1;
    else
    {
        // If a and m are relatively prime, then modulo
        // inverse is a^(m-2) mode m
        
        return power(a, m - 2, m);
    }
}
 
// To compute x^y under modulo m
int power(int x, unsigned int y, unsigned int m)
{
    if (y == 0)
        return 1;
    int p = power(x, y / 2, m) % m;
    p = (p * p) % m;
 
    return (y % 2 == 0) ? p : (x * p) % m;
}
 
// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

bool fn(int l,int r,int k)
{
    bool f = false;
    while(l<r)
    {
        int mid = (l+r)/2;
        if(k<mid)
        {
            r = mid-1;
        }else if(k>mid)
        {
            l = mid+1;
        }else
        {
            f = true;
            return f;
        }
    }
    return f;
}
int main()
{
    vector<vector<int>> A={{2,9},{10,10},{10,12}};
    int cntt = 0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=A[i][0];j<=A[i][1];j++)
        {
            if(fn(A[i][0],A[i][1],j))
            {
                cntt++;
            }
        }
        
        int total = A[i][1]-A[i][0]+1;
        if(total%cntt==0)
        {
            total=total/cntt;
            cntt = 1;
        }

        
        cout<<(cntt*(1000000008)/total)<<endl;
    }
    return 0;
}