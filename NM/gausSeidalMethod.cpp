#include <stdio.h>
#include <math.h>

float f1(float x, float y, float z) {
    return (17 - y + 2 * z) / 20;
}

float f2(float x, float y, float z) {
    return (-18 - 3 * x + z) / 20;
}

float f3(float x, float y, float z) {
    return (25 - 2 * x + 3 * y) / 20;
}

int main() {
    float x = 0, y = 0, z = 0; // Initial guesses or starting values for x, y, and z
    float xNew, yNew, zNew; // Temporary variables to store updated values
    
    int maxIterations = 100;
    float tolerance = 0.001;

    printf("Iteration\t   x\t\t   y\t\t   z\n");
    printf("----------------------------------------------\n");

    for (int i = 0; i < maxIterations; i++) {
        xNew = f1(x, y, z);
        yNew = f2(xNew, y, z);
        zNew = f3(xNew, yNew, z);
        
        printf("%5d\t%10.6f\t%10.6f\t%10.6f\n", i + 1, xNew, yNew, zNew);
        
        // Check for convergence
        float diffX = fabs(xNew - x);
        float diffY = fabs(yNew - y);
        float diffZ = fabs(zNew - z);
        
        if (diffX < tolerance && diffY < tolerance && diffZ < tolerance) {
            printf("\nConverged after %d iterations.\n", i + 1);
            printf("x = %f, y = %f, z = %f\n", xNew, yNew, zNew);
            break;
        }
        
        x = xNew;
        y = yNew;
        z = zNew;
    }

    return 0;
}
