/*
 */
#include <cstdio>
#include <vector>
#include <unordered_set>

typedef unsigned int ui;
typedef unsigned long long ull;
ui s, t;
std::vector<ui> current_combination;
std::vector<std::vector<ui>> combinations;
const ui S = 103;
std::vector<ui> divisors[S];

bool valid_current_combination()
{
  if (current_combination.size() == 0)
    return true;
  std::unordered_set<ui> unique_divisors;
  ui total_divisors = 0;
  for (ui no : current_combination)
  {
    unique_divisors.insert(divisors[no].begin(), divisors[no].end());
    total_divisors += divisors[no].size() - 1; // Don't include 1
  }
  return unique_divisors.size() - 1 == total_divisors;
}

void solve(ui sum)
{
  ui combination_size = current_combination.size();
  if (combination_size > t || (sum >= s && combination_size != t) || !valid_current_combination())
    return;
  if (sum == s && combination_size == t)
    combinations.push_back(current_combination);
  ui start = combination_size == 0 ? 1 : current_combination[combination_size - 1];
  for (ui i = start; i <= s - sum; ++i)
  {
    current_combination.push_back(i);
    solve(sum + i);
    current_combination.pop_back();
  }
}

int main()
{
  // Generate divisors
  for (ui i = 1; i * i <= S; ++i)
    for (ui j = i; i * j <= S; ++j)
    {
      divisors[i * j].push_back(j);
      if (i != j)
        divisors[i * j].push_back(i);
    }
  ui T;
  scanf("%u", &T);
  for (ui test = 1; test <= T; ++test)
  {
    current_combination.clear();
    combinations.clear();
    printf("Case %u:\n", test);
    scanf("%u%u", &s, &t);
    solve(0);
    for (std::vector<ui> &combination : combinations)
      for (ui i = 0; i < combination.size(); ++i)
        printf("%u%c", combination[i], " \n"[i == combination.size() - 1]);
  }
  return 0;
}
