#include<stdio.h>
#include<math.h>
#include <stdlib.h>

float f(float x)
{
	return pow(x,3) - 25;
}

float derivative(float x) 
{
	return 3*pow(x,2);
}

void main()
{
    float x, epsilon, error, x_prev, error_abs;
    int max_iter, i=0;
    
    printf("\nEnter the value of x: ");
    scanf("%f", &x);
    
    printf("\nEnter the value of epsilon: ");
    scanf("%f", &epsilon);
    
    printf("\nEnter the value of maximun number of itrations: ");
    scanf("%d", &max_iter);
    
    printf("\nIteration  x_0  x_1  Error ");
    while(i <= max_iter) 
    {
		x_prev = x;
		
		x = x - f(x)/derivative(x);
		error = x - x_prev;
		if(error<0)
		  error_abs = -error;
		else
		  error_abs = error;  
		
		printf("\n%d    %f    %f    %f", i+1, x_prev, x, error_abs);
		if(error_abs < epsilon)
		  break;
		
		i++;
	}
	printf("\nThe square root is: %f\n", x);
}
