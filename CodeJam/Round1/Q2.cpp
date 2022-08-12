#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int i=0; i<T; i++)
    {
        string str;
        cin>>str;
        string s;
        bool flag =true;
        for(int j=0;j<str.size()-1;j++)
        {
            flag = true;
            int k = j;
            if(str[k]==str[k+1])
            {
                while(k<str.size()-1 && str[k]==str[k+1])
                {
                    k++;
                }
                
                if(k!=str.size()-1)
                {
                    if(str[k]>str[k+1])
                    {
                        flag = false;
                    }
                }else
                {
                    flag = false;
                }
            }
            
            s.push_back(str[j]);
            if(str[j]<str[j+1])
            {
                s.push_back(str[j]);
            }else if(str[j]==str[j+1])
            {
                if(flag)
                {
                        s.push_back(str[j]);
                }
            }
        }
        s.push_back(str[str.size()-1]);
        cout<<"Case #"<<i+1<<": "<<s<<endl;
    }
    return 0;
}