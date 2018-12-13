#ifndef FIZZ_BUZZ_HPP
#define FIZZ_BUZZ_HPP

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>
#include <utility>

namespace fizz_buzz {
  template <class Int>
  using range = typename std::enable_if<std::is_integral<Int>::value,
                                        std::pair<Int, Int>>::type;

  template <class Int>
  auto make_range(Int first, Int last) -> range<Int> {
    return {first, last};
  }

  template <class Int>
  auto process(const Int n) ->
      typename std::enable_if<std::is_integral<Int>::value, std::string>::type {
    std::ostringstream result;
    if (n % 3 == 0) {
      result << "fizz";
    }
    if (n % 5 == 0) {
      result << "buzz";
    }
    if (n % 3 != 0 && n % 5 != 0) {
      result << n;
    }
    return result.str();
  }

  template <class Int>
  auto show(std::pair<Int, Int> const &range) -> void {
    for (Int i = range.first; i <= range.second; ++i) {
      std::cout << process(i) << std::endl;
    }
  }
}

#endif
