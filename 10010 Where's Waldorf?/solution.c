#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int dRow[] = {0, 1, 0, -1, 1, 1, -1, -1}, dCol[] = {1, 0, -1, 0, 1, -1, -1, 1};

bool searchInDirection(char **grid, int m, int n, char *word, int wordLen, int row, int col, int dir) {
    for(int i = 0; i < wordLen; ++i) {
        int newRow = row + i * dRow[dir], newCol = col + i * dCol[dir];
        if(newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || toupper(word[i]) != toupper(grid[newRow][newCol]))
            return false;
    }
    return true;
}

int main() {
	int cases;
	scanf("%d", &cases);
	bool firstCase = true;
	while(cases--) {
		if(!firstCase)
			puts("");
		int m, n;
		scanf("%d %d", &m, &n);
		char **grid = (char**)malloc(m * sizeof(char*));
		for(int i = 0; i < m; ++i) {
		    grid[i] = (char*)malloc((n + 1) * sizeof(char));
			scanf("%s", grid[i]);
		}
		int k;
		scanf("%d", &k);
		getchar();
		while(k--) {
		    char *word = NULL;
		    size_t wordsize = 0;
			getline(&word, &wordsize, stdin);
			word[strcspn(word, "\n")] = '\0';
			int wordLen = strlen(word);
			bool found = false;
			for(int row = 0; row < m && !found; ++row) {
				for(int col = 0; col < n && !found; ++col) {
					for(int dir = 0; dir < 8 && !found; ++dir) {
                        if(searchInDirection(grid, m, n, word, wordLen, row, col, dir)) {
                            printf("%d %d\n", row + 1, col + 1);
                            found = true;
                        }
                    }
				}
			}
			free(word);
		}
		for(int i = 0; i < m; ++i)
            free(grid[i]);
		free(grid);
		firstCase = false;
	}
	return 0;
}
