#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter Row: ";
    int row,count;
    cin>>row;
    for(int i=0;i<row;i++){
        count=1;
        int count2=row;
        for(int j=0;j<row-i;j++){
            cout<<"  ";
        }
        for(int j=0;j<i;j++)
        {
            cout<<count2<<" ";
        }
    
        for(int j=0;j<=i;j++){
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
      
    return 0;
}