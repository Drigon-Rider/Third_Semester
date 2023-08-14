#include <stdio.h>

float calculate(int x[], int y[], int a, int n, int z) {
    float upp = 1.0;
    float down = 1.0;
    int x0 = x[z];
    int y0 = y[z];
    for (int i = 0; i < n; i++) {
        if (i == z) {
            printf("Skip\n");
        } else {
            upp *= (a - x[i]);
            down *= (x0 - x[i]);
        }
    }
    upp *= y0;
    return upp / down;
}

int main() {
    int n, a;
    printf("Enter the number of data: ");
    scanf("%d", &n);
    printf("Enter the value of a: ");
    scanf("%d", &a);
    int z = 0;
    int x[n], y[n];
    printf("Array x:\n");
    for (int i = 0; i < n; i++) {
        printf("%d : ", i);
        scanf("%d", &x[i]);
    }
    printf("Array y:\n");
    for (int i = 0; i < n; i++) {
        printf("%d : ", i);
        scanf("%d", &y[i]);
    }
    float cal;
    float nm = 0.0; // Initialize nm to zero
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        cal = calculate(x, y, a, n, i);
        nm += cal;
    }
    printf("result: %f", nm);
    return 0;
}
