#include <stdio.h>

int main() {
    int N;
    while(scanf("%d", &N) && N != 0)
        printf("%d\n", N * (N + 1) * ((N << 1) + 1) / 6);
	return 0;
}
