#include <bits/stdc++.h>

using namespace std;

void solve(int n,vector<vector<char>> &g,int k,int r,int c)
{
   
}

int main()
{
    int T;
    cin>>T;
   
    for(int t = 0;t<T;t++)
    {
        int n,k,r,c;
        cin>>n>>k>>r>>c;
        vector<vector<char>> g(n,vector<char>(n,'.'));
        r--;
        c--;
        vector<pair<int,int>> v={{r,c}};
        for(int i=0;i<n;i+=k)
        {
            g[(r+i)%n][c]='X';
            v.push_back({(r+i)%n,c});
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<v.size();j++)
            {
                g[(v[j].first-i+n)%n][(v[j].second+i+n)%n] = 'X';
            }
        }
        for(vector<char> v:g)
        {
            for(char c:v)cout<<c;
            cout<<endl;
        }
    }
    return 0;
}