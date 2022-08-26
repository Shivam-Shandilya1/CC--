#include<bits/stdc++.h>
using namespace std;

int FindDistance(int N,vector<vector<char>> &map,pair<int,int> src,pair<int,int> dest)
{
    // cout<<src.first<<" "<<src.second<<" "<<dest.first<<" "<<dest.second<<endl;
  vector<vector<int>> visited(N,vector<int>(N,0));
  vector<vector<int>> dis(N,vector<int>(N));
  dis[src.first][src.second]=0;
  visited[src.first][src.second]=1;
  queue<pair<int,int>> q;
  q.push(src);
  while(!q.empty())
  {
    pair<int,int> it = q.front();
    // cout<<it.first<<" "<<it.second<<endl;
    q.pop();
     if(it.first+1<N && it.second<N && it.second>=0 && it.first+1>=0 && !visited[it.first+1][it.second] && map[it.first+1][it.second]!='#' )
    {
        // cout<<"1"<<endl;
      visited[it.first+1][it.second] = 1;
      dis[it.first+1][it.second] = dis[it.first][it.second]+1;
      q.push({it.first+1,it.second});
    }
    if(it.first-1<N && it.second<N && it.second>=0 && it.first-1>=0 && !visited[it.first-1][it.second] && map[it.first-1][it.second]!='#')
    {
        // cout<<2<<endl;
      visited[it.first-1][it.second]=1;
      dis[it.first-1][it.second] = dis[it.first][it.second]+1;
      q.push({it.first-1,it.second});
    }
    if(it.first<N && it.second+1<N && it.second+1>=0 && it.first>=0 && !visited[it.first][it.second+1] && map[it.first][it.second+1]!='#')
    {
        // cout<<3<<endl;
      visited[it.first][it.second+1] = 1;
      dis[it.first][it.second+1] = dis[it.first][it.second]+1;
      q.push({it.first,it.second+1});
    }
    if(it.first<N && it.second-1<N && it.second-1>=0 && it.first>=0 && !visited[it.first][it.second-1] && map[it.first][it.second-1]!='#')
    {
        // cout<<4<<endl;
      visited[it.first][it.second-1] = 1;
      dis[it.first][it.second-1] = dis[it.first][it.second]+1;
      q.push({it.first,it.second-1});
    }
  } 
  if(!visited[dest.first][dest.second])return -1;
  return dis[dest.first][dest.second];
}

int main()
{
  int T;
  cin>>T;
  for(int t = 0;t<T;t++)
  {
    int N;
    cin>>N;
    vector<vector<char>> map(N,vector<char>(N,0));
    vector<pair<int,int>> players,mines;
    for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
      {
        cin>>map[i][j];
        if(map[i][j]=='^')players.push_back({i,j});
        if(map[i][j]=='*')mines.push_back({i,j});
      }
    }

    vector<int> distance(5);
    for(int i=0;i<2;i++)
    {
      distance[i] = FindDistance(N,map,players[i],mines[0]);
    }
    for(int i=0;i<2;i++)
    {
      distance[i+2] = FindDistance(N,map,players[i],mines[1]);
    }
    distance[4] = FindDistance(N,map,mines[0],mines[1]);
    
  int ans = INT_MAX;
  if(distance[0]!=-1 && distance[3]!=-1)ans = max(distance[0],distance[3]);
  if(distance[1]!=-1 && distance[2]!=-1)ans = min(ans,max(distance[1],distance[2]));
  if(distance[4]!=-1)
  {
    if(distance[0]!=-1 && distance[2]!=-1)
    {
      ans = min(ans,distance[4]+min(distance[0],distance[2]));
    }
    if(distance[1]!=-1 && distance[3]!=-1)
    {
      ans = min(ans,distance[4]+min(distance[1],distance[3]));
    }
  }
  if(ans>=INT_MAX)cout<<"No"<<endl;
  else
  {
    cout<<"Yes"<<endl;
    cout<<ans<<endl;
  }
  }
  return 0;
}