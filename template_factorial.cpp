#include <format>
#include <iostream>

using std::cout;
using std::format;

/***********************************************
 *
 *  CHAPTER 8 CHALLENGE - NON RECURSEIVE FACTORIAL
 *
 *  Build off of Chapter 6 challenge, and create a a template version of the non-recursive factorial funcion
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

template <typename T>
T factorial(T n)
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
  int i{5};
  cout << format("Factorial of {} is {}\n", i, factorial(i));

  long long unsigned int longer_number{15};
  cout << format("Factorial of {} is {}\n", longer_number, factorial(longer_number));

  long double longest_number{25};
  cout << format("Factorial of {} is {:-4.5}\n", longest_number, factorial(longest_number));
}
