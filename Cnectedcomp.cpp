#include <bits/stdc++.h>
#include <sstream>
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
    int cnt = 0,vertix=0,index=1;
    map<int,vector<int>> m;
    vector<vector<int>> vec;
    vector<int> v;
    while(file >> n)
    {
        if(cnt == 0)
        {
            vertix = n;
        }else{
            if(cnt%vertix!=0)
            {
                v.push_back(n);
            }else{
                v.push_back(n);
                vec.push_back(v);
                v.clear();
            }
        }
        cnt++;
    }
    for(int i = 0;i<vec.size();i++)
    {
        for(int j = 0;j<vec[i].size();j++)
        {
            if(vec[i][j] == 1)
            {
                v.push_back(j+1);
            }
        }
        m.insert({i+1,v});
        v.clear();
    }
    
    vector<bool> visited (vertix,false);
    vector<bool>prev(vertix,false);
    stack<int> s;
    s.push(1);
    int top;
    int count = 1;
    int cntcomp = 0;
    bool completed = false;
    string str;
    string str2;
   while(!completed)
   {
       completed = true;
        while(s.size()!=0)
    {
        
        top = s.top();
        
        if((visited[top-1] == true))
        {
            while(visited[s.top()-1] == true)
            {
                
               s.pop();
               if(s.empty())break;
            }
            
        }else
        {
            s.pop();
            visited[top-1]=true;
            for(int i = 0;i<m[top].size();i++)
            {
                s.push(m[top][i]); 
            }
        }
       count++;
    } 
    int t= 0;
    str2.append("$");
    for(int i = 0;i<visited.size();i++)
    {
        completed = completed&&visited[i];
    }
    
    for(int i = 0;i<visited.size();i++)
    {
        
        if(visited[i] == false && t==0)
        {
            s.push(i+1);
            t++;
        }
        if(visited[i] == true)
        {
            if(prev[i]==false)
            {
                str2.append("$"+to_string(i+1));
            }
            prev[i] = true;
        }
        
        str.append(str2);
        str2.clear();
    }
    
    
    cntcomp++;
    
   
   }
    cout<<cntcomp<<str<<endl;
    return 0;
}