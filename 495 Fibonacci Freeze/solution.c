#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *number;
    short digits;
} Fib;

Fib fib[5001];

int main() {
    fib[0].number = strdup("0");
    fib[1].number = strdup("1");
    fib[0].digits = fib[1].digits = 1;
    for(int i = 2; i <= 5000; ++i) {
        fib[i].number = (char*)malloc((fib[i - 1].digits + 1) * sizeof(char));
        memset(fib[i].number, '0', fib[i - 1].digits + 1);
        short j;
        for(j = 0; j < fib[i - 1].digits; ++j) {
        	fib[i].number[j + 1] += (fib[i].number[j] + fib[i - 1].number[j] + fib[i - 2].number[j] - 3 * '0') / 10;
        	fib[i].number[j] = (fib[i].number[j] + fib[i - 1].number[j] + fib[i - 2].number[j] - 3 * '0') % 10 + '0';
        }
        fib[i].digits = j + (fib[i].number[j] - '0');
    }
    int number;
    while(scanf("%d", &number) == 1) {
        printf("The Fibonacci number for %d is ", number);
        for(int i = fib[number].digits - 1; i >= 0; --i)
            putchar(fib[number].number[i]);
        putchar('\n');
    }
    for(int i = 0; i <= 5000; ++i)
        free(fib[i].number);
    return 0;
}
