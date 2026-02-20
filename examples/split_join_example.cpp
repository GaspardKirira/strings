#include <strings/strings.hpp>
#include <iostream>

int main()
{
  std::string input = "apple,banana,orange";

  auto parts = strings::split(input, ',');

  std::cout << "Split result:\n";
  for (const auto &p : parts)
    std::cout << "- " << p << "\n";

  std::string joined = strings::join(parts, " | ");

  std::cout << "\nJoined: " << joined << "\n";
}
