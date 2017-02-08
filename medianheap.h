#pragma once
#include <queue>
using namespace std;

template <typename T>
class medianheap
{
public:
  /* Constructor
   * Builds the min and max heaps, using their default constructors
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
  const T& top();

  /* pop
   * Removes the top item from the heap
   *
   * Pre : The heap must not be empty, otherwise an exception is thrown
   */
  void pop();

private:
  priority_queue<T, vector<T>, less<T> > max_heap;
  priority_queue<T, vector<T>, greater<T> > min_heap;
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

#include "hourglassheap.hpp"

