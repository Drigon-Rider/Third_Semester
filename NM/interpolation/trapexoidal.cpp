#include <stdio.h>
#include <math.h>

float f(float x) {
    return 1 / (1 + x * x);
}

int main() {
    int n;
    float a, b, h, sum = 0, sum1 = 0, I;

    printf("Enter lower and higher limit: ");
    scanf("%f %f", &a, &b);

    printf("Number of subintervals: ");
    scanf("%d", &n);

    h = (b - a) / n;

    sum = f(a) + f(b); // Add the first and last terms

    for (int i = 1; i < n; i++) {
        float x = a + i * h;
        sum1 += f(x);
    }

    I = h * (sum + 2 * sum1) / 2; // Calculate the final result using the trapezoidal rule

    printf("Numerical Integration result: %f\n", I);

    return 0;
}
