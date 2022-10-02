// #include<bits/stdc++.h>
// using namespace std;

 
// typedef long long ll;
// #define mod 1000000007
// #define pb push_back
// #define MP make_pair

// #define forn(i,n) for(long long i=0;i<(n);i++)
// #define vll vector<ll>
// #define forr(i,n) for(ll i=n-1;i>=0;i--)
// bool possible(long long len,long long k,long long n){
//   long long a=k-len+1;
//   long long sum1=(a-1)*a/2-1;
//   long long sum2=k*(k+1)/2-1;
//   long long val=sum2-sum1-(len-1);
//   if(val>=n)return true;
//   return false;
// }
// void sol2(){
//   long long n;
//   cin>>n;
//   vector<long long> pos(n);
//   vector<int> t(n);
//   for(int i=0;i<n;i++)cin>>pos[i];
//   for(int i=0;i<n;i++)cin>>t[i];

// }
// void sol3()
// {
//   string s;
//   cin>>s;
  
//   for(int i=0;i<s.size();i++)
//     {
//       v.push_back(s[i]-'0');
//     }

//     map<int,vector<int>> m;
//     for(int i=0;i<v.size();i++)
//     {
//       m[v[i]].push_back(i);
//     }

//     for(auto it:m)
//     {
//       int prev = 0;
//       for(int k:it.second)
//       {
//         str.erase(str.begin()+prev,k)
//       }
//     }
// }

// void sol(){
//   long long cost = 0;
//   int n,c;
//   cin>>n>>c;
//   vector<int> planets(n);
//   for(int i=0;i<n;i++)cin>>planets[i];
//   map<int,int> m;
//   for(int k:planets)m[k]++;
//   for(auto it:m)
//   {
//     if(it.second>c)cost+=c;
//     else cost+=it.second;
//   }
//   cout<<cost<<endl;
// }
// int main(){
//   sio();
//   int testcase;
//   cin>>testcase;
//     for(int t=0;t<testcase;t++){
//       sol3();
//     }
// }
#include <bits/stdc++.h>
using namespace std;
#define mod2 998244353
void sio(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}


// vector<vector<int>> v = {{1,-2},{2,-1},{1,2},{2,1},{-1,2},{-2,1},{-1,-2},{-2,-1}};

// bool isValid(int i,int j,int r,int c)
// {
//   for(vector<int> v1:v)
//   {
    
//     int p = i+v1[0];
//     int q = j+v1[1];
//     if(p>=1 && p<=r && q>=1 && q<=c)return true;
//   }
//   return false;
// }

// void sol()
// {
//   long long n;
//   cin>>n;
//   vector<long long> a(n);
//   for(long long i=0;i<n;i++)cin>>a[i];
//   vector<long long> b(n);
//   for(long long i=0;i<n;i++)cin>>b[i];
//   priority_queue<long long> q0,q1;
//   int s0=INT_MIN,s1=INT_MIN;
// for(long long i=0;i<n;i++)
// {
//   if(a[i]==0)
//   {
//     if(q0.empty())s0=b[i];
//     q0.push(b[i]);
    
//     // cout<<"q0"<<" "<<b[i]<<endl;
//   }else
//   {
//     if(q1.empty())s1=b[i];
//     q1.push(b[i]);
    
//     // cout<<"q1"<<" "<<b[i]<<endl;
//   }
// }

// long long ans = 0;
// // cout<<q0.size()<<" "<<q1.size()<<endl;
// if(q0.size()==q1.size())
// {
//   long long trn = 0;
//   if(s0<=s1)trn = 1;
// //   cout<<trn<<endl;
//   while(!q0.empty() || !q1.empty())
//   {
//     if(trn)
//     {
//       long long tp = q1.top();
//       ans+=tp;
//       q1.pop();
//       if(!q0.empty())ans+=tp;
//     }else
//     {
//       long long tp = q0.top();
//       ans+=tp;
//       q0.pop();
//       if(!q1.empty())ans+=tp;
//     }
//     trn = 1-trn;
//   }
// //   cout<<trn<<" "<<ans<<endl;
// }else if(q0.size()<q1.size())
// {
//   long long trn = 1;
  
