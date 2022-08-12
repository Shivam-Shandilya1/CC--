#include <bits/stdc++.h>
using namespace std;
void ArtWork(int R, int C)
{
    for(int i=0;i<=2*R;i++)
    {
        for(int j=0;j<=2*C;j++)
        {
            if(i%2==0)
            {
                if(j%2==0)
                {
                    if((i==0 || i==1)&&j==0)cout<<".";
                    else cout<<"+";
                }
                else
                {
                    if(j==1 && (i==0||i==1))cout<<".";
                    else cout<<"-";
                } 
            }else
            {
                if(j%2==0)
                {
                    if((i==0 || i==1)&&j==0)cout<<".";
                    else cout<<"|";
                }
                else cout<<".";
            }
        }
        cout<<endl;
    }
}
int main()
{
    int T,R,C;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>R>>C;
        cout<<"Case #"<<i+1<<":"<<endl;
        ArtWork(R,C);
    }
    return 0;
}