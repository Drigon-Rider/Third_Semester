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

    while (fabs(b - a) > tolerance) {
        c = (a + b) / 2;

        if (f(c) == 0.0) {
            printf("Exact root found: %lf\n", c);
            return 0;
        } else if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    printf("Approximate root: %lf\n", (a + b) / 2);

    return 0;
}
