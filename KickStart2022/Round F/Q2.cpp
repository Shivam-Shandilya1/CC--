#include <bits/stdc++.h>
using namespace std;

void solve(int N,int Q,int x,vector<double> up[],vector<double> down[],vector<double> &full, vector<int> &level,vector<int> &levelcnt)
{
    while(down[x].size()!=0)
    {
        x = down[x][0];
    }
    double tmp = 1;
    queue<pair<int,double>> q;
    q.push({x,full[x]});
    while(!q.empty() && tmp != 0)
    {
        auto it = q.front();
        q.pop();
        tmp = it.second;
        full[it.first] = 1;
        
        double temp = tmp;
        for(double j:up[it.first])
        {
            if(full[j]==1)
            {
                q.push({j,full[j]});
            }else
            {
                double tmp2 = 1-full[j];
                double tmp3 = temp/levelcnt[level[it.first]];
                if(tmp>=min(tmp2,tmp3))
                {
                full[j] += min(tmp2,tmp3);
                tmp -= (min(tmp2,tmp3));
                }
                if(full[j]==1)q.push({j,full[j]});
            }
            if(tmp==0)break;
        }
    }
}

int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int N,Q;
        cin>>N>>Q;
        vector<double> down[N];
        vector<double> up[N];
        vector<int> level(N,0);
        vector<int> levelcnt(N,0);
        levelcnt[0]=1;
        for(double i=0;i<N-1;i++)
        {
            int p,q;
            cin>>p>>q;
            if(p<=q){
            up[p-1].push_back(q-1);
            level[q-1] = level[p-1]+1;
            levelcnt[level[q-1]]++;
            down[q-1].push_back(p-1);
            }else
            {
                down[p-1].push_back(q-1);
                level[p-1] = level[q-1]+1;
                levelcnt[level[p-1]]++;
                up[q-1].push_back(p-1);
            }
        }

        // for(int k:level)cout<<k<<" ";
        // cout<<endl;
        
        // for(int k:levelcnt)cout<<k<<" ";
        // cout<<endl;

        vector<double> full(N,0.0);

        for(int i=0;i<Q;i++)
        {
            
            int x;
            cin>>x;
            solve(N,Q,x-1,up,down,full,level,levelcnt);
        }
        int ans = 0;
        for(double k:full)if(k==1)ans++;
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    return 0;
}