#include <stdio.h>
int *populateArray(int Array[], int ArrayLength);
int linearSearch(int gesuchteZahl, int Suchbereich[], int ArrayLength);
int binarySearch(int gesuchteZahl, int Suchbereich[], int ArrayLength);
int searchingBinary(int gesuchteZahl, int suchbereich[], int arrayLength);

int main()
{
    int Test[100];
    populateArray(Test, 100);
    int gesuchteZahl;
    printf("Geben sie eine Zahl ein, die Sie suchen; Array enthaelt alle ganzen Zahlen von 0 - 99 an selbigem Index\n");
    scanf("%d", &gesuchteZahl);
    printf("Die Zahl befindet sich an Index %d, linaer ermittelt\n", linearSearch(gesuchteZahl, Test, 100));
    printf("Die Zahl befindet sich an Index %d, binear ermittelt\n", binarySearch(gesuchteZahl, Test, 100));
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
