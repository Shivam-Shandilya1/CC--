#include<iostream>
using namespace std;
int main(){{
    int row;
    cout<<"Enter Number of Rows: ";
    cin>>row;
    for(int i=0;i<row;i++){
        for(int j=0;j<row;j++){
         if(j<=i){
             cout<<'*';
         }
         else
         {
             cout<<" ";
         }
        }
        for(int j=row;j<2*row;j++){
            if(j<2*row-i-1){
              cout<<' ';
            }else
            {
                cout<<'*';
            }
        }
        cout<<endl;
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<row;j++){
         if(j<row-i){
             cout<<'*';
         }
         else
         {
             cout<<" ";
         }
        }
        for(int j=row;j<2*row;j++){
            if(j<row+i){
              cout<<' ';
            }else
            {
                cout<<'*';
            }
        }
        cout<<endl;
    }
    return 0;
}}