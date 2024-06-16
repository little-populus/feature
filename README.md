# Program entry change way

As usual, program normmally starts with a main function.

```cpp
int main() {
    return 0;
}
```

However, this is not a only way to start a program. There are many ways to do it.

In this project, we are expolring how to change the program entry.

## How to change the program entry

### first way to change the program entry

In linux, all programs exactly starts with _start function. And `main` just is called as `_start`.

so we can change the program entry as follows:

```c
#include <unistd.h>
void _start() {
    main();
    _exit(0);
}
```

Here is a basic point:

_start is not a normal function, so it can not end with `return 0;`.

To reach our result of my project, we can change the program entry as follows:

just change what _start calls from `main` to `function_you_want`.

Here my first example is start.c and not_main.cpp.

there two files construct changing entry point.

just compile these files as follows:

```bash
gcc -o start start.c
gcc -o not_main not_main.cpp
```

and use ld linker to link these two files as follows:

```bash
ld -plugin /usr/libexec/gcc/x86_64-linux-gnu/13/liblto_plugin.so \
-plugin-opt=/usr/libexec/gcc/x86_64-linux-gnu/13/lto-wrapper \
-plugin-opt=-fresolution=/tmp/ccm6G760.res \
-plugin-opt=-pass-through=-lgcc_s \
-plugin-opt=-pass-through=-lgcc \
-plugin-opt=-pass-through=-lc \
-plugin-opt=-pass-through=-lgcc_s \
-plugin-opt=-pass-through=-lgcc \
--build-id --eh-frame-hdr -m elf_x86_64 --hash-style=gnu --as-needed \
-dynamic-linker /lib64/ld-linux-x86-64.so.2 -pie \
start.o \
/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/crti.o \
/usr/lib/gcc/x86_64-linux-gnu/13/crtbeginS.o \
-L/usr/lib/gcc/x86_64-linux-gnu/13 \
-L/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu \
-L/usr/lib/gcc/x86_64-linux-gnu/13/../../../../lib \
-L/lib/x86_64-linux-gnu \
-L/lib/../lib \
-L/usr/lib/x86_64-linux-gnu \
-L/usr/lib/../lib \
-L/usr/lib/gcc/x86_64-linux-gnu/13/../../.. \
not_main.o -v -lstdc++ -lm -lgcc_s -lgcc -lc -lgcc_s -lgcc \
/usr/lib/gcc/x86_64-linux-gnu/13/crtendS.o \
/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/crtn.o \
-o not_main
```
