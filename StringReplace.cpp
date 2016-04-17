#include<stdio.h>
#include<string.h>
int main() {
	char ch[1000];
	scanf("%[^\n]s",ch);
    int len=strlen(ch);
    printf("\nENTER THE WORD TO BE SEARCHED\n");
    char search[30];
    scanf("%s",&search);
    int slen=strlen(search);
    int count=0;
    printf("\nENTER THE WORD TO BE REPLACED\n");
    char replace[30];
    scanf("%s",&replace);
    for(;count<len;count++) {
    	if(ch[count]==search[0]) {
    		int flag=0;
    		int i2=0;
    		int backup=count;
    		while(i2<slen){
    			if(ch[count++]!=search[i2++])
    			   flag=1;
			}
			if(flag==0) {
				printf("%s ",replace);
			}
			else {
				count=backup;
				printf("%c",ch[count]);
			}
			  	
		}
		else
		  printf("%c",ch[count]);
    	
	}
}
