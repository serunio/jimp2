#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char** argv)
{
    srand(time(NULL));
    FILE* out = fopen("grafy/grafD.txt", "w");
    int rozmiar = argc > 1 ? atoi(argv[1]) : 5;
    char* graf = malloc((rozmiar+1) * sizeof(char));
    for(int i = 0; i<rozmiar; i++) {

        for(int j = 0; j<rozmiar; j++){
            graf[j] = '0';
        }
        graf[rozmiar] = '\0';
        int j = rand() % 2 + 2;
        for(; j>0; j--) {
            int indeks =  i == 0 ? rand()%(rozmiar-1) : rand()%rozmiar;
            if(indeks == i || graf[indeks] != '0')
            {
                j++;
                continue;
            }

            graf[indeks] = rand()%9 + 1 + '0';
        }
        fprintf(out, "%s\n", graf);
    }

    return 0;
}
