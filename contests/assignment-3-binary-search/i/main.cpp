/*
(x, h)
while (h != 0)
  x++
  if (x-1 not in segment)
    h--

- Two pointers on segments
- Maximize longest segments distance
- if (r.start - l.end - still_height < h)
  - r++
  - if (r - l > 1)
    - still_height += segments[r - 1].end - segments[r - 1].start
- else
  - if (r - l > 1)
    - still_height -= segments[l + 1].end - segments[l + 1].start
  - l++
- segments distance = maximize on still_height + r.end - r.start + l.end - l.start # if l, r are different

- total distance = segments distance + h
*/
#include <cstdio>
#include <algorithm>

const int N = 2e5 + 5;
struct Segment
{
  long long start;
  long long end;
};
Segment segments[N];

int main()
{
  int n;
  long long h;
  scanf("%d%lld", &n, &h);
  for (int i = 0; i < n; ++i)
  {
    scanf("%lld%lld", &(segments[i].start), &(segments[i].end));
  }
  int l = 0;
  int r = 0;
  long long longest_segments_distance = segments[r].end - segments[r].start;
  long long still_height = 0;
  while (r != n - 1 || l != n - 1)
  {
    if ((l == r || segments[r].start - segments[l].end - still_height < h) && (r != n - 1))
    {
      ++r;
      if (r - l > 1)
        still_height += segments[r - 1].end - segments[r - 1].start;
    }
    else
    {
      if (r - l > 1)
        still_height -= segments[l + 1].end - segments[l + 1].start;
      ++l;
    }
    if (l == r || segments[r].start - segments[l].end - still_height < h)
    {
      longest_segments_distance = std::max(
          longest_segments_distance,
          still_height + segments[r].end - segments[r].start + (l != r) * (segments[l].end - segments[l].start));
    }
  }
  long long total_distance = longest_segments_distance + h;
  printf("%lld\n", total_distance);
  return 0;
}
