#include<stdio.h>
int main(void) {
	int p[3][5]= {
					{ 2, 4, 6, 8, 10},
					{ 3, 6, 9, 12, 15},
					{ 5, 10, 15, 20, 25}
				};
	printf("%p %p %p %p %p",*p,(*p+1), (*(p+1)),(*(p+1)+1),(*(p+1)+1)+1);
}
