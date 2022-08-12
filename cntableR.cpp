#include <bits/stdc++.h>
using namespace std;

int noterms (int n,int a,int b);

int main()
{
    ifstream file ("input.txt");
    
    if(!file)
    {
    cout<<"Error opening output file"<<endl;
    system("pause");
    return -1;
    }
    int input;
    int a,b,i = 0,suminput = 0;
    while(file >> input){
      if(i == 0)a = input; 
      else b =input;
      i++;
      suminput+=input;
    }
    if(a%b==0 || b%a ==0)cout<<"Invalid Input"<<endl;
    i=2;
    int cnt = 0;
    while(i<=suminput)
    {
        cnt+=noterms(i,a,b);
        i++;
    }
    cout<<"Position: "<<cnt<<", Number: "<<a<<"/"<<b<<endl;
return 0;
}

int noterms (int n,int a,int b)
{
    if(n==2)return 1;
    int cnt = 0;
    if(n%2!=0)
    {
    for(int i = 1;i<n;i++){{
        if((n-i)%i == 0 || i%(n-i) == 0)
        {
            continue; 
        }else{
            if(n == a+b)
            {
                if(i == a)
                {
                    return cnt+2;
                }
            }
            cnt++;
        }
    }}        
    }
    else{
    for(int i = n-1;i>=1;i--){{
        if((n-i)%i == 0 || i%(n-i) == 0)
        {
            continue;
        }else{
            if(n == a+b)
            {
                if(i == a)
                {
                    return cnt+2;
                }
            }
            cnt++;
        }
    }} 
    }

    return cnt+2;
} 