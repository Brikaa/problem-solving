/*
Nb, Ns, Nc: number of bread, sausage, cheese I have respectively
Pb, Ps, Pc: prices

Lets do
Rb, Rs, Rc: number of bread, sausage, cheese in the recipe

ok(req)
  - return money > natural(Pb * (req * Rb - Nb)) + natural(Ps * (req * Rs - Ns)) + natural(Pc * (req * Rc - Nc))
*/
#include <cmath>
#include <cstdio>

long long natural(long long num)
{
  return num >= 0 ? num : 0;
}

const int N = 107;
int rb = 0;
int rs = 0;
int rc = 0;
int pb, ps, pc;
int nb, ns, nc;
char recipe[N];
long long money;

bool ok(long long req)
{
  return money >= natural(pb * (req * rb - nb)) + natural(ps * (req * rs - ns)) + natural(pc * (req * rc - nc));
}

int main()
{
  scanf("%s", recipe);
  scanf("%d%d%d", &nb, &ns, &nc);
  scanf("%d%d%d", &pb, &ps, &pc);
  scanf("%lld", &money);
  for (char *c = recipe; *c; ++c)
  {
    if (*c == 'B')
      ++rb;
    else if (*c == 'S')
      ++rs;
    else if (*c == 'C')
      ++rc;
  }
  long long l = 0;
  long long r = 1e12 + 150;
  while (r - l > 1)
  {
    long long mid = (l + r) / 2;
    if (ok(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%lld\n", l);
  return 0;
}
