#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ArrayTests

#include <boost/test/unit_test.hpp>

#include "array/Array.h"

BOOST_AUTO_TEST_SUITE(ArrayTestSuite)

BOOST_AUTO_TEST_CASE(ArrayBasic) {
  array::Array<int, 3> A;
  BOOST_CHECK(A.size() == 3);

  A[0] = 1;
  A[1] = 1;
  A[2] = 2;
  BOOST_CHECK(A.at(0) == 1);
  BOOST_CHECK(A.at(1) == 1);
  BOOST_CHECK(A.at(2) == 2);
  BOOST_CHECK(A.front() == 1);
  BOOST_CHECK(A.back() == 2);
  auto it = A.begin();
  auto ie = A.end();
  size_t i = 0;
  int a[3];
  for (; it != ie; ++it, ++i) {
    a[i] = *it;
  }
  BOOST_CHECK(a[0] == 1);
  BOOST_CHECK(a[1] == 1);
  BOOST_CHECK(a[2] == 2);

  A.fill(20);
  BOOST_CHECK(A[0] == 20);
  BOOST_CHECK(A[1] == 20);
  BOOST_CHECK(A[2] == 20);

  int *b = A.data();
  BOOST_CHECK(b[0] == 20);
  BOOST_CHECK(b[1] == 20);
  BOOST_CHECK(b[2] == 20);
}

BOOST_AUTO_TEST_CASE(ArrayConstructor) {
  array::Array<float, 3> A;
  A[0] = 1.f;
  A[1] = 2.f;
  A[2] = 3.f;

  array::Array<float, 3> B(A);
  BOOST_CHECK(B[0] == 1.f);
  BOOST_CHECK(B[1] == 2.f);
  BOOST_CHECK(B[2] == 3.f);
  BOOST_CHECK((B != A) == false);
  BOOST_CHECK((B == A) == true);

  array::Array<float, 3> C({1.f, 2.5f, 3.f});
  BOOST_CHECK(C[0] == 1.f);
  BOOST_CHECK(C[1] == 2.5f);
  BOOST_CHECK(C[2] == 3.f);

  array::Array<float, 3> D = {1.f, 2.f, 3.f};
  BOOST_CHECK(D[0] == 1.f);
  BOOST_CHECK(D[1] == 2.f);
  BOOST_CHECK(D[2] == 3.f);
}

BOOST_AUTO_TEST_SUITE_END()
