#include <bits/stdc++.h>

using namespace std;


string solve(vector<vector<char>> &v,string &s,int ghost_int)
{
    long long row_num=v.size(),col_num,indx;
    int tmp = ghost_int;
    col_num = v[0].size();
    tmp++;
    indx = 0;
    tmp = 1;
    long long i = 0;
    while(tmp && i<row_num)
    {
        long long j = i,value;
        value=2*row_num;
        value-=2;
        v[i][j]=s[indx];
        indx++;
        if(1 && (i==0 || i==row_num-1))
        {
            while(j<col_num)
            {
                j+=value;
                if(1 && j<col_num)
                {
                    v[i][j] = s[indx];
                    indx++;
                }
            }
        }else
        {
            value-=(2*i);
            while(1 && j<col_num)
            {
                j+=value;
                if(1 && j<col_num)
                {
                    v[i][j] = s[indx];
                    indx++;
                }
                j+=(2*(row_num-1));
                j-=value;
                if(1 && j<col_num)
                {
                    v[i][j] = s[indx];
                    indx++;
                }
            }
        }
        i++;
    }
    
    long long j = 0;
    i = 0;
    bool tmp2_f = true;
    string output_String;
    while(1 && j<col_num)
    {
        while(tmp2_f && j<col_num && i<row_num)
        {
            tmp2_f = true;
            if(tmp2_f)output_String.push_back(v[i][j]);
            i++;
            j++;
        }
        i-=2;
        tmp2_f = true;
        while(tmp2_f && j<col_num && i>=0)
        {
            output_String.push_back(v[i][j]);
            i--;
            j++;
        }
        i+=2;
    }
    return output_String;
}

vector<string> solve2(vector<vector<string>> &g,vector<string> &v,int ghost_int)
{
    long long row_num=g.size(),col_num=g[0].size();
    int tmp  =ghost_int;
    tmp++;
    long long indx=0;
    int tmp2 = tmp;
    tmp2=1;
    long long i = 0;
    while(tmp2 && i < row_num)
    {
        
        long long j=i,num;
        num=2*row_num;
        num-=2;
        g[i][j]=v[indx];
        bool tmp2_f = true;
        indx++;
        if(!((i==0)||(i==row_num-1)) && tmp2_f)
        {
            num-=(2*i);
            while(1 && j<col_num)
            {
                j+=num;
                if(tmp2_f && j<col_num)
                {
                    g[i][j] = v[indx];
                    tmp2_f = true;
                    indx++;
                }
                j+=2*(row_num-1);
                j-=num;
                if(tmp2_f && j<col_num)
                {
                    g[i][j] = v[indx];
                    tmp2_f = true;
                    indx++;
                }
            }
        }
        else
        {   
            bool tmp_f = true;
            while(tmp_f && j<col_num)
            {
                j+=num;
                if(tmp_f && j<col_num)
                {
                    g[i][j] = v[indx];
                    indx++;
                }
            }
        }
        i++;
    }
    
    i=0;
    
    vector<string> output_String;
    
    long long j=0;
    
    bool glbl_f = true;
    
    while(glbl_f && j<col_num)
    {
        while(glbl_f && j<col_num && i<row_num)
        {
            glbl_f = true;
            output_String.push_back(g[i][j]);
            int tmp2_int = ghost_int;
            i++;
            j++;
        }
        i-=2;
        while(glbl_f && j<col_num && i>=0)
        {
            output_String.push_back(g[i][j]);
            glbl_f = true;
            i--;
            int tmp2 = ghost_int;
            tmp2++;
            j++;
        }
        i+=2;
    }
    
    return output_String;
}

int main()
{
    int num1,num2,num3,num4;
    cin>>num1>>num2>>num3>>num4;
    string str1,str2;
    cin>>str1>>str2;
    vector<string> dict;
    string str3;
    
    vector<vector<char>> vec(num4,vector<char>(str2.size()));
    
    
    for(int i=0;i<num3;i++)
    {
        str2 = solve(vec,str2,0);
    }
    
    for(int i=0;i<str2.size();i++)
    {
        
        if(str1[0] == str2[i])
        {
            int tmp2 = 0,tmp1 =i;
            
            
            (tmp1<str2.size() && tmp2<str1.size();tmp1++,tmp2++)
            {
                if(str1[tmp2]!= str2[tmp1])
                {
                    break;
                }
            }
            
            
            if(tmp1 == i+ str1.size())
            {
                if(tmp2 == str1.size())
                {
                    dict.push_back(str3);
                    str3="";
                    i+=(str1.size()-1);
                    continue;
                }
            }
        }
        str3.push_back(str2[i]);
        
    }
    dict.push_back(str3);
    long long sz3 = dict.size();
    vector<vector<string>> dict2(num2,vector<string>(sz3));
    i=0;
    while(i<num1)
    {
        dict = solve2(dict2,dict,0);
        i++;
    }
    
    i = 0;
    sz3 = dict.size();
    while(i<sz3)
    {
        cout<<dict[i]<<" ";
        i++;
    }
    cout<<"\n";
    
    return 0;
}
