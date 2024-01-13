/*
12378216378126 % 8
= ((123782163781 % 8) * 100 + 26) % 8
*/
#include <string>
#include <iostream>

typedef unsigned int ui;
typedef unsigned long long ull;
std::string digits;

const ui MOD = 15;
const ui N = 1e4 + 5;

bool memo[MOD][N][2];
bool visited[MOD][N][2];

bool solve(int mod, ui idx, bool taken)
{
  bool ok = (mod == 0 && taken);
  if (ok || idx >= digits.size())
    return ok;
  bool &vis = visited[mod][idx][taken];
  bool &res = memo[mod][idx][taken];
  if (!vis)
  {
    vis = true;
    res = solve(mod, idx + 1, taken) || solve((mod * 10 + digits[idx]) % 8, idx + 1, true);
  }
  return res;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> digits;
  bool res = solve(0, 0, false);
  std::cout << (res ? "YES" : "NO") << '\n';
  if (res)
  {
    std::string ans = "";
    ui size = digits.size();
    ui mod = 0;
    bool taken = false;
    for (ui i = 0; i < size; ++i)
    {
      if (!solve(mod, i + 1, taken))
      {
        ans += digits[i];
        mod = (mod * 10 + digits[i]) % 8;
        taken = true;
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}
