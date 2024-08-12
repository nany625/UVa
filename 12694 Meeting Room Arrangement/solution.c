#include <stdio.h>
#include <stdlib.h>

typedef struct {
    short s, f;
} Event;

int compare(const void *a, const void *b) {
    Event *e1 = (Event*)a;
    Event *e2 = (Event*)b;
    if(e1->f == e2->f)
        return e1->s < e2->s;
    return e1->f > e2->f;
}

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        Event *events = NULL;
        int size = 0;
        short s, f;
        while(scanf("%hd %hd", &s, &f) && (s != 0 || f != 0)) {
            events = (Event*)realloc(events, (size + 1) * sizeof(Event));
            events[size].s = s;
            events[size++].f = f;
        }
        qsort(events, size, sizeof(Event), compare);
        int end = 0, count = 0;
        for(int i = 0; i < size; ++i) {
            if(events[i].s >= end) {
                end = events[i].f;
                ++count;
            }
        }
        printf("%d\n", count);
        free(events);
    }
	return 0;
}
