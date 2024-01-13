#include <string>
#include <iostream>
#include <map>

const std::string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";
std::map<char, char> lefts;
std::map<char, char> rights;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  for (int i = 1; i < (int)keyboard.size(); ++i)
    lefts[keyboard[i]] = keyboard[i - 1];
  for (int i = 0; i < (int)keyboard.size() - 1; ++i)
    rights[keyboard[i]] = keyboard[i + 1];
  char shift;
  std::string sentence;
  std::cin >> shift >> sentence;
  std::map<char, char> &m = shift == 'R' ? lefts : rights;
  for (char c : sentence)
    std::cout << m[c];
  std::cout << '\n';
  return 0;
}
