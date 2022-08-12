#include <bits/stdc++.h>
using namespace std;
class graph
{
    int shauryV;
    list <int> *shauryl;
public:
    graph(int shauryv)
    {
       shauryV=shauryv;
       shauryl=new list<int>[shauryV];
    }
    void addkarobhai(int i,int j,bool unederdir=true)
    {
       shauryl[i].push_back(j);
       if(unederdir)
       {
           shauryl[j].push_back(i);
        }
    }
   
    void print(int a)
    {
        bool thefkuc=false;
        int shauryppp=-1;
        for(int i=0;i<a;i++)
        {
            for(auto node:shauryl[i])
            {
                if(shauryppp==node && shauryl[i].size()==1)
                {
                    thefkuc=true;

                }
                if(shauryl[i].size()==1)
                {
                    shauryppp=node;
                }             
            }
        }
        if(thefkuc==false)
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<0<<endl;
        }     
    }
};
int main()
{
    int shaurya,shauryb;
    freopen("input.txt","r",stdin);
    cin>>shaurya>>shauryb;
    int shauryn= shaurya+shauryb;
    int shauryarr[shauryn][shauryn];
    for(int shauryi=0;shauryi<shauryn;shauryi++)
    {
        for(int shauryj=0;shauryj<shauryn;shauryj++)
        {
            cin>>shauryarr[shauryi][shauryj];

        }
    }
    int shaurycount=0;
    map<int,int>shaurym;
    vector <int> shaurychecker;
    for(int shauryi=shaurya;shauryi<shauryn;shauryi++)
    {
        for(int shauryj=0;shauryj<shaurya;shauryj++)
        {
            if(shauryarr[shauryi][shauryj]==1)
            {
                shaurycount++;
                shaurym.insert(pair<int, int>(shauryi, shauryj));
                shaurychecker.push_back(shauryi);
                shaurychecker.push_back(shauryj);                
            }           
        }     
    }
    sort(shaurychecker.begin(),shaurychecker.end());
    shaurychecker.erase(unique(shaurychecker.begin(),shaurychecker.end()),shaurychecker.end());
    int r=shaurychecker.size();
    graph shauryg(r);
    map<int,int>::iterator itr;
    for(itr=shaurym.begin();itr!=shaurym.end();itr++)
    {
        shauryg.addkarobhai(itr->first,itr->second);
    } 
    shauryg.print(shaurya);    
    return 0;
}