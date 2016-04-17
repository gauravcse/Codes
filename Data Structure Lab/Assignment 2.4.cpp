#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

char *getString(char *str) {
	str=(char*)malloc(sizeof(char)*25);
	char ch;
	scanf("%c",&ch);
	int count=0;
	while(ch!='\n') {
		str[count++]=ch;
		scanf("%c",&ch);
	}
	str[count]='\0';
	return str;
}

int StringLen(char *str) {
	char ch=str[0];
	int count=0;
	while(ch!='\0') {
		count++;
		ch=str[count];
	}
	return  count;
}

int CompareTo(char *str1,char *str2) {
	int len1=StringLen(str1);
	int len2=StringLen(str2);
	int min=(len1>=len2)?len2:len1;
	int count=0;
	while(count<min) {
		if(str1[count]==str2[count]) {
			count++;
			continue;
		}
		else if(str1[count]>str2[count]) {
			return 1;
		}
		else {
			return -1;
		}
	}
}

char *Concatenate(char *str1,char *str2,char *concat) {
	int count,i;
	count=i=0;
	while(str1[i]!='\0') {
		concat[count++]=str1[i++];
	}
	i=0;
	while(str2[i]!='\0') {
		concat[count++]=str2[i++];
	}
	concat[count]='\0';
	return concat;
}

int SubSearch(char *str,char *sub) {
	int len=StringLen(str);
	int lens=StringLen(sub);
	if(lens>len)
	    return -1;
	else if (lens==len) {
		if(CompareTo(str,sub)==0) {
			return 1;
		}
		else 
		    return -1;
	}
	else {
		int i;
		for(i=0;i<len;i++) {
			int pos=0,count=i;
			while(sub[pos]==str[count] && pos<lens && count<len){
				pos++;
				count++;
			}
			if(pos==lens)
				return i;
		}
		return -1;
	}
}

char *CopyStr(char *str,char *copy) {
	int len=StringLen(str);
	copy=(char*)malloc(sizeof(char)*len);
	int count=0;
	while(count<len) {
		copy[count]=str[count];
		count++;
	}
	return copy;
}

void frequency(char *str) {
	int len=StringLen(str);
	int count=0,i=0;
	for(;i<len;i++) {
		if(str[i]=='\0') {
			continue;
		}
		else {
			int occurence=1;
			for(int j=i+1;j<=len;j++) {
				if(str[j]==str[i]) {
					occurence++;
					str[j]='\0';
				}
			}
			printf("The letter %c occurs %d times\n",str[i],occurence);
			str[i]='\0';
		}
	}
}

void UpperCase(char *str) {
	int len=StringLen(str);
	int count=0;
	char *upper;
	upper=(char*)malloc(sizeof(char)*len);
	while(count<len) {
		char ch=str[count];
		if(ch>=97 && ch<=122) {
			upper[count++]=char(ch-32);
		}
		else
			upper[count++]=ch;
	}
	upper[count]='\0';
	printf("Uppercase of %s is %s\n",str,upper);
}

void LowerCase(char *str) {
	int len=StringLen(str);
	int count=0;
	char *upper;
	upper=(char*)malloc(sizeof(char)*len);
	while(count<len) {
		char ch=str[count];
		if(ch>=65 && ch<=90) {
			upper[count++]=char(ch+32);
		}
		else
			upper[count++]=ch;
	}
	upper[count]='\0';
	printf("LowerCase of %s is %s\n",str,upper);
}

void Toggle(char *str) {
	int len=StringLen(str);
	int count=0;
	char *upper;
	upper=(char*)malloc(sizeof(char)*len);
	while(count<len) {
		char ch=str[count];
		if(ch>=97 && ch<=122) {
			upper[count++]=char(ch-32);
		}
		else if(ch>=65 && ch<=90)
			upper[count++]=char(ch+32);
		else
			upper[count++]=ch;
	}
	upper[count]='\0';
	printf("Toggled form of %s is %s\n",str,upper);
}

char *Replace(char *str,char old,char nw) {
	int len=StringLen(str);
	int count=0;
	while(count<len) {
		char ch=str[count];
		if(ch==old) {
			str[count]=nw;
		}
		count++;
	}
	return str;
}

int WordCount(char *str) {
	int len=StringLen(str);
	int count=0;
	for(int i=0;i<len;i++) {
		if(str[i]==' ' && ((str[i+1]>='a' && str[i+1]<='z')||(str[i+1]>='A' && str[i+1]<='Z')))
			count++;
		if(str[i+1]=='.')
			break;
	}
	return ++count;
}
int main(void) {
	char *str1,*str2;
	str1=getString(str1);
	str2=getString(str2);
	
	//Length of the String
	int len1=StringLen(str1);
	int len2=StringLen(str2);
	printf("The Length of the strings are : %d  and   %d\n",len1,len2);
	
	//Compare the Two Strings and Return 1 if str1 is lexicographically higher or -1 if the opposite is
	//the case else returns 0 for equality
	int compare=CompareTo(str1,str2);
	printf("The result of comaprison of the Strings are : %d\n",compare);
	
	//Concatenate Two Strings
	char *concat;
	concat=(char*)malloc(sizeof(char)*(len1+len2));
	concat=Concatenate(str1,str2,concat);
	printf("The concatenated String is %s \n",concat);
	
	//Copy a String to another
	char *copy;
	copy=CopyStr(str1,copy);
	printf("The Copied String is %s and the String after Copying is %s\n",str1,copy);
	
	//Search for a Substring in A string
	printf("Enter the Substring :  ");
	char *sub;
	sub=getString(sub);
	int position=SubSearch(concat,sub);
	if(position==-1) {
		printf("Substring is Absent\n");
	}
	else {
		printf("Substring is present at Location : %d\n",position+1);
	} 
	
	//Frequency of Letters in A string
	frequency(concat);
	
	concat=Concatenate(str1,str2,concat);
	
	//Case Converter
	UpperCase(concat);
	LowerCase(concat);
	Toggle(concat); 
	
	//Replace a letter with another letter
	char *replaced;
	replaced=(char*)malloc(sizeof(char)*50);
	char o,n;
	printf("Enter the letter to be Replaced is and letter with which it is to be Replaced ");
	scanf("%c %c",&o,&n);
	replaced=Replace(concat,o,n);
	printf("The string after replacement is : %s\n",replaced);
	
	// Count Words in the String
	int words=0;
	words=WordCount(concat);
	printf(" Number of Words are : %d\n",words);
	
	//Reverse The String 
	Reverse(concat);
	
}
