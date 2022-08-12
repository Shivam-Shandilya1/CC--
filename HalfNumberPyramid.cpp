#include <iostream>
using  namespace std;
int main()
{
    int row;
    cout<<"Enter Number of Rows: ";
    cin>>row;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<i+1;
        }
        cout<<endl;
    }
}