/*
4
132 2 32 4321

expected
1
4
9
10

- pair possible because same combination, don't count self: nc2(freq[combination])
- pair possible because common bits: freq[comb1] * freq[comb2]
*/

#include <cstdio>
#include <cmath>
#include <string>
#include <iostream>

int freq[1030];

long long nc2(int n)
{
  if (n < 2)
    return 0;
  long long res = 1;
  for (int i = 1; i <= 2; ++i)
  {
    res *= n - i + 1;
    res /= i;
  }
  return res;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i)
  {
    std::string number;
    std::cin >> number;
    std::string combination = "0000000000";
    for (auto c : number)
      combination[c - '0'] = '1';
    int f = 0;
    for (int i = 0; i <= 10; ++i)
      if (combination[i] == '1')
        f += pow(2, i);
    ++freq[f];
  }
  long long ans = 0;
  for (int i = 1; i < 1024; ++i)
  {
    ans += nc2(freq[i]);
    for (int j = i + 1; j < 1024; ++j)
      if (i & j)
        ans += freq[i] * freq[j];
  }
  std::cout << ans << '\n';
  return 0;
}
