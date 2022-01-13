#include <stdio.h>
int *populateArray(int Array[], int ArrayLength);
int linearSearch(int gesuchteZahl, int Suchbereich[], int ArrayLength);
int binarySearch(int gesuchteZahl, int Suchbereich[], int ArrayLength);
int searchingBinary(int gesuchteZahl, int suchbereich[], int arrayLength);
int implementieren();

int main()
{
    int gesuchteZahl;
    printf("Geben sie eine Zahl ein, diese wird in einem Array aller Primzahlen bis 100 gesucht, bei Erfolg wird ihre position ausgegeben\n");
    scanf("%d", &gesuchteZahl);
    int result = implementieren(gesuchteZahl);
    if (result != 0)
    {
        printf("Ihre gesuchte Zahl ist die %d. Primzahl.", result);
    }
    return 0;
}

int implementieren(int gesuchteZahl)
{
    int primzahlen[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    return binarySearch(gesuchteZahl, primzahlen, 25) + 1; // Position = x. Primzahl
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

int binarySearch(int gesuchteZahl, int suchbereich[], int arrayLength)
{
    int gefundenenePosition = searchingBinary(gesuchteZahl, suchbereich, arrayLength);
    if (suchbereich[gefundenenePosition] == gesuchteZahl)
    {
        return gefundenenePosition;
    }
    else
    {
        return -1;
    }
}

int searchingBinary(int gesuchteZahl, int suchbereich[], int arrayLength)
{
    int mitte = arrayLength / 2; //"obere Mitte"
    int remainingLength;

    if (arrayLength <= 1)
    {
        return 0;
    }
    else if (gesuchteZahl == suchbereich[mitte])
    {
        return mitte;
    }
    else if (gesuchteZahl > suchbereich[mitte])
    {
        if (arrayLength % 2 == 0)
        {
            remainingLength = arrayLength / 2 - 1;
        }
        else
        {
            remainingLength = arrayLength / 2;
        }
        return mitte + 1 + searchingBinary(gesuchteZahl, &suchbereich[mitte + 1], remainingLength);
    }
    else
    {
        remainingLength = arrayLength / 2;
        return searchingBinary(gesuchteZahl, suchbereich, remainingLength);
    }
}
