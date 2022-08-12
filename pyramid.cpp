#include<iostream>
using namespace std;
int main()
{
    int row;
    cout<<"Enter Row: ";
    cin>>row;
    for(int i=0;i<row;i++)
    {
        int count=1;
        for(int j=0;j<2*row;j++)
        {
          if(j<row-i){
              cout<<" ";
          }
          else if(j>=row-i && j<=row)
          {
              cout<<count<<" ";
              count++;
          }
        }
        cout<<endl;
    }
    return 0;
}