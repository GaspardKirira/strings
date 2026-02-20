# strings

Modern header-only C++ string utilities for safe parsing, splitting,
trimming, case conversion, and text processing.

## Installation

### Using Vix Registry

``` bash
vix add gaspardkirira/strings@0.1.0
vix deps
```

### Manual Download

Download the latest release from:

👉 https://github.com/GaspardKirira/strings/releases

Or clone directly:
``` bash
git clone https://github.com/GaspardKirira/strings.git
```

Then include the `include/` directory in your project.

## Quick Example

``` cpp
#include <strings/strings.hpp>
#include <iostream>

int main()
{
  std::string text = "   Hello,World   ";

  auto trimmed = strings::trim(text);
  auto parts = strings::split(trimmed, ',');
  auto lower = strings::to_lower(parts[0]);

  std::cout << lower << "\n";
}
```

### Output
```text
hello
```

## Features

-   `trim` / `ltrim` / `rtrim`
-   `split` by delimiter
-   `join` with delimiter
-   `to_lower` / `to_upper`
-   `starts_with` / `ends_with`
-   `replace_all`

All functions are:

-   Header-only\
-   Zero dependencies\
-   Safe with `std::string_view`\
-   C++17 compatible

## Examples

See the `examples/` directory for:

-   `trim_example.cpp`
-   `split_join_example.cpp`
-   `case_example.cpp`
-   `replace_example.cpp`

## Tests

Run tests with:

``` bash
vix tests
```

## License

MIT License.

