#include<bits/stdc++.h>
using namespace std;

void number (int m, int s)
{

  int sum = s;

  string mini = "", maxi = "";

  if ((m != -1 and s == 0) or s > 9 * m)
    {
      cout << "-1 -1";
      return;
    }

  for (int i = 0; i < m; i++)
    {
      int x = min (9, s);
      maxi += to_string (x);

      s = s - x;
    }

  for (int i = 0; i < m - 1; i++)
    {
      int x = min (9, sum);
      mini += to_string (x);

      sum -= x;
    }

  mini = to_string (sum) + mini;

  cout << mini << " " << maxi;

  return;

}

int main ()
{

  int m, s;
  cin >> m >> s;

  number (m, s);

  return 0;
}