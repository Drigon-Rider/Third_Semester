#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define e 0.0001

float g(float x) {
    return pow(2*x + 5, 1.0/3.0);
}

float f(float x) {
    return x*x*x - 2*x - 5;
}
float dg(float x)
{

    return 2*(pow(2*x+5,(-2/3)))/3;//-0.66667
}

int main() {
    float a, b;

    do {
        printf("Enter initial condition = ");
        scanf("%f%f", &a, &b);
    } while (f(a) * f(b) > 0);

    int i = 1;

    if (dg((a+b)/2)< 1) {
        do {
            b = a;
            a = g(b);
            printf("Iteration %d: %.6f\n", i, a);
            i++;
        } while (fabs(a - b) > e);
    }

    printf("The root = %.6f", a);

    return 0;
}
