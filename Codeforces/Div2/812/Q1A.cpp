#include<bits/stdc++.h>

using namespace std;

void sio(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}



// void sol1(){
//   int n,k;
//   cin>>n>>k;
  
//   vector<int> v(n);
//   for(int i=0;i<n;i++){
//     cin>>v[i];
//   }

//   long long sum=0;
//   for(int i=0;i<k;i++){
//     int mx=INT_MIN;
//     for(int j=i;j<n;j+=k){
//         mx=max(mx,v[j]);
//     }
//     sum+=mx;
//   }
//   cout<<sum<<endl;
// }

void sol(){
  int n,x,y;
  cin>>n>>x>>y;
  if(x==0&&y==0){cout<<-1<<endl;return;}

  if(x==0||y==0){
    int a=max(x,y);
    if((n-1)%a==0){
      int k=a;
      int t=0;
      int var=1;
      for(int i=1;i<n;i++){
        if(t>=k){
          var=i+1;
          t=0;
        }
        cout<<var<<" ";
        t++;

      }
      cout<<endl;
    }else{
      cout<<-1<<endl;
    }
  }else{
    cout<<-1<<endl;
  }
}
void sol2(){
  int n;
  cin>>n;
  vector<int> arr;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;

    arr.push_back(a);
  }
  int ans=0;
  for(int i=1;i<n-1;i++){
    if(arr[i]>arr[i+1]){
      cout<<i-1<<" "<<i<<endl;
      if((arr[i]+arr[i-1])%2==0){
        arr[i-1]=arr[i];
      }else{
        arr[i]=arr[i-1];
      }
    }
  }
  cout<<endl;
}

int main(){
   sio();
long long T;
cin>>T;
while(T--)
{
    sol1();
}
return 0;}

