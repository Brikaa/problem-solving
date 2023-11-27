/*
n items needed to make brownie
k grams special item
ai grams of item i needed in one brownie
I have xi grams of item i

Can I make n brownies
  - need n * ai gram of item i
*/
#include <cstdio>
#include <iostream>

const int N = 1e5 + 5;
int n;
long long special;
long long have[N];
long long needed[N];

bool ok(long long req)
{
  long long special_left = special;
  for (int i = 0; i < n; ++i)
  {
    if (have[i] < req * needed[i])
      special_left -= req * needed[i] - have[i];
    if (special_left < 0)
    {
      return false;
    }
  }
  return special_left >= 0;
}

int main()
{
  std::cin >> n >> special;
  for (int i = 0; i < n; ++i)
  {
    std::cin >> needed[i];
  }
  for (int i = 0; i < n; ++i)
  {
    std::cin >> have[i];
  }
  long long l = 0;
  long long r = 2e9 + 150;
  while (r - l > 1)
  {
    long long mid = (r + l) / 2;
    if (ok(mid))
      l = mid;
    else
      r = mid;
  }
  std::cout << l << '\n';
}
