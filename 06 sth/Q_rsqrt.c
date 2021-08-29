#include <stdio.h>
#include <math.h>


float Q_rsqrt( float number )
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *(long *)&y;                // evil floating point bit hack
    i = 0x5f3759df - (i >> 1);      // what the fuck?
    y = *(float *)&i;
    y = y * (threehalfs - (x2 * y * y));        // 1st iteration
//  y = y * (threehalfs - (x2 * y * y));        // 2nd iteration, can be removed

    return y;
}



int main ( int argc, char * argv[])
{
    printf("%f,%f\n", Q_rsqrt(2), Q_rsqrt(4));
    printf("%f,%f\n", 1/sqrt(2), 1/sqrt(4));

    return 1;
}