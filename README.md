*This project has been created as part of the 42 curriculum by mrouabss.*

# Libft

## Description

Libft is my own C library, the first project of the 42 curriculum. Its goal is
to reimplement a set of functions from the C standard library, add some extra
utility functions, and gather them in a static library (`libft.a`) that can be
reused in every later project.

Along the way the project teaches how memory really works in C: bytes and
pointers, `malloc`/`free` and leaks, signed vs. unsigned types, string
handling, function pointers, and linked lists. All functions follow the 42
Norm, use only the allowed external functions (`malloc`, `free`, `write`), and
must never crash (no segfault, no double free, no leaks).

## Instructions

Requirements: a C compiler (`cc`) and `make`.

| Command | Result |
|---|---|
| `make` | Builds `libft.a` (compiled with `-Wall -Wextra -Werror`) |
| `make clean` | Removes the object files |
| `make fclean` | Removes the object files and `libft.a` |
| `make re` | Rebuilds everything from scratch |

Running `make` twice does not relink: the second call reports that there is
nothing to be done.

To use the library in your own program, include the header and link it:

```
cc -Wall -Wextra -Werror main.c -L. -lft 
```

`libft.h` contains the prototypes of every function and the `t_list` type.

## Resources

- `man 3` pages for each libc function (`man 3 strlcpy`, `man 3 memmove`, ...)
- The C standard (ISO/IEC 9899) for the exact behavior of `strcmp`,
  `memcmp`, `strchr` (the terminating `\0` counts as part of the string)
- The 42 Norm (norminette documentation)
- Valgrind and AddressSanitizer documentation, used to detect leaks and
  out-of-bounds accesses
- GNU Make manual, for the Makefile and the `ar` archive tool

### How AI was used

AI (Claude) was used as a tutor and reviewer, not as a replacement for
understanding the code:

- **Explanations**: concepts such as ASCII, `char` vs `int`, signed/unsigned
  conversions, `size_t` underflow, pointers to pointers (`**`), `memmove`
  overlap, file descriptors, linked lists, and how a Makefile and the
  compilation steps work.
- **Code review and debugging**: reviewing functions I wrote, pointing out
  edge cases (empty strings, `NULL`, `size == 0`, overflow in `ft_calloc`,
  `\0` handling in `ft_strchr`), and helping interpret compiler, norminette,
  valgrind and tester output.
- **Test programs**: small `main` files used to compare my functions against
  the real libc.
- **Norm fixes**: formatting-only corrections suggested for norminette errors,
  and a restructured `ft_split` (split into helper functions to respect the
  25-line and 5-variable limits).
- In a few cases the AI provided a corrected version of a function after I had
  written my own attempt (for example `ft_memmove`, `ft_strlcat`, `ft_itoa`);
  I then read, tested and adapted it so that I could explain it during peer
  evaluation.

All code in this repository was read, compiled, tested and is understood by me.

## Library description

`libft.a` contains 43 functions, grouped in three parts. Every function is in
its own `ft_*.c` file.

### Part 1: libc functions

| Function | Description |
|---|---|
| `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` | Character class tests (ASCII), same behavior as the libc functions |
| `ft_toupper`, `ft_tolower` | Convert a letter to upper / lower case |
| `ft_strlen` | Length of a string, without the `\0` |
| `ft_strchr`, `ft_strrchr` | First / last occurrence of a character (the `\0` is searchable) |
| `ft_strncmp` | Compare at most `n` characters, as `unsigned char` |
| `ft_strnstr` | Find a substring in the first `len` characters of a string |
| `ft_strlcpy`, `ft_strlcat` | Size-bounded copy / concatenation, always `\0`-terminated, return the length they tried to create |
| `ft_strdup` | Duplicate a string in newly allocated memory |
| `ft_atoi` | Convert the beginning of a string to an `int` |
| `ft_memset`, `ft_bzero` | Fill a memory area with a byte / with zeros |
| `ft_memcpy`, `ft_memmove` | Copy memory (`ft_memmove` handles overlapping areas) |
| `ft_memchr`, `ft_memcmp` | Search / compare bytes in a memory area |
| `ft_calloc` | Allocate zero-initialized memory, with overflow check |

### Part 2: additional functions

| Function | Description |
|---|---|
| `ft_substr` | Allocate and return a substring of a string |
| `ft_strjoin` | Allocate and return the concatenation of two strings |
| `ft_strtrim` | Remove characters of a given set from both ends of a string |
| `ft_split` | Split a string with a delimiter into a `NULL`-terminated array of strings |
| `ft_itoa` | Convert an `int` to a string (handles negatives and `INT_MIN`) |
| `ft_strmapi` | Apply a function to each character and build a new string |
| `ft_striteri` | Apply a function to each character of a string, in place |
| `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` | Write a character / string / string + newline / number to a file descriptor |

### Linked lists

The `t_list` type holds a `void *content` and a `next` pointer.

| Function | Description |
|---|---|
| `ft_lstnew` | Create a new node |
| `ft_lstadd_front`, `ft_lstadd_back` | Add a node at the beginning / end of a list |
| `ft_lstsize` | Count the nodes |
| `ft_lstlast` | Return the last node |
| `ft_lstdelone`, `ft_lstclear` | Delete one node / the whole list, using a `del` function for the content |
| `ft_lstiter` | Apply a function to the content of every node |
| `ft_lstmap` | Build a new list by applying a function to each content, cleaning up on failure |

## Technical choices

- `unsigned char` is used whenever bytes are compared or read through a
  `void *`, so that bytes above 127 behave like in the libc.
- Counters that are compared with a size use `size_t`; the underflow case
  (`0 - 1`) is avoided by checking before subtracting.
- Functions that allocate return `NULL` on failure and free whatever they had
  already allocated (`ft_split`, `ft_lstmap`).
