#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverseWord(char **str) {
	int l = strlen(*str);
	for(int i = 0; i < (l/2); i++) {
		char temp = (*str)[l - i - 1];
		(*str)[l - i - 1] = (*str)[i];
		(*str)[i] = temp;
	}
}

char* reverse(char *inp) {
	
	char *word = (char*)malloc(sizeof(char)*50);
	char *out = (char*)malloc(sizeof(char)*strlen(inp));
	int count = 0;
	for(int i = 0; i < strlen(inp); i++) {
		if((inp[i] >= 65 && inp[i] <= 90) || (inp[i] >= 97 && inp[i] <= 122)) {
			word[count++] = inp[i];
		}
		else {
			word[count] = '\0';
			count = 0;
			reverseWord(&word);
			strcat(out,word);
			int r = strlen(out);
			out[r] = inp[i];
			out[r + 1] = '\0';
			//strcat(out,(char*)inp[i]);
		}
	}
	return out; 
}

int main(void) {
	char *str ;//= (char*)malloc(sizeof(char)*200);
	str = "this IS Gaurav,   ,,,,    Mitra AND- You are? who?";
	//scanf("%[^\n]s",str);
	printf("%s",str);
	char *out = reverse(str);
	printf("%s\n",out);
	
}
