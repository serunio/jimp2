#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int nowakomorka(int komorka, int kierunek, int x)
{
	switch(kierunek)
	{
		case 0:
			return komorka - x;
			break;
		case 1:
			return komorka + 1;
			break;
		case 2:
			return komorka + x;
			break;
		case 3:
			return komorka - 1;
			break;
	}
}
int main()
{
    FILE* in = fopen("grafy/grafA.txt", "r");
    int n, x, y;
    int c;
    fscanf(in, "%d %d", &x, &y);
    fgetc(in);
    n = x*y;
    int** graf = malloc(n*sizeof(int*));
    int* heur = malloc(n*sizeof(int));
    for(int i = 0; i<n; i++)
    {
        graf[i] = malloc(4*sizeof(int));
    }
    for(int i = 0; i<n; i++)
    {
	    for(int j = 4; j>0; j--)
		    fgetc(in);
        for(int j = 0; j<4; j++)
            graf[i][j] = fgetc(in) - '0';
	fscanf(in, "%d", &heur[i]);
	fgetc(in);
    }

    int node, min=1000, visits=0, nowa;
    int* nodes = malloc(n*sizeof(int));
    int* weights = malloc(n*sizeof(int));
    int* visited = calloc(n,sizeof(int));
    for(int i = 0; i<n; i++)
    {
        weights[i] = INT_MAX/2;
    }
    node = 0;
    weights[node] = 0;
    while (visits<n) {

        for (int i = 0; i < 4; i++) {
		nowa = nowakomorka(node, i ,x); 
            if (graf[node][i] > 0 && graf[node][i] + weights[node] < weights[nowa]) {
                weights[nowa] = graf[node][i] + weights[node];
                nodes[nowa] = node;

            }
        }
        visited[node] = 1;
        visits++;
        min = INT_MAX/2;
        for (int j = 0; j < n; j++)
            if (weights[j] >= 0 && weights[j]+heur[j] < min && visited[j] != 1) {
                node = j;
                min = weights[j]+heur[j];
            }

    }
    node = n-1;
    while (node != 0)
    {
        printf("(%d)", node+1);
        node = nodes[node];
    }
    printf("(1)\n");

    return 0;
}
