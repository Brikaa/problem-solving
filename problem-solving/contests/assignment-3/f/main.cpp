/*
- Items from 1 to n
- Can buy p items
- Price of an item is xi + ai * p
  - xi base cost
  - ai index of the item
  - p number of items

ok
  - sort by xi + ai * p
  - Try to buy till pth item
*/
#include <algorithm>
#include <cstdio>

struct Item
{
  int index;
  int base_price;
  int price;
};

const int N = 1e5 + 5;
Item items[N];
int n;
int k;

bool less_than(Item a, Item b)
{
  return a.price < b.price;
}

bool ok(int req, int &spent)
{
  spent = 0;
  if (req > n)
    return false;
  for (int i = 1; i <= n; ++i)
  {
    items[i].price = items[i].base_price + items[i].index * req;
  }
  std::sort(items + 1, items + n + 1, less_than);
  for (int i = 1; i <= req; ++i)
  {
    spent += items[i].price;
    if (spent > k)
      return false;
  }
  return spent <= k;
}

int main()
{
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i)
  {
    items[i].index = i;
    scanf("%d", &(items[i].base_price));
  }
  int l = 0;
  int r = n + 3;
  int spent_ref = 0;
  int spent = 0;
  while (r - l != 1)
  {
    int mid = (r + l) / 2;
    if (ok(mid, spent_ref))
    {
      l = mid;
      spent = spent_ref;
    }
    else
      r = mid;
  }
  printf("%d %d\n", l, spent);
}
