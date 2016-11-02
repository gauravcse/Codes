#include <iostream>
#include<cstdlib>
#define llu long long int
#define MAX 1000000007

using namespace std;

int cmpfnc (const void * a, const void * b) {
   return ( *(long long int*)a - *(long long int*)b );
}

int main(void) {
	int t;
	cin>>t;
	while(t--) {
		llu n,k;
		cin>>n>>k;
		llu parr[n+1],pcount = 0;
		llu narr[n+1],ncount = 0;
		for(int i = 0; i < n;i++) {
			llu num;
			cin>>num;
			if(num >= 0) {
				parr[pcount++] = num;
			}
			else {
				narr[ncount++] = num;
			}
		}
		qsort(narr,ncount,sizeof(llu),cmpfnc);
		qsort(parr,pcount,sizeof(llu),cmpfnc);
		llu pidx = 0,nidx = 0,prod = 1;
		if (k%2 == 0) {
			while(k > 0) {
				if(ncount % 2 == 0 && pcount % 2 == 0) {
					if(pidx >= pcount) {
						prod *= narr[nidx] * narr[nidx+1];
						nidx += 2;
						k -= 2;
					}
					else if (nidx >= ncount) {
						prod *= parr[pidx] * narr[pidx+1];
						pidx += 2;
						k -= 2;
					}
					else {
						llu ppr = 1,npr = 1;
						npr *= narr[nidx] * narr[nidx+1];
						ppr *= parr[pidx] * parr[pidx + 1];
						if (npr > ppr) {
							prod *= npr;
							nidx += 2;
							k -= 2;
						}
						else {
							prod *= ppr;
							pidx += 2;
							k -= 2;
						}
					}
					
				}
				else if(ncount % 2 != 0 && pcount % 2 != 0) {
					if(pidx + 1 == pcount ){
						
					}
				}
				/*if(pidx >= pcount) {
					prod *= narr[nidx] * narr[nidx+1];
					nidx += 2;
					k -= 2;
				}
				else if (nidx >= ncount) {
					prod *= parr[pidx] * narr[pidx+1];
					pidx += 2;
					k -= 2;
				}
				else {
					llu ppr = 1,npr = 1;
					npr *= narr[nidx] * narr[nidx+1];
					ppr
				}*/
			}
		}
	}
}
