#include <strings/strings.hpp>
#include <iostream>

int main()
{
  std::string text = "hello world, world!";
  std::string replaced = strings::replace_all(text, "world", "vix");

  std::cout << replaced << "\n";
}
