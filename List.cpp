#include<stdio.h>

int list[1000];
int top=-1;
int len=0;

int main(void) {
	
}

int isEmpty() {
	if(top==-1) {
		return 0;
	}
	return 1;
}
int listLen() {
	return len;
}

int Read(int n) {
	if(!isEmpty() && n>=top && n<(top+len)) {
		return list[n];
	}
	return -9999;
}

void insert(int n,int value) {
	if(n<=top || top==-1) {
		top=n;
	}
	for(int i=(len+top)-1;i>n;i--) {
		list[i+1]=list[i];
	}
	list[n]=value;
	len++;
}

void del(int n){
	if(n==top) {
		list[top]=-9999;
	}
	for(int i=n;i<(len+top);i++) {
		list[i]=list[i+1];
	}
	
}
