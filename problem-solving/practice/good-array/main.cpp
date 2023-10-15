#include <iostream>
#include <vector>

const int N = 2e5;
int arr[N];
std::vector<int> answers;
int main()
{
  /*
    - If removed max, sum of elements must be 2 * second max
    - If removed non-max, sum of elements must be 2 * max
  */
  int n;
  std::cin >> n;
  int max = 0;
  int second_max = 0;
  long long sum = 0;
  for (int i = 0; i < n; ++i)
  {
    int no;
    std::cin >> no;
    sum += no;
    if (no > max)
    {
      second_max = max;
      max = no;
    }
    else if (no > second_max)
    {
      second_max = no;
    }
    arr[i] = no;
  }
  for (int i = 0; i < n; ++i)
  {
    long long rem = sum - arr[i];
    if ((arr[i] == max && rem == 2 * second_max) || (arr[i] != max && rem == 2 * max))
    {
      answers.push_back(i + 1);
    }
  }
  std::cout << answers.size() << '\n';
  for (int answer : answers)
  {
    std::cout << answer << ' ';
  }
  std::cout << '\n';
  return 0;
}
