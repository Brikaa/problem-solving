#include <vector>

template <class T>
class Heap
{
private:
  std::vector<T> v;

public:
  T extract();
  void insert(T element);
  bool empty();
};

int left_child(const int index)
{
  return index * 2 + 1;
}

int right_child(const int index)
{
  return index * 2 + 2;
}

int parent(const int index)
{
  return (index - 1) / 2;
}

template <class T>
void swap(T &t1, T &t2)
{
  const T temp = t1;
  t1 = t2;
  t2 = temp;
}

template <class T>
T Heap<T>::extract()
{
  const T to_extract = v[0];
  v[0] = v[v.size() - 1];
  v.pop_back();
  int current_index = 0;
  while (current_index <= (int)v.size())
  {
    int children_indices[2] = {left_child(current_index), right_child(current_index)};
    int index_largest = current_index;
    for (int i = 0; i < 2; ++i)
    {
      int child_idx = children_indices[i];
      if (child_idx < (int)v.size() && v[child_idx] > v[index_largest])
      {
        index_largest = child_idx;
      }
    }
    if (index_largest == current_index)
      break;
    else
    {
      swap(v[index_largest], v[current_index]);
      current_index = index_largest;
    }
  }
  return to_extract;
}

template <class T>
void Heap<T>::insert(T element)
{
  v.push_back(element);
  for (int current_index = v.size() - 1; current_index > 0; current_index = parent(current_index))
  {
    const int p = parent(current_index);
    if (v[current_index] > v[p])
      swap(v[current_index], v[p]);
    else
      break;
  }
}

template <class T>
inline bool Heap<T>::empty()
{
  return v.size() == 0;
}
