#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
#define endl "\n"
#define test ll t; cin>>t; while(t--)
typedef long long int ll;
int solve()
{
    string s; cin>>s;
    vector<int>a(3,0);
    for(auto it:s) a[it-'0']++;
    sort(a.begin(),a.end());
    if((a[2]-a[0])>1) return 0;
    if(a[2]==a[0]) return 6;
    return 2;
}
int main() {
    FIO;
    test
    {
       cout<<solve()<<endl;
    }
	return 0;
}