/*
*    Programmer : Prasanta Dutta
*/

#include<stdio.h> /* For Basic IO */

int main(int argc, char const *argv[])
{
    int num;
    printf("Enter a 3 digit integer : ");
    scanf("%i",&num);
    int lst_dig = num % 10;
    int mid_dig = num / 10 % 10;
    int fst_dig = num / 100;
    printf("The reversed number is : %i%i%i\n",lst_dig,mid_dig,fst_dig);
    return 0;
}
