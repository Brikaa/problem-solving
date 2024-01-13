/*
Call comes
- If employee away, forward to another employee
- If another employee away, forward to another employee
- And so on
*/
#include <cstdio>
#include <unordered_map>
#include <unordered_set>

typedef unsigned int ui;
typedef unsigned long long ull;

// Employee xxxx shall forward in time yyyy to zzzz
std::unordered_map<ui, std::unordered_map<ui, ui>> forward;

int main()
{
  ui T;
  scanf("%u", &T);
  printf("CALL FORWARDING OUTPUT\n");
  for (ui system = 1; system <= T; ++system)
  {
    forward.clear();
    printf("SYSTEM %d\n", system);
    // source time duration target
    while (true)
    {
      ui source, time, duration, target;
      scanf("%u", &source);
      if (source == 0)
        break;
      scanf("%u%u%u", &time, &duration, &target);
      for (ui t = time; t <= time + duration; ++t)
        forward[source][t] = target;
    }
    while (true)
    {
      ui time, extension;
      scanf("%u", &time);
      if (time == 9000)
        break;
      scanf("%u", &extension);
      std::unordered_set<ui> taken;
      ui current_employee = extension;
      bool valid = true;
      while (forward[current_employee][time] != 0 && valid)
      {
        current_employee = forward[current_employee][time];
        if (taken.find(current_employee) != taken.end())
          valid = false;
        taken.insert(current_employee);
      }
      if (!valid)
        current_employee = 9999;
      printf("AT %04d CALL TO %04d RINGS %04d\n", time, extension, current_employee);
    }
  }
  printf("END OF OUTPUT\n");
  return 0;
}
