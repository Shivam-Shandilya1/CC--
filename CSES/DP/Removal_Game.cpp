<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

// int solve(vector<int> &list,int sum,int l,int r,int turn)
// {
//     if(l>r)return sum;
//     if(!turn) return max(solve(list,sum+list[l-1],l+1,r,1),solve(list,sum+list[r-1],l,r-1,1));
//     else return min(solve(list,sum,l+1,r,0),solve(list,sum,l,r-1,0));
// }
int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  long long sum = 0;
  for (int&v : x) {
    cin >> v;
    sum += v;
  }

  vector<vector<long long>> dp(n,vector<long long>(n));
  for (int l = n-1; l >= 0; l--) {
    for (int r = l; r < n; r++) {
      if (l == r) {
	dp[l][r] = x[l];
      } else {
	dp[l][r] = max(x[l]-dp[l+1][r],
		       x[r]-dp[l][r-1]);
      }
    }
  }
  cout << (sum+dp[0][n-1])/2 << endl;
=======
#include<bits/stdc++.h>
using namespace std;

// int solve(vector<int> &list,int sum,int l,int r,int turn)
// {
//     if(l>r)return sum;
//     if(!turn) return max(solve(list,sum+list[l-1],l+1,r,1),solve(list,sum+list[r-1],l,r-1,1));
//     else return min(solve(list,sum,l+1,r,0),solve(list,sum,l,r-1,0));
// }
int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  long long sum = 0;
  for (int&v : x) {
    cin >> v;
    sum += v;
  }

  vector<vector<long long>> dp(n,vector<long long>(n));
  for (int l = n-1; l >= 0; l--) {
    for (int r = l; r < n; r++) {
      if (l == r) {
	dp[l][r] = x[l];
      } else {
	dp[l][r] = max(x[l]-dp[l+1][r],
		       x[r]-dp[l][r-1]);
      }
    }
  }
  cout << (sum+dp[0][n-1])/2 << endl;
>>>>>>> ac692f2be99fee60a2c70d2afe7883dc73991ee6
}