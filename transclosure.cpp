#include <bits/stdc++.h>
using namespace std;
int main()
{
ifstream file("input.txt");
if(!file)
{
    cout<<"Error opening output file"<<endl;
    system("pause");
    return -1;
}
map<int,vector<int>> row;
int n,i=0,elem,cnt = 0,r=0,c=0;
while(file >> n)
{
    c = cnt%elem;
    r = cnt/elem;
    if(i==0){
        elem = n;
        i++;
    }else
    {
    if(n == 1)
    {
        row[r].push_back(c);
        
    }
    cnt++;
    }
    
}
string s;

for(auto it = row.begin();it!=row.end();it++)
{
    for(int j = 0;j<it->second.size();j++)
    {
        for(int k : row[it->second[j]])
        {
            if(count(it->second.begin(),it->second.end(),k))
            {
                continue;
            }else
            {
                it->second.push_back(k);
                
            }
        }
    }
}

vector<vector<int>> v (elem,vector<int>(elem,0));
for(auto it = row.begin();it!=row.end();it++)
{
    for(int j:it->second)
    {
        v[it->first][j] = 1;
    }
    
}

for(int i = 0; i < v.size(); i++)
{
    for(int j:v[i])
    {
        if(j)s.push_back('1');
        else s.push_back('0');
        s.push_back('$');
    }
    s.push_back('$');
}

cout<<s<<endl;
return 0;
}