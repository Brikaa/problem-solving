/*
n elements
How many 3-tuples can I form such that elements in each tuple are distinct and one element can't be used in more than
one tuple

1 2 3 4 4 5
^ ^   ^
    ^   ^ ^

1 2 2 3 3 4

1 1 1 2 3 4

map element to count
priority queue based on an element's count
*/
#include <cstdio>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>

std::unordered_map<int, int> element_to_count;
struct ElementToCount
{
  int element;
  int count;
};
class Compare
{
public:
  bool operator()(ElementToCount &a, ElementToCount &b)
  {
    return a.count < b.count;
  }
};
std::priority_queue<ElementToCount, std::vector<ElementToCount>, Compare> pq;

bool less_than(ElementToCount &a, ElementToCount &b)
{
  return a.element < b.element;
}

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    int diameter;
    scanf("%d", &diameter);
    element_to_count[diameter]++;
  }
  for (auto p : element_to_count)
  {
    ElementToCount e;
    e.element = p.first;
    e.count = p.second;
    pq.push(e);
  }
  std::vector<std::vector<ElementToCount>> tuples;
  while (pq.size() >= 3)
  {
    std::vector<ElementToCount> extracted;
    for (int i = 0; i < 3; ++i)
    {
      ElementToCount e = pq.top();
      pq.pop();
      extracted.push_back(e);
    }
    for (auto e : extracted)
    {
      --e.count;
      if (e.count > 0)
        pq.push(e);
    }
    std::sort(extracted.begin(), extracted.end(), less_than);
    tuples.push_back(extracted);
  }
  printf("%d\n", (int)tuples.size());
  for (auto tuple : tuples)
  {
    printf("%d %d %d\n", tuple[2].element, tuple[1].element, tuple[0].element);
  }
}
