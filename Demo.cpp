// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
    int input,num=6;
    cout << "INPUT: ";
    cin>>input;
    vector<int> v;
    while(v.size()<input)
    {
        int i=2,count=0,term=0;
        while(i*i<=num)
        {
            if(num%i==0)
            {
                ((double)num/i==(double)i)?count++:count+=2;
            }
            i++;
            term++;
        }
        cout<<count<<endl;
        if(count==2 && term==1)v.push_back(num);
        num++;
    }
    cout<<"Hello"<<v[input-1]<<endl;
    return 0;
}