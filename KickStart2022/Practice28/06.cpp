#include <bits/stdc++.h>
using namespace std;
int main()
{
int T;
cin>>T;
for(int tc=0;tc<T;tc++)
{
    int N,M;
    cin>>N>>M;
    vector<int> bags;
    for(int cb=0;cb<N;cb++)
    {
        int k;
        cin>>k;
        bags.push_back(k);
    }
    int sum=0;
    for(int k:bags)sum+=k;
    cout<<"Case #"<<tc+1<<": "<<sum%M<<endl;
}
return 0;
}