/*
find laptop[i]
such that laptop[i].quality > laptop[i - 1].quality && laptop[i].price < laptop[i - 1].price

(3, 3), (3, 5), (2, 4)
*/
#include <cstdio>
#include <algorithm>

struct Laptop
{
  int price;
  int quality;
};

bool greater(Laptop &l1, Laptop &l2)
{
  return l1.price > l2.price;
}

const int N = 1e5 + 5;
Laptop laptops[N];
Laptop laptops_consolidated[N];

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d%d", &(laptops[i].price), &(laptops[i].quality));
  std::sort(laptops, laptops + n, greater);

  int no_consolidated = 1;
  laptops_consolidated[0] = laptops[0];
  for (int i = 1; i < n; ++i)
  {
    if (laptops[i].price == laptops[i - 1].price)
      laptops_consolidated[no_consolidated - 1] = laptops[i].quality < laptops[i - 1].quality
                                                      ? laptops[i]
                                                      : laptops[i - 1];
    else
      laptops_consolidated[no_consolidated++] = laptops[i];
  }

  bool found = false;
  for (int i = 1; i < n; ++i)
  {
    if (laptops_consolidated[i].quality > laptops_consolidated[i - 1].quality)
    {
      found = true;
      printf("Happy Alex\n");
      break;
    }
  }
  if (!found)
    printf("Poor Alex\n");
  return 0;
}
