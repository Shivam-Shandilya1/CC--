/*Author: Shivam Shandilya */
/*Link Section */
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
/*Global Decalaration Section */
/* main() function section */
int main()
{
    int rows,col;
  cout<<"Enter Rows: ";
  cin>> rows;
  cout<<"Enter Column: ";
  cin>> col;
for(int i=0;i<rows;i++){
    for(int j=0;j<col;j++){
        if(i>=1 && i<rows-1)
        {
        if(j==0 || j==col-1)
        {
            cout<<'*';
        }else
        {
            
                cout<<" ";
            
        } 
        }
        else
        {
            
            cout<<'*';
            
        }
}
 cout<<endl;
}
return 0;
}