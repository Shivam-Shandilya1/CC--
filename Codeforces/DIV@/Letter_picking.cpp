// #include <bits/stdc++.h>
// using namespace std;

// void solve(string s,vector<int> &v,int i,int j,int trn)
// {
//     if(i>j)return;
//     char c_b = s[i],c_e = s[j];
//     if(c_b<c_e)
//     {
//         // cout<<"B:"<<c_b<<" "<<trn<<endl;
//         // s.erase(s.begin());
//         v[trn]+=c_b;
//         solve(s,v,i+1,j,1-trn);
//     }else
//     {
//         // cout<<"E:"<<c_e<<" "<<trn<<endl;
//         // s.erase(s.begin()+s.size()-1);
//         v[trn]+=c_e;
//         solve(s,v,i,j-1,1-trn);
//     }
    
// }

// int main()
// {
//     int T;
//     cin>>T;
//     for(int t=0;t<T;t++)
//     {
//         string s;
//         cin>>s;
//         vector<int> v(2,0);
//         solve(s,v,0,s.size()-1,0);
//         for(int k:v)cout<<k<<" ";
//         cout<<endl;
//         if(v[0]<v[1])cout<<"Alice"<<endl;
//         if(v[0]==v[1])cout<<"Draw"<<endl;
//         if(v[0]>v[1])cout<<"Bob"<<endl;
//         // vector<vector<vector<int>>> dp(s.size(),vector<vector<int>>(s.size(),vector<int>(2,0)));
//         // for(int i=0;i<s.size();i++)
//         // {
//         //     dp[i][i][0]=s[i];
//         //     dp[i][i][1]=s[i];
//         // }
//         // for(int i=s.size()-1;i>=0;i--)
//         // {
//         //     for(int j=i+1;j<s.size();j++)
//         //     {
//         //         if(s[i]<s[j])
//         //         {
//         //             dp[i][j][0]= s[i]+dp[i+1][j][1];
                    
//         //         }
//         //         else
//         //         {
//         //             dp[i][j][1] = s[j]+dp[i][j-1][0];
//         //         }
//         //     }
//         // }
//         // cout<<dp[0][s.size()-1][0]<<" "<<dp[0][s.size()-1][1]<<endl;
//         // if(dp[0][s.size()-1][0]>dp[0][s.size()-1][1])
//         // {
//         //     cout<<"Alice"<<endl;
//         // }
//         // else if(dp[0][s.size()-1][0]==dp[0][s.size()-1][1])cout<<"Draw"<<endl;
//         // else 
//         // {
//         //     cout<<"Bob"<<endl;
//         // }
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define lli long long int
 
// #define INF LLONG_MAX
// #define pb push_back
// #define ff first
// #define ss second
// #define mod 1000000007
 

 
// bool palin(string s)
// {
//     string str=s;
//     reverse(str.begin(),str.end());
//     if(str==s)return true;
//     return false;
// }
 
// bool check(string s)
// {
//     lli n=(int)s.size();
//     if(n==0)return true;
//     int c=1;
//     char prev=s[0];
//     for(int i=1;i<n;i++)
//     {
//         if(s[i]==prev)c++;
//         else
//         {
//             if(c&1)return false;
//             c=1;
//             prev=s[i];
//         }
//     }
//     return true;
// }
 
// bool check2(string s)
// {
//     lli n=(int)s.size();
//     lli start=0,end=n-1;
//     while(start<end && start<n && end>=0)
//     {
//         if(s[start]==s[end])
//         {
//             start++;
//             end--;
//         }
//         else
//         break;
//     }
//     string str="";
//     for(int i=start;i<=end;i++)str+=s[i];
//     return check(str);
// }
 
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     lli t=1,n,i;
//     cin>>t;
//     while(t--)
//     {
//         string s;
//         cin>>s;
//         n=(int)s.size();
//         if(palin(s) || check(s) || check2(s))
//         {
//             cout<<"Draw\n";
//             continue;
//         }
//         cout<<"Alice\n";
//     }
// }
#include<bits/stdc++.h>
using namespace std;
long long recurse(long long i,long long j,vector<vector<long long>>& dp,string &s){
    if(i>j)return 1;
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    long long ans_start = -1,ans_end = 0;
    long long need = recurse(i+2,j,dp,s);

    if(s[i]<s[i+1])
    {
        if(need==2)ans_start = 2;
        else ans_start = 0;
    }else if(s[i]==s[i+1])ans_start = need;
    else
    {
        if(need == 0)ans_start = 0;
        else ans_start = 2;
    }
    
    need = recurse(i+1,j-1,dp,s);
    if(s[i]<s[j])
    {
        if(need == 2)
        {
            ans_start = max(ans_start,2ll);
        }else
        {
            ans_start = max(ans_start,0ll);
        }
        
    }else if(s[i]==s[j])
    {
        ans_start = max(ans_start,need);
    }else
    {
        if(need == 0)ans_start = max(ans_start,0ll);
        else ans_start = max(ans_start,2ll);
    }
    
    need = recurse(i,j-2,dp,s);
    if(s[i]<s[j-1])
    {
        if(need == 2)ans_end = 2;
        else ans_end = 0;
    }else if(s[j]==s[j-1])
    {
        ans_end = need;
    }else
    {
        if(need == 0)ans_end = 0;
        else ans_end = 2;
    }
    
    need = recurse(i+1,j-1,dp,s);
    if(s[j]<s[i])
    {
        if(need == 2)
        {
            ans_end = max(ans_end,2ll);
        }else
        {
            ans_end = max(ans_end,0ll);
        }
    }else if(s[j]==s[i])
    {
        ans_end = max(ans_end,need);
    }else
    {
        if(need==0)ans_end = max(ans_end,0ll);
        else ans_end = max(ans_end,2ll);
    }

    dp[i][j] = min(ans_start,ans_end);
    return dp[i][j];
}
int main()
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        string s;
        cin>>s;
        int n = s.size();
        vector<vector<long long>> dp(n,vector<long long>(n,-1));
        vector<string> ans = {"Alice","Draw","Bob"};
        cout<<ans[recurse(0,n-1,dp,s)]<<endl;
    }
    return 0;
}