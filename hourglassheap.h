#pragma once
#include <queue>
using namespace std;

template <typename T>
class HourglassHeap
{
public:
  HourglassHeap();
  void insert(const T& x);
  T top();
  void pop();
private:
  priority_queue<T, vector<T>, less<T> > max_heap;
  priority_queue<T, vector<T>, greater<T> > min_heap;
  T median;
  void balance();
};

#include "hourglassheap.hpp"

