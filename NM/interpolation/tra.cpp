#include <stdio.h>
#include <math.h>

// Function to integrate: 1 / (1 + x^2)
double function(double x) {
    return 1.0 / (1.0 + x * x);
}

// Trapezoidal Rule function
double trapezoidal_rule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (function(a) + function(b));

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += function(x);
    }

    return h * sum;
}

int main() {
    double a = 0.0, b = 1.0;
    int n;

    printf("Enter the number of subintervals : ");
    scanf("%d", &n);
    double result = trapezoidal_rule(a, b, n);
    printf("Approximate integral: %lf\n", result);

    return 0;
}
