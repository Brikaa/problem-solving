#include <iostream>
#include <vector>

int main()
{
  int n;
  std::vector<int> v;
  std::cin >> n;

  for (int i = 0; i < n; ++i)
  {
    int no;
    std::cin >> no;
    v.push_back(no);
  }

  int max = v[0];
  for (int i = 1; i < n; ++i)
  {
    max = v[i] > max ? v[i] : max;
  }

  int *arr = new int[max];
  for (int i = 0; i < max; ++i)
  {
    arr[i] = 0;
  }
  for (int i : v)
  {
    arr[i]++;
  }

  int no_to_check_for;
  std::cin >> no_to_check_for;
  std::cout << arr[no_to_check_for] << '\n';
}
