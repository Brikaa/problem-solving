/*
n houses on the x axis
m signal stations
Find the maximum distance between a house and a signal station such that that signal station is the only way to cover
the house

house_cover(house) = min(left_signal_station(house), right_signal_station_right(house))

- Sort houses and signal stations together
- queue houses to check
- last signal station
- for i in houses and signal stations:
  - if i is signal station
    - last signal station = coordinate i
    - for j in houses to check;
      - h = j.pop()
      - h.closest_signal_station = min(h.closest_signal_station, signal station coordinate) // beware of -1
  - if i is house
    - i.closest_signal_station = last signal station coordinate
    - houses to check append i
- maximize closest_signal_station in house entities
*/
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>

const int HOUSE_ENTITY = 0;
const int SIGNAL_STATION_ENTITY = 1;
const int N = 1e5 + 5;
const int M = N;

struct Entity
{
  int type;
  int coordinate;
  int closest_signal_station;
};

Entity entities[2 * N];

bool smaller_than(Entity e1, Entity e2)
{
  return e1.coordinate < e2.coordinate;
}

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  int a = n + m;
  for (int i = 0; i < n; ++i)
  {
    Entity &e = entities[i];
    scanf("%d", &(e.coordinate));
    e.type = HOUSE_ENTITY;
    e.closest_signal_station = 2e9 + 100;
  }
  for (int i = n; i < a; ++i)
  {
    scanf("%d", &(entities[i].coordinate));
    entities[i].type = SIGNAL_STATION_ENTITY;
  }
  std::sort(entities, entities + a, smaller_than);

  std::stack<Entity *> houses_to_check;
  int last_signal_station = 0;
  bool first_passed = false;
  for (int i = 0; i < a; ++i)
  {
    Entity &e = entities[i];
    // fprintf(stderr, "%d - coordinate: %d\n", e.type, e.coordinate);
    if (e.type == SIGNAL_STATION_ENTITY)
    {
      last_signal_station = e.coordinate;
      first_passed = true;
      while (!houses_to_check.empty())
      {
        Entity *h = houses_to_check.top();
        h->closest_signal_station = std::min(h->closest_signal_station, abs(last_signal_station - h->coordinate));
        houses_to_check.pop();
        // fprintf(stderr, "House %d, closest signal station: %d\n", h->coordinate, h->closest_signal_station);
      }
    }
    else
    {
      e.closest_signal_station = first_passed ? abs(e.coordinate - last_signal_station) : e.closest_signal_station;
      houses_to_check.push(&e);
    }
  }

  // fprintf(stderr, "===========\n");
  // for (int i = 0; i < a; ++i)
  // {
  //   Entity &e = entities[i];
  //   if (e.type == HOUSE_ENTITY)
  //     fprintf(stderr, "House of coordinate %d, closest signal station: %d\n", e.coordinate, e.closest_signal_station);
  // }

  int r = 0;
  for (int i = 0; i < a; ++i)
  {
    Entity &e = entities[i];
    if (e.type == HOUSE_ENTITY)
      r = std::max(e.closest_signal_station, r);
  }
  printf("%d\n", r);
}
