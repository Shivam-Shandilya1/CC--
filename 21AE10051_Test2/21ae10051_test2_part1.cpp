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
    cout<<"Maximum happiness is "<<max_happiness<<endl;
    cout<<"Acitivies selected: ";
    for(int i=0;i<res_Arr.size();i++)cout<<res_Arr[i]+1<<",";
    return 0;
}
