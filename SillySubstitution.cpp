#include <bits/stdc++.h>
using namespace std;
int main()
{
    int input;
    cin>>input;
    for(int i=0;i<input;i++)
    {
        string S;
        int size;
        cin>>size;
        cin>>S;
        int pos= INT_MAX;
        string result=S;
        while(pos!=-1)
        {
            if(result.find("01")!=-1)
        {
            pos = result.find("01");
            result=result.substr(0,pos)+"2"+result.substr(pos+2); 
        }if(result.find("12")!=-1)
        {
            pos = result.find("12");
            result=result.substr(0,pos)+"3"+result.substr(pos+2); 
        }if(result.find("23")!=-1)
        {
            pos = result.find("23");
            result=result.substr(0,pos)+"4"+result.substr(pos+2); 
        }if(result.find("34")!=-1)
        {
            pos = result.find("34");
            result=result.substr(0,pos)+"5"+result.substr(pos+2); 
        }if(result.find("45")!=-1)
        {
            pos = result.find("45");
            result=result.substr(0,pos)+"6"+result.substr(pos+2); 
        }if(result.find("56")!=-1)
        {
            pos = result.find("56");
            result=result.substr(0,pos)+"7"+result.substr(pos+2); 
        }if(result.find("67")!=-1)
        {
            pos = result.find("67");
            result=result.substr(0,pos)+"8"+result.substr(pos+2); 
        }if(result.find("78")!=-1)
        {
            pos = result.find("78");
            result=result.substr(0,pos)+"9"+result.substr(pos+2); 
        }if(result.find("89")!=-1)
        {
            pos = result.find("89");
            result=result.substr(0,pos)+"0"+result.substr(pos+2); 
        }if(result.find("90")!=-1)
        {
            pos = result.find("90");
            result=result.substr(0,pos)+"1"+result.substr(pos+2); 
        }else
        {
            pos = -1;
            break;
        }         
        }
        cout<<"Case #"<<i+1<<": "<<result<<endl;
        pos = INT_MAX;
    }
return 0;
}