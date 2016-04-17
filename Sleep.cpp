#include <stdio.h>
#include <windows.h>
#include<unistd.h>

int main(){
char letter;
printf("Enter in a character:");
scanf("%c", &letter);
unsigned int k=sleep(5);
printf("%d",k);
printf("Letter was: %c", letter);
return 0;
}
