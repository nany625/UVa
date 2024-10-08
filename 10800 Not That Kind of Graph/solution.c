#include <stdio.h>
#include <string.h>

int main() {
	int N;
	scanf("%d", &N);
	char stockPrice[51];
	for(int i = 1; i <= N; ++i) {
		printf("Case #%d:\n", i);
		scanf("%s", stockPrice);
		int min, max, curr = 0;
		switch(stockPrice[0]) {
		    case 'R':
		        min = max = curr++;
		        break;
		    case 'F':
		        min = max = --curr;
		        break;
		    case 'C':
		        min = max = curr;
		}
		int len = strlen(stockPrice);
		for(int j = 1; j < len; ++j) {
		    switch(stockPrice[j]) {
    			case 'R':
    				if(max < curr)
    					max = curr;
    				++curr;
    				break;
    			case 'F':
    				--curr;
    				if(min > curr)
    					min = curr;
    				break;
    			case 'C':
    				if(min > curr)
    					min = curr;
    				if(max < curr)
    					max = curr;
		    }
		}
		char graph[max - min + 1][len + 1];
		int start = max;
		for(int j = 0; j < len; ++j) {
			for(int k = 0; k < max - min + 1; ++k) {
				graph[k][j] = ' ';
				graph[k][j + 1] = '\0';
			}
			switch(stockPrice[j]) {
			    case 'R':
    				graph[start--][j] = '/';
    				break;
    			case 'F':
    				graph[++start][j] = '\\';
    				break;
    			case 'C':
    				graph[start][j] = '_';
			}
		}
		for(int j = 0; j < max - min + 1; ++j) {
		    len = strlen(graph[j]) - 1;
			while(graph[j][len] == ' ')
				graph[j][len--] = '\0';
			printf("| %s\n", graph[j]);
		}
		putchar('+');
		len = strlen(stockPrice) + 2;
		while(len--)
			putchar('-');
		puts("\n");
	}
	return 0;
}
