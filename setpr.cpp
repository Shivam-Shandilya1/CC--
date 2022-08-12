#include <bits/stdc++.h>
using namespace std;

int main()
{
  int i = 0,t=-1;
  vector<int> v,v1;
  int word;
  ifstream myfile("input.txt");
  if(!myfile) 
  {
    cout<<"Error opening output file"<<endl;
    system("pause");
    return -1;
  }
  while(myfile >> word)
  {
    if(i == 0)
    {
        i = word;
        t++;
    }else
    {
        if(t==0)
        {
            v.push_back(word);
        }else
        {
            v1.push_back(word);
        }
        i--;
    } 
  }
  vector<int> v2;
  map<int,int> m;
  for(int k:v){
    m[k]++;
  }
  for(int k:v1){
    m[k]++;
  }
  cout<<"Ans 1(a): "<<endl;
  cout<<"Intersection of Set A and Set B:-"<<endl;
  for(auto it = m.begin();it!=m.end();it++)
  {
    if(it->second>1)
    {
      cout<<it->first<<" ";
      v2.push_back(it->first);
    }
    
  }
  cout<<endl;
  cout<<"Ans 1(b): "<<endl;
  cout<<"Union of Set A and Set B:-"<<endl;
  for(auto it = m.begin();it!=m.end();it++)
  {
    cout<<it->first<<" ";
  }
  cout<<endl;
  cout<<"Ans 1(c): "<<endl;
  cout<<"Difference between Set A and Set B (A-B):-"<<endl;
  for(int k:v2)  m.erase(k);
  for(int k:v1) m.erase(k);
  for(auto it = m.begin();it!=m.end();it++)
  {
    cout<<it->first<<" ";
  }
  cout<<endl;
}