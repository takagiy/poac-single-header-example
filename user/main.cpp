#include <fizz_buzz.hpp>

auto main() -> int {
  auto range = fizz_buzz::make_range(1, 20);
  fizz_buzz::show(range);
}
