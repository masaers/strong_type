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
strong_type(int*, c_type);

using namespace std;

int foo(a_type a) {
  cout << "a_type" << endl;
  return (int)a;
}

int bar(a_type a) {
  cout << "a_type" << endl;
  return (int)a;
}

int bar(b_type b) {
  cout << "b_type" << endl;
  return (int)b;
}

int bar(c_type c) {
  cout << "c_type" << endl;
  return *c;
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
    foo(a);
    foo(2); // should not work
    
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
    bar(b += b); // should be b_type
  }

  {
    int i = 10;
    c_type p(&i);
    cout << p << endl;
    cout << *p << endl;
    bar(p);
    bar(*p);
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
