/*
Coder:

Working Example 1:
   Enter 10 x-coordinates: 8 2 11 6 5 4 12 9 6 1

   Enter 10 y-coordinates: 3 10 3 6 8 12 1 4 9 14

   m = -1.1, b = 14.1, line equation is: y = -1.1x + 14.1

*/

#include <stdio.h>

int main()
{
   float x[10], y[10], x_, y_, m, b, sum_x = 0, sum_y = 0, avg_x, avg_y, slope, numerator = 0, denominator = 0, y_intercept;
   int i;

   printf("\nEnter 10 x-coordinates: ");
   for (i = 0; i <= 9; i++)
   {
      scanf("%f", &x[i]);
      sum_x += x[i];
   }
   printf("\nEnter 10 y-coordinates: ");
   for (i = 0; i <= 9; i++)
   {
      scanf("%f", &y[i]);
      sum_y += y[i];
   }
   avg_x = sum_x / 10;
   avg_y = sum_y / 10;

   for (i = 0; i <= 9; i++)
   {
      numerator += (x[i] - avg_x) * (y[i] - avg_y);
      denominator += (x[i] - avg_x) * (x[i] - avg_x);
   }

   slope = numerator / denominator;
   y_intercept = avg_y - slope * avg_x;

   printf("\nm = %.1f, b = %.1f, line equation is: y = %.1fx + %.1f\n", slope, y_intercept, slope, y_intercept);
}
