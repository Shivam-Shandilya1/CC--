#include<iostream>
using namespace std;
int main(){{
    int row;
    cout<<"Enter Your Row: ";
    cin>>row;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<2*row-1;j++)
        {
            if(j<row-i-1 || j>=2*row-i-1)
            {
                cout<<" ";
            }
            else
            {
                cout<<"* ";
            }
        }
        cout<<endl;
    }
    return 0;
}}