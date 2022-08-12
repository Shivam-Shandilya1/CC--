#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<unsigned long long,pair<unsigned long long,unsigned long long>>& a,pair<unsigned long long,pair<unsigned long long,unsigned long long>>& b)
        {
            if(a.second.second<b.second.second)
            {
                return true;
            }else if(a.second.second==b.second.second)
            {
                if(a.second.first<b.second.first)
                {
                    return true;
                }
            }
            return a.second.second<b.second.second;
        }

bool cmp1(pair<unsigned long long,pair<unsigned long long,unsigned long long>>& a,pair<unsigned long long,pair<unsigned long long,unsigned long long>>& b)
{
    return a.second.first<b.second.first;
}

bool cmp2(pair<unsigned long long,pair<unsigned long long,unsigned long long>>& a,pair<unsigned long long,pair<unsigned long long,unsigned long long>>& b)
{
    return a.second.second<b.second.second;
}

bool cmp3(pair<unsigned long long,pair<unsigned long long,unsigned long long>>& a,pair<unsigned long long,pair<unsigned long long,unsigned long long>>& b)
{
            if(a.second.first<b.second.first)
            {
                return true;
            }else if(a.second.first==b.second.first)
            {
                if(a.second.second<b.second.second)
                {
                    return true;
                }
            }
            return a.second.first<b.second.first;
}

int main()
{
    unsigned long long T;
    cin>>T;
    for(unsigned long long i=0;i<T;i++)
    {
        unsigned long long N;
        cin>>N;
        map<unsigned long long,pair<unsigned long long,unsigned long long>> m;
        vector<bool> initiators(N+1,true);
        
        for(unsigned long long j=0;j<N;j++)
        {
            unsigned long long p;
            cin>>p;
            m.insert({j+1,{p,0}});
        }
        for(unsigned long long j=0;j<N;j++)
        {
            unsigned long long p;
            cin>>p;
            initiators[p] = false;
            m[j+1].second = p;
        }
        vector<pair<unsigned long long,pair<unsigned long long,unsigned long long>>>init;
        for(unsigned long long j=0;j<initiators.size();j++)
        {
            if(initiators[j] == true)init.push_back({j,{m[j].first,m[j].second}});
        }
        unsigned long long sum = 0;
        
        
        
    
        
        sort(init.begin(),init.end(),cmp);  
        
        
    
        

        vector<bool> visited(N+1,false);
        for(unsigned long long i =0;i<init.size();i++)
        {
            unsigned long long maxfun = 0;
            unsigned long long p = init[i].first;
            while(p!=0 && visited[p]!=true)
            {
                maxfun = max(m[p].first,maxfun);
                visited[p] = true;
                p = m[p].second;
            }
            sum+=maxfun;
        }

        unsigned long long result = sum;

        vector<bool> visited4(N+1,false);

        reverse(init.begin(),init.end());
        
        
    
                
        sum = 0;
        for(unsigned long long i =0;i<init.size();i++)
        {
            unsigned long long maxfun = 0;
            unsigned long long p = init[i].first;
            while(p!=0 && visited4[p]!=true)
            {
                maxfun = max(m[p].first,maxfun);
                visited4[p] = true;
                p = m[p].second;
            }
            sum+=maxfun;
        }
        
        result = max(result,sum);

        vector<bool> visited1(N+1,false);

        sort(init.begin(),init.end(),cmp1);
        
        
    
                
        sum = 0;
        for(unsigned long long i =0;i<init.size();i++)
        {
            unsigned long long maxfun = 0;
            unsigned long long p = init[i].first;
            while(p!=0 && visited1[p]!=true)
            {
                maxfun = max(m[p].first,maxfun);
                visited1[p] = true;
                p = m[p].second;
            }
            sum+=maxfun;
        }
        
        result = max(result,sum);

        vector<bool> visited5(N+1,false);

        reverse(init.begin(),init.end());
        
        
    
                
        sum = 0;
        for(unsigned long long i =0;i<init.size();i++)
        {
            unsigned long long maxfun = 0;
            unsigned long long p = init[i].first;
            while(p!=0 && visited5[p]!=true)
            {
                maxfun = max(m[p].first,maxfun);
                visited5[p] = true;
                p = m[p].second;
            }
            sum+=maxfun;
        }
        
        result = max(result,sum);

        vector<bool> visited2(N+1,false);

        sort(init.begin(),init.end(),cmp2);
        
        
    
                
        sum = 0;
        for(unsigned long long i =0;i<init.size();i++)
        {
            unsigned long long maxfun = 0;
            unsigned long long p = init[i].first;
            while(p!=0 && visited2[p]!=true)
            {
                maxfun = max(m[p].first,maxfun);
                visited2[p] = true;
                p = m[p].second;
            }
            sum+=maxfun;
        }
        
        result = max(result,sum);

        vector<bool> visited6(N+1,false);

        reverse(init.begin(),init.end());
        
        
    
                
        sum = 0;
        for(unsigned long long i =0;i<init.size();i++)
        {
            unsigned long long maxfun = 0;
            unsigned long long p = init[i].first;
            while(p!=0 && visited6[p]!=true)
            {
                maxfun = max(m[p].first,maxfun);
                visited6[p] = true;
                p = m[p].second;
            }
            sum+=maxfun;
        }
        
        result = max(result,sum);

        vector<bool> visited3(N+1,false);

        sort(init.begin(),init.end(),cmp3);
        
        
    
                
        sum = 0;
        for(unsigned long long i =0;i<init.size();i++)
        {
            unsigned long long maxfun = 0;
            unsigned long long p = init[i].first;
            while(p!=0 && visited3[p]!=true)
            {
                maxfun = max(m[p].first,maxfun);
                visited3[p] = true;
                p = m[p].second;
            }
            sum+=maxfun;
        }
        
        result = max(result,sum);
        

        vector<bool> visited7(N+1,false);

        reverse(init.begin(),init.end());
        
        
    
                
        sum = 0;
        for(unsigned long long i =0;i<init.size();i++)
        {
            unsigned long long maxfun = 0;
            unsigned long long p = init[i].first;
            while(p!=0 && visited7[p]!=true)
            {
                maxfun = max(m[p].first,maxfun);
                visited7[p] = true;
                p = m[p].second;
            }
            sum+=maxfun;
        }
        
        result = max(result,sum);

        cout<<"Case #"<<i+1<<": "<<result<<endl;
    }
    return 0;
}