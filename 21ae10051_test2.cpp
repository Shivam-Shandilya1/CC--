#include <bits/stdc++.h>
using namespace std;

int max_happiness = 0;
vector<int> res_Arr;
void solve(int n,vector<int> &activity,int earnings[],int costs[],int rewards[],int day,int money,int reward)
{
    if(day>=n)
    {
        if(reward+money>=max_happiness)
        {
            res_Arr = activity;
            max_happiness = reward+money;
        }
        return;
    }
    solve(n,activity,earnings,costs,rewards,day+1,money+earnings[day],reward);
    if(money<costs[day])
    {
        return;
    }
    activity.push_back(day);
    solve(n,activity,earnings,costs,rewards,day+1,money-costs[day],reward+rewards[day]);
    activity.pop_back();
    return;
}
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
    solve(n,activity,earnings,costs,rewards,0,0,0);
    cout<<"Part1:\n";
    cout<<"Maximum happiness is "<<max_happiness<<endl;
    cout<<"Acitivies selected: ";
    for(int i=0;i<res_Arr.size();i++)cout<<res_Arr[i]+1<<",";


    cout<<"\nPart2: "<<endl;
    vector<int> activy;
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

    int max_happines = dp[n][0];
    int money = 0;
    activy = res_Arr;
    for(int j=0; j<=10000; j++){
        if(dp[n][j] > max_happines){
            max_happines = dp[n][j];
            money = j;
        }
    }

    
    max_happines = max_happiness;
    for(int i=n; i>=1; i--){
        if(dp[i][money] == dp[i-1][money]){
            continue;
        }
        money -= costs[i-1];
    }

    
    cout<<"Maximum happiness is "<<max_happines<<endl;
    cout<<"Activities selected: ";
    for(int i=0;i<activy.size();i++) cout<<activy[i]+1<<",";
    return 0;
}
