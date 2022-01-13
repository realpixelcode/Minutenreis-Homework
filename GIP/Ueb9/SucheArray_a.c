#include <stdio.h>
int *populateArray(int Array[], int ArrayLength);
int linearSearch(int gesuchteZahl, int Suchbereich[], int ArrayLength);
int binarySearch(int gesuchteZahl, int *suchbereich, int start, int ende);
int searchingBinary(int gesuchteZahl, int suchbereich[], int arrayLength);

int main()
{
    int Test[100];
    populateArray(Test, 100);
    int gesuchteZahl;
    printf("Geben sie eine Zahl ein, die Sie suchen; Array enthaelt alle ganzen Zahlen von 0 - 99 an selbigem Index\n");
    scanf("%d", &gesuchteZahl);
    printf("Die Zahl befindet sich an Index %d, linaer ermittelt\n", linearSearch(gesuchteZahl, Test, 100));
    printf("Die Zahl befindet sich an Index %d, binear ermittelt\n", binarySearch(gesuchteZahl, Test, 0, 99));
    return 0;
}

int *populateArray(int Array[], int ArrayLength)
{
    for (int i = 0; i <= ArrayLength - 1; i++)
    {
        Array[i] = i;
    }
    return Array;
}

int linearSearch(int gesuchteZahl, int suchbereich[], int arrayLength)
{
    for (int i = 0; i <= arrayLength - 1; i++)
    {
        if (gesuchteZahl == suchbereich[i])
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int gesuchteZahl, int *suchbereich, int start, int ende)
{
    int mitte = (start + ende) / 2; //"obere Mitte"
    if (ende < start)
    {
        return -1;
    }
    else if (gesuchteZahl == suchbereich[mitte])
    {
        return mitte;
    }
    else if (gesuchteZahl > suchbereich[mitte])
    {
        return binarySearch(gesuchteZahl, suchbereich, mitte + 1, ende);
    }
    else
    {
        return binarySearch(gesuchteZahl, suchbereich, start, mitte - 1);
    }
}
