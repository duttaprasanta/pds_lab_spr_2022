/*
*    Programmer : Prasanta Dutta
*/

#include<stdio.h> /* For Basic IO */
#include<math.h> /* For round */

int main(int argc, char const *argv[])
{
    int n, m, k, dayNumber;
    double f;
    printf("Enter the number of machines : ");
    scanf("%i",&m);
    printf("Enter day number (1-7) : ");
    scanf("%i",&dayNumber);
    if(dayNumber == 3 || dayNumber == 6){
        printf("Enter the number of machines under inspection : ");
        scanf("%i",&k);
    }
    else if(dayNumber == 4 || dayNumber == 5 || dayNumber == 7){
        printf("Enter boosting factor : ");
        scanf("%lf",&f);
    }
    switch (dayNumber)
    {
        case 1:
            n = m;
            break;
        case 2:
            n = round(m + (double)m/2 + (double)m/4);
            break;
        case 3:
            n = round(m-k + (double)(m-k)/2 + (double)(m-k)/4);
            break;
        case 4:
            n = round(m + f * m);
            break;
        case 5:
            n = round(m + f * m);
            break;
        case 6:
            n = round(m-k + (double)(m-k)/2 + (double)(m-k)/4);
            break;
        case 7:
            n = round(m + f * m);
            break;
        default:
            printf("Warning : Invalid day number\n");
            return 0;
    }
    printf("Number of manufactured cars : %i\n",n);
    return 0;
}
