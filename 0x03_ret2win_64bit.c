// gcc -fno-stack-protector -z execstack -no-pie -o level2 SourceCode_for_YouTube/0x02_ret2win64bit.c


// To install GDB and gef

// sudo apt install gdb
// wget -O ~/.gdbinit-gef.py -q https://gef.blah.cat/py
// echo source ~/.gdbinit-gef.py >> ~/.gdbinit

// To install pwn
// pip install pwntools

#include <stdio.h>
#include <stdlib.h>

// Declare gets manually to bypass compiler restriction
char *gets(char *s);

// Simulate a pop rdi; ret gadget
__attribute__((naked)) void pop_rdi_ret() {
    __asm__(
        "pop %rdi\n"
        "ret\n"
    );
}

// Simulate a pop rsi; ret gadget
__attribute__((naked)) void pop_rsi_ret() {
    __asm__(
        "pop %rsi\n"
        "ret\n"
    );
}

void win(unsigned int param1, unsigned int param2) {
    puts("Win function is running.");
    if (param1 == 0xDEADBEEF && param2 == 0xC0DEBEEF) {
        puts("Exploited!!!!!");
    } else {
        puts("Where are the parameters?? :(");
    }
}

void unsafe() {
    char buffer[64];

    puts("Overflow me:");
    gets(buffer);  // Intentional vulnerability
    
    // void *ret_addr = __builtin_return_address(0);
    // printf("Return address: %p\n", ret_addr);
}

int main() {
    unsafe();
    return 0;
}
