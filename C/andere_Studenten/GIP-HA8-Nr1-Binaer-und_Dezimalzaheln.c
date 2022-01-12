#include <stdio.h>

void dezimalInBinaer()
{
    unsigned long long int binaer, dezimal1;
    unsigned long long int decimalToBinary(unsigned long long int dezimal0);

    printf("\nGeben Sie Ihre Dezimalzahl ein: ");
    scanf("%llu", &dezimal1);

    if (dezimal1 < 0)
    {
        printf("\nUngueltige EIngabe");

        return;
    }

    binaer = decimalToBinary(dezimal1);

    printf("\n\nIhre Binaerzahl:\t%llu", binaer);
}

void binaerInDezimal()
{
    unsigned long long int dezimal, binaer1, binaerzahl(unsigned long long int);
    unsigned long long int binaryToDecimal(unsigned long long int binaer0);

    printf("\nGeben Sie ihre Binaerzahl ein: ");
    scanf("%llu", &binaer1);

    if (!binaerzahl(binaer1))
    {
        printf("\nUngueltige Eingabe");

        return;
    }

    dezimal = binaryToDecimal(binaer1);

    printf("\n\nIhre Dezimalzahl:\t%llu", dezimal);
}

int main()
{
    unsigned long long int eingabe;

    printf("\n\nGeben Sie 1 ein, wenn Sie eine Dezimalzahl in eine Binaerzahl umrechen wollen. \nGeben Sie 2 ein, wenn Sie eine Binaerzahl in eine Dezimalzahl umwandeln wollen. \nEingabe: ");
    scanf("%llu", &eingabe);

    switch (eingabe)
    {
    case 1:
        dezimalInBinaer();
        break;

    case 2:
        binaerInDezimal();
        break;

    default:
        printf("Ungueltige Eingabe");
    }

    return 0;
}

unsigned long long int binaerzahl(unsigned long long int binaer)
{
    if (binaer < 0)
    {
        return 0;
    }

    while (binaer > 0)
    {
        if (binaer % 10 != 0 && binaer % 10 != 1) //Überpfrüfung letzter Stelle
        {
            return 0;
        }

        binaer = binaer / 10;
    }

    return 1;
}

unsigned long long int decimalToBinary(unsigned long long int dezimal0)
{
    unsigned long long int binaer = 0, rest, faktor = 1;

    while (dezimal0 > 0)
    {
        rest = dezimal0 % 2;
        dezimal0 = dezimal0 / 2;
        binaer = binaer + rest * faktor;
        faktor = faktor * 10;
    }

    return binaer;
}

unsigned long long int binaryToDecimal(unsigned long long int binaer0)
{
    unsigned long long int dezimal = 0, rest, faktor = 1;
    while (binaer0 > 0)
    {
        rest = binaer0 % 10;
        binaer0 = binaer0 / 10;
        dezimal = dezimal + rest * faktor;
        faktor = faktor * 2;
    }

    return dezimal;
}