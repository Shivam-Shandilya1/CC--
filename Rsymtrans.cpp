#include <bits/stdc++.h>
using namespace std;
int main()
{
ifstream file("input.txt");
if(!file)
{
    cout<<"Error opening output file"<<endl;
    system("pause");
    return -1;
}
vector <vector<int>> v;
vector<int> g1;
int n,i=0,j,elem;
while(file >> n)
  {
      if(i == 0)
      {
          j=n;
          elem=n;
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
  map<int,vector<int>> m;
  for(int i=0;i<elem;i++)
  {
      for(int j=0;j<elem;j++)
      {
          if(v[i][j]==1)
          {
              m[i].push_back(j);
          }
          
      }
     
  }

bool antisym =true;
for(int i = 0; i < elem; i++)
{
    for(int j = 0; j<elem;j++)
    {
        if(i!=j)
        {
            if(v[i][j]==1)
            {
                if(v[i][j]==v[j][i])
                {
                    antisym = false;
                    break;
                }
            }
            
        }
    }
    if(!antisym){
        break;
    }
}
cout<<antisym<<endl;
if(antisym)cout<<"Relation is Anti-Symmetric.\n";
bool transitive;
if(elem!=0)
{
     transitive= true;
}
else 
{
    transitive = false;
}
for(auto it = m.begin(); it!=m.end();it++)
{
    
    for(int i = 0;i<it->second.size();i++)
    {
        
        for(int k:m[it->second[i]])
        {
            
            if(count(it->second.begin(),it->second.end(),k))
            {
                
                continue;
            }else
            {
                transitive = false;
                break;
            }
        }
        if(!transitive)
        {
            break;
        }
        
    }
    if(!transitive)
        {
            break;
        }
}
cout<<transitive<<endl;
if(transitive) cout<<"Relation is Transitive.\n";
return 0;
}