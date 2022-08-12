
#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    bool DetectCycle(vector<vector<int>>& adj,vector<int>& visited,int v)
    {
        if(visited[v]==1)
            return true;
        if(visited[v]==2)
            return false;
        
        visited[v]=1;   
        for(int i=0;i<adj[v].size();++i)
            if(DetectCycle(adj,visited,adj[v][i]))
                return true;
        
        visited[v]=2;   
        return false;
    }
    
    
    bool detectCycle(vector<vector<int>>& adj,int n)
    {
        vector<int> visited(n,0);
        for(int i=0;i<n;++i)
            if(!visited[i])
                if(DetectCycle(adj,visited,i))
                    return true;
        return false;
    }
    
    
    void dfs(vector<vector<int>>& adj,int v,vector<bool>& visited,stack<int>& mystack)
    {
        visited[v] = true;
        for(int i=0;i<adj[v].size();++i)
            if(!visited[adj[v][i]])
                dfs(adj,adj[v][i],visited,mystack);
        
        mystack.push(v);
    }
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        int n=pre.size();
        vector<vector<int>> adj(num);
        
        for(int i=0;i<n;++i)
            adj[pre[i][1]].push_back(pre[i][0]);
        
        
        vector<int> ans;
        if(detectCycle(adj,num))
            return ans;        
        
        
        stack<int> mystack;
        vector<bool> visited(num,false);
        
        
        for(int i=0;i<num;++i)
            if(!visited[i])
                dfs(adj,i,visited,mystack);
        
        while(!mystack.empty())
        {
            ans.push_back(mystack.top());
            mystack.pop();
        }
        return ans;
    }
};
    int main()
    {
        ifstream file("input.txt");
        if(!file)
        {
            cout<<"Error opening output file"<<endl;
            system("pause");
            return -1;
        }
        int n, i=0,elem,cnt = 0;
        vector<int> v;
        vector<vector<int>> g;
        while(file >> n)
        {

            if(i == 0)
            {
                elem = n;
                i++;
            }else
            {
                v.push_back(n);
                cnt++;
                if(cnt == elem)
                {
                    g.push_back(v);
                    v.clear();
                    cnt = 0;
                }
            }
        }
        vector<vector<int>> g1;
        vector <int> v1;
        for(int i = 0 ;i< g.size();i++)
        {
            for(int j = 0;j<g[i].size();j++)
            {
                if((g[i][j] == 1) &&( i!=j))
                {
                    v1.push_back(i);
                    v1.push_back(j);
                    g1.push_back(v1);
                    v1.clear();
                }
            }
        }
        Solution S;
        vector<int> vec = S.findOrder(elem,g1);
        reverse(vec.begin(),vec.end());
        for(int i = 0;i<vec.size();i++)
        {
            
            cout<<vec[i]+1;
            if(i!=vec.size()-1)
            {
                cout<<"$";
            }
        }
        return 0;
    }
