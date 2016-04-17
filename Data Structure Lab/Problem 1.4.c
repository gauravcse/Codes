#include<stdio.h>
#include<time.h>
main(){
	int i,flag[30000];
	long long num;
	FILE *fp;
	for(i=0;i<30000;i++)
		flag[i]=0;
	fp=fopen("list4.txt","w+");
	srand(time(NULL));
	i=1;
	while(i<=30000){
		num=rand()%30000;
		num++;
		if(flag[num-1]==0){
			fprintf(fp,"%lld\n",num);
			i++;
			flag[num-1]=1;
		}
	}
	fclose(fp);
	return 0;
}
