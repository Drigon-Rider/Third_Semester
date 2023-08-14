#include <stdio.h>
#include <math.h>

double f(double x) {
    return x*x - 2*x - 5;
}

int main() {
    double a, b, c, tolerance;

    while (1) {
        printf("Enter interval [a, b]: ");
        scanf("%lf %lf", &a, &b);

        if (f(a) * f(b) > 0) {
            printf("Error: Please enter a different interval.\n");
        } else {
            break;
        }
    }

    printf("Enter tolerance: ");
    scanf("%lf", &tolerance);

    printf("\n\n=================================================\n");
    printf("Itr \t a \t\t b \t\t c \n");
    printf("=================================================\n");

    int iteration = 1;
    while (fabs(b - a) > tolerance) {
        c = (a + b) / 2;

        printf("%d \t %lf \t %lf \t %lf \n", iteration, a, b, c);

        if (f(c) == 0.0) {
            printf("\nExact root found: %lf\n", c);
            return 0;
        } else if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }

        iteration++;
    }

    printf("\nApproximate root: %lf\n", (a + b) / 2);

    return 0;
}
