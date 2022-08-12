#include <bits/stdc++.h>

using namespace std;

string CheckSpell(const string& spell) {
  // TODO: implement this method to determine if the given spell is valid or not

  return "";
}

int main() {
  int test_case_count;
  cin >> test_case_count;
  string spell;

  for (int tc = 1; tc <= test_case_count; ++tc) {
    cin >> spell;
    cout << "Case #" << tc << ": " << CheckSpell(spell) << "\n";
  }
  return 0;
}
