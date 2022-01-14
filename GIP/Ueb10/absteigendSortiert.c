#include <stdio.h>
int absteigend(long long n, int highestNumberThusFar);

int main()
{
    long long number;
    printf("Geben Sie ihre Zahl zum testen ein\n");
    scanf("%lld", &number);
    if (number < 0)
    {
        printf("Ungueltige Eingabe\n");
        return 0;
    }
    if (absteigend(number, 0))
    {
        printf("%lld ist absteigend sortiert\n", number);
    }
    else
    {
        printf("%lld ist NICHT absteigend sortiert\n", number);
    }
    return 0;
}

int absteigend(long long n, int highestNumberThusFar)
{
    if (n > 0)
    {
        if (n % 10 > highestNumberThusFar)
        {
            highestNumberThusFar = n % 10;
            return absteigend(n / 10, highestNumberThusFar);
        }
        else if (n % 10 == highestNumberThusFar)
        {
            return absteigend(n / 10, highestNumberThusFar);
        }
        else
        {
            return 0;
        }
    }
    return 1;
}