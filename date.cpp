#include<stdio.h>
#include<stdlib.h>
struct date {
	int day;
	int month;
	long year;
} ;
int main() {
	struct date date1,date2;
    scanf("%d",&date1.day);
    scanf("%d",&date2.day);
    scanf("%d",&date1.month);
    scanf("%d",&date2.month);
    scanf("%d",&date1.year);
    scanf("%d",&date2.year);
    scanf("%d %d %l",&date2.day,&date2.month,&date2.year);
    printf("\n");
    if((date1.day==date2.day))
        printf("EQUAL DATES");
    else
         printf("UNEQUAL DATES");
    printf("\n");
    if(date1.month==date2.month)
        printf("EQUAL DATES");
    else
         printf("UNEQUAL DATES");
     printf("\n");
    if(date1.year==date2.year)
        printf("EQUAL DATES");
}
