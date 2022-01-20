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
    while (string[i] != '\0')
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] = (string[i] - 'A' - key + 26) % 26 + 'A'; //-A | +A => modulo nur aufs alphabet anwenden, 0 = A, 25 = Z
        }
        i++;
    }
    return string;
}

char *encipher(char string[], int key)
{
    return decipher(string, -key);
}