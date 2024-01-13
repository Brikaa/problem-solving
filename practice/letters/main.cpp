#include <iostream>

const int N = 200;
int f_heading['z' - 'A' + 1];
int f_text['z' - 'A' + 1];
char heading[N];
char text[N];

void create_frequency_array(int *f, char *c)
{
  for (; *c; ++c)
  {
    if (*c == ' ')
      continue;
    f[*c - 'A']++;
  }
}

int main()
{
  /*
    - Create frequency array for heading freq_heading
    - Create frequency array for letters freq_text
    - Compare if freq_text[i] > freq_heading[i] for i in range 'A' to 'z': return NO
  */
  std::cin.getline(heading, N);
  std::cin.getline(text, N);
  create_frequency_array(f_heading, heading);
  create_frequency_array(f_text, text);
  for (int i = 0; i <= 'z' - 'A'; ++i)
  {
    if (f_text[i] > f_heading[i])
    {
      std::cout << "NO\n";
      return 0;
    }
  }
  std::cout << "YES\n";
  return 0;
}
