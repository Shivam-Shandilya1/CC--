vector<int> Solution::incorrectValues(vector<vector<int> > &A) {
    int cntt=0;
    for(int i=0;A.size();i++)
    {
        for(int j=A[i][0];j<=A[i][1];j++)
        {
            if(fn(A[i][0],A[i][1],j))
            {
                cntt++;
            }
        }
        int total = A[i][1]-A[i][0]+1;
        if(total%cntt==0)
        {
            total=total/cntt;
            cntt=1;
        }
        cout<<(cntt*(1/total))%(1000000007)<<endl;
    }
    return 0;
}

bool fn(int l,int r, int k)
{
    bool f=false;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(k<mid)
        {
            r=mid-1;
        }
        else if(k>mid)
        {
            l=mid+1;
        }
        else{
            f=true;
            return f;
        }
    }
    return f;
}