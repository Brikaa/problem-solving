/*
Is it a palindrome? Can leading zeroes be added to make it a palindrome?

0161000
- Two pointers
- If right pointer is still in the trailing zeroes, we have some tolerance for the left pointer

4020400
*/
#include <iostream>
#include <string>

int main()
{
  std::string in;
  std::cin >> in;
  int l = 0;
  int r = in.size() - 1;
  bool in_trailing_zeroes = true;
  bool palindrome = true;
  while (l < r && palindrome)
  {
    if (in[r] != '0')
      in_trailing_zeroes = false;
    if (in[r] != in[l] && in_trailing_zeroes)
      --r;
    else if (in[r] == in[l])
    {
      ++l;
      --r;
    }
    else
      palindrome = false;
  }
  if (palindrome)
    printf("YES\n");
  else
    printf("NO\n");
}
