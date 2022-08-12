#include <bits/stdc++.h>
using namespace std;

vector<int> GetHIndexScore(vector<int> citations_per_paper) {
  vector<int> h_index;
  // TODO: Calculate and return h-index score for each paper.
  priority_queue<int,vector<int>,greater<int>> q;
  int k=1,past=0;
  for(int i=0;i<citations_per_paper.size();i++)
  {
    
    if(citations_per_paper[i]>=k)
    {
      q.push(citations_per_paper[i]);
      
    }
    if(q.size()>=k)
    {
        h_index.push_back(k);
        past=k;
        k++;
        
        while(q.top()<k && !q.empty())
        {
         
          q.pop();
        }
       
    }else
    {
        h_index.push_back(past);
    }
    
  }
  
  return h_index;
}

int main() {
  int tests;
  cin >> tests;
  for (int test_case = 1; test_case <= tests; test_case++) {
    // Get number of papers for this test case
    int paper_count;
    cin >> paper_count;
    // Get number of citations for each paper
    vector<int> citations(paper_count);
    for (int i = 0; i < paper_count; i++) {
      cin >> citations[i];
    }
    vector<int> answer = GetHIndexScore(citations);
    cout << "Case #" << test_case << ": ";
    for (int i = 0; i < answer.size(); i++) {
      cout << answer[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
