#include <bits/stdc++.h>

using namespace std;

int positiveAnswersCount(int N, int Q, string blockCharacters, vector<int> L,
                         vector<int> R) {
  // TODO: Complete this function to count number of questions Anna can answer
  // "yes" to
  int cnt = 0;
  for(int i=0;i<Q;i++)
  {
    string str = blockCharacters.substr(L[i]-1,R[i]-L[i]+1);
    map<char,int> m;
    for(char c: str)m[c]++;
    bool flag = true;
    if(str.size()%2==0)
    {
      for(auto it:m)
      {
        if(it.second%2!=0){
          flag = false;
          break;
        }
      }
    }else{
      int k = 0;
      for(auto it:m)
      {
        if(it.second%2!=0){
          k++;
        }
        if(k>1)
        {
          flag = false;
          break;
        }
      }
    }
    if(flag)cnt++;
  }
  return cnt;
}

int main() {
  int T;
  // Get number of test casess
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    int N, Q;
    // Get number of blocks and number of questions
    cin >> N >> Q;

    string blockCharacters;
    // Get the string representing the characters on the blocks
    cin >> blockCharacters;

    vector<int> L(Q), R(Q);
    for (int i = 0; i < Q; i++) {
      cin >> L[i] >> R[i];
    }

    cout << "Case #" << tc << ": "
         << positiveAnswersCount(N, Q, blockCharacters, L, R) << endl;
  }
  return 0;
}
