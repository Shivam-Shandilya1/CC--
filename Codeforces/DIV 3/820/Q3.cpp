#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// int main()
// {
//     int T;
//     cin>>T;
//     for(int t=0;t<T;t++)
//     {
//         string s;
//         cin>>s;
//         int n = s.size();
        
//         vector<pair<char,int>> s1;
//         for(int i=0;i<n;i++)
//         {
//             if(s[i]>=min(s[0],s[n-1]) && s[i]<=max(s[0],s[n-1]))
//             {
//                 s1.push_back({s[i],i});
//             }
//         }
//         long long cost=0;
//         sort(s1.begin(),s1.end());
//         for(int i=1;i<s1.size();i++)
//         {
//             cost+=abs(s1[i].first-s1[i-1].first);
//         }
//         cout<<cost<<" "<<s1.size()<<endl;
//         if(s[0]>s[n-1])
//         {
//             reverse(s1.begin(),s1.end());
//             for(int i=0;i<s1.size()-1;i++)cout<<s1[i].second+1<<" ";
//             cout<<s1[s1.size()-1].second+1<<endl;
//             cout<<endl;
//         }else
//         {
//             for(int i=0;i<s1.size()-1;i++)cout<<s1[i].second+1<<" ";
//             cout<<s1[s1.size()-1].second+1<<endl;
//             cout<<endl;
//         }
        
//     }
//     return 0;
// }
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    char c = s[0];
    char h = s[n - 1];
    if(c >= h)
    {
        vector<pair<int, int> > v;
        for(int i = 1; i < n - 1; i++)
        {
            if(s[i] <= c && s[i] >= h)
            {
                v.push_back({s[i] - 'a' + 1, i});
            }
        }
        sort(v.rbegin(), v.rend());
        int val = c - 'a';
        int val1 = h - 'a';
        int cst = abs(val - val1);
        int jmp = v.size() + 1;
        cout << cst << " " << jmp + 1<< endl;
        cout << 1 << " ";
        for(int i = 0; i < v.size(); i++)
        {
            cout << v[i].second + 1 << " ";
        }
        cout << n << endl;
    }
    else
    {
        vector<pair<int, int> > v;
        for(int i = 1; i < n - 1; i++)
        {
            if(s[i] <= h && s[i] >= c)
            {
                v.push_back({s[i] - 'a' + 1, i});
            }
        }        
        sort(v.begin(), v.end());
        int val = c - 'a';
        int val1 = h - 'a';
        int cst = abs(val - val1);
        int jmp = v.size() + 1;
        cout << cst << " " << jmp + 1<< endl;
        cout << 1 << " ";
        for(int i = 0; i < v.size(); i++)
        {
            cout << v[i].second + 1 << " ";
        }
        cout << n << endl;
    }
}
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
ll t=1;
cin>>t;
while(t--)
{
    solve();
}
return 0;}