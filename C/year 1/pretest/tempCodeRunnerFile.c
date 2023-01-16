#include <stdio.h>
#include <math.h>

int main()
{
    float w,h;
    scanf("%f",&w);
    scanf("%f",&h);
    printf("BMI: %.2f",w/pow((h/100),2));
}