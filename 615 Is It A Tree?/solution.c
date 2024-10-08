#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NODES 50000

int **conn, connCount[MAX_NODES + 1], parentCount[MAX_NODES + 1], edgeCount, startVertex;
bool visited[MAX_NODES + 1], isTree = true;

void init() {
    memset(connCount + 1, 0, MAX_NODES * sizeof(int));
    memset(parentCount + 1, 0, MAX_NODES * sizeof(int));
    edgeCount = startVertex = 0;
    isTree = true;
}

void dfs(int vertex, int *nodeCount) {
    visited[vertex] = true;
    ++(*nodeCount);
    for(int i = 0; i < connCount[vertex]; ++i) {
        if(!visited[conn[vertex][i]])
            dfs(conn[vertex][i], nodeCount);
    }
}

int main() {
    conn = (int**)calloc(MAX_NODES + 1, sizeof(int*));
    int cases = 0, parent, child;
    while(scanf("%d %d", &parent, &child) && parent >= 0 && child >= 0) {
        if(parent == 0 && child == 0) {
            if(!isTree)
                printf("Case %d is not a tree.\n", ++cases);
            else if(edgeCount == 0)
                printf("Case %d is a tree.\n", ++cases);
            else {
                memset(visited + 1, 0, MAX_NODES * sizeof(bool));
                int nodeCount = 0;
                dfs(startVertex, &nodeCount);
                if(nodeCount == edgeCount + 1)
                    printf("Case %d is a tree.\n", ++cases);
                else
                    printf("Case %d is not a tree.\n", ++cases);
            }
            init();
        } else {
            if(parentCount[child] < 1) {
                conn[parent] = (int*)realloc(conn[parent], (connCount[parent] + 1) * sizeof(int));
                conn[parent][connCount[parent]++] = child;
                conn[child] = (int*)realloc(conn[child], (connCount[child] + 1) * sizeof(int));
                conn[child][connCount[child]++] = parent;
                ++parentCount[child];
                ++edgeCount;
                startVertex = parent;
            } else
                isTree = false;
        }
    }
    for(int i = 0; i <= MAX_NODES; ++i)
        free(conn[i]);
    free(conn);
	return 0;
}
