#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    ifstream file("input.txt");
    if(!file)
    {
        cout<<"Error opening output file"<<endl;
        system("pause");
        return -1;
    } 
    int cnt = 0,CardV1=0,CardV2=0,adjmatrixsize=0;;
    while(file >> n)
    {
        if(cnt == 0)
        {
            CardV1=n;
        }else if(cnt == 1)
        {
            CardV2=n;
        }
        cnt++;
        adjmatrixsize = CardV1+CardV2;
    }
    return 0;
}