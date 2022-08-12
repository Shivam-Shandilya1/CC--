#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
bool checkPalindrome(ull A)
{
    ull n = 0,rev = 0,digit = 0;
    n=A;
    
    do
    {
        digit = A%10;
        rev = (rev*10)+digit;
        A/=10;
    }while(A!=0);
    
    return n == rev;
}
int main()
{
    ull t;
    cin >> t;
    for (ull tc = 1; tc <= t; ++tc) 
    {
        ull cnt = 0;
        ull A;
        cin>>A;
        
        for(ull f = 1;f<=sqrt(A);f++)
        {
            if(A%f==0)
            {
                if(checkPalindrome(f))
                {
                    cnt++;
                }
                if(f!=(A/f) && checkPalindrome(A/f))
                {
                    cnt++;
                }
            }
        }
        cout<<"Case #"<<tc<<": "<<cnt<<endl;
    }
    return 0;
}