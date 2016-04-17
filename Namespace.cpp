#include<iostream>
#include<stdio.h>

namespace myspace {
	void cout(int str) {
		printf("%d\n",str+10);
	}
}

using namespace myspace;

int main(void) {
	cout(5);
}
