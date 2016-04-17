#include<iostream>
#include<bitset>
#include<list>

using namespace std;

int main(void) {
	bitset <100007> sieve;
	list <int> prime;
	sieve.reset();
	sieve.flip();
	sieve.set(0,false);
	sieve.set(1,false);
	for(int i=2;i<100000;i++) {
		if(sieve.test((size_t)i)) {
			for(int j=i*i;j<100000;j+=i)
				sieve.set((size_t)j,false);
			prime.push_back((int)i);
		}
	}
	
	list<int>::const_iterator iter;
	for(iter=prime.begin();iter!=prime.end();++iter)
		cout<<*iter<<"	";
}
