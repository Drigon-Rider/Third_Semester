#include <stdio.h>
#include <math.h>

int main() {
    int n;
    float a, b, A, sumx = 0, sumy = 0, sumx2 = 0, sumxy = 0;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n];

    printf("Enter the data points (x y):\n");
    for (int i = 0; i < n; i++) {
        printf("Data point %d: ", i + 1);
        scanf("%f %f", &x[i], &y[i]);
    }

    for (int i = 0; i < n; i++) {
        sumx += x[i];
        sumy += log(y[i]);
        sumx2 += x[i] * x[i];
        sumxy += x[i] * log(y[i]);
    }

    b = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx);
    A = (sumy - b * sumx) / n;
    a = exp(A);

    printf("Estimated coefficients: y=%fe^ %fx\n", a, b);

    return 0;
}
