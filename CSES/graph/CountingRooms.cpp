#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &room,vector<vector<int>> &visited,int i,int j)
{
    // cout<<i<<" "<<j<<endl;
    // cout<<p.first<<" "<<p.second<<endl;
    int n = room.size();
    int m = room[0].size();
    if(i<0 || i>=n ||j<0 ||j>=m)return;
    visited[i][j]=1;
     if(i-1>=0 &&  !visited[i-1][j])
    {
        dfs(room,visited,i-1,j);
    }
    if(j-1>=0 && !visited[i][j-1])
    {
        dfs(room,visited,i,j-1);
    }if(i+1<n && !visited[i+1][j])
    {
        dfs(room,visited,i+1,j);
    }
    if(j+1<m && !visited[i][j+1])
    {
        dfs(room,visited,i,j+1);
    }
}

int main()
{
    int n,m,ans = 0;
    cin>>n>>m;
    vector<vector<int>> visited(n,vector<int>(m,0));
    
    vector<vector<char>> room(n,vector<char>(m,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>room[i][j];
            if(room[i][j] == '#')visited[i][j]=1;
        }
    }

    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(room[i][j]=='.')
            {
              if(!visited[i][j])
              {
                ans++;
                dfs(room,visited,i,j);
              }
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}