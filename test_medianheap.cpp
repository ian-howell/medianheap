#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
#include "medianheap.h"

BOOST_AUTO_TEST_SUITE(medianheap_suite)

/* Default Constructor Test */
BOOST_AUTO_TEST_CASE(default_constructor)
{
  medianheap<int> empty;
  BOOST_CHECK_EQUAL(empty.size(), 0);
}

/* Copy Constructor Test */
BOOST_AUTO_TEST_CASE(copy_constructor)
{
  medianheap<int> heap1;
  for (int i = 0; i < 10; i++)
    heap1.push(i);

  medianheap<int> heap2(heap1);
  while (!heap1.empty())
  {
    BOOST_CHECK_EQUAL(heap1.top(), heap2.top());
    BOOST_CHECK_EQUAL(heap1.size(), heap2.size());
    heap1.pop();
    heap2.pop();
  }
  BOOST_CHECK(heap2.empty());
}

/* Assignment Operator test */
BOOST_AUTO_TEST_CASE(assignment_operator)
{
  BOOST_CHECK(false);
}

/* Equality Operator */
BOOST_AUTO_TEST_CASE(equality_operator)
{
  BOOST_CHECK(false);
}
 
/* Non-Equality Operator */
BOOST_AUTO_TEST_CASE(nonequality_operator)
{
  BOOST_CHECK(false);
}

BOOST_AUTO_TEST_CASE(out_of_bounds_exception)
{
  medianheap<int> heap;
  BOOST_CHECK_THROW(heap.pop(), OutOfBoundsException);
}

BOOST_AUTO_TEST_CASE(insert)
{
  medianheap<int> heap;
  for (int i = 1; i <= 5; i++)
  {
    heap.push(i);
    BOOST_CHECK_EQUAL(heap.size(), i);
  }
}

BOOST_AUTO_TEST_CASE(top)
{
  medianheap<int> heap;
  for (int i = 0; i < 10; i++)
    heap.push(i+1);

  BOOST_CHECK_EQUAL(heap.size(), 10);

  BOOST_CHECK_EQUAL(heap.top(), 6);
  heap.pop();
  heap.pop();
  heap.pop();
  BOOST_CHECK_EQUAL(heap.top(), 4);
}

BOOST_AUTO_TEST_CASE(pop)
{
  medianheap<int> heap;
  for (int i = 0; i < 5; i++)
    heap.push(i);

  BOOST_CHECK_EQUAL(heap.size(), 5);
  for (int i = 4; i >= 4; i--)
  {
    heap.pop();
    BOOST_CHECK_EQUAL(heap.size(), i);
  }
}

BOOST_AUTO_TEST_CASE(empty)
{
  medianheap<int> heap;
  BOOST_CHECK(heap.empty());
}

BOOST_AUTO_TEST_CASE(size)
{
  medianheap<int> heap;
  BOOST_CHECK_EQUAL(heap.size(), 0);
  for (int i = 1; i <= 5; i++)
  {
    heap.push(i);
    BOOST_CHECK_EQUAL(heap.size(), i);
  }
}

BOOST_AUTO_TEST_SUITE_END()
