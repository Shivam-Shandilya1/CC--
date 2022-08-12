#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool reachDestination(int sx, int sy, int dx, int dy) {
    // Write your code here
     while(dx!=sx || dy!=sy)
     {
         cout<<"Start:"<<dx<<" "<<dy<<endl;
         if(dx-dy>=sx)
         {
             
             dx-=dy; 
         }else if(dy-dx>=sy)
         {
             
             dy-=dx;
         }else
         {
             
             return false;
         }
         
     }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a,b,c,d;
        cin >> a>> b>> c>> d;

        
        if(reachDestination(a,b,c,d)){
            cout<< "true" << endl;
        }
        else{
            cout << "false" << endl;
        }
    }
}