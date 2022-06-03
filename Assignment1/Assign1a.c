/*
*    Programmer : Prasanta Dutta
*/

#include<stdio.h> /* For Basic IO */
#include<math.h> /* For fabs */

int main(int argc, char const *argv[])
{
    int a;
    double u,alpha,time;
    printf("Enter the values of a, u, alpha & time (space seperated) : ");
    scanf("%i %lf %lf %lf",&a,&u,&alpha, &time);
    /* Here we are actually calculating the distance in 1d. Hence 
    * dist = abs(final_x_coordinate - origin's x coordinate)
    * = abs(final_x_coordinate)
    * = abs(a + u*time + 0.5 * time *time * alpha)
    */
    double dist = fabs(a + u*time + 0.5 * time * time * alpha);
    printf("Distance from origin : %lf\n",dist);
    return 0;
}
