#include <format>
#include <iostream>

using std::cout;
using std::format;

/***********************************************
 *
 *  CHAPTER 5 CHALLENGE - PRIME NUMBERS
 *
 *  Create a program that prints all prime numbers
 *  from 1 to 100.
 *
 *  A prime number is a number that is only divisible by 1 and itself.
 *
 * 1.  Create a for loop that iterates from 2 to 100.
 * 2.  Create a for loop that iterates from 2 to the current number.
 * 3.  If the current number is divisible by the current factor, then the number is not prime.
 * 4.  If the current number is not divisible by the current factor, then the number is prime.
 * 5.  Print the current number if it is prime.
 *
 ************************************************/

int main()
{
  bool prime_flag{false};

  for (auto candidate = 2; candidate < 100; ++candidate)
  {

    prime_flag = true;
    for (auto factor = 2; factor < candidate; ++factor)
    {
      if (candidate % factor == 0)
      {
        prime_flag = false;
        break;
      }
    }
    if (prime_flag)
      cout << format("{} \n", candidate);
  }
}
