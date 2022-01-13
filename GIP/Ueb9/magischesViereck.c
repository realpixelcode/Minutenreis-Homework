#include <stdio.h>
#include <stdlib.h>

int **initialize2DArray(int seitenlaenge);
int **magicSquare(int seitenlaenge);
void printQuadrat(int **quadrat, int seitenlaenge);
int rechteSpalte(int spalte, int seitenlaenge);
int linkeSpalte(int spalte, int seitenlaenge);
int untereZeile(int zeile, int seitenlaenge);
void freeSquare(int **quadrat, int seitenlaenge);

int main()
{
    int seitenlaenge;
    printf("Geben Sie eine ungerade Seitenlaenge fuer ihr gewuenschtes magisches Quadrat an.\n");
    scanf("%d", &seitenlaenge);
    if (seitenlaenge < 1 || seitenlaenge % 2 != 1)
    {
        printf("Ungueltige Eingabe.\n");
        return 1;
    }
    printQuadrat(magicSquare(seitenlaenge), seitenlaenge);
    return 0;
}

int **initialize2DArray(int seitenlaenge)
{
    int **quadrat = calloc(seitenlaenge, sizeof(int *));
    for (int i = 0; i < seitenlaenge; i++)
    {
        quadrat[i] = (int *)calloc(seitenlaenge, sizeof(int));
    }
    return quadrat;
}

void printQuadrat(int **quadrat, int seitenlaenge)
{
    for (int zeile = 0; zeile < seitenlaenge; zeile++)
    {
        for (int spalte = 0; spalte < seitenlaenge; spalte++)
        {
            printf("%d\t", quadrat[spalte][zeile]);
        }
        printf("\n");
    }
    freeSquare(quadrat, seitenlaenge);
}

void freeSquare(int **quadrat, int seitenlaenge)
{
    for (int i = 0; i < seitenlaenge; i++)
    {
        free(quadrat[i]);
    }
    free(quadrat);
}

int **magicSquare(int seitenlaenge)
{
    int **quadrat = initialize2DArray(seitenlaenge);
    int i = 1;
    int spalte = seitenlaenge / 2;
    int zeile = (zeile + 1) % seitenlaenge;
    quadrat[spalte][zeile] = i;
    i++;
    while (i <= seitenlaenge * seitenlaenge)
    {
        spalte = (spalte + 1) % seitenlaenge;
        zeile = (zeile + 1) % seitenlaenge;
        if (quadrat[spalte][zeile] == 0)
        {
            quadrat[spalte][zeile] = i;
            i++;
        }
        else
        {
            while (quadrat[spalte][zeile] != 0)
            {
                spalte = (spalte + seitenlaenge - 1) % seitenlaenge; //+seitenlaenge um -1 % seitenlaenge = -1 zu entgehen
                zeile = (zeile + 1) % seitenlaenge;
            }
            quadrat[spalte][zeile] = i;
            i++;
        }
    }
    return quadrat;
}