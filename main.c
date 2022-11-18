#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
//start of code
int main() {
    //variables
    float a, b, increment, coefficient, expo, sum;
    int val, val2, poly, avg;
    //values for variables
    printf("a: ");
    scanf("%f", & a);
    printf("b: ");
    scanf("%f", & b);
    printf("increment: ");
    scanf("%f", & increment);
    printf("maximum degree of function: ");
    scanf("%d", & poly);
    int k = poly;
    int j = poly;
    //coefficient array setup
    float coarray[poly];
    //while loop to find all coefficient vals
    while (poly >= 0) {
        printf("Coeffecient for degree %d: ", poly);
        scanf("%f", & coefficient);
        coarray[poly] = coefficient;
        poly--;
    }
    int e = coarray[0];
    //string creation
    char riemannType[10];
    char midpointType[] = "midpoint";
    char leanType[] = "right";
    printf("Riemann sum (midpoint/right/left):");
    scanf("%s", & riemannType);
    //values to allocate for array
    int iterations = ((b - a) / increment);
    int z = (iterations * k);
    val = strcmp(midpointType, riemannType);
    val2 = strcmp(leanType, riemannType);
    //y-value array setup
    float yval[z];
    //riemann sum calculation
    if (val == 0) {
        float eval = a + (.5 * increment);
        while (eval <= b) {
            //y-value at each eval
            while (k >= 0) {
                expo = pow(eval, k);
                yval[z] = coarray[k] * expo;
                if (k == 0) {
                    yval[z] = e;
                }
                sum += yval[z];
                k--;
                z--;
            }
            eval = eval + increment;
            k = j;
        }
    } else if (val2 == 0) {
        float eval = a + increment;
        while (eval <= (b + (increment / 2))) {
            //y-value at each eval
            while (k >= 0) {
                expo = pow(eval, k);
                yval[z] = coarray[k] * expo;
                if (k == 0) {
                    yval[z] = e;
                }
                sum += yval[z];
                k--;
                z--;
            }
            eval = eval + increment;
            k = j;
        }
    } else {
        float eval = a;
        while (eval <= b) {
            //y-value at each eval
            while (k >= 0) {
                expo = pow(eval, k);
                yval[z] = coarray[k] * expo;
                if (k == 0) {
                    yval[z] = e;
                }
                sum += yval[z];
                k--;
                z--;
            }
            eval = eval + increment;
            k = j;
        }
    }
    printf("Integral: %f \n", (sum * increment));
    int ticks = clock();
    printf("Time taken to execute: %f \n", (float)ticks / CLOCKS_PER_SEC);
    return 0;
}