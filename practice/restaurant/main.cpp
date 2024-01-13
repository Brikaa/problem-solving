/*
n orders
li: start time for order i
ri: end time for order i
(1 3), (4 12)
(1, 3), (1, 4), (1, 5), (4, 8), (1, 9), (9, 10), (11, 12)
^                         ^                 ^        ^
*/
#include <stdio.h>
#include <algorithm>

struct Order
{
  int l;
  int r;
};
const int N = 5e5 + 5;
Order orders[N];

bool smaller(Order &r1, Order &r2)
{
  return r1.r < r2.r;
}

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    scanf("%d%d", &(orders[i].l), &(orders[i].r));
  }
  std::sort(orders, orders + n, smaller);
  Order prev_choice = orders[0];
  int no_orders = 1;
  for (int i = 1; i < n; ++i)
  {
    if (orders[i].l > prev_choice.r)
    {
      prev_choice = orders[i];
      ++no_orders;
    }
  }
  printf("%d\n", no_orders);
  return 0;
}
