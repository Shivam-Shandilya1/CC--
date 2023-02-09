// #Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.
// # The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).
// #graph = [[1,2],[3],[3],[]]
// #Output: [[0,1,3],[0,2,3]]
#include <bits/stdc++.h>
using namespace std;

// To execute C++, please define "int main()"

//paths:{0,1,3}
//p:{0,1}
void dfs(vector<vector<int>> &adj,vector<vector<int>> &paths,vector<int> &p, int src, int dest)
{
  p.push_back(src);
  
  if(src==dest)
  {
    paths.push_back(p);
    return;
  }

  for(int j:adj[src])
  {
    dfs(adj,paths,p,j,dest);
    p.pop_back();
  }
}
void solve(vector<vector<int>> &adj)
{
  int V = adj.size(); //4
  vector<vector<int>> paths;
  vector<int> p;
  dfs(adj,paths,p,0,V-1); //src: 0 dest: 3

  for(vector<int> v:paths)
  {
    for(int k:v)
    {
      cout<<k<<" ";
    }
    cout<<endl;
  }
  //0//3
}

int main() {
  int V; // Vertices
  cin>>V;
  vector<vector<int>> adj={{1,2},{3},{3},{}};

  solve(adj);  

  return 0;
}
