
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
// void sol()
// {
//   long long n;
//   cin>>n;
//   vector<long long> a(n);
//   for(long long i=0;i<n;i++)cin>>a[i];
//   vector<long long> b(n);
//   for(long long i=0;i<n;i++)cin>>b[i];
//   priority_queue<long long> q0,q1;
// for(long long i=0;i<n;i++)
// {
//   if(a[i]==0)
//   {
//     q0.push(b[i]);
//     // cout<<"q0"<<" "<<b[i]<<endl;
//   }else
//   {
//     q1.push(b[i]);
//     // cout<<"q1"<<" "<<b[i]<<endl;
//   }
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
// }#include<bits/stdc++.h>
// using namespace std;
// void sio(){
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     freopen("error.txt", "w", stderr);
// #endif
// }
// typedef long long ll;
// #define mod 1000000007
// #define pb push_back
// #define MP make_pair
// #define mod2 998244353
// #define forn(i,n) for(int i=0;i<(n);i++)
// #define vll vector<ll>
// #define forr(i,n) for(ll i=n-1;i>=0;i--)
void sol(){
  long long n;
  cin>>n;
  long long k;
  cin>>k;
  vector<long long> arr;
  for(int i=0;i<k;i++){
    long long a;
    cin>>a;
    arr.push_back(a);
  }
  if(k==1){
    cout<<"YES"<<endl;
    return;
  }
  long long m=INT_MIN;
  for(int i=0;i<k-1;i++){
    if(arr[i+1]-arr[i]<m){
     cout<<"NO"<<endl;
      return;
    }else{
      m=arr[i+1]-arr[i];
    }
  }
  long long a=n-k+1;
  long long ele=(arr[1]-arr[0])*a;
  if(ele>=arr[0]){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}

 
int main(){
  sio();
  int T;
  cin>>T;
    for(int t=0;t<T;t++){
      sol();
    }
}