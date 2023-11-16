/*
m markers
c caps
mi.d diameter of marker i
mi.c color of marker i
ci.d diameter of cap i
ci.c color of cap i

- for diameter in diameter_to_marker_colors
  - matching_caps = diameter_to_cap_colors[diameter]
  - marker_colors = diameter_to_marker_colors[diameter]
  - for color in marker_colors
    - remove matching_caps[color]
    - if removed
      - beautifully_closed++
  - normally_closed += min(matching_caps.size(), marker_colors.size())
*/
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stdio.h>
#include <algorithm>

int main()
{
  std::unordered_map<int, std::vector<int>> diameter_to_marker_colors;
  std::unordered_map<int, std::unordered_multiset<int>> diameter_to_cap_colors;
  int non_beautifully_closed = 0;
  int beautifully_closed = 0;
  int n, m;
  scanf("%d%d", &n, &m);
  while (n--)
  {
    int d, c;
    scanf("%d%d", &c, &d);
    diameter_to_marker_colors[d].push_back(c);
  }
  while (m--)
  {
    int d, c;
    scanf("%d%d", &c, &d);
    diameter_to_cap_colors[d].insert(c);
  }
  for (auto &m_pair : diameter_to_marker_colors)
  {
    std::unordered_multiset<int> &matching_caps = diameter_to_cap_colors[m_pair.first];
    std::vector<int> &marker_colors = m_pair.second;
    int remaining_markers = 0;
    for (int color : marker_colors)
    {
      auto matching_color = matching_caps.find(color);
      if (matching_color != matching_caps.end())
      {
        matching_caps.erase(matching_color);
        ++beautifully_closed;
      }
      else
      {
        ++remaining_markers;
      }
    }
    int remaining_caps = matching_caps.size();
    non_beautifully_closed += std::min(remaining_caps, remaining_markers);
  }
  printf("%d %d\n", non_beautifully_closed + beautifully_closed, beautifully_closed);
  return 0;
}
