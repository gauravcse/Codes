#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
int *getarray(int);
void fill(int, int, int, int*);
void arrayprint(int, int*);
void insertion_sort(int, int*);
void lin_search(int, int, int*);
int main(void) {
     int *a; int n; 
     int r; int random; 
     int d;
     scanf("%d", &n); a = getarray(n);
     scanf("%d", &random); // Randomizer
     scanf("%d", &r); // Elements are 0 - r
     fill(random, r, n, a);
     arrayprint(n, a);
     insertion_sort(n, a);
     arrayprint(n, a);
     scanf("%d", &d); // Looking for d
     lin_search(d, n, a);
     return 0;
}
int *getarray(int m) {
      int *a;
      return a = malloc(m * sizeof(int));
}
void fill(int shk, int rng, int m, int *array) {
        float x;
        srand(shk);
        for (int i = 1; i <= m - 1; i = 1 + i) {
             x = rand(); // Convert to float first
             array[i] = rng * x / RAND_MAX;       
        }
}
void arrayprint(int m, int *array) {
        for (int i = 1; i <= m - 1; i = 1 + i) 
        printf("a[%d] = %d\n", i, array[i]);
}
void insertion_sort(int m, int *array) {
         int t, k;
         array[0] = INT_MIN;
         for (int i = 2; i <= m - 1; i = 1 + i) {
               t = array[i]; k = i - 1;
               while (t < array[k]) {
                   array[k+1] = array[k]; k = k -1;
                }
                array[k + 1] = t;
          }
}
void lin_search(int dt, int m, int *array) {
      int k;
      array[0] = dt; 
      k = m - 1;
      while (dt != array[k]) k = k - 1;
      if (k) 
          printf("%d is at %dth place", dt, k);
      else printf("DATA NOT FOUND");
}