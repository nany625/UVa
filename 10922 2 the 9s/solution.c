#include <stdio.h>
#include <string.h>

int sumOfDigits(int n) {
    int result = 0;
    while(n > 0) {
        result += n % 10;
        n /= 10;
    }
    return result;
}

int main() {
    char N[1001];
    while(scanf("%s", N) && N[0] != '0') {
        int degree = 0, temp = 0, len = strlen(N);
        for(int i = 0; i < len; ++i)
            temp += N[i] - '0';
        while(temp > 9 && temp % 9 == 0) {
            ++degree;
            temp = sumOfDigits(temp);
        }
        degree += temp == 9;
        if(degree == 0)
            printf("%s is not a multiple of 9.\n", N);
        else
            printf("%s is a multiple of 9 and has 9-degree %d.\n", N, degree);
    }
    return 0;
}
