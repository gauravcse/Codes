#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int len(int x);
int max(int x,int y);
int karatsuba(int x,int y,int xlen,int ylen);
int karatsuba(int x,int y,int xlen,int ylen) {
	int n=max(xlen,ylen);
	if(n==1)
	  return x*y;
	int xr=x%(int)(pow(10,((xlen)/2)));
	int yr=y%(int)(pow(10,((ylen)/2)));
	int xl=x/(int)((pow(10,(int)(xlen-xlen/2))));
	int yl=y/(int)((pow(10,(int)(ylen-ylen/2))));
	int P1=karatsuba(xl,yr,len(xl),len(yr));
	int P2=karatsuba(xr,yl,len(xr),len(yl));
	int P3=karatsuba((xl+yr),(yl+xr),len(xl+yr),len(yl+xr));
	return (P1*pow(10,n)+(P3-P1-P2)*pow(10,(n/2)),P2);
	
}
int max(int x,int y) {
	int maxi= (x>=y)?x:y;
	return maxi;
}
int len(int x) {
	int length;
	while(x>0) {
		length++;
		x=x/10;
	}
}
int main(void) {
	int a,b;
	int lena,lenb;
	scanf("%d %d",&a,&b);
	lena=len(a);
	lenb=len(b);
	int mul=karatsuba(a,b,lena,lenb);
	
}
