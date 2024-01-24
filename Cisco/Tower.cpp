#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &dp,int N,vector<int> &A,int i)
{
    if(i>=N)return 1e9;
    if(i == N-1)return 0;
    if(dp[i]!=-1)return dp[i];
    int op1 = 1e9,op2 = 1e9;
    if(i+1 < N)op1 = solve(dp,N,A,i+1) + abs(A[i+1] - A[i]);
    if(i+3 < N)op2 = solve(dp,N,A,i+3) + abs(A[i+3] - A[i]);
    return dp[i] = min(op1,op2); 
}
int MinCost(int N,vector<int> &A)
{
    vector<int> dp(N,-1);
    return solve(dp,N,A,0);
}
int main()
{
    int N;
    cin>>N;
    vector<int> A(N);
    for(int i = 0;i<N;i++)
    {
        cin>>A[i];
    }
    cout<<MinCost(N,A)<<endl;
    return 0;
}

// void findMeanMedianMode(int N, vector<int>& A, double& mean, double& median, int& mode) {
//     double sum = 0;
//     for(int num : A) {
//         sum += num;
//     }
//     mean = sum / N;
//     sort(A.begin(), A.end());
//     if(N % 2 == 0) {
//         median = (A[N/2 - 1] + A[N/2]) / 2.0;
//     } else {
//         median = A[N/2];
//     }
//     map<int, int> freqMap;
//     for(int num : A) {
//         freqMap[num]++;
//     }
//     int maxFreq = 0;
//     for(auto& [num, freq] : freqMap) {
//         if(freq > maxFreq) {
//             maxFreq = freq;
//             mode = num;
//         }
//     }
// }

// int main() {
//     int N;
//     cin >> N;
    
//     vector<int> A(N);
//     for(int i = 0; i < N; i++) {
//         cin >> A[i];
//     }
    
//     double mean, median;
//     int mode;
//     findMeanMedianMode(N, A, mean, median, mode);
//     cout << fixed << setprecision(6);
//     cout << "Mean: " << mean << endl;
//     cout << "Median: " << median << endl;
//     cout << "Mode: " << mode << endl;
    
//     return 0;
// }