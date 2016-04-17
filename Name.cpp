#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
	char name[100][25];
	char temp[25];
	int l;
	scanf("%d",&l);
	printf("\n");
	for(int i=0;i<l;i++) {
		scanf("%s",name[i]);
		printf("\n");
	}
	for(int i=2;i<=l;i++) {
		int j=i-1;
		strcpy(temp,name[i]);
		while((j>=0)&&(strcmp(temp,name[j])>0)) {
		     strcpy(name[j],name[j-1]);
		     j--;
	    }
	    strcpy(name[j+1],temp)	;
	}
	for(int i=0;i<l;i++) {
	printf("\n%s",name[i]);
	}
}
