#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    FILE* in = fopen("grafy/grafD.txt", "r");
    int n=0;
    while(fgetc(in) != '\n')
            n++;
    rewind(in);
    int** graf = malloc(n*sizeof(int*));
    for(int i = 0; i<n; i++)
    {
        graf[i] = malloc(n*sizeof(int));
    }
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            graf[i][j] = fgetc(in) - '0';
        fgetc(in);
    }

    int node, min=1000, visits=0;
    int* nodes = malloc(n*sizeof(int));
    int* weights = malloc(n*sizeof(int));
    int* visited = calloc(n,sizeof(int));
    for(int i = 0; i<n; i++)
    {
        weights[i] = INT_MAX;
    }
    node = 0;
    weights[node] = 0;
    while (visits<n) {

        for (int i = 0; i < n; i++) {
            if (graf[node][i] > 0 && graf[node][i] + weights[node] < weights[i]) {
                weights[i] = graf[node][i] + weights[node];
                nodes[i] = node;

            }
        }
        visited[node] = 1;
        visits++;
        min = 1000;
        for (int j = 0; j < n; j++)
            if (weights[j] >= 0 && weights[j] < min && visited[j] != 1) {
                node = j;
                min = weights[j];
            }

    }
    node = n-1;
    while (node != 0)
    {
        printf("(%d)<-%d-", node, graf[nodes[node]][node]);
        node = nodes[node];
    }
    printf("(0)\n");

    return 0;
}
