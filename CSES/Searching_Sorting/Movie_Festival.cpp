#include <bits/stdc++.h>
using namespace std;
static bool cmp(pair<int,int> &a,pair<int,int> &b)
{
    return a.second < b.second;
}
int main()
{
    int n; //number of movies
    cin>>n;
    vector<pair<int,int>> movies;
    for(int i = 0;i<n;i++)
    {
        int a,b; //a:arrival time b:leaving time
        cin>>a>>b;
        movies.push_back({a,b}); // use 0 to indicate arrival of guest in vector v
    }
    sort(movies.begin(),movies.end(),cmp);
    int i = 0;
    int ans = 0;
    while(i<n)
    {
        int j = i + 1;
        ans++;
        while(j < n && movies[j].first < movies[i].second)j++;
        i = j;
    }
    cout<<ans<<endl;
    return 0;
}