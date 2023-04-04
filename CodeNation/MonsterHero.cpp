#include<bits/stdc++.h>
using namespace std;

void dfs(int src,vector<int> cost[],vector<int> adj[],int n,vector<int> &tax,vector<int> &vis,int comingFrom)
{
    for(auto it:adj[src])
    {
        if(comingFrom == -1)
        {
            cost[src][0] = mn,   
        }
    }
}

int main()
{
    int A = 3;

    vector<int> B[2] = {{1,2},{1,3}};
    vector<int> C[2] = {{1,3},{1,2}};
    vector<int> D = {2,2,8};
    vector<int> adj[3];

    for(vector<int> v:B)adj[v[0]].push_back(v[1]);

    vector<int> cost[2];
    vector<int> vis(3,0);
    dfs(1,cost,adj,A,D,vis,-1);
    return 0;
}