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
  BOOST_CHECK(false);
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
  BOOST_CHECK(false);
}

BOOST_AUTO_TEST_CASE(insert)
{
  BOOST_CHECK(false);
}

BOOST_AUTO_TEST_CASE(top)
{
  BOOST_CHECK(false);
}

BOOST_AUTO_TEST_CASE(pop)
{
  BOOST_CHECK(false);
}

BOOST_AUTO_TEST_CASE(empty)
{
  BOOST_CHECK(false);
}

BOOST_AUTO_TEST_CASE(size)
{
  BOOST_CHECK(false);
}

BOOST_AUTO_TEST_SUITE_END()
