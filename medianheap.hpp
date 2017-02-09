#include <queue>

template <typename T>
medianheap<T>::medianheap() : length(0)
{ /* Intentionally left empty */ }

template <typename T>
void medianheap<T>::push(const T& x)
{
  if (min_heap.empty() || x > median)
  {
    min_heap.push(x);
    length++;
  }
  else
  {
    max_heap.push(x);
    length++;
  }

  balance();
}

template <typename T>
const T& medianheap<T>::top() const throw (OutOfBoundsException)
{
  if (length == 0)
    throw OutOfBoundsException();
  return median;
}

template <typename T>
void medianheap<T>::pop() throw (OutOfBoundsException)
{
  if (length == 0)
    throw OutOfBoundsException();

  if (min_heap.size() >= max_heap.size())
  {
    min_heap.pop();
    length--;
  }
  else
  {
    max_heap.pop();
    length--;
  }

  balance();
}

template <typename T>
size_t medianheap<T>::size() const
{
  return length;
}

template <typename T>
void medianheap<T>::balance()
{
  if (min_heap.size() > max_heap.size() + 1)
  {
    max_heap.push(min_heap.top());
    min_heap.pop();
    length--;
  }
  else if (max_heap.size() > min_heap.size() + 1)
  {
    min_heap.push(max_heap.top());
    max_heap.pop();
    length--;
  }

  if (min_heap.size() >= max_heap.size())
    median = min_heap.top();
  else
    median = max_heap.top();
  return;
}
