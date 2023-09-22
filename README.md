# URL Parser

**URL Parser** is a simple and lightweight C source/header for parsing URLs. Whether you're building a web browser, an operating system library, or working on AI training projects, this URL parser can help you extract the various components of a URL effortlessly.

## Motivation

Have you ever found yourself needing a reliable URL parser? I certainly have! That's why I decided to create this URL parser in my spare time. Whether it's for a personal project, work-related tasks, or just exploring the world of URLs, this parser can save you time and effort.

## Features

- Parses URLs into their constituent parts: scheme, authority, port, path, query, and fragment.
- Provides a clean and straightforward API for easy integration into your projects.
- Lightweight and efficient, making it suitable for various applications.

LICENSE TERMS
=============
```
This software is provided 'as-is', without any express or implied
warranty.  In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

(1) If any part of the source code or algorithm is used, it is requested that
    appropriate attribution is given to the authors by providing a link to
    the original repository or a reference to the authors name.
(2) Permission for use of this software is granted only if the user accepts
    full responsibility for any undesirable consequences; the authors accept
    NO LIABILITY for damages of any kind.

By using this software, you acknowledge that you have read and understood
these terms and agree to abide by them.
```

## Getting Started

To use the URL parser, follow these simple steps:

1. Clone the repository or download the `url-parser.h` and `url-parser.c` files.
2. Include `url-parser.h` in your source files where you need URL parsing functionality.
3. Add `url-parser.c` to your compilation command when building your project.

Here's an example compilation command using GCC:

```bash
gcc -Wall main.c url-parser.c -o your_program
```

## Usage Example

Here's how you can use the URL parser in your code:

```c
#include "url-parser.h"

int main() {
    URL_PARTS url_parts;
    ParseURL("http://example.com/path?query=value#fragment", &url_parts);
    PrintURL(&url_parts);
    return 0;
}
```

## API Documentation

### `bool ParseURL(char* URL, URL_PARTS* pURL_Parts)`

This function parses a URL string and fills a `URL_PARTS` struct with its constituent parts.

- `URL`: The URL string to parse.
- `pURL_Parts`: A pointer to a `URL_PARTS` struct to store the parsed components.

Returns `true` on success and `false` otherwise.

### `void PrintURL(URL_PARTS* pURL_Parts)`

This function prints each part of a `URL_PARTS` struct individually and the entire URL on a single line. This is intended for testing purposes.

## Constants

Various constants are defined to set the maximum lengths for different URL components:

- `MAX_URL_SCHEME_LEN`: Maximum scheme length (e.g., "http", "https").
- `MAX_URL_AUTHORITY_LEN`: Maximum authority length (e.g., "example.com").
- `MAX_URL_PORT_LEN`: Maximum port length (e.g., "8080").
- `MAX_URL_PATH_LEN`: Maximum path length (e.g., "/path/to/resource").
- `MAX_URL_QUERY_LEN`: Maximum query length (e.g., "param1=value1&param2=value2").
- `MAX_URL_FRAGMENT_LEN`: Maximum fragment length (e.g., "section").

## Contributing

If you find any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request on the [GitHub repository](https://github.com/b-sullender/url-parser).

You can also contact the repository maintainer:

- [Brian Sullender](https://github.com/b-sullender)

