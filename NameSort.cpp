#include<stdio.h>
#include<string.h>
int main() {
	char arr[100][50];
	int number;
	printf("NUMBER OF ELEMENTS\n");
	scanf("%d",&number);
	printf("\n");
	for(int i=0;i<number;i++){
		printf("\nENTER THE NAME AT THE %dth POSITION ",i+1);
		scanf("%s",arr[i]);
	}
	for(int i=2;i<=number;i++){
		char pivot[50];
		strcpy(pivot,arr[i]);
		int j=i;
		while((strcmp(arr[j-1],pivot)>0)) {
			strcpy(arr[j],arr[j-1]);
			j--;
		}
		strcpy(arr[j],pivot);
    }
    printf("\nTHE SORTED ARRAY OF NAMES IS \n");
    for(int i=0;i<=number;i++)
        printf(" %s ",arr[i]);
}
