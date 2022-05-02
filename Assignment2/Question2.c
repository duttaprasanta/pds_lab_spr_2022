/*
* Programmer : Prasanta Dutta
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int n; int k;
    printf("Enter the number of steps (n) : ");
    scanf("%d", &n);
    printf("Enter the number of iterations (k) : ");
    scanf("%d", &k);
    int D = 0;
    for (int i = 1; i <= k; i++) {
        int x = 0;
        for (int j = 0; j < n; j++) {
            x += rand() & 1 ? -1 : 1;
        }
        D += abs(x) * abs(x);
    }
    printf("D_E = %lf\n", sqrt(D/k));
    return 0;
}
