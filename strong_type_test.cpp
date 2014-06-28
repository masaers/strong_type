/*******************************************************************************
 * Tests strong types.
 *
 * \author Markus Saers
 ******************************************************************************/
#include "strong_type.hpp"
#include <iostream>
#include <cassert>


strong_type(int, a_type);
strong_type(int, b_type);

using namespace std;

int bar(a_type a) {
  cout << "a_type" << endl;
  return (int)a;
}

int bar(b_type b) {
  cout << "b_type" << endl;
  return (int)b;
}

int bar(int x) {
  cout << "int" << endl;
  return x;
}

int main(const int argc, const char** argv) {
  using namespace std;
  
  {
    a_type a(100);
    cout << a << endl;
    a += 10;
    cout << a << endl;
    a_type a2 = a + 1;
    cout << a2 << endl;
    a_type a3 = 1 + a;
    cout << a3 << endl;
    bar(a);

    b_type b(1000);
    cout << b << endl;
    b_type b2 = a + b;
    cout << b2 << endl;
    bar(b);
    bar((int)b);
    bar((b_type)a);
    bar(b_type(a));
    bar(a + b);
    bar(1 + b);
    bar(b + 1);
    bar(b + b); // should be b_type
  }

  {
    strong_type(int*, ptr);
    int i = 10;
    ptr p(&i);
    cout << p << endl;
    cout << *p << endl;
  }

  
  return EXIT_SUCCESS;
}

/******************************************************************************/
