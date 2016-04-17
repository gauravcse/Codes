#include<stdio.h>
#include<string.h>
char* freqcheck(char*,char b[]);
int main() {
	printf("ENTER THE SENTENCE\n");
	char* sen;
	scanf("%[^\n]s",&sen);
	int len=strlen(sen);
	char temp[50];
	int j=0;
	for(int i=0;i<len;i++) {
		if((sen[i]!=' ')&&(sen[i]!='.'))
		  temp[j++]=sen[i];
		else {
			temp[j]='\0';
		    *sen=freqcheck(*sen,temp);
			j=0;
		}
	}
}
char* freqcheck(char* a,char b[]) {
	int freq=0;
	char temp[50];
	int j=0;
	for(int i=0;i<strlen(a);i++) {
		if((a[i]!=' ')&&(a[i]!='.'))
		  temp[j++]=a[i];
		else {
			temp[j]='\0';
			if(strcmp(temp,b)==0){
			  freq++;
			int k=i-j;
			while(k--)
			  a[k]=' ';
			j=0;
		}
    }
    printf("THE FREQUENCY OF THE WORD %s IS %d ",b,freq);
    printf("\n");
    return *a;

}
}

