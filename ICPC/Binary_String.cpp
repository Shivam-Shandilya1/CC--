#include<bits/stdc++.h>
using namespace std;
void sio(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

int solve(string s,int x){
    int n=s.length();
    vector<int> ans;
    int size=0;
    int one=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            if(size!=0){
                ans.push_back(size);
                size=0;
            }
            one++;
        }else{
            size++;
        }
    }
    if(size!=0){
        ans.push_back(size);
        size=0;
    }
    if(ans.size()==0){cout<<one<<endl;return 0;}
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    int i=0;
    while(x>0&&i<ans.size()){
        int k=(x-1)/2;
        if(k==0)break;
        else{
            k=min(ans[i],k);
            x-=2*k+1;
            one+=k;
        }
                  i++;
    }
    cout<<one<<endl;
    return 0;
}
int main(){
  sio();
    int testcase;
    cin>>testcase;
    for(int t=0;t<testcase;t++){
        int n,x;
        cin>>n>>x;
        string s;
        cin>>s;
        solve(s,x);
    }
}




  



  


