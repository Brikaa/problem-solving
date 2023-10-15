#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> answers;
std::unordered_map<long long, std::vector<int>> positions;
long long sum = 0;
int max = 0, second_max = 0, n;
int main()
{
  /*
    - Max is a nice number if 2 * second_max = sum_array - max
    - x is a nice number if 2 * max = sum_array - x
    - x = sum_array - 2 * max
  */
  std::cin >> n;
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
    positions[no].push_back(i + 1);
  }
  if (2 * second_max == sum - max)
    answers.insert(answers.end(), positions[max].begin(), positions[max].end());
  long long rem = sum - 2 * max;
  if (rem != max)
    answers.insert(answers.end(), positions[rem].begin(), positions[rem].end());

  std::cout << answers.size() << '\n';
  for (int answer : answers)
  {
    std::cout << answer << ' ';
  }
  std::cout << '\n';

  return 0;
}
