#include <stdio.h>
#include <math.h>

double f(double x) {
    return x*x - 2*x - 5;
}

double f_prime(double x) {
    return 2*x - 2;
}

int main() {
    double x0, x1, tolerance;

    printf("Enter initial guess x0: ");
    scanf("%lf", &x0);

    printf("Enter tolerance: ");
    scanf("%lf", &tolerance);

    printf("\n\n=================================================\n");
    printf("Itr \t x0 \t\t f(x0) \t\t f'(x0) \t x1 \n");
    printf("=================================================\n");

    int iteration = 1;
    do {
        double fx0 = f(x0);
        double fx0_prime = f_prime(x0);

        x1 = x0 - fx0 / fx0_prime;

        printf("%d \t %.6lf \t %.6lf \t %.6lf \t %.6lf\n", iteration, x0, fx0, fx0_prime, x1);

        x0 = x1;
        iteration++;
    } while (fabs(f(x1)) > tolerance);

    printf("\nApproximate root: %.6lf\n", x1);

    return 0;
}
