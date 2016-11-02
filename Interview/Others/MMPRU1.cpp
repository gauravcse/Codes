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
		if(ncount == 0 || pcount == 0) {
			llu product = 1;
			if (ncount == 0) {
				qsort(parr,pcount,sizeof(llu),cmpfnc);
				for(int i = 0; i < k; i++) {
					product *= parr[i];
				}
			}
			else {
				qsort(narr,ncount,sizeof(llu),cmpfnc);
				if (k % 2 == 0) {
					for(int i = 0; i < k; i++) {
						product *= narr[i];
					}
				}
				else {
					for(int i = 0; i < k-1; i++) {
						product *= narr[i];
					}
					product *= narr[ncount-1];
				}
			}
			cout<<"ONE IS ZERO : ";
			if (product%MAX < 0) {
				cout<<(MAX + product%MAX)<<endl;
			}
			else {
				cout<<(product%MAX)<<endl;
			}
		}
		else {
			qsort(narr,ncount,sizeof(llu),cmpfnc);
			qsort(parr,pcount,sizeof(llu),cmpfnc);
			int pidx = 0, nidx = 0;
			llu product = 1;
			while(k >= 2) {
				llu pp = INT_MIN,np = INT_MIN;
				if(pidx +1 >= pcount || nidx + 1 >= ncount) {
					break;
				}
				if(pidx + 1 < pcount) {
					pp = parr[pidx] * parr[pidx + 1];
				}
				if(nidx + 1 < ncount) {
					np = narr[nidx] * narr[nidx + 1];
				}
				if(pp > np) {
					product *= pp;
					pcount += 2;
					k -= 2;
				}
				else {
					product *= np;
					ncount += 2;
					k -= 2;
				}
			}
			if(pidx + 1 > pcount) {
				while(k > 0) {
					product *= narr[nidx++];
					k--;
				}
			}
			else {
				while(k > 0) {
					product *= parr[pidx++];
					k--;
				}
			}
			
			if (product%MAX < 0) {
				cout<<(MAX + product%MAX)<<endl;
			}
			else {
				cout<<(product%MAX)<<endl;
			}
		}
	}
}
