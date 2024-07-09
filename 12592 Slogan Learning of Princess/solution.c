#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *firstLine, *secondLine;
} Slogan;

int compare(const void *a, const void *b) {
    return strcmp(((Slogan*)a)->firstLine, ((Slogan*)b)->firstLine);
}

char *binarySearch(Slogan *array, int size, char *key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(array[mid].firstLine, key);
        if(cmp == 0)
            return array[mid].secondLine;
        if(cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return NULL;
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();
    Slogan slogans[N];
    for(int i = 0; i < N; ++i) {
        slogans[i].firstLine = slogans[i].secondLine = NULL;
        size_t bufsize = 0;
        getline(&slogans[i].firstLine, &bufsize, stdin);
        getline(&slogans[i].secondLine, &bufsize, stdin);
        slogans[i].firstLine[strcspn(slogans[i].firstLine, "\n")] = '\0';
    }
    qsort(slogans, N, sizeof(Slogan), compare);
    int Q;
    scanf("%d", &Q);
    getchar();
    while(Q--) {
        char *buffer = NULL;
        size_t bufsize = 0;
        getline(&buffer, &bufsize, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        printf("%s", binarySearch(slogans, N, buffer));
        free(buffer);
    }
    for(int i = 0; i < N; ++i) {
        free(slogans[i].firstLine);
        free(slogans[i].secondLine);
    }
    return 0;
}
