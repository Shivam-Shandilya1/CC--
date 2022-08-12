#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    
    vector<int> v;
    for(int t=0;t<T;t++)
    {
        for(int i=0;i<4;i++)
        {
            int k;
            cin>>k;
            v.push_back(k);
        }

        int W;
        cin>>W;
        vector<vector<int>> dp(v.size()+1,vector<int>(W+1,0));
        for(int i=0;i<=v.size();i++)dp[i][0] = 1;
        
        for(int i=1;i<=v.size();i++)
        {
            for(int j=1;j<=W;j++)
            {
                if(j>=v[i-1]) dp[i][j] = dp[i][j-v[i-1]] || dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        for(int i=0;i<=v.size();i++)
        {
            for(int j=0;j<=W;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }

        string ans="";
        int i = v.size();
        int j = W;
        while(i>0 && j>0)
        {
            if(j>=v[i-1])
            {
                ans+= (char)(i+97-1);
                j-=v[i-1];
            }else
            {
                i--;
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}