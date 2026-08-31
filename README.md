# C-Calculator

A simple command-line calculator written in C, built from scratch using a lexer, parser, and error handling.

## Features

- `+` `-` `*` `/` `^`
- Parentheses and operator precedence
- Unary minus
- Floating-point calculations
- Error handling (invalid characters, mismatched parens, division by zero, etc.)
- Modular C project structure
- CMake build system
- Example usage

## Build

```bash
git clone https://github.com/SubhransuPrabhat/C-Calculator.git
cd C-Calculator

mkdir build
cd build
cmake ..
cmake --build .
```

## Install (optional)

```bash
cmake --install .
```

This puts `libcalculator.so` and `calculator.h` on your system so other programs can link with `-lcalculator`. Not required if you just want to build and run the example.

## Usage

Build the example:

```bash
gcc -Iinclude Example/main.c -Lbuild -lcalculator -o Example/calculator
./Example/calculator
```

Or if you havent installed library:

```bash
gcc -Include Example/main.c src/*.c -lm -o calculator
./calculator
```

> Expressions should be quoted when using shell characters such as `*`, `(` and `)`.

## Structure

```
src/        → Lexer, parser & calculator
include/    → Public headers
Example/    → Example program
```

---

Built as a learning project to understand C, parsing, lexers, modular programming, and CMake.
