#pragma once
#include <cstddef> // for size_t
#include <queue>

class OutOfBoundsException {};

template <typename T>
class medianheap
{
public:
  /* Constructor
   * Builds the min and max heaps, using their default constructors
   * Initializes length to 0
   */
  medianheap();

  /* insert
   * Inserts the value x into the medianheap
   *
   * Pre : Type T must have the > operator defined
   * Post: x has been added to the heap
   *
   * @param const T& x: The value to insert
   */
  void insert(const T& x);

  /* top
   * Returns the top of the heap
   *
   * Pre : The heap must not be empty, otherwise an exception is thrown
   *
   * @return const T&: the current top of the heap
   */
  const T& top() const throw (OutOfBoundsException);

  /* pop
   * Removes the top item from the heap
   *
   * Pre : The heap must not be empty, otherwise an exception is thrown
   */
  void pop() throw (OutOfBoundsException);

  /* size
   * Returns the number of elements currently in the heap
   *
   * @return size_t: The number of elements in the heap
   */
  size_t size() const;

private:
  std::priority_queue<T, std::vector<T>, std::less<T> > max_heap;
  std::priority_queue<T, std::vector<T>, std::greater<T> > min_heap;
  size_t length;
  T median;

  /* balance
   * Balances the min heap with the max heap - Keeps the difference in size
   * within 1
   * It then assesses which heap contains the median, and assigns it
   *
   * Pre : The heap must not be empty, otherwise an exception is thrown
   */

  void balance();
};

#include "medianheap.hpp"
