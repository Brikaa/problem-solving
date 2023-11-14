#include <iostream>

/*
n elements: arr[n]
m operations (li, ri, di): range to increase by di
k queries (xi, yi): range of operations to do
- Loop over queries producing final summed array of final_summed_operations[m]
- Loop over final_summed_operations producing final_summed_arr[n]
*/

struct Operation
{
  int l;
  int r;
  long long d;
};

const int N = 1e5 + 5;
const int M = N;
const int K = N;

long long arr[N];
long long arr_partial_sum[N];
Operation operations[M];
int operations_partial_sum[M];

int main()
{
  int n, m, k;
  std::cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i)
  {
    std::cin >> arr[i];
  }
  for (int i = 1; i <= m; ++i)
  {
    std::cin >> operations[i].l >> operations[i].r >> operations[i].d;
  }
  for (int i = 1; i <= k; ++i)
  {
    int x, y;
    std::cin >> x >> y;
    ++operations_partial_sum[x];
    --operations_partial_sum[y + 1];
  }
  for (int i = 2; i <= m; ++i)
  {
    operations_partial_sum[i] += operations_partial_sum[i - 1];
    operations[i].d *= operations_partial_sum[i];
  }
  operations[1].d *= operations_partial_sum[1];
  for (int i = 1; i <= m; ++i)
  {
    arr_partial_sum[operations[i].l] += operations[i].d;
    arr_partial_sum[operations[i].r + 1] -= operations[i].d;
  }
  for (int i = 2; i <= n; ++i)
  {
    arr_partial_sum[i] += arr_partial_sum[i - 1];
  }
  for (int i = 1; i <= n; ++i)
  {
    std::cout << arr[i] + arr_partial_sum[i] << " \n"[i == n];
  }
}
