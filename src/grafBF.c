#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** graf;
int edges;
int compare(const void* a, const void* b)
{
	return graf[*(int*)a][edges] > graf[*(int*)b][edges] ? 1 : -1;
}
int main(int argc, char** argv)
{
	FILE* out = fopen("grafy/grafBF.txt", "w");
	edges = argc > 1 ? atoi(argv[1]) : 7;
	int maxNodes = edges-1;
	int a, b, waga;
	srand(time(NULL));
	
	int* queue = malloc(maxNodes * sizeof(int));
	for(int i = 0; i < maxNodes; i++)
		queue[i] = i;
	graf = malloc(maxNodes * sizeof(int*));
	for(int i = 0; i<maxNodes; i++)
	{
		graf[i] = malloc((edges+1) * sizeof(int));
		for(int j = 0; j < edges; j++)
			graf[i][j] = 0;
		graf[i][edges] = 0;
	}
	for(int i = 0; i < edges; i++)
	{
		waga = rand()%9 +1;
		a = b = queue[0];
		while(a==b)
			b = queue[rand()%(maxNodes-2)];
		graf[a][i] = waga;
		graf[b][i] = -1*waga;
		graf[a][edges]++;
		graf[b][edges]++;
		qsort(queue, maxNodes, sizeof(int), compare);
	}

	for(int i = 0; i < maxNodes; i++)
	{
		fprintf(out, "%d.", i+1);
		for(int j = 0; j < edges; j++)
			fprintf(out, "%2i ", graf[i][j]);
		fprintf(out, "\n");
		free(graf[i]);
	}	

	fclose(out);
	free(graf);
	return 0;
}
