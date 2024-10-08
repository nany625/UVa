#include <stdio.h>
#include <string.h>

int main() {
	char X[251], Y[251];
	while(scanf("%s %s", X, Y) == 2) {
	    int lenX = strlen(X), lenY = strlen(Y);
	    char ans[lenX + lenY + 1];
	    memset(ans, '0', sizeof(ans));
	    ans[lenX + lenY] = '\0';
	    for(int i = lenY - 1; i >= 0; --i) {
	        for(int j = lenX - 1; j >= 0; --j) {
	            ans[i + j] += ((X[j] - '0') * (Y[i] - '0') + ans[i + j + 1] - '0') / 10;
	            ans[i + j + 1] = ((X[j] - '0') * (Y[i] - '0') + ans[i + j + 1] - '0') % 10 + '0';
	        }
	    }
	    int i = 0;
		while(i < lenX + lenY && ans[i] == '0')
		    ++i;
		puts(i == lenX + lenY ? "0" : ans + i);
	}
	return 0;
}
