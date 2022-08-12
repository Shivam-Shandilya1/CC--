#include <bits/stdc++.h>
using namespace std;
struct DisjointSets{
   int *parent, *rnk;
   int n;
   DisjointSets(int n){
      this->n = n;
      parent = new int[n+1];
      rnk = new int[n+1];
   for (int i = 0; i <= n; i++){
      rnk[i] = 0;
      parent[i] = i;
   }
}
int find(int u){
   if (u != parent[u]){
       parent[u] = find(parent[u]);
   }
   return parent[u];
}
void merge(int x, int y){
   x = find(x), y = find(y);
   if (rnk[x] > rnk[y])
      parent[y] = x;
   else
      parent[x] = y;
   if (rnk[x] == rnk[y])
      rnk[y]++;
   }
};
int kruskalMST(vector<pair<int,pair<int,int>>> edges,int V){
   int mst_wt = 0;
   sort(edges.begin(), edges.end());
   DisjointSets ds(V);
   vector< pair<int, pair<int,int>> >::iterator it;
   for (it=edges.begin(); it!=edges.end(); it++){
      int u = it->second.first;
      int v = it->second.second;
      int set_u = ds.find(u);
      int set_v = ds.find(v);
      if (set_u != set_v){
         
         mst_wt += it->first;
         ds.merge(set_u, set_v);
      }
   }
   return mst_wt;
}
int main()
{
    int n,vertices,cnt = 0;
    vector<int> matrices;
    vector<vector<int>> adjmatrices;
    ifstream file("input.txt");
    while(file >> n)
    {
        if(cnt == 0)
        {  
            vertices = n;
        }else
        {
            if(cnt%vertices!=0)
            {
                matrices.push_back(n);
            }else
            {
                matrices.push_back(n);
                adjmatrices.push_back(matrices);
                matrices.clear(); 
            }
        }
        cnt++;
    }
    vector<pair<int,pair<int,int>>> v;
    vector<int>v1;
    for(int i= 0;i<adjmatrices.size();i++)
    {
        for(int j=i;j<adjmatrices[i].size();j++)
        {
            if(adjmatrices[i][j]!=0)
            {
                v.push_back({adjmatrices[i][j],{i+1,j+1}});
            }
        }
    }
    cout<<kruskalMST(v,vertices);
    return 0;
}