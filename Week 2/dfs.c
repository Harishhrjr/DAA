#include <stdio.h>
#define MAX 100
int visited[MAX];
void dfs(int graph[][MAX], int n, int start) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            dfs(graph, n, i);
        }
    }
}
int main() {
    printf("Harish.r CH.SC.U4cse24163\n");
    int n = 4;
    int graph[MAX][MAX] = {
        {0,1,1,0},
        {1,0,1,1},
        {1,1,0,0},
        {0,1,0,0}
    };
    for (int i = 0; i < MAX; i++)
        visited[i] = 0;

    dfs(graph, n, 0);

    return 0;
}
