#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
	int cases;
	scanf("%d", &cases);
	getchar();
	getchar();
	bool firstCase = true;
	while(cases--) {
	    if(!firstCase)
	        puts("");
	    char plaintext[66], substitution[66];
	    fgets(plaintext, sizeof(plaintext), stdin);
		fgets(substitution, sizeof(substitution), stdin);
		printf("%s%s", substitution, plaintext);
		char text[68];
		while(fgets(text, sizeof(text), stdin) && strcmp(text, "\n") != 0) {
		    int lenText = strlen(text);
		    for(int i = 0; i < lenText; ++i) {
		        int lenPlainText = strlen(plaintext);
		        bool found = false;
		        for(int j = 0; j < lenPlainText && !found; ++j) {
		            if(text[i] == plaintext[j]) {
		                putchar(substitution[j]);
		                found = true;
		            }
		        }
		        if(!found)
		            putchar(text[i]);
		    }
		}
		firstCase = false;
	}
	return 0;
}
