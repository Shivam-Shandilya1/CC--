#include <bits/stdc++.h>
using namespace std;
void printLevels(vector<int> graph[], int V, int x)
{
    
    int level[V];
    bool marked[V];
  
     
    queue<int> que;
  
    
    que.push(x);
  
    
    level[x] = 0;
  
    
    marked[x] = true;
  
    
    while (!que.empty()) {
  
       
        x = que.front();
  
        
        que.pop();
  
        
        for (int i = 0; i < graph[x].size(); i++) {
            
            int b = graph[x][i];
  
            
            if (!marked[b]) {
  
               
                que.push(b);
  
                
                level[b] = level[x] + 1;
  
                
                marked[b] = true;
            }
        }
    }
  
    
    for (int i = 0; i < V; i++)
    {
        cout << level[i];
        if(i!=V-1)
        {
            cout<<"$";
        }
    }
        
        cout<<endl;
}
int main()
{
ifstream file("input.txt");
int n,cnt = 0,vertices,root;
    if(!file)
    {
        cout<<"Error opening output file"<<endl;
        system("pause");
        return -1;
    } 
    vector<vector<int>> adjmatrices;
    vector<int> matrices;
    while(file >> n)
    {
        if(cnt == 0){
            vertices = n;
        }
        else if(cnt != vertices*vertices+1){
            if(cnt%vertices != 0)
            {
                matrices.push_back(n);
            }else
            {
                matrices.push_back(n);
                adjmatrices.push_back(matrices);
                matrices.clear();
            }
        }else{
            root = n;
        }
        cnt++;
    }
    vector<int> graph[vertices];
    
    for(int i = 0; i < adjmatrices.size(); i++)
    {
        for(int j= 0; j<adjmatrices[i].size(); j++)
        {
            if(adjmatrices[i][j]!=0)
            {
                graph[i].push_back(j);
            }
        }
    }

    
   printLevels(graph,vertices,root-1);
return 0;
}