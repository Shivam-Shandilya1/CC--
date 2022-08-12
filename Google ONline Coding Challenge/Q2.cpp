//#include<bits/stdc++.h>

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<map>
#include<stack>
#include<unordered_set>
using namespace std;
// int Bseach(vector<int> &arr,int val,int si,int ei)
// {
//     int low=si;
//     int high=ei;
//     while(low<=high)
//     {
//         int mid=(low+high)/2;
//         if(val==arr[mid])return mid;
//         else if(val>arr[mid])low=mid+1;
//         else if(val<arr[mid])high=mid-1;
//     }return si;

// }
int conquer(vector<int> &arr,int si,int mid,int ei)
{
    int ans=0;
    for(int i=mid+1;i<=ei;i++)
    {
        int index=lower_bound(arr.begin()+si,arr.begin()+mid,arr[i])-arr.begin();
       
        if(arr[index]>=arr[i])
             ans+=index-si ;
        else ans+=index+1-si;

    }
    vector<int> temp(ei-si+1,0);
        int i=si;
        int j=mid+1;
        int k=0;
        while(i<=mid&&j<=ei)
        {
            if(arr[i]<=arr[j])
            {
           temp[k]=arr[i];
                i++;
            }
            else if(arr[j]<arr[i])
            {
                temp[k]=arr[j];
              j++;

            }k++;
        }
        while(i<=mid)
        {
            temp[k]=arr[i];
            i++;
            k++;
        }
        while(j<=ei)
        {
            temp[k]=arr[j];
            j++;
            k++;
        }
        for(int i=0;i<temp.size();i++)
        {
            arr[si+i]=temp[i];
        }
        cout<<ans<<endl;
    return ans;

}
int divide(vector<int> &arr,int si,int ei)
{
    if(si>=ei)return 0;
    int mid=(si+ei)/2;
   int left= divide(arr,si,mid);
   int right= divide(arr,mid+1,ei);
   int h= conquer(arr,si,mid,ei);
    return left+right+h;

}
int main()
{
    vector<int>a={8,0,-1,2,4};
    
    // int index=lower_bound(a.begin()+1,a.begin()+2,2)-a.begin();
    int val= divide(a,0,a.size()-1);
    cout<<val;
    return 0;
}
