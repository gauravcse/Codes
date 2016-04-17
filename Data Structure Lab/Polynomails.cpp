#include<stdio.h>
#include<stdlib.h>
int* fillpoly(int n,int poly[]);
int main(void) {
	printf("Enter the degree of the first polynomial \n");
	int n;
	scanf("%d",&n);
	int *poly1;
	poly1=fillpoly(n,poly1);
	int i;
	for(i=0;i<n;i++) {
    printf("%d ",poly1[i]);
    }  
	printf("Enter the degree of the second polynomial \n");
	scanf("%d",&n);
	int *poly2;
	poly2=fillpoly(n,poly2);
	for(i=0;i<n;i++) {
    printf("%d ",poly2[i]);
    }
}

int *fillpoly(int n,int poly[]) {
	//char arr[(4*n+4)];
//	int poly[n];
	char ch;
	scanf("%c",&ch);
	while(ch!='\n') {
		if(ch>='0' && ch<='9') {
			char coeff=ch-48;
			ch=getchar();
			if(ch=='x') {
				scanf("%c",&ch);
				if(ch=='^') {
					scanf("%c",&ch);
					if(ch>='0' && ch<='9') {
						poly[ch-48]=coeff;
						continue;
				    }
			    }
		    }
	    	else {
		    	poly[0]=coeff;
			    break;
		    }
    	}
		ch=getchar();      
    }
    return poly;
}

