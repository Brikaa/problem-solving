/*
no sectors = no main threads
- n threads
- vector of vectors representing attachment points
- for i .. no threads
  - take no bridges
  - for i .. no bridges
    - take attachment point
    - attachment_points[i] push back point {forms_bridge_with_next: true}
    - attachment_points[(i + 1) % n] push back point {forms_bridge_with_next: false}
- for i .. no threads
  - sort attachment_points[i] based on distance
- for i .. no threads
  - go to first attachment point in attachment_points[i] with forms_bridge_with_next = true
  - go to the same attachment point attachment_points[(i + 1) % no_bridges]
  - count how many points till the next forms_bridge_with_next = true in attachment_points[i]
  - count how many points till the same point in attachment_points[(i + 1) % no_bridges]
  - if not equal, ++imbalance

  - f = 0, s = 0
  - f_between = 0
  - s_between = 0
  - first = attachment_points[i]
  - second = attachment_points[(i + 1) % n]
  - while (!first[f].forms_bridge_with_next)
    - ++f
  - while second[s].distance != first[f].distance
    - ++s
  - while f < first.size()
    - ++f
    - if !first[f].forms_bridge_with_next
      - ++f_between
    - else
      - while second[s].distance != first[f].distance
        - ++s
        - ++s_between
      - if f_between != s_between
        - ++imbalance
      - f_between = 0
      - s_between = 0
*/
#include <cstdio>
#include <algorithm>
#include <vector>

struct AttachmentPoint
{
  int distance;
  bool forms_bridge_with_next;
};

const int N = 1e3 + 3;
std::vector<AttachmentPoint> attachment_points[N];

bool less_than(AttachmentPoint &a, AttachmentPoint &b)
{
  return a.distance < b.distance;
}

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; ++j)
    {
      int p;
      scanf("%d", &p);

      AttachmentPoint p1;
      p1.distance = p;
      p1.forms_bridge_with_next = true;
      attachment_points[i].push_back(p1);

      AttachmentPoint p2;
      p2.distance = p;
      p2.forms_bridge_with_next = false;
      attachment_points[(i + 1) % n].push_back(p2);
    }
  }

  for (int i = 0; i < n; ++i)
    std::sort(attachment_points[i].begin(), attachment_points[i].end(), less_than);

  int unstable = 0;
  for (int i = 0; i < n; ++i)
  {
    int f = 0;
    int s = 0;
    int f_between = 0;
    int s_between = 0;
    auto &first = attachment_points[i];
    auto &second = attachment_points[(i + 1) % n];
    while (!first[f].forms_bridge_with_next)
      ++f;
    while (second[s].distance != first[f].distance)
      ++s;
    while (f < (int)first.size() - 1)
    {
      ++f;
      ++f_between;
      if (first[f].forms_bridge_with_next)
      {
        while (second[s].distance != first[f].distance)
        {
          ++s;
          ++s_between;
        }
        if (f_between != s_between)
          ++unstable;
        f_between = 0;
        s_between = 0;
      }
    }
  }
  printf("%d\n", unstable);
  return 0;
}
