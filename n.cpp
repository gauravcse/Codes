#include<stdio.h>
#include<math.h> 

int main() {
	long long unsigned num;
	scanf("%d",&num);
	printf("%d",((num & (num-1)) == 0));
}

