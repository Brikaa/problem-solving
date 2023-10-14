#include "heap.h"
#include <iostream>

int main()
{
  Heap<int> heap;
  heap.insert(1);
  heap.insert(2);
  heap.insert(9);
  heap.insert(4);
  heap.insert(8);
  heap.insert(5);
  heap.insert(13);
  heap.insert(3);
  heap.insert(6);
  heap.insert(4);
  heap.insert(1);
  while (!heap.empty())
    std::cout << heap.extract() << '\n';
}
