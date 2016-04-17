//UNCLOMPETED 
#include<stdio.h>
#include<stdlib.h>
void create_string(char*);
int str_len(char*);
int str_cmp(char*, char*);
void str_cat(char*, char*, char*);
void str_cpy(char*, char*);
void search(char*, char*);
void convert_case(char*);
main(){
	char str1[100],str2[100],str[200];
	create_string(str1);
	create_string(str2);
	search(str2,str1);
	convert_case(str1);
	printf("%s\n",str1);
	return 0;
}
void create_string(char *str){
	printf("Enter the string: ");
	scanf("%[^\n]%*c",str);
}
int str_len(char *str){
	int n=0;
	while(str[n]!='\0')
		n++;
	return n;
}
int str_cmp(char *str1, char *str2){
	int n=0;
	while(str1[n]==str2[n] && str1[n]!='\0' && str2[n]!='\0')
		n++;
	if(str1[n]=='\0' && str2[n]=='\0')
		return 0;
	else if((int)str1[n]>(int)str2[n])
		return 1;
	else
		return -1;
}
void str_cat(char *str, char *str1, char *str2){
	int n=0,i=0;
	while(str1[i]!='\0')
		str[n++]=str1[i++];
	i=0;
	while(str2[i]!='\0')
		str[n++]=str2[i++];
	str[n]='\0';
}
void str_cpy(char *str2, char *str1){  //Copying from str1 to str2
	int n=0;
	while(str1[n]!='\0'){
		str2[n]=str1[n];
		n++;
	}
	str2[n]='\0';
}
void search(char *wrd, char *str){
	int i=0,j=0,pos,flag=0;
	while(str[i]){
		pos=i;
		while(wrd[j] && wrd[j]==str[i++])
			j++;
		if(!wrd[j])
			flag=printf("Word Found at position %d\n",pos+1);
		j=0; i++;
	}
	if(!flag)
		printf("Word not Found\n");
}
void convert_case(char *str){
	int choice;
	printf("\t1. to Lower Case\n\t2. to Upper Case\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			while(*str){
				if(*str>='A' && *str<='Z')
					*str=*str-'A'+'a';
				str++;
			}
		case 2:
			while(*str){
				if(*str>='a' && *str<='z')
					*str=*str+'A'-'a';
				str++;
			}
	}
}











