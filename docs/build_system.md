# Build system
This document describes the build system used for this decompilation project, for those interested to learn about how we build
the ROM.
- [Extracting assets](#extracting-assets)
- [Delinking code](#delinking-code)
- [Compiling code](#compiling-code)
- [Generating a linker command file](#generating-a-linker-command-file)
- [Linking modules](#linking-modules)
- [Building the ROM](#building-the-rom)

## Extracting assets
We use [`ds-rom`](https://github.com/AetiasHax/ds-rom) to extract code and assets from a base ROM that you provide yourself. It
extracts the following data:
- ARM7 program
    - Code for the DS coprocessor CPU, the ARM7TDMI aka ARM7
    - The program is likely similar to other retail games, so it is not decompiled in this project
- ARM9 program
    - The main program that runs on game launch
    - Also contains the Instruction TCM (ITCM) and Data TCM (DTCM) modules
- ARM9 overlays
    - Dynamically loaded modules that overlap each other in memory
- Banner
    - Logo and text that is displayed on the DS home menu
- Files/assets
    - Models, textures, maps, etc.

## Delinking code
We use [`dsd`](https://github.com/AetiasHax/ds-decomp) as a toolkit for DS decompilation. This includes taking the extracted
code and splitting (delinking) them into smaller files. By editing a `delinks.txt` file, we can tell `dsd` to add more delinked
files to the project.

Each `delinks.txt` file belongs to one module, such as the ARM9 program, the ITCM, the DTCM or an overlay.

> [!NOTE]
> For interested readers:  
> All modules are loaded into RAM. This is different from the DS predecessor, the Game Boy Advance (GBA), in which all code was
> simply on the ROM at all times. As a result, the GBA's RAM only consisted of variable data.
>
> For the DS, however, code and data is competing for space on the same RAM. For reference, the original DS has 4 MB of general
> purpose RAM. Phantom Hourglass consists of about 4.2 MB of code. Not only would there be no space for variables, the RAM
> wouldn't even contain all code at once!
>
> This is why overlays have to exist. They are code modules which are loaded at runtime, and some of them share the same
> address space with each other. Such overlays cannot be loaded at the same time, for obvious reasons.
>
> Note that the DS does have other memory components used by ARM9, namely the ITCM and DTCM. TCM stands for tightly coupled
> memory and has predictable access time unlike typical RAM. However, they are fully static, which means no heap or stack will
> live there. So, they are mostly reserved for hot code and data.

Each module and delinked file consist of multiple sections:
- `.text`: Functions
- `.init`: Static initializers
- `.ctor`: List of static initializers
- `.rodata`: Global constants
- `.data`: Global variables
- `.bss`/`.sbss`: Global uninitialized variables

When the code is linked, all code of the same section will be written adjacent to each other. More on this in
[Linking modules](#linking-modules) below.

## Compiling code
This game was written in C++, so most of the code we decompile will be in this programming language. In C++, we typically don't
have to express which section we want the code to be written to. Instead, the compiler determines the section automatically.
Here are a few examples of how to generate code for different section types.

- `.text`
    - Functions and member functions (aka methods)
    - Example:
```cpp
void GlobalFunction() {}
void MyClass::MemberFunction() {}
```
- `.init`
    - Static initializers, i.e. global variables that are initialized by a constructor
    - To our knowledge, there is at most one static initializer per source file. This means that multiple variables can be
    initialized in one static initializer, if they are in the same source file.
    - See the example below. Since `foo` is initialized by a constructor and not as plain data, this constructor has to be
    called at some point before `foo` can be used. Overlays do this happens as soon as the overlay has been loaded.
```cpp
class Foo {
    int myValue;
    Foo(int value): myValue(value) {}
};

// This will be a static initializer
Foo foo = Foo(42);
```
- `.ctor`
    - List of static initializers
    - Generated automatically when you create a static initializer
- `.rodata`
    - Global or static constants
    - Example:
```cpp
// This will be .rodata
const unsigned int fibonacciLimit = 8;

int BadFibonacci(unsigned int n) {
    assert(n < fibonacciLimit);

    // This will also be .rodata
    static const int fibonacciNumbers[] = {
        1, 1, 2, 3, 5, 8, 13, 21
    };
    return fibonacciNumbers[n];
}
```
- `.data`
    - Global or static variables
    - Example:
```cpp
// .data variables must have an initial value other than 0
int maxPlayerHealth = 20;

void DamagePlayer(int damage) {
    static int playerHealth = maxPlayerHealth;
    playerHealth -= damage;
}
```
- `.bss`
    - Global or static uninitialized variables
    - Example:
```cpp
// .bss variables always have an initial value of 0
int bssInt = 0;
bool bssBool = false;

// ...but you don't have to explicitly assign 0
short bssShort;
```
- `.sbss`:
    - "Small" global or static uninitialized variables
    - Not part of the ARM standard, but appears to exist in the game in some way
    - Example:
```cpp
#pragma section sbss begin
int thisWillBeSbss;
#pragma section sbss end
```

## Generating a linker command file

The linker command file (LCF), also known as linker script, tells the linker in which order it should link the compiled or
assembled files. It is generated by `dsd` which calculates a correct file order according to the `delinks.txt`.

The LCF also decides in what order the sections are linked in each module. In the main module, the order is:

 `.text` | `.init` | `.rodata` | `.ctor` | `data` | `.bss` | `.sbss`
---------|---------|-----------|---------|--------|--------|---------
<br>

For overlays, `.init` comes after `.rodata`:

 `.text` | `.rodata` | `.init` | `.ctor` | `data` | `.bss` | `.sbss`
---------|-----------|---------|---------|--------|--------|---------
<br>

The ITCM only contains `.text` and the DTCM only contains `.data` and `.bss`.

The LCF generates ROM images for each module into the `/build/<version>/build/` directories. These are then passed back into
`ds-rom` to rebuild the ROM.

## Linking modules
The LCF and list of compiled/assembled files will be passed to the linker, which generates the files mentioned in the previous
section.

The linker eliminates some dead code such as unused constructor and destructor variants.

## Building the ROM

At this stage, we should have all the resources needed to rebuild the ROM. We use `ds-rom` to build everything according to the
specifications of the base ROM, but instead using the ROM images that the linker created.