//   while(!q0.empty() || !q1.empty())
//   {
//     if(trn)
//     {
//       long long tp = q1.top();
//       ans+=tp;
//       q1.pop();
//       if(!q0.empty())ans+=tp;
//     }else
//     {
//       long long tp = q0.top();
//       ans+=tp;
//       q0.pop();
//       if(!q1.empty())ans+=tp;
//     }
//     if(!q0.empty() && !q1.empty())trn = 1-trn;
//     else
//     {
//       if(!q0.empty())trn = 0;
//       else trn=1;
//     }
//     // cout<<ans<<" "<<trn<<endl;
//   }
// }else
// {
//   long long trn = 0;
//   long long cnt = 0;
//   while(!q0.empty() ||!q1.empty())
//   {
//     if(trn)
//     {
//       long long tp = q1.top();
//       ans+=tp;
//       q1.pop();
//       if(!q0.empty())ans+=tp;
//     }else
//     {
//       long long tp = q0.top();
//       ans+=tp;
//       q0.pop();
//       if(!q1.empty())ans+=tp;
//     }
//     if(!q0.empty() && !q1.empty())trn = 1-trn;
//     else
//     {
//       if(!q0.empty())trn = 0;
//       else trn=1;
//     }
//   }
// }

// cout<<ans<<endl;
// }
void sol()
{
    long long n;
    cin >> n;
    vector<long long> a(n), b(n);
    for(int i=0;i<n;i++)  cin >> a[i];
    for(int i=0;i<n;i++)  cin >> b[i];
    vector<long long> fire, frost;
    for(int i=0;i<n;i++)
    {
        if(a[i])
        {
            fire.push_back(b[i]);
        }
        else    frost.push_back(b[i]);
    }
    sort(fire.rbegin(), fire.rend());
    sort(frost.rbegin(), frost.rend());
    long long val1 = 0, val2 = 0;
    if(fire.size()) val1 = fire.back();
    if(frost.size())    val2 = frost.back();
    long long i = 0;
    for(i = 0; i < min((int)(fire.size() - 1), (int)frost.size()); i++)
    {
        val1 += (frost[i] * 2);
        val1 += (fire[i] * 2);
    }
    while(i < (int)(fire.size() - 1))
    {
        val1 += (fire[i]);
        i++;
    }
    if(i < frost.size())
    {
        val1 += (2 * frost[i]);
        i++;
    }
    while(i < frost.size())
    {
        val1 += frost[i];
        i++;
    }
    i = 0;
    // cout << min(3, -1) << endl;
    // cout <<  fire.size() << ":" << (int)(frost.size()  - 1) << endl;
    // cout << min((int)fire.size(), (int)(frost.size() - 1)) << endl;
    for(i = 0; i < min((int)fire.size(), (int)(frost.size() - 1)); i++)
    {
        val2 += (frost[i] * 2);
        val2 += (fire[i] * 2);
    }
    while(i < (int)(frost.size() - 1))
    {
        val2 += (frost[i]);
        i++;
    }
    if(i < fire.size())
    {
        val2 += (2 * fire[i]);
        i++;
    }
    while(i < fire.size())
    {
        val2 += fire[i];
        i++;
    }
    if(fire.size() == 0)
    {
        val1 -= (frost[0]);
    }
    if(frost.size() == 0)   val2 -= (fire[0]);
    cout << max(val1, val2) << endl;
}
// int main(){
//     //freopen("input.txt", "r", stdin);
//     //freopen("output.txt", "w", stdout);
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);
// cout.tie(NULL);
// ll t=1;
// cin>>t;
// while(t--)
// {
//     solve();
// }
// return 0;}
    
int main()
{

  long long T;
  cin>>T;
  for(long long t=0;t<T;t++)
  {
    sol();
  }
  return 0;
}