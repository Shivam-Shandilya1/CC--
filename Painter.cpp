#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<char,vector<int>>m;
    string P;
    int input,sq;
    cin>>input;
    for(int i = 0;i<input;i++)
    {
        cin>>sq;
        cin>>P;
        for(int j = 0;j<sq;j++)
        {
            if(P[j]=='R' || P[j]=='Y' || P[j]=='B')
            {
                m[P[j]].push_back(j);
            }else if(P[j]=='O') {
                m['R'].push_back(j);
                m['Y'].push_back(j);
            }else if(P[j]=='P')
            {
                m['R'].push_back(j);
                m['B'].push_back(j);
            }else if(P[j]=='G')
            {
                m['Y'].push_back(j);
                m['B'].push_back(j);
            }else if(P[j]=='A')
            {
                m['R'].push_back(j);
                m['Y'].push_back(j);
                m['B'].push_back(j);
            }else
            {
                continue;
            }
        }
        int sum = 0;
        for(auto it = m.begin();it!=m.end();it++)
        {
            for(int k=0;k<it->second.size()-1;k++)
            {
                if((it->second[k]+1)!=it->second[k+1])
                {
                    sum++;
                }else{
                    continue;
                }
            }
            sum++;
        }
        cout<<"Case #"<<i+1<<": "<<sum<<endl;
        m.clear();
    }
return 0;
}