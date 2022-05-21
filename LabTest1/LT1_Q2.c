/*
Coder: Nishkal Prakash

Working Example 1:
	Enter X_0, Eplsilon, MaxIteration: 5 0.005 10

	Iteration       x_0             x_1             Error
	1               5.000000        3.666667        1.333333
	2               3.666667        3.064279        0.602388
	3               3.064279        2.930340        0.133939
	4               2.930340        2.924031        0.006309
	5               2.924031        2.924018        0.000014
	The square root is: 2.924018
*/

#include <stdio.h>
#include <math.h>

int main()
{
	double x0, ep, err, x1;
	int mi, i = 0;

	printf("\nEnter X_0, Eplsilon, MaxIteration: ");
	scanf("%lf %lf %d", &x0, &ep, &mi);
	printf("\n%-10s\t%-8s\t%-8s\t%-8s", "Iteration", "x_0", "x_1", "Error");
	do
	{
		x1 = x0 - (pow(x0, 3) - 25) / (3 * pow(x0, 2));
		err = fabs(x1 - x0);
		printf("\n%-10d\t%-8lf\t%-8lf\t%-8lf", i + 1, x0, x1, err);
		x0 = x1;
	} while (err > ep && ++i < mi);
	printf("\nThe square root is: %lf\n", x1);
}
