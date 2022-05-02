/*
* Programmer : Ayan Chaudhury
*/

#include<stdio.h>
int main()
{
    int cost = 9999999;
    int final[4];
    int currentComb[4];
    int isDistinct;
    int a[4] = {82,83,69,92};
    int b[4] = {77,37,49,92};
    int c[4] = {11,69,5,86};
    int d[4] = {8,9,98,23};
    int i, j, k, l;
    for (i=0 ; i<4 ; i++){
        for (j=0 ; j<4 ; j++){
            for (k=0 ; k<4 ; k++){
                for (l=0 ; l<4 ; l++){
                    currentComb [0] = i;
                    currentComb [1] = j;
                    currentComb [2] = k;
                    currentComb [3] = l;
                    isDistinct = 1;
                    for (int p=0 ; p<4 ; p++){
                        int q;
                        for (q=0 ; q<p ; q++){
                            if (currentComb[p] == currentComb[q])
                                isDistinct = 0;
                        }
                    }
                    if(isDistinct == 1){
                        int currentCost = a[i]+b[j]+c[k]+d[l];
                        if(currentCost < cost){
                            cost = currentCost;
                            final[0] = i;
                            final[1] = j;
                            final[2] = k;
                            final[3] = l;
                        }
                    }
                }
            }
        }
    }
    printf("%d, %d, %d, %d, %d\n", cost, final[0],final[1], final[2], final[3]);

    return 0;
}