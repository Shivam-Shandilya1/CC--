#include <iostream>
#include <string>

using namespace std;

string GetRuler(const string& kingdom) {
  // TODO: implement this method to determine the ruler name, given the kingdom.
  string ruler = "";
  if(kingdom[kingdom.size()-1] == 'a' || kingdom[kingdom.size()-1] == 'e' ||kingdom[kingdom.size()-1] == 'i' ||kingdom[kingdom.size()-1] == 'o' ||kingdom[kingdom.size()-1] == 'u' ||kingdom[kingdom.size()-1] == 'A' ||kingdom[kingdom.size()-1] == 'E' ||kingdom[kingdom.size()-1] == 'I' ||kingdom[kingdom.size()-1] == 'O' ||kingdom[kingdom.size()-1] == 'U')
  {
    ruler = "Alice";
  }else if(kingdom[kingdom.size()-1] == 'y'||kingdom[kingdom.size()-1] == 'Y')
  {
    ruler="nobody";
  }else
  {
    ruler="Bob";
  }
  return ruler;
}

int main() {
  int testcases;
  cin >> testcases;
  string kingdom;

  for (int t = 1; t <= testcases; ++t) {
    cin >> kingdom;
    cout << "Case #" << t << ": " << kingdom << " is ruled by "
         << GetRuler(kingdom) << ".\n";
  }
  return 0;
}
