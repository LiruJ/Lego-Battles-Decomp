# Inline assembler
- [Differences from standalone assembler](#differences-from-standalone-assembler)

## Differences from standalone assembler
Below is a list of differences between the inline assembler and the standalone disassembler. If something is missing, feel free
to contribute to the list!
- [Pool constants](#pool-constants)
- [Data sections](#data-sections)
- [Comments](#comments)

### Pool constants
There is no `.word` or other data directives in the inline assembler. Instead, there are three built-in instructions you can
use:

#### `dcd`: Emits a literal 32-bit value
```asm
mov r0, [pc, #0]
bx lr
dcd 0x1234
```

#### `ldconst`: Loads a literal 32-bit value
```asm
ldconst r0, #0x1234
bx lr
```
This code is equivalent to the above example using `dcd`.

#### `lda`: Loads the address to a symbol
```
lda r0, data_ov00_02abcdef
```

### Data sections
Directives such as `.section`, `.data` and `.bss` are not supported in the inline assembler. It's possible to change section
with a `#pragma`, but there's no need to. Data should only be defined in standalone assembly or C/C++.

### Comments
Inline assembly is handled by the compiler, so comments must be in C/C++ format. This means using `//` and `/* */` instead of
`#` or `;`.

Semicolons `;` instead mark the end of an instruction and are optional. You can use them to put multiple instructions on one
line, but we avoid doing it so that we can preserve as much similarity to standalone assembly as possible.
