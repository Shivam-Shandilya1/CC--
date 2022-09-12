#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int t =0;t<T;t++)
    {
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        bool end= false;
        bool all_zero =true;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        for(int i=0;i<n;i++)
        {
            cin>>b[i];
            if(b[i]!=0)all_zero = false;
            if(b[i]>a[i])
            {
                end = true;
            }
        }

        if(all_zero)
        {
            cout<<"Yes"<<endl;
            continue;
        }

        if(end)
        {
            cout<<"No"<<endl;
            continue;
        }

        int d;
        
        for(int i=0;i<n;i++)
        {
            if(b[i]!=0)
            {
                d = a[i]-b[i];
                break;
            }
        }

        bool f = true;
        for(int i=0;i<n && f;i++)
        {
            if(a[i]==0 || b[i]==0)
            {
                if(a[i]-b[i]>d)
                {
                    cout<<"No"<<endl;
                    f = false;
                }
            }else
            {
                if(a[i]-b[i]!=d)
                {
                    cout<<"No"<<endl;
                    f= false;
                }
            }
        }
        if(f)cout<<"Yes"<<endl;
    }
    return 0;
}