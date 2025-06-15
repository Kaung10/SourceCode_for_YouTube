// gcc  -fno-stack-protector -z execstack -no-pie -o level2 0x02_ret2win.c -m32

// If error is #include <bits/libc-header-start.h> , write this command
// sudo apt update
// sudo apt install gcc-multilib libc6-dev-i386


#include <stdio.h>
#include <stdlib.h>

// Declare gets manually to bypass compiler restriction
char *gets(char *s);

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
}

int main() {
    unsafe();
    return 0;
}
