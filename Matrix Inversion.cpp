#include<stdio.h>
#include<stdlib.h>

int main(void) {
	printf("Enter the order of the matrix : ");
	int order;
	scanf("%d",&order);
	float matrix[order][2*order];
	printf("Enter the Matrix Elements : \n");
	for(int i=0;i<order;i++) {
		for(int j=0;j<order;j++)
			scanf("%f",&matrix[i][j]);
	}
	for(int i=0;i<order;i++) {
		for(int j=order;j<2*order;j++)
			if(i==(j-order))
				matrix[i][j]=1;
			else
				matrix[i][j]=0;
	}
	for(int i=0;i<order;i++) {
		for(int j=0;j<2*order;j++)
			printf("%0.3f	",matrix[i][j]);
		printf("\n");
	}
	for(int i=0;i<order-1;i++) {
		for(int j=i;j<2*order;j++)
			matrix[i][j]/=matrix[i][i];
		for(int i=0;i<order;i++) {
			for(int j=0;j<2*order;j++)
				printf("%0.3f	",matrix[i][j]);
		printf("\n");
		}
		for(int j=i+1;j<order;j++) {
			float factor=matrix[j][i];
			for(int k=i;k<2*order;k++)
				matrix[j][k]-=(factor)*matrix[i][k];
		}
		printf("PASS : %d\n ",i);
		for(int i=0;i<order;i++) {
			for(int j=0;j<2*order;j++)
				printf("%0.3f	",matrix[i][j]);
		printf("\n");
		}
	}
	printf("Inverted Matrix is : \n");
	for(int i=0;i<order;i++) {
		for(int j=order;j<2*order;j++)
			printf("%0.3f	",matrix[i][j]);
		printf("\n");
	}
}
