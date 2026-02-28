# IMPROVEMENT_PLAN.md — libft Comprehensive Improvement Plan

## Executive Summary

This library is a well-structured reimplementation of standard C library functions, written as a 42 School project. It has a thoughtful directory hierarchy, consistent naming, two build systems (Make + CMake), and CI configuration. However, it contains a number of bugs ranging from memory-safety issues to incorrect semantics, has zero test coverage, minimal documentation, and is missing many standard functions. This plan addresses all of these areas in priority order.

---

## Priority 1 — Critical Bug Fixes (Memory Safety and Correctness)

These issues can cause crashes, memory leaks, or undefined behavior in production use.

### Fix 1.1: ft_lstnew — Unchecked malloc for content

**File:** `src/containers/list/ft_lstnew.c`

**Problem:** `malloc(content_size)` is called and its return value is immediately passed to `ft_memcpy` without a NULL check. If `malloc` fails, `ft_memcpy(NULL, content, content_size)` is undefined behavior.

**Fix:** After `list->content = malloc(content_size)`, check `if (!list->content)`. On failure, `free(list)` and `return (NULL)`.

---

### Fix 1.2: ft_lstmap — Partial list memory leak on allocation failure

**File:** `src/containers/list/ft_lstmap.c`

**Problem:** When `ft_lstnew` fails mid-traversal, `return (NULL)` is called without freeing the already-built result list.

**Fix:** On `ft_lstnew` failure inside the loop, call `ft_lstdel(&res, ...)` to free the partial result, then return NULL.

---

### Fix 1.3: ft_swap — Unchecked malloc

**File:** `src/basics/memory/transform/ft_swap.c`

**Problem:** `tmp = malloc(bytes)` is not checked. If it fails, `ft_memcpy(NULL, x, bytes)` crashes.

**Fix:** Check the return value and return early on NULL.

---

### Fix 1.4: ft_strcmp — Logically incorrect equal-string detection

**File:** `src/basics/strings/iterate/ft_strcmp.c`

**Problem:** The inner check `if (*ps1 == '\0' && *ps2 == '\0')` runs after the post-increment, meaning it checks the bytes *after* the equal bytes. For strings on heap allocations, this accesses memory past the allocation boundary — undefined behavior.

**Fix:** Use the standard idiom:
```c
while (*ps1 && (*ps1 == *ps2)) { ps1++; ps2++; }
return (*(unsigned char *)ps1 - *(unsigned char *)ps2);
```

---

### Fix 1.5: ft_iscntrl — Incorrect semantics for non-ASCII values

**File:** `src/basics/chars/check/ft_iscntrl.c`

**Problem:** `!ft_isprint(c)` returns true for any value >= 128 (non-ASCII), treating them as control characters. The C standard says `iscntrl` covers only `[0x00, 0x1F]` and `0x7F`.

**Fix:**
```c
int ft_iscntrl(int c) { return ((c >= 0 && c <= 31) || c == 127); }
```

---

### Fix 1.6: ft_readline — fd stored in content_size (semantic abuse + sign narrowing)

**File:** `src/utils/file/ft_readline.c`

**Problem:** The `t_list` node's `content_size` field (`size_t`) is repurposed to store a file descriptor (`int`). The cast `(int)tmp->content_size` narrows `size_t` to `int`, which is implementation-defined on 64-bit platforms.

**Fix:** Use a dedicated struct for readline state. Define a private `t_gnl_state` structure with `int fd` and `char *remainder` fields instead of abusing `t_list`.

---

## Priority 2 — Logic Bugs and Behavioral Deviations

### Fix 2.1: ft_strcountwords — Incorrect word count for leading/trailing delimiters

**File:** `src/basics/strings/iterate/ft_strcountwords.c`

**Problem:** For input `" hello world "` with delimiter `' '`, the function gives the wrong count due to unconditionally adding 1 at the end regardless of a trailing delimiter.

