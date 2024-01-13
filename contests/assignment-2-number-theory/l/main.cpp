/*
  - and = 1, or = 0: impossible
  - and = 0, or = 1: one is 1 and one is 0
  - and = 1, or = 1: both are 1
  - and = 0, or = 0: both are 0
*/
#include <cstdio>
#include <bitset>
#define uint unsigned int

int main()
{
  uint t;
  scanf("%u", &t);
  while (t--)
  {
    uint a = 0, o = 0;
    scanf("%u%u", &a, &o);
    std::bitset<32> and_bitset(a), or_bitset(o), first_bitset, second_bitset;
    bool first_bitset_bit = true, valid = true;
    for (int i = 31; i >= 0 && valid; --i)
    {
      if (and_bitset[i] && !or_bitset[i])
        valid = false;
      else if (!and_bitset[i] && or_bitset[i])
      {
        first_bitset.set(i, first_bitset_bit);
        second_bitset.set(i, !first_bitset_bit);
        first_bitset_bit = false;
      }
      else
      {
        first_bitset.set(i, and_bitset[i]);
        second_bitset.set(i, and_bitset[i]);
      }
    }
    if (valid)
      printf("%lu %lu\n", second_bitset.to_ulong(), first_bitset.to_ulong());
    else
      printf("-1\n");
  }
  return 0;
}
