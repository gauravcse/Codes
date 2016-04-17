#include <stdio.h>
#include<math.h>
int main(void) {
  
     float x, n_x, fn, dfn;
     
     printf("Let us solve x**4 = 81" "\n\n");
     n_x = 10; 
     printf("%f\n", n_x); 
     do {
          x = n_x;
          fn = x*x*x*x - 5*x*x*x + 3*x*x +10;
          dfn = 4*x*x*x - 15*x*x + 6*x ;
          n_x = x - fn / dfn;
          printf("%f\n", n_x); 
     }  while ((x - n_x) >= 0.000001 || (x - n_x) <= -0.000001);
     
     printf("\nx = %f", n_x);

  return 0;
}
