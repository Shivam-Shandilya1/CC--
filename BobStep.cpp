#include <bits/stdc++.h>
using namespace std;
long long int factorial(int n);
long long int nCr(int n,int r);
int main()
{
    int fw,step;
    ifstream myfile("input.txt");
  if(!myfile) 
  {
    cout<<"Error opening output file"<<endl;
    system("pause");
    return -1;
  }
  while(myfile >> fw){
      step = fw;
  }
  if(step<0)cout<<"Invalid Input"<<endl;
  
  cout<<"Ans 2: Bob's new house has "<<step<<" stairs."<<endl;
  int n = step;
  int r = step;
  long long int sum = 0;
  while(r>=0) {
      sum+= nCr(n,r);
      n--;
      r-=2;
  } 
  if(step == 0)sum=0;
  cout<<"The Number of ways in which Bob can reach the Top = "<<sum<<endl;
}

long long int factorial(int n)
{
    return (n!=0)?n*factorial(n-1):1;
}

long long int nCr(int n,int r)
{
    return (factorial(n)/(factorial(r)*factorial(n-r)));
}