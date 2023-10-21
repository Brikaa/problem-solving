#include <iostream>


int arr[] = {0, 2, 5, 1, 8, 9, 33, 22};
const int N = sizeof(arr) / sizeof(N);
int sum_prefix[N];
int sum_suffix[N];
int min_prefix[N];
int min_suffix[N];

int main()
{
  sum_prefix[0] = arr[0];
  min_prefix[0] = arr[0];
  for (int i = 1; i < N; ++i)
  {
    sum_prefix[i] = sum_prefix[i - 1] + arr[i];
    min_prefix[i] = std::min(min_prefix[i - 1], arr[i]);
  }
  return 0;
}
