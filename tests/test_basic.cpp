#include <strings/strings.hpp>

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

static void test_trim()
{
  using strings::ltrim;
  using strings::rtrim;
  using strings::trim;

  assert(ltrim("   hello") == "hello");
  assert(ltrim("hello") == "hello");
  assert(ltrim("   ") == "");
  assert(ltrim("") == "");

  assert(rtrim("hello   ") == "hello");
  assert(rtrim("hello") == "hello");
  assert(rtrim("   ") == "");
  assert(rtrim("") == "");

  assert(trim("   hello   ") == "hello");
  assert(trim("hello") == "hello");
  assert(trim("   ") == "");
  assert(trim("") == "");
  assert(trim("  hello   world  ") == "hello   world");
}

static void test_case_conversion()
{
  using strings::to_lower;
  using strings::to_upper;

  assert(to_lower("ABC") == "abc");
  assert(to_lower("AbC123") == "abc123");
  assert(to_lower("") == "");

  assert(to_upper("abc") == "ABC");
  assert(to_upper("aBc123") == "ABC123");
  assert(to_upper("") == "");
}

static void test_prefix_suffix()
{
  using strings::ends_with;
  using strings::starts_with;

  assert(starts_with("hello", "he"));
  assert(starts_with("hello", ""));
  assert(!starts_with("hello", "hello!"));
  assert(!starts_with("", "a"));

  assert(ends_with("hello", "lo"));
  assert(ends_with("hello", ""));
  assert(!ends_with("hello", "x"));
  assert(!ends_with("", "a"));
}

static void test_split()
{
  using strings::split;

  {
    auto v = split("a,b,c", ',');
    assert((v == std::vector<std::string>{"a", "b", "c"}));
  }

  {
    auto v = split("a,,b", ',');
    assert((v == std::vector<std::string>{"a", "", "b"}));
  }

  {
    auto v = split("", ',');
    assert((v == std::vector<std::string>{""}));
  }

  {
    auto v = split(",", ',');
    assert((v == std::vector<std::string>{"", ""}));
  }
}

static void test_join()
{
  using strings::join;

  {
    std::vector<std::string> parts{"a", "b", "c"};
    assert(join(parts, ",") == "a,b,c");
  }

  {
    std::vector<std::string> parts{"a"};
    assert(join(parts, ",") == "a");
  }

  {
    std::vector<std::string> parts{};
    assert(join(parts, ",") == "");
  }

  {
    std::vector<std::string> parts{"", "b", ""};
    assert(join(parts, "-") == "-b-");
  }
}

static void test_replace_all()
{
  using strings::replace_all;

  assert(replace_all("hello world", "world", "vix") == "hello vix");
  assert(replace_all("aaaa", "aa", "b") == "bb");
  assert(replace_all("abc", "x", "y") == "abc");
  assert(replace_all("", "a", "b") == "");
  assert(replace_all("abc", "", "x") == "abc");
  assert(replace_all("abc", "a", "") == "bc");
}

int main()
{
  test_trim();
  test_case_conversion();
  test_prefix_suffix();
  test_split();
  test_join();
  test_replace_all();

  std::cout << "[strings] All tests passed.\n";
  return 0;
}
