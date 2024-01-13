/*
- I can create 2 ^ n - 1 out of two numbers whose sum is 2 ^ n - 1
- Any number xor itself is 0
- If you want to generate any number using another number
  - x ^ target = z
  - then x ^ z = target
- 0 xor any number is the number

- 262143
- Identity requires 4 numbers (don't use 1 to 14, target, (target + 1) ^ target, (target + 2) ^ (target + 1))
- n % 4 == 1
  - Identity, target
  - If number == 0: 3 ^ 5 ^ 7 ^ 8 ^ 9 instead of last identity, if n==1: invalid
- n % 4 == 2
  - identity, 262143 ^ (262143 ^ target)
  - If number == 0: 3 ^ 4 ^ 5 ^ 7 ^ 8 ^ 13 instead of last identity, if n==2: invalid
- n % 4 == 3
  - identity, 262143 ^ (262143 ^ target + 1) ^ ((target + 1) ^ (target))
  - If number == 0: 1 ^ 3 ^ 4 ^ 5 ^ 7 ^ 8 ^ 12 instead of last identity, if n==3: 1 ^ 2 ^ 3
- n % 4 == 0
  - identity, 262143 ^ (262143 ^ target + 2) ^ ((target + 2) ^ (target + 1)) ^ ((target + 1) ^ target)
  - If number == 0: identity
*/
#include <cstdio>
#include <unordered_set>
#include <vector>

typedef unsigned int uint;
typedef unsigned long long ulong;

int main()
{
  const uint factor = 262143;
  uint n, target;
  scanf("%u%u", &n, &target);
  if (n == 2 && target == 0)
    printf("NO\n");
  else if (n == 3 && target == 0)
    printf("YES\n1 2 3\n");
  else if (n == 1 && target == 0)
    printf("YES\n0\n");
  else
  {
    std::vector<uint> ans;
    std::unordered_set<uint> disallowed = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
        target, (target + 1) ^ target, (target + 2) ^ (target + 1), factor, factor ^ (target + 2)};
    uint no_identities = (n / 4);
    if ((n % 4 == 0 && target != 0) || (n % 4 > 0 && target == 0))
      --no_identities;
    uint b = 15;
    uint no_iterations = no_identities * 2;
    while (no_iterations--)
    {
      while (disallowed.find(b) != disallowed.end() || disallowed.find(factor - b) != disallowed.end())
        ++b;
      ans.push_back(b);
      ans.push_back(factor - b);
      ++b;
    }
    if (n % 4 == 1 && target != 0)
    {
      ans.push_back(target);
    }
    else if (n % 4 == 1 && target == 0)
    {
      ans.push_back(3);
      ans.push_back(5);
      ans.push_back(7);
      ans.push_back(8);
      ans.push_back(9);
    }
    if (n % 4 == 2 && target != 0)
    {
      ans.push_back(factor);
      ans.push_back(factor ^ target);
    }
    else if (n % 4 == 2 && target == 0)
    {
      ans.push_back(3);
      ans.push_back(4);
      ans.push_back(5);
      ans.push_back(7);
      ans.push_back(8);
      ans.push_back(13);
    }
    else if (n % 4 == 3 && target != 0)
    {
      ans.push_back(factor);
      ans.push_back(factor ^ (target + 1));
      ans.push_back((target + 1) ^ (target));
    }
    else if (n % 4 == 3 && target == 0)
    {
      ans.push_back(1);
      ans.push_back(3);
      ans.push_back(4);
      ans.push_back(5);
      ans.push_back(7);
      ans.push_back(8);
      ans.push_back(12);
    }
    else if (n % 4 == 0 && target != 0)
    {
      ans.push_back(factor);
      ans.push_back(factor ^ (target + 2));
      ans.push_back((target + 2) ^ (target + 1));
      ans.push_back((target + 1) ^ target);
    }
    printf("YES\n");
    for (uint i = 0; i < ans.size(); ++i)
      printf("%u%c", ans[i], " \n"[i == ans.size() - 1]);
    // for (uint i = 0; i < ans.size(); ++i)
    //   fprintf(stderr, "%u%c", ans[i], "^\n"[i == ans.size() - 1]);
  }
  return 0;
}
