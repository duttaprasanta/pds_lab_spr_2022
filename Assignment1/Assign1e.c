/*
*    Programmer : Prasanta Dutta
*/

#include<stdio.h> /* For Basic IO */

int main(int argc, char const *argv[])
{
    char type; double weight; double base_price,gst,total_price,rate,gst_price;
    printf("Enter type of wood : ");
    scanf(" %c",&type);
    printf("Enter weight of wood (in Kg): ");
    scanf("%lf",&weight);
    switch (type)
    {
        case 'n':
            rate = 1100;
            gst = 0.2;
            break;
        case 's':
            rate = 780;
            gst = 0.15;
            break;
        default:
            printf("Warning : Invalid type of wood\n");
            return 0;
    }    
    base_price = weight * rate;
    gst_price = base_price * gst;
    total_price = base_price + gst_price;
    puts("--------------------------------");
    printf("Base price = %.2lf\n",base_price);
    printf("GST = %.2lf\n",gst_price);
    printf("Total price = %.2lf\n",total_price);
    puts("--------------------------------");
    return 0;
}