**Fix:** Rewrite to count non-delimiter sequences: a word starts when the current character is not the delimiter and the previous character was the delimiter (or it's the first character).

---

### Fix 2.2: ft_strsplit — sizeof(pointer) used instead of sizeof(char)

**File:** `src/basics/strings/create/ft_strsplit.c`

**Problem:**
1. `malloc(ft_strlen(str) * sizeof(s))` — `sizeof(s)` is `sizeof(char*)` = 8, not 1
2. `malloc(sizeof(src) * (wrd + 2))` — `sizeof(src)` is `sizeof(char**)` = 8, should be `sizeof(char*)`

**Fix:** Change `sizeof(s)` to `sizeof(char)`. Change `sizeof(src)` to `sizeof(char *)`.

---

### Fix 2.3: ft_strnjoin — Off-by-one from pre-increment

**File:** `src/basics/strings/create/ft_strnjoin.c`

**Problem:** `int nbr = ft_strlen(s1) + ++len` pre-increments `len`, making the loop copy `len+1` characters from `s2` instead of `len`.

**Fix:** Use `len + 1` in the allocation without modifying `len`, then let the loop use the original `len`.

---

### Fix 2.4: ft_lstdelone — Node leaked when del is NULL

**File:** `src/containers/list/ft_lstdelone.c`

**Problem:** The node and its content are only freed if `del != NULL`. If `del` is NULL, the node itself is permanently leaked.

**Fix:** Always free the node; only call `del(content, content_size)` if `del != NULL`.

---

## Priority 3 — Code Quality Improvements

### 3.1 Replace magic ASCII numbers with character literals

Replace in `ft_isblank.c`, `ft_isspace.c`, `ft_toupper.c`, `ft_tolower.c`, `ft_isgraph.c`, `ft_isprint.c`:
- `c == 9` → `c == '\t'`
- `c == 32` → `c == ' '`
- `c - 32` / `c + 32` → compute using character literal difference

### 3.2 Use size_t for string lengths throughout

In `ft_strdup.c`, `ft_strlen.c`, `ft_str_endswith.c`, `ft_str_startswith.c`:
- Change `int l`, `int len`, `int s1_l` to `size_t`

### 3.3 Standardize NULL pointer convention

Replace `(char*)0`, `(char **)0`, and bare `0` used as pointer null values with `NULL` throughout.

### 3.4 Add const to non-mutating pointer parameters

Change `char *s1, char *s2` to `const char *s1, const char *s2` in `ft_str_endswith` and `ft_str_startswith`.

### 3.5 Rename `new` parameter in ft_lstadd

`t_list *new` conflicts with the C++ `new` keyword. Rename to `t_list *node` or `t_list *elem`.

### 3.6 Remove redundant void* cast in ft_memalloc

`mem = (void*)malloc(size)` — the cast is redundant in C. Remove it.

### 3.7 Fix ft_strtrim empty-result allocation

Replace `return (ft_strnew(1))` with `return (ft_strnew(0))` when `min == max` to correctly allocate only the null terminator.

### 3.8 Add a master include header

Create `inc/libft.h` that includes all sub-headers in dependency order. Currently users must include each header separately and in the correct order; an umbrella header greatly improves usability.

---

## Priority 4 — Missing Standard Functions to Add

### Tier A — ctype.h
- `ft_isxdigit(int c)` — test for hex digit `[0-9A-Fa-f]`

### Tier B — string.h
- `ft_strlcpy(char *dst, const char *src, size_t size)` — bounds-safe string copy
- `ft_strpbrk(const char *s, const char *accept)` — find first char from accept set
- `ft_strspn(const char *s, const char *accept)` — count leading chars in accept set
- `ft_strcspn(const char *s, const char *reject)` — count leading chars not in reject set

### Tier C — Number conversion
- `ft_strtol(const char *str, char **endptr, int base)` — base-aware signed conversion
- `ft_strtoul(const char *str, char **endptr, int base)` — unsigned variant
- `ft_lltoa(long long n)` — convert long long to allocated string
- `ft_itoa_base(int n, int base)` — convert integer to any base (2–16) string

### Tier D — List utilities
- `ft_lstsize(t_list *lst)` — returns count of nodes
- `ft_lstlast(t_list *lst)` — returns pointer to last node
- `ft_lstadd_back(t_list **alst, t_list *new)` — append to end of list

### Tier E — Math
- `ft_max(int a, int b)` / `ft_min(int a, int b)` — simple comparison functions
- `ft_clamp(int val, int min, int max)` — clamp value to range

### Tier F — Formatted output (major addition)
- `ft_printf(const char *format, ...)` — supports `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%p`, `%%`
- `ft_dprintf(int fd, const char *format, ...)` — fd-variant of printf

---

## Priority 5 — Documentation

### 5.1 Expand the README

The current `README.md` contains only a Travis CI badge. It needs:
- Build instructions (`make`, `make clean`, `make fclean`, `make re`)
- Usage example (compiler flags, include path)
- Function reference organized by header
- License section

### 5.2 Add Doxygen-style comments to all headers

Each function declaration should document parameters, return value, and NULL handling:
```c
/**
 * @brief Duplicates a string.
 * @param s1 The string to duplicate. Must not be NULL.
 * @return Pointer to the new string, or NULL if allocation fails.
 */
char *ft_strdup(const char *s1);
```

### 5.3 Document NULL behavior contracts

Functions currently handle NULL inconsistently:
- `ft_strdup(NULL)` — crashes (no NULL guard in ft_strlen)
- `ft_strtrim(NULL)` — returns NULL (has NULL guard)
- `ft_putstr(NULL)` — silently does nothing
- `ft_strcmp(NULL, ...)` — crashes

Audit every function, add NULL guards where semantically appropriate, and document the behavior in the header.

### 5.4 Add CHANGELOG.md

Track all fixes and additions between versions.

---

## Priority 6 — Testing Infrastructure

Currently there are **zero tests**. This is the single biggest quality gap.

### 6.1 Create a tests/ directory

```
tests/
    Makefile
    main_test.c
    test_chars.c
    test_memory.c
    test_strings.c
    test_numbers.c
    test_maths.c
    test_list.c
    test_readline.c
```

### 6.2 Critical test cases to add immediately

- `ft_strcmp("", "")` → 0
- `ft_strcmp("a", "a")` → 0
- `ft_strcountwords("", ' ')` → 0
- `ft_strcountwords(" hello world", ' ')` → 2
- `ft_strcountwords(" hello world ", ' ')` → 2
- `ft_strsplit("  hello  world  ", ' ')` → handles multiple consecutive delimiters
- `ft_itoa(INT_MIN)` → `"-2147483648"`
- `ft_itoa(0)` → `"0"`
- `ft_iscntrl(127)` → non-zero
- `ft_iscntrl(200)` → zero
- `ft_lstnew(NULL, 0)` → no crash
- `ft_lstmap` with failing allocator → no leak

### 6.3 Add test target to Makefile

```makefile
test: $(NAME)
    $(MAKE) -C tests
    ./tests/libft_tests
.PHONY: test
```

### 6.4 Add AddressSanitizer CI checks

Run tests with `-fsanitize=address,undefined` and Valgrind to catch memory errors automatically.

---

## Priority 7 — Build System

### 7.1 Add dependency file generation

Add `-MMD -MP` flags and `-include $(OBJ:.o=.d)` to track header dependencies precisely, avoiding full rebuilds when unrelated headers change.

### 7.2 Add install target

```makefile
PREFIX ?= /usr/local
install: $(NAME)
    install -d $(PREFIX)/lib $(PREFIX)/include/libft
    install -m 644 $(NAME) $(PREFIX)/lib/
    cp -r inc/libft $(PREFIX)/include/
.PHONY: install
```

### 7.3 Add shared library target

```makefile
libft.so: $(OBJ)
    $(CC) -shared -o $@ $(OBJ)
```

### 7.4 Strengthen compiler warning flags

Current `CFLAGS = -Wall -Wextra -Werror -O2` is a good baseline. Add:
- `-Wshadow` — detect variable shadowing
- `-Wconversion` — catch implicit type conversions (catches int/size_t issues)
- `-Wstrict-prototypes` — enforce strict prototypes
- `-pedantic` — strict standard compliance

### 7.5 Migrate CI from Travis to GitHub Actions

Travis CI's free tier is defunct. Migrate to `.github/workflows/ci.yml` with a matrix across `gcc`/`clang` and `ubuntu`/`macos`.

---

## Summary Table

| ID   | Issue                                          | Severity | Category      |
|------|------------------------------------------------|----------|---------------|
| 1.1  | ft_lstnew: NULL deref after malloc             | Critical | Memory Safety |
| 1.2  | ft_lstmap: leak on partial alloc failure       | Critical | Memory Safety |
| 1.3  | ft_swap: NULL deref after malloc               | Critical | Memory Safety |
| 1.4  | ft_strcmp: UB in equal-string path             | Critical | Correctness   |
| 1.5  | ft_iscntrl: wrong for non-ASCII values         | High     | Correctness   |
| 1.6  | ft_readline: fd stored in size_t field         | High     | Safety/Design |
| 2.1  | ft_strcountwords: wrong for edge-case delims   | High     | Logic Bug     |
| 2.2  | ft_strsplit: sizeof(pointer) not sizeof(char)  | High     | Memory        |
| 2.3  | ft_strnjoin: off-by-one from pre-increment     | Medium   | Logic Bug     |
| 2.4  | ft_lstdelone: node leaked when del==NULL       | Medium   | Memory Leak   |
| 3.x  | Magic ASCII numbers, int vs size_t, etc.       | Low–Med  | Code Quality  |
| —    | Zero test coverage                             | Critical | Testing       |
| —    | README is nearly empty                         | High     | Documentation |
| —    | Travis CI defunct                              | High     | CI/CD         |
| —    | Missing ft_isxdigit, ft_strlcpy, ft_strpbrk   | Medium   | Missing Func  |
| —    | Missing ft_strtol / ft_strtoul                 | Medium   | Missing Func  |
| —    | Missing ft_lstsize, ft_lstlast, ft_lstadd_back | Low      | Missing Func  |
| —    | No master include header                       | Medium   | Usability     |

---

## Recommended Implementation Sequence

**Phase 1 — Critical fixes (highest impact, lowest risk):**
1. Fix ft_lstnew malloc check (1.1)
2. Fix ft_lstmap leak (1.2)
3. Fix ft_swap malloc check (1.3)
4. Fix ft_strcmp logic (1.4)
5. Fix ft_iscntrl semantics (1.5)

**Phase 2 — Logic bugs:**
6. Fix ft_strcountwords (2.1)
7. Fix ft_strsplit sizeof errors (2.2)
8. Fix ft_strnjoin off-by-one (2.3)
9. Fix ft_lstdelone incomplete free (2.4)

**Phase 3 — Code quality:**
10. Replace magic numbers with char literals (3.1)
11. Fix size_t usage throughout (3.2)
12. Standardize NULL comparisons (3.3)
13. Add const to parameters (3.4)
14. Create master include header (3.8)

**Phase 4 — Testing infrastructure:**
15. Set up `tests/` directory and harness
16. Write tests for all known bugs
17. Write tests for all other functions
18. Add test target to Makefile, enable ASAN

**Phase 5 — Missing functions and documentation:**
19. Add `ft_isxdigit`, `ft_strlcpy`, `ft_strpbrk`
20. Add `ft_strtol` / `ft_strtoul`
21. Add list utilities (`ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`)
22. Expand README
23. Add Doxygen comments to headers
24. Migrate CI to GitHub Actions
