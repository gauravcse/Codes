#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void) {
	int t;
	scanf("%d",&t);
	while(t--) {
	    char mol[100];
	    scanf("%s",mol);
	    int len=strlen(mol);
	    int sum=0;
	    for(int i=0;i<len;i++){
	    	//int tempsum=0;
	    	if(mol[i]=='(')
	    	  sum+=computebraces(mol,i+1);
            ;
            if(mol[i]=='C'||mol[i]=='H'||mol[i]=='O')
              sum+=compute(mol,i);
		}
    }
}
int compute(int* mol,int i) {
	    int tempsum=0;
		if(mol[i]=='C')
			  if(mol[i+1]>=48)&&(mol[i+1]<=57)
			    tempsum=12*(int)(mol[i+1]);
			else if(mol[i]=='H')
			  if(mol[i+1]>=48)&&(mol[i+1]<=57)
			    tempsum=1*(int)(mol[i+1]);
			else if(mol[i]=='O')
			  if(mol[i+1]>=48)&&(mol[i+1]<=57)
			    tempsum=16*(int)(mol[i+1]);
		return tempsum;
}

