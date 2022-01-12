#include <stdio.h>
#include <math.h>
int solve(double a, double b, double c, double *x1, double *x2);


int main() {
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

int solve(double a, double b, double c, double *x1, double *x2){
    double p = b / a;
    double q = c / a;
    *x1 = -(p/2) + sqrt((p/2 * p/2) - q);
    *x2 = -(p/2) - sqrt((p/2 * p/2) - q);
    if (!*x1 && !*x2){
        return 0;
    }
    else if ((!*x1) || (!*x2)) {
        return 1;
    }
    else{
        return 2;
    }
}

