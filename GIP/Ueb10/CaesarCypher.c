#include <stdio.h>
#include <stdlib.h>
char *decipher(char string[], int key);
char *encipher(char string[], int key);

int main()
{

    char string[] = "YLHOH NDPHQ DOOPDHKOLFK CX GHU XHEHUCHXJXQJ HLQHQ JURVVHQ IHKOHU\nJHPDFKW CX KDEHQ DOV VLH YRQ GHQ EDHXPHQ KHUXQWHUJHNRPPHQ ZDUHQ XQG\nHLQLJH VDJWHQ VFKRQ GLH EDHXPH VHLHQ HLQ KROCZHJ JHZHVHQ GLH RCHDQH\nKDHWWH PDQ QLHPDOV YHUODVVHQ GXHUIHQ";
    printf("%s\n", decipher(string, 3));
    return 0;
}

char *decipher(char string[], int key)
{
    int i = 0;
    int size = 1;
    char *decryptedString = malloc(size * sizeof(char));
    while (string[i] != 0)
    {
        size++;
        if (string[i] >= 65 && string[i] <= 90)
        {
            decryptedString[i] = (string[i] - 65 - key + 26) % 26 + 65; //+26 um negative Werte zu verhindern
        }
        else
        {
            decryptedString[i] = string[i]; //alle nicht großbuchstaben werden ersetzt
        }
        decryptedString = realloc(decryptedString, size * sizeof(char));
        i++;
    }
    decryptedString[i] = 0;
    return decryptedString;
}

char *encipher(char string[], int key)
{
    return decipher(string, -key);
}