#include <stdio.h>
#include <math.h>

int main() {
    int n;
    float sumx = 0, sumy = 0, sumxy = 0, sumxsq = 0;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n];

    // Input the data points
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i]);
        
        // Calculate the required sums for linear regression
        sumx += x[i];
        sumy += y[i];
        sumxy += x[i] * y[i];
        sumxsq += x[i] * x[i];
    }

    // Calculate the coefficients of the linear regression equation (y = mx + b)
    float meanx = sumx / n;
    float meany = sumy / n;
    float m = (sumxy - n * meanx * meany) / (sumxsq - n * meanx * meanx);
    float b = meany - m * meanx;

    printf("Linear Regression Equation: y = %.2fx + %.2f\n", m, b);

    return 0;
}
