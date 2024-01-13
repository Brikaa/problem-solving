#include <set>
#include <string>
#include <iostream>
#include <vector>

std::set<std::string> words;

int main()
{
  std::string word;
  while (std::cin >> word)
  {
    std::string sanitized = "";
    std::vector<std::string> words_vec;
    for (auto letter : word)
    {
      if (isalpha(letter))
        sanitized += tolower(letter);
      else
      {
        words_vec.push_back(sanitized);
        sanitized = "";
      }
    }
    words_vec.push_back(sanitized);
    for (auto w : words_vec)
      if (w != "")
        words.insert(w);
  }
  for (auto word : words)
    std::cout << word << '\n';
}
