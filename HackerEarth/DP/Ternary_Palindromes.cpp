#include <bits/stdc++.h>
using namespace std;

bool hasPalSub(string S)
{
	for(int i=0;i<S.size()-1;i++)
	{
		int l = i,r = i;
		if(r<S.size() && S[r]==S[r+1])
		{
			return true;
		}
		if(S[l-1]==S[r+1])return true;
	}
	return false;
}

int main() {
	int T;
	cin>>T;

	for(int t=0;t<T;t++)
	{
		string S;
		cin>>S;
		cout<<hasPalSub(S)<<endl;
	}
}