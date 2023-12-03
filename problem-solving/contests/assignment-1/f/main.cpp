/*
Get the number of spaces after merging the two surfaces
- Get the shortest distance on all lines (least number of whitespaces)
- for each line, voids += no_spaces - shortest distance
*/
#include <string>
#include <algorithm>
#include <iostream>

const int N = 17;
std::string lines[N];

int main()
{
  while (true)
  {
    std::string n_str;
    std::getline(std::cin, n_str);
    int n = atoi(n_str.c_str());
    if (n == 0)
      break;
    for (int i = 0; i < n; ++i)
      std::getline(std::cin, lines[i]);
    int min_spaces = 50;
    for (int i = 0; i < n; ++i)
      min_spaces = std::min(min_spaces, (int)std::count(lines[i].begin(), lines[i].end(), ' '));
    int voids = 0;
    for (int i = 0; i < n; ++i)
      voids += (int)std::count(lines[i].begin(), lines[i].end(), ' ') - min_spaces;
    std::cout << voids << '\n';
  }
}
