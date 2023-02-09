#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;

        vector<int> v[N];
        unordered_map<int,int> m;

        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
           
            for(int j=0;j<k;j++)
            {
                int k2;
                cin>>k2;
                v[i].push_back(k2);
                m[k2]++;
            }
        }

        bool f1 = true;
        for(int i=0;i<N;i++)
        {
            bool f = true;
            for(int j = 0;j<v[i].size();j++)
            {
                if(m[v[i][j]]==1)
                {
                    f = false;
                    break;
                }
            }
            if(f)
            {
                cout<<"YES\n";
                f1 = false;
                break;
            }
        }
        if(f1)
        {
            cout<<"NO\n";
        }
    }
    return 0;
}
