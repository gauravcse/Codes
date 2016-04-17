#include<stdio.h>
#include<math.h> 

int isPower(unsigned int num) {
	int boolean = (num & (num-1));
	if (boolean==0){
		return 1;
	}
	else 
	    return 0;
}

int main(void) {
	int t;
	scanf("%d",&t);
	while(t--){
		unsigned int a,b,ans=0;
		scanf("%d %d",&a,&b);
		if(a==b) {
			printf("%u\n",0);
			continue;
		}
		else if(a==1) {
			ans=log(b)/log(2);
			printf("%u\n",ans);
			continue;
		}
		else if(b==1) {
			while(a!=1) {
				if(a%2==0) {
					a=a/2;
					ans++;
				}
				else {
					a=(a-1)/2;
					ans++;
				}
			}
			printf("%u\n",ans);
			continue;
		}
		else if(b==(a-1)){
			printf("%u\n",2);
			continue;
		}
		else if(isPower(a)) {
			if(b>a) {
				if(a!=2) {
					ans=log(b)/log(a);
					printf("%u\n",ans);
				}
				else {
					ans=log(b)/log(2);
					printf("%u\n",--ans);
				}
				continue;
			}
			else {
				while(b!=a) {
					b=b*2;
					ans++;
				}
				printf("%u\n",ans);
				continue;
			}
		}
		else if(a%2==0) {
			a=a/2;
			ans++;
			while(a!=1 && !isPower(a)) {
				if(a%2==0) {
					a=a/2;
					ans++;
				}
				else {
					a=(a-1)/2;
					ans++;
				}
			}
			if(b>a) {
				if(a==1) {
					ans+=(int)(log(b)/log(2));
				}
				else if(a==2) {
					ans+=(int)(log(b)/log(2));
					ans--;
				}
				else {
					ans+=(int)(log(b)/log(a));
				}
				printf("%u\n",ans);
				continue;
			}
			else {
				while(b!=a) {
					b=b*2;
					ans++;
				}
				printf("%u\n",ans);
				continue;
			}
		}
		else {
			a=(a-1)/2;
			ans++;
			while(a!=1 && !isPower(a)) {
				if(a%2==0) {
					a=a/2;
					ans++;
				}
				else {
					a=(a-1)/2;
					ans++;
				}
			}
			if(b>a){
				if(a==1) {
					ans+=(int)(log(b)/log(2));
				}
				else if(a==2) {
					ans+=(int)(log(b)/log(2));
					ans--;
				}
				else {
					ans+=(int)(log(b)/log(a));
				}
				printf("%u\n",ans);
				continue;
			}
			else {
				while(b!=a) {
					b=b*2;
					ans++;
				}
				printf("%u\n",ans);
				continue;
			}
		}
	}
	return 0;
}
