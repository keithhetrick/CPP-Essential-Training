#include <format>
#include <iostream>

using std::cout;
using std::format;

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
