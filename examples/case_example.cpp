#include <strings/strings.hpp>
#include <iostream>

int main()
{
  std::string text = "HeLLo Vix";

  std::cout << "Lower: " << strings::to_lower(text) << "\n";
  std::cout << "Upper: " << strings::to_upper(text) << "\n";
}
