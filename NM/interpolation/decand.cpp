#include <stdio.h>
#include <math.h>

#define e 0.0001

float f(float x) {
    return x*x*x - 2*x - 5;
}

int main() {
    float x0, x1, x2;

    printf("Enter initial guesses x0 and x1: ");
    scanf("%f%f", &x0, &x1);

    printf("\n\n=================================================\n");
    printf("Itr \t x0 \t\t x1 \t\t x2 \t\t f(x2) \n");
    printf("=================================================\n");

    int i = 1;

    do {
        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));

        printf("%d \t %.6f \t %.6f \t %.6f \t %.6f\n", i, x0, x1, x2, f(x2));

        x0 = x1;
        x1 = x2;
        i++;
    } while (fabs(x2 - x1) > e);

    printf("\nApproximate root: %.6f\n", x2);

    return 0;
}
