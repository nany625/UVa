#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char ch, keyboard[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    while((ch = getchar()) != EOF) {
        if(ch == ' ' || ch == '\n')
            putchar(ch);
        else {
            if(isupper(ch))
                tolower(ch);
            for(int i = 2; i < 47; ++i) {
                if(ch == keyboard[i]) {
                    putchar(keyboard[i - 2]);
                    break;
                }
            }
        }
    }
    return 0;
}
