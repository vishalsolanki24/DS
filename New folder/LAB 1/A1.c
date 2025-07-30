#include <stdio.h>


void main() {
    float radius, area;
int PI=3.14;
  
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    
    area = PI * radius * radius;

    printf("Area of the circle = %.2f\n", area);

 
}
