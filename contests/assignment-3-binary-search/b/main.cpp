/*
ok(req)
  - Put pointer on maximum and pointer on minimum
  - while
    - if element at maximum pointer is lower than req, return false
    - if maximum pointer eq minimum pointer, return true
    - Give from maximum to minimum till either maximum becomes req or minimum becomes req
    - If maximum above req
      - Increase minimum pointer
    - If minimum below req or maximum eq req
      - Increase maximum pointer

  - a b req k x
  - b + x - x * k / 100 = req
  - x * (1 - k / 100) = req - b
  - x = (req - b) / (1 - k / 100)
  - if a - x < req
    - x = a - req
*/
#include <vector>
#include <cstdio>
#include <algorithm>

int n;
int k;

bool ok(double req, std::vector<double> power)
{
  int min_p = 0;
  int max_p = n - 1;
  while (max_p != min_p)
  {
    if (power[max_p] < req)
      return false;
    if (power[min_p] > req)
      return true;
    double x = (req - power[min_p]) / (1 - k / 100.0);
    bool is_enough = true;
    if (power[max_p] - x < req)
    {
      is_enough = false;
      x = power[max_p] - req;
    }
    // fprintf(stderr, "req: %.7f, min: %.7f, k: %d, x: %.7f, is enough: %d\n", req, power[min_p], k, x, is_enough);
    power[max_p] -= x;
    power[min_p] += x - x * k / 100.0;
    if (is_enough)
      ++min_p;
    else
      --max_p;
  }
  // fprintf(stderr, "Exiting while\n");
  return power[max_p] >= req;
}

int main()
{
  scanf("%d%d", &n, &k);
  std::vector<double> power;
  for (int i = 0; i < n; ++i)
  {
    int e;
    scanf("%d", &e);
    power.push_back(e);
  }
  std::sort(power.begin(), power.end());
  double l = 0;
  double r = power[n - 1];
  while (r - l > 1e-7)
  {
    double mid = (r + l) / 2;
    // fprintf(stderr, "l: %.7f r: %.7f\n", l, r);
    if (ok(mid, power))
      l = mid;
    else
      r = mid;
  }
  printf("%.7f\n", l);
  return 0;
}
