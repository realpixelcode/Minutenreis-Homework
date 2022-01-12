#include <stdio.h>
#include <math.h>


int solve(double a, double b, double c, double *ergebnis1, double *ergebnis2)
{
    double d;
    d=pow(b,2)-4*a*c;
    
    if(d<0)
    {
        return 0;
    }
    
    if(d==0)
    {
        *ergebnis1=(-b)/(2*a);
        return 1;
    }
    
    if(d>0)
    {
        *ergebnis1=(-b+sqrt(d))/(2*a);
        *ergebnis2=(-b-sqrt(d))/(2*a);
        return 2;
    }
}


int main()
{
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double x1, x2;
    int anzahl = solve(a, b, c, &x1, &x2);
    if (!anzahl)
    printf("keine Loesung");
    else if (anzahl == 1)
    printf("eine Loesung x: %lf", x1);
    else if (anzahl > 1)
    printf("zwei Loesungen x1: %lf x2: %lf", x1, x2);

    return 0;
}
