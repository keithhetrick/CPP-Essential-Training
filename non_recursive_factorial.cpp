// recursive-factorial.cpp by Bill Weinman <http://bw.org/>
// updated 2022-06-01
#include <format>
#include <iostream>

using std::cout;
using std::format;

/***********************************************
 *
 *  CHAPTER 6 CHALLENGE - NON RECURSEIVE FACTORIAL
 *
 *  Create a non-recursive funcion for calculating factorials
 *
 *  Example of recursive function below:
 *
 *  using std::format;
 *  using std::cout;
 *
 *  unsigned long factorial(unsigned long n) {
 *      if (n < 2) return 1;
 *      return n * factorial(n - 1);
 *  }
 *
 *  int main() {
 *      unsigned long n {5};
 *      cout << format("Factorial of {} is {}\n", n, factorial(n));
 *  }
 *
 ************************************************/

unsigned long factorial(unsigned long n)
{
  auto result = n;
  while (n > 1)
  {
    result *= --n;
  }
  return result;
}

int main()
{
  unsigned long n{6};
  cout << format("Factorial of {} is {}\n", n, factorial(n));
}
