#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX 100

int find_digits(int number, int *count)
{
   int digits[MAX], i=0, j, remainder, sum=0;
   while(number)
   {
      digits[i] = number%10;
      i++;
      number = number/10;
   }
   
   *count = i;
   
   for(j=0; j< i; j++)
   {
       sum += digits[j];
   }
   return sum;
}

void main()
{
   srand(time(0));
   int number_a, number_b, remainder, digits_a[MAX], digits_b[MAX], no_of_rounds, i, no_of_digits_a = 0, no_of_digits_b = 0, j, point_a=0, point_b=0, badge_a=0, badge_b=0, sum_a=0, sum_b=0, badge_a_temp, badge_b_temp, final_score_a, final_score_b, char_select;
   char alphabet[2] = { 'a', 'b'};   
   
   printf("\nNumber of rounds: ");
   scanf("%d", &no_of_rounds);
   
   for(i=0; i<no_of_rounds; i++)
   {
      
      printf("\nRound %d ---> ", i+1);
      number_a = (rand() % (1000 - 5 + 1)) + 5;
      printf("A's number: %d", number_a);
      sum_a = find_digits(number_a, &no_of_digits_a);
      
      number_b = (rand() % (1000 - 5 + 1)) + 5;
      sum_b = find_digits(number_b, &no_of_digits_b); 
      printf("   B's number: %d", number_b);
      
      if(no_of_digits_a > no_of_digits_b)
      {
         point_a += no_of_digits_a;
         point_b += no_of_digits_b;
         badge_a += 1;
         badge_a_temp = 1;
         badge_b_temp = 0;
          
         printf("\nA's point: %d", no_of_digits_a);
         printf(" B's point: %d", no_of_digits_b);
         printf("\nA's badge: %d", badge_a_temp);
         printf(" B's badge: %d", badge_b_temp);
         printf("\n-- A wins Round %d --\n\n", i+1);
      } 
      
      else if(no_of_digits_a < no_of_digits_b)
      {
         point_a += no_of_digits_a;
         point_b += no_of_digits_b;
         badge_b += 1; 
         
         badge_a_temp = 0;
         badge_b_temp = 1;
         
         printf("\nA's point: %d", no_of_digits_a);
         printf(" B's point: %d", no_of_digits_b);
         printf("\nA's badge: %d", badge_a_temp);
         printf(" B's badge: %d", badge_b_temp);
         printf("\n-- B wins Round %d --\n\n", i+1);
      }
      else 
      {
         if(sum_a > sum_b)
         {
            point_a += sum_a;
            point_b += sum_b;
            badge_a += 1;
            badge_a_temp = 1;
            badge_b_temp = 0;
         } 
         
         else if(sum_a < sum_b)   
         //else    
         {
            point_a += sum_a;
            point_b += sum_b;
            badge_b += 1;
            badge_a_temp = 0;
            badge_b_temp = 1;
         }
         
         else
         {
            char_select = alphabet[rand() % 2];
            //printf("%c", char_select);
            
            if(char_select=='a')
            {
               point_a += sum_a;
               point_b += sum_b;
               badge_a += 1;
               badge_b += 0;
               badge_a_temp = 1;
               badge_b_temp = 0;
            }
            else
            {
               point_a += sum_a;
               point_b += sum_b;
               badge_a += 0;
               badge_b += 1;
               badge_a_temp = 0;
               badge_b_temp = 1;
            }
         }
         
         printf("\nA's point: %d", sum_a);
         printf(" B's point: %d", sum_b);
         printf("\nA's badge: %d", badge_a_temp);
         printf(" B's badge: %d", badge_b_temp);
         
         if(badge_a_temp > badge_b_temp)
            printf("\n-- A wins Round %d --\n\n", i+1);
            
         else if(badge_a_temp < badge_b_temp)
            printf("\n-- B wins Round %d --\n\n", i+1);  
            
         else
            printf("\n-- Both win Round %d --\n\n", i+1);    
           
      }
   }
   
   final_score_a = point_a*badge_a;
   final_score_b = point_b*badge_b;
   printf("\nA's total score: %d, B's total score: %d", final_score_a, final_score_b);
      
   if(final_score_a > final_score_b)
      printf("\n--- A wins the game ---\n");
      
   else
      printf("\n--- B wins the game ---\n");   
}
