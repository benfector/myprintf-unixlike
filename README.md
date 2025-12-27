# Simple printf() Implementation

### Improved thanks to Reddit feedback! Thanks everyone, learned a lot! 💚
### Additionally, I formatted the code with clang-format (Google style) : `clang-format -style=Google -i printf.c`

Educational project to understand how printf() works behind the scenes on Unix-like systems (OpenBSD, FreeBSD, Linux, macOS, etc.).

## Features 
- Format specifiers: `%d`, `%s`, `%c`, `%f`
- Direct syscall (write() instead of stdio)
- Integer to string conversion (manual, no sprintf)
- Edge case handling (INT_MIN, NULL strings)
- test suite (11 categories)

## What I Learned
- Variadic functions (stdarg.h)
- Integer to string conversion (modulo/division)
- Syscall usage (write() directly)
- Edge case handling (INT_MIN overflow, NULL checks)

## Building 
```bash
make
./myprintf
```

## Test Output
Compares `my_printf()` with standard `printf()` side-by-side.

## Known Limitations
- No padding/width (`%10d`)
- No precision control (`.2f` is hardcoded)
- No hex/octal (`%x`, `%o`)
- No pointers (`%p`)

These are intentional -- focus was on understanding core concepts.

## License
MIT
```
---
MIT License

Copyright (c) 2025 benfector

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

## Feedback welcome!
