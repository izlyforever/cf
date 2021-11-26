#include <stdio.h>
int main(void) {
    int foo=10, bar=15, high, low;
    __asm__ __volatile__(
    "mull %%edx"
    : "=a"(low), "=d"(high)
    : "a"(foo), "d"(bar)
    );
    printf("%d %d\n", high, low);
    // __asm__ __volatile__ ("addl %%ebx,%%eax"
    //     : "=eax"(foo) 
    //     : "eax"(foo), "ebx"(bar) 
    //     : "eax" 
    // );
    return 0;
}