/*
(((1 + 3) * 4) + 5) + 2
(((x1 o1 x2) o2 x3) o3 x4) o4 x5
*/
#include <cstdio>

typedef unsigned int ui;
typedef unsigned long long ull;
const ui N = 5;
long long numbers[N];
bool taken[N];

bool solve(long long prev, ui op_index)
{
  if (op_index == 4)
    return prev == 23;
  bool res = false;
  for (ui i = 0; i < N; ++i)
  {
    if (taken[i])
      continue;
    taken[i] = true;
    res |= solve(prev + numbers[i], op_index + 1) ||
           solve(prev * numbers[i], op_index + 1) ||
           solve(prev - numbers[i], op_index + 1);
    taken[i] = false;
  }
  return res;
}

int main()
{
  while (true)
  {
    for (ui i = 0; i < 5; ++i)
      scanf("%lld", numbers + i);
    if (numbers[0] == 0)
      break;
    bool res = false;
    for (ui i = 0; i < N; ++i)
    {
      if (taken[i])
        continue;
      taken[i] = true;
      res |= solve(numbers[i], 0) ||
             solve(numbers[i], 0) ||
             solve(numbers[i], 0);
      taken[i] = false;
    }
    printf("%sossible\n", res ? "P" : "Imp");
  }
  return 0;
}
