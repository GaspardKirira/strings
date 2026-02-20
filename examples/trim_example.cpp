#include <strings/strings.hpp>
#include <iostream>

int main()
{
  std::string input = "   hello world   ";
  std::string result = strings::trim(input);

  std::cout << "Original: [" << input << "]\n";
  std::cout << "Trimmed : [" << result << "]\n";
}
