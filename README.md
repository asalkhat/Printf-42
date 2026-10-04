*This activity has been created as part of the 42 curriculum by asalkhat.*

## Description

ft_printf is a static library written in C that recreates the behavior of the standard `printf()` function for a specific set of conversions.

The goal of this project is to:

- Understand how variadic functions work in C.
- Practice using `va_list`, `va_start`, `va_arg`, and `va_end`.
- Understand formatted output and different number representations.
- Practice working with characters, strings, numbers, hexadecimal values, and pointers.
- Create a reusable `libftprintf.a` library for future 42 projects.

Supported conversions:

- `%c`
- `%s`
- `%p`
- `%d`
- `%i`
- `%u`
- `%x`
- `%X`
- `%%`

## Instructions

`make` to compile the library.

`make clean` to remove all object files.

`make fclean` to remove all object files and the library.

`make re` to remove all object files and the library, then compile the library again.

The compiled library is called `libftprintf.a`.

To compile a test program:

```bash
cc main.c libftprintf.a -o test
./test
```

## Algorithm and Technical Choices

The format string is processed from left to right. When `%` is found, the next character determines which conversion should be used.

`va_arg()` retrieves the corresponding argument, which is then passed to a helper function responsible for printing it.

Separate helper functions are used for characters, strings, signed numbers, unsigned numbers, hexadecimal numbers, and pointers.

Numbers are printed digit by digit, using recursion where needed. Hexadecimal numbers use a base of 16, and pointers are converted to `unsigned long` before being printed in hexadecimal.

This structure keeps the functions simple, organized, and reusable.

## Resources

I used the following resources to understand C programming and the topics required for this project:

- GeeksforGeeks: https://www.geeksforgeeks.org/
- Reddit: https://www.reddit.com/
- Linux Manual Pages: https://man7.org/linux/man-pages/
- W3Schools: https://www.w3schools.com/c/
- Neso Academy: https://www.youtube.com/@nesoacademy
- Portfolio Courses: https://www.youtube.com/@PortfolioCourses

I also used AI as a learning and debugging assistant. It was used to explain C concepts, variadic functions, pointers, hexadecimal numbers, Makefiles, and to help understand and debug problems during the project.
