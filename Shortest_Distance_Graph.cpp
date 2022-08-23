#include <bits/stdc++.h>

using namespace std;

void BFS(int V,vector<vector<int>> adj[],vector<int> &visited,int i)
{
    visited[i] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,i});
    while(!q.empty())
    {
        auto it = q.top();
        q.pop();
        for(vector<int> v:adj[it.second])
        {
            if(visited[v[0]]>visited[it.second]+v[1])
            {
                visited[v[0]] = visited[it.second]+v[1];
                q.push({visited[v[0]],v[0]});
            }
        }
    } 
}

vector<int> Shortest_Distance(int V,vector<vector<int>> adj[])
{
    vector<int> visited(V,INT_MAX);
    int src;
    cin>>src;

    BFS(V,adj,visited,src);
    

    return visited;
}

int main() 
{
    int V;
    cin>>V;

    vector<vector<int>> adj[V];

    int E;
    cin>>E;

    for(int i=0;i<E;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    vector<int> ans;
    ans = Shortest_Distance(V,adj);

    for(int i=0;i<ans.size();i++)
    {
        cout<<i<<": "<<ans[i]<<endl;
    }
    return 0;
}