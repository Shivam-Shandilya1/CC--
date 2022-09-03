#include <bits/stdc++.h>
using namespace std;
int main() {
	int N,K;
	cin>>N>>K;
	vector<int> choc(N);
	for(auto &it:choc)cin>>it;

	vector<vector<int>> dp(N,vector<int>(N,0));

	for(int i=0;i<N;i++)dp[i][i]=1;
	for(int i = N-1;i>=0;i--)
	{
		for(int j=i+1;j<N;j++)
		{
			if(choc[i] == choc[j])
			{
				dp[i][j]=1;
				int sum = 0;
				for(int k1 = 1;k1<=K;k1++)
				{
					for(int k2=1;k2<=K;k2++)
					{
						if(i+k1<N && j>=k2 && i+k1<=j-k2)sum=sum||dp[i+k1][j-k2];
					}
				}
				dp[i][j] = sum;
			}
		}
	}
	if(dp[0][N-1])cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}