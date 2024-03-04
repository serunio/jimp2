#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
	FILE* in = fopen("grafy/grafBF.txt", "r");
	int edges;
	int nodes = 0;
	int n=0;
	int c;
	while((c = fgetc(in)) != '\n')
	{
		n++;
	}
	nodes++;
	while((c = fgetc(in)) != EOF)
		if(c=='\n')
			nodes++;
	edges = (n-2)/3;
	rewind(in);
	int** graf = malloc(nodes*sizeof(int*));
		for(int i = 0; i < nodes; i++)
		{
			graf[i] = malloc(edges*sizeof(int));
			c = fgetc(in);
		       	c = fgetc(in);
			for(int j = 0; j < edges; j++)
				fscanf(in, "%i", &graf[i][j]);
			c = fgetc(in);
			c = fgetc(in);
		}
	fclose(in);

	int* poprzedni = malloc(nodes*sizeof(int));
	int* koszt = malloc(nodes*sizeof(int));
	koszt[0] = 0;
	for(int i = 1; i < nodes; i++)
		koszt[i] = INT_MAX/2;

	int a, b, na=0, nb=0;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < edges; j++)
		{
			na=0;
			while((a = graf[na][j]) <= 0)
				na++;
			nb=0;
			while((b = graf[nb][j]) >= 0)
				nb++;
			if(koszt[na]+a < koszt[nb])
			{
				koszt[nb] = koszt[na]+a;
				poprzedni[nb] = na;
			}
			if(koszt[nb]+b < koszt[na])
			{
				koszt[na] = koszt[nb]+b;
				poprzedni[na] = nb;
			}
		}
	}
	//for(int i = 0; i < nodes; i++)
	//{
	//	printf("%i ", poprzedni[i]+1);
	//}
	n = nodes-1;
	while(n!=0)
	{
		printf("(%d)",n+1);
       		n = poprzedni[n];	
	}
	printf("(1)\n");
	for(int i = 0; i < nodes; i++)
		free(graf[i]);
	free(graf);
	free(koszt);
	free(poprzedni);
	return 0;
}
