#include<stdio.h>
#include<math.h>
#define e 0.0001
double f(double x){
    return x*x*x-2*x-5;
}
int main(){
    double a,b,c;
    printf("Enter initial guesses: ");
    scanf("%lf %lf",&a,&b);
    do{
        a=b;
        b=c;
        c=(a*f(b)-b*f(a))/(f(b)-f(a));
    }while(fabs(a-b)>e);
    printf("Root: %lf",c);
    return 0;
}