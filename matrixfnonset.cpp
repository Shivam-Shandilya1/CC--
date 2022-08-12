#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
    ifstream file("input.txt");
    if(!file) 
  {
    cout<<"Error opening output file"<<endl;
    system("pause");
    return -1;
  }
  int elem,i=0,j;
  vector<vector<int>> v;
  vector<int> g1;
  
 while(file >> n)
 {
   if(i == 0){
     j = n;
     elem = n;
     i++;
   }else
   {
     g1.push_back(n);
     j--;
     if(j==0)
     {
       v.push_back(g1);
       g1.clear();
       j = elem;
     }
   }
 }
 bool one2one = true;
 bool onto = true;
 for(int i=0;i<v.size();i++)
 { 
   int sum = 0;
   for(int k:v[i])sum+=k;
   one2one = one2one && sum;
   if(sum!=0)
   {
     sum = 0;
   }
 }
 
 for(int i=0;i<v.size();i++)
 {
   int sum = 0;
   for(int k = 0;k<v.size();k++)sum+=v[k][i];
   onto = onto && sum;
   if(sum!=0)
   {
     sum = 0;
   }
 }

 cout<<one2one<<onto<<endl;
 if(one2one)
 {
   cout<<"function is one-one."<<endl;
 }
 if(onto)
 {
   cout<<"function is onto."<<endl;
 }
return 0;
}
