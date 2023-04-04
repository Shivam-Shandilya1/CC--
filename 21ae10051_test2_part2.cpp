#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Write n:";
    cin>>n;
    int earnings[n];
    int costs[n];
    int rewards[n];
    cout<<"Write "<<n<<" earnings: ";
    for(int i=0;i<n;i++)
    {
        cin>>earnings[i];
    }
    cout<<"Write "<<n<<" costs: ";
    for(int i=0;i<n;i++)
    {
        cin>>costs[i];
    }
    cout<<"Write "<<n<<" rewards: ";
    for(int i=0;i<n;i++)
    {
        cin>>rewards[i];
    }

    vector<int> activity;
    int dp[n+1][10001];
    memset(dp, 0, sizeof(dp)); // initialize dp array with 0
    for(int i=1; i<=n; i++){
        for(int j=0; j<=10000; j++){
            if(costs[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-costs[i-1]] + rewards[i-1]);
            }
        }
    }

    int max_happiness = dp[n][0];
    int money = 0;
    for(int j=0; j<=10000; j++){
        if(dp[n][j] > max_happiness){
            max_happiness = dp[n][j];
            money = j;
        }
    }

    for(int i=n; i>=1; i--){
        if(dp[i][money] == dp[i-1][money]){
            continue;
        }
        activity.push_back(i-1);
        money -= costs[i-1];
    }

    reverse(activity.begin(), activity.end());
    cout<<"Maximum happiness is "<<max_happiness<<endl;
    cout<<"Activities selected: ";
    for(int i=0;i<activity.size();i++) cout<<activity[i]+1<<",";
    return 0;
}
