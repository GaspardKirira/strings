#pragma once

#include <algorithm>
#include <cctype>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

namespace strings
{

  /**
   * @brief Remove leading whitespace from a string view and return a new string.
   *
   * This function considers standard ASCII whitespace as defined by std::isspace.
   *
   * @param input The input text.
   * @return A new std::string without leading whitespace.
   */
  inline std::string ltrim(std::string_view input)
  {
    std::size_t start = 0;

    while (start < input.size() &&
           std::isspace(static_cast<unsigned char>(input[start])))
    {
      ++start;
    }

    return std::string(input.substr(start));
  }

  /**
   * @brief Remove trailing whitespace from a string view and return a new string.
   *
   * This function considers standard ASCII whitespace as defined by std::isspace.
   *
   * @param input The input text.
   * @return A new std::string without trailing whitespace.
   */
  inline std::string rtrim(std::string_view input)
  {
    if (input.empty())
      return {};

    std::size_t end = input.size();

    while (end > 0 &&
           std::isspace(static_cast<unsigned char>(input[end - 1])))
    {
      --end;
    }

    return std::string(input.substr(0, end));
  }

  /**
   * @brief Remove leading and trailing whitespace from a string view.
   *
   * Equivalent to rtrim(ltrim(input)).
   *
   * @param input The input text.
   * @return A new std::string with both ends trimmed.
   */
  inline std::string trim(std::string_view input)
  {
    return rtrim(ltrim(input));
  }

  /**
   * @brief Convert a string view to lowercase.
   *
   * Uses std::tolower on each character (ASCII-oriented). For non-ASCII locales,
   * behavior depends on the current C locale.
   *
   * @param input The input text.
   * @return A new std::string in lowercase.
   */
  inline std::string to_lower(std::string_view input)
  {
    std::string result(input);

    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c)
                   { return static_cast<char>(std::tolower(c)); });

    return result;
  }

  /**
   * @brief Convert a string view to uppercase.
   *
   * Uses std::toupper on each character (ASCII-oriented). For non-ASCII locales,
   * behavior depends on the current C locale.
   *
   * @param input The input text.
   * @return A new std::string in uppercase.
   */
  inline std::string to_upper(std::string_view input)
  {
    std::string result(input);

    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c)
                   { return static_cast<char>(std::toupper(c)); });

    return result;
  }

  /**
   * @brief Check if input starts with the given prefix.
   *
   * @param input The input text.
   * @param prefix The prefix to test.
   * @return true if input starts with prefix, otherwise false.
   */
  inline bool starts_with(std::string_view input, std::string_view prefix)
  {
    if (prefix.size() > input.size())
      return false;

    return input.substr(0, prefix.size()) == prefix;
  }

  /**
   * @brief Check if input ends with the given suffix.
   *
   * @param input The input text.
   * @param suffix The suffix to test.
   * @return true if input ends with suffix, otherwise false.
   */
  inline bool ends_with(std::string_view input, std::string_view suffix)
  {
    if (suffix.size() > input.size())
      return false;

    return input.substr(input.size() - suffix.size()) == suffix;
  }

  /**
   * @brief Split a string view by a single character delimiter.
   *
   * Notes:
   * - Keeps empty segments (e.g. "a,,b" -> ["a", "", "b"]).
   * - Always returns at least one element (possibly empty).
   *
   * @param input The input text.
   * @param delimiter The delimiter character.
   * @return A vector of segments as std::string.
   */
  inline std::vector<std::string> split(std::string_view input, char delimiter)
  {
    std::vector<std::string> result;
    std::string current;

    for (char c : input)
    {
      if (c == delimiter)
      {
        result.push_back(current);
        current.clear();
      }
      else
      {
        current += c;
      }
    }

    result.push_back(current);
    return result;
  }

  /**
   * @brief Join a list of strings with a delimiter.
   *
   * @param parts The strings to join.
   * @param delimiter The delimiter to insert between parts.
   * @return The joined string. Returns empty string if parts is empty.
   */
  inline std::string join(
      const std::vector<std::string> &parts,
      std::string_view delimiter)
  {
    if (parts.empty())
      return {};

    std::ostringstream oss;

    for (std::size_t i = 0; i < parts.size(); ++i)
    {
      oss << parts[i];
      if (i + 1 < parts.size())
        oss << delimiter;
    }

    return oss.str();
  }

  /**
   * @brief Replace all occurrences of a substring with another substring.
   *
   * If @p from is empty, the input is returned unchanged.
   *
   * @param input The input text.
   * @param from The substring to replace.
   * @param to The replacement substring.
   * @return A new std::string with all replacements applied.
   */
  inline std::string replace_all(
      std::string_view input,
      std::string_view from,
      std::string_view to)
  {
    if (from.empty())
      return std::string(input);

    std::string result(input);
    std::size_t pos = 0;

    while ((pos = result.find(from, pos)) != std::string::npos)
    {
      result.replace(pos, from.size(), to);
      pos += to.size();
    }

    return result;
  }

} // namespace strings
