#include <math.h>
#include <stdio.h>
int main() {
    /*
    this program will find the roots of a quadratic equation in C
    Atention: it will not calculate them if the discriminant or DELTA
    is less than zero, because the roots in that case are complex
    numbers
    [they are not real numbers]
    */
    double a, b, c, DELTA, root1, root2;
    printf("Enter coefficients a, b and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    DELTA = b * b - 4 * a * c;

    /*
    DELTA > 0, 2 different real roots
    */
    if(a == 0){
        printf("This is not a quadratic equation! \n");
    }
    else{
    if (DELTA > 0) {
        root1 = (-b + sqrt(DELTA)) / (2 * a);
        root2 = (-b - sqrt(DELTA)) / (2 * a);
        printf("root1 = %.2lf and root2 = %.2lf", root1, root2);
    }

    /*
    DELTA - 0, just one real root
    */
    else if (DELTA == 0) {
        root1 = root2 = -b / (2 * a);
        printf("root1 = root2 = %.2lf;", root1);
    }

    /*
    DELTA is less than zero, so the roots will not be found here
    */
    else {   
        printf("DELTA is less than zero, so the roots are complex numbers, try other coefficients \n");
    }
}

    return 0;
} 
