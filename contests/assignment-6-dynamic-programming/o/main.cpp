/*
10 33
*/

#include <string>
#include <iostream>

typedef unsigned int ui;
typedef unsigned long long ull;

const ui N = 10;
const ui S = 100;
std::string l;
std::string r;
ui n;
ui memo[N][S][2][2];
ui visited[N][S][2][2];
ui vid;

ui is_prime(ui number)
{
  if (number == 1 || number == 0)
    return false;
  for (ui i = 2; i * i <= number; ++i)
    if (number % i == 0)
      return false;
  return true;
}

ui solve(ui idx, ui sum, bool prev_equal_lb, bool prev_equal_ub)
{
  if (idx == n)
    return is_prime(sum);
  ui &vis = visited[idx][sum][prev_equal_lb][prev_equal_ub];
  ui &ret = memo[idx][sum][prev_equal_lb][prev_equal_ub];
  if (vis != vid)
  {
    vis = vid;
    ui start = prev_equal_lb ? l[idx] - '0' : 0;
    ui end = prev_equal_ub ? r[idx] - '0' : 9;
    ret = 0;
    for (ui i = start; i <= end; ++i)
      ret += solve(idx + 1, sum + i, prev_equal_lb && i == start, prev_equal_ub && i == end);
  }
  return ret;
}
int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  ui t;
  std::cin >> t;
  while (t--)
  {
    ++vid;
    std::cin >> l >> r;
    while (l.size() < r.size())
      l = "0" + l;
    n = l.size();
    std::cout << solve(0, 0, true, true) << '\n';
  }
  return 0;
}
