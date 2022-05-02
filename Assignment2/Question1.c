/*
* Programmer : Ayan Chaudhury
*/

#include<stdio.h>
#include<math.h>

int main()
{
  double z = 100.0;
  int iter = 0;
  double steps = 0.0;
  double z1;
  while ((iter <= 50) && (z != 0.0))
    {
      z1 = z;
      steps = sqrt (fabs (z));
      z = z - steps;
      iter++;
      if (z < 0)
        z = -z;
      if ((z != 0) && (z1 == z)){
          steps = steps - (1 / iter);
          z = z - steps*steps;
          if (z < 0)
            z = -z;
      }
      printf ("(%f,%d)   ", z, iter);
    }
  return 0;
}