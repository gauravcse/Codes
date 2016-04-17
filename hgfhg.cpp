#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	char c;int k,i;k=0;int n;char *s;
	scanf("%d",&n);
	s=(char*)malloc(n*sizeof(char));
	//while((c=getchar())!='\n')
	//{//
	//	s[k++]=c;
	//}
	c='\0';
	while(c!='\n'){
	
		scanf("%c", &c);
		s[k++]=c;
} 
	sleep(5);
    //char arr[100];
    //scanf("%[^\n]s",&arr);
    printf("%s",s);
	/*for(i=0;i<k;i++)
	printf("%c",s[i]);
	*/
	return 0;
}
