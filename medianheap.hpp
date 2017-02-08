#include <queue>

template <typename T>
medianheap<T>::medianheap()
{ /* Intentionally left empty */ }

template <typename T>
void medianheap<T>::insert(const T& x)
{
  if (min_heap.empty() || x > median)
    min_heap.push(x);
  else
    max_heap.push(x);

  balance();
}

template <typename T>
const T& medianheap<T>::top()
{
  return median;
}

template <typename T>
void medianheap<T>::pop()
{
  if (min_heap.size() >= max_heap.size())
    min_heap.pop();
  else
    max_heap.pop();

  balance();
}

template <typename T>
void medianheap<T>::balance()
{
  if (min_heap.size() > max_heap.size() + 1)
  {
    max_heap.push(min_heap.top());
    min_heap.pop();
  }
  else if (max_heap.size() > min_heap.size() + 1)
  {
    min_heap.push(max_heap.top());
    max_heap.pop();
  }

  if (min_heap.size() >= max_heap.size())
    median = min_heap.top();
  else
    median = max_heap.top();
  return;
}
