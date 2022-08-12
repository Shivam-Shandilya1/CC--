#include <bits/stdc++.h>
using namespace std;
 
vector<int> visited;
void dfs(int i, int k, map<int, vector<int>> m,vector<int> A, vector<bool> vis,int &ans, vector<int>& path)
{
 
    if(vis[i])return;
    
    vis[i] = true;
    
    path.push_back(i);
 
    // Traverse for all children
    for (int j : m[i]) {
      if(A[i]==k) ans++;
      
       if(A[j]<=k)dfs(j,k,m,A,vis,ans, path);
       
    }
    
}
 
 
int countSpecialPaths(int N,vector<vector<int>> &edges,vector<int> &A)
{
    return 0;
} 
// Driver code
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    for(int t_i = 0; t_i<T;t_i++)
    {
        int N;
        cin>>N;
        vector<vector<int>> edges(N-1,vector<int>(2));
        for(int i_edges = 0;i_edges<N-1;i_edges++)
        {
            for(int j_edges = 0; j_edges<2;j_edges++)
            {
                cin>>edges[i_edges][j_edges];
            }
        }
        map<int,vector<int>> m;
        for(int i=0;i<edges.size();i++)
        {
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }
        for(auto it:m)
        {
            cout<<it.first<<": ";
            for(int i:it.second)
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }
        vector<int> A(N+1);
        for(int i_A = 0; i_A<N;i_A++)
        {
            cin>>A[i_A+1];
        }

        // long long out_;
        int ans = 0;
        vector<bool> vis(N+1,false);
        cout<<" -------"<<endl;
        for(int i=1;i<=N;i++)
        {
            vector<int> path;
            dfs(i,A[i],m,A,vis,ans, path);
            vis.clear();
            for(int l: path) cout<< l<<" ";
            cout<<endl;
            path.clear();
         
        }
        cout<<ans<<endl;
        
        // out_ = countSpecialPaths(N,edges,A);
        cout<<"\n";
    }
    return 0;
}