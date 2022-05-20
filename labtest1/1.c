/*Example:
Input: Monthly salary = 85000, house loan = 0, life insurance premium = 130000, medical insurance = 40000
Output: Total tax: 165000
Example:
Input: Monthly salary = 130000, house loan = 275000, life insurance premium = 95000, medical insurance = 0
Output: Total tax: 318000*/

#include<stdio.h>

void main()

{
   float salary_month, house_loan, life_in, med_in, income_year, taxable_amount=0, total_tax;
      
   printf("\nEnter monthly salary, house loan, life insurance premium, medical insurance: ");
   scanf("%f %f %f %f", &salary_month, &house_loan, &life_in, &med_in);
   
   income_year = salary_month*12;
   //printf("\nYearly income: %f\n", income_year);
   
   if(income_year >= 1000000)
   {
       if(house_loan>=0 && house_loan<=250000)
          taxable_amount = income_year - house_loan;
       else 
          taxable_amount = income_year - 250000;   
        
       if(life_in>=0 && life_in<=150000) 
          taxable_amount = taxable_amount - life_in;
       else 
          taxable_amount = taxable_amount - 150000;   
          
       if(med_in>=0 && med_in<=50000)    
          taxable_amount = taxable_amount - med_in;
       else 
          taxable_amount = taxable_amount - 50000;   
       
       //printf("\nTaxable amount: %f\n", taxable_amount);
          
       if(taxable_amount >= 0 && taxable_amount <= 250000)
          total_tax = 0;
                       
       else if(taxable_amount>=250001 && taxable_amount<=500000)
          total_tax = 0.05*taxable_amount; 
          
       else if(taxable_amount>=500001 && taxable_amount<=750000) 
          total_tax = 12500 + 0.1*taxable_amount;   
          
       else if(taxable_amount>=750001 && taxable_amount<=1000000)
          total_tax = 37500 + 0.15*taxable_amount;
                   
       else if(taxable_amount>=1000001 && taxable_amount<=1250000) 
          total_tax = 75000 + 0.2*taxable_amount; 
          
       else if(taxable_amount>=1250001 && taxable_amount<=1500000)  
          total_tax = 125000 + 0.25*taxable_amount;   
          
       else
          total_tax = 187500 + 0.30*taxable_amount;  
   }
   
   else
   {
       if(house_loan>=0 && house_loan<=250000) 
          total_tax = 0; 
          
       else if(taxable_amount>=250001 && taxable_amount<=500000)
          total_tax = 0.05; 
          
       else if(taxable_amount>=500001 && taxable_amount<=750000)
          total_tax = 12500 + 0.1*taxable_amount;   
          
       else if(taxable_amount>=750001 && taxable_amount<=1000000) 
          total_tax = 37500 + 0.15*taxable_amount;
          
       else if(taxable_amount>=1000001 && taxable_amount<=1250000)
          total_tax = 75000 + 0.2*taxable_amount;
          
       else if(taxable_amount>=1250001 && taxable_amount<=1500000)
          total_tax = 125000 + 0.25*taxable_amount;   
          
       else
          total_tax = 187500 + 0.30*taxable_amount;    
   }  
   
   printf("\nTotal tax: %.2f \n", total_tax);     
}

