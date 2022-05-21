/*
Coder: Nishkal Prakash

Working Example 1:
   Input: Monthly salary = 85000, house loan = 0, life insurance premium = 130000, medical insurance = 40000
   Output: Total tax: 52500.00
Working Example 2:
   Input: Monthly salary = 130000, house loan = 275000, life insurance premium = 95000, medical insurance = 0
   Output: Total tax: 118000.00

*/

#include <stdio.h>

int main()
{
   double ms, hl, li, mi, yi, tax = 0;
   int exp = 100000;
   printf("\nEnter Monthly Salary, House Loan, Life Insurance premium, Medical Insurance: ");
   scanf("%lf %lf %lf %lf", &ms, &hl, &li, &mi);

   yi = (ms * 12) / exp;

   if (yi >= 10)
   {
      yi -= (hl > 250000) ? 2.5 : hl / exp;
      yi -= (li > 150000) ? 1.5 : li / exp;
      yi -= (mi > 50000) ? .5 : mi / exp;
   }

   if (yi > 15)
      tax = 1.875 + 0.3 * (yi - 15);
   else if (yi > 12.5)
      tax = 1.25 + 0.25 * (yi - 12.5);
   else if (yi > 10)
      tax = 0.75 + 0.2 * (yi - 10);
   else if (yi > 7.5)
      tax = 0.375 + 0.15 * (yi - 7.5);
   else if (yi > 5)
      tax = 0.125 + 0.1 * (yi - 5);
   else if (yi > 2.5)
      tax = 0.05 * yi;
   printf("\nTotal tax: %.2lf \n", tax * exp);
}