#include <bits/stdc++.h>
using namespace std;

int solve(int N,vector<string> &col,vector<int> &dur,vector<int> &uid)
{
    vector<pair<string,int>> v;
    for(int i=0;i<N;i++)
    {
        v.push_back({col[i],uid[i]});
    }
    
    vector<pair<int,int>> v1;
    for(int i=0;i<N;i++)
    {
        v1.push_back({dur[i],uid[i]});
    }

    sort(v.begin(),v.end());
    sort(v1.begin(),v1.end());

    int ans = 0;
    for(int i=0;i<N;i++)
    {
        if(v[i].second==v1[i].second)ans++;
    }

    return ans;
}

int main()
{
    int T;
    cin>>T;
    
    for(int t=0;t<T;t++)
    {
        int N;
        cin>>N;
        vector<string> col(N);
        vector<int> dur(N);
        vector<int> uid(N);
        for(int i=0;i<N;i++)
        {
            cin>>col[i];
            cin>>dur[i];
            cin>>uid[i];
        }
        
        cout<<"Case #"<<t+1<<": "<<solve(N,col,dur,uid)<<endl;
    }

    return 0;
}