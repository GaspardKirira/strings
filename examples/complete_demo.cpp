#include <strings/strings.hpp>
#include <iostream>

int main()
{
  std::string text = "   Hello,World   ";

  auto trimmed = strings::trim(text);
  auto parts = strings::split(trimmed, ',');
  auto lower = strings::to_lower(parts[0]);

  std::cout << "Processed: " << lower << "\n";
}
