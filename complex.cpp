#include<iostream>
#include<stdlib.h>

using namespace std;

class complex {
	private:
		double real ;
		double imaginary ;
	public :
	        complex(int,int);
		void output();
		void add(complex,complex);
		void subtract(complex,complex);
};


	complex::complex(int a,int b) {
		real=a;
		imaginary=b;
	}
	
	void complex::output() {
		if(this->real==0 && this->imaginary!=0) {
			if(this->imaginary>0) {
				cout<<this->imaginary<<" i"<<endl;	
			}
			else {
				cout<<"-"<<abs(this->imaginary)<<" i"<<endl;
			}
		}
		else if(this->imaginary==0) {
			cout<<this->real<<endl;
		}
		else {
			if(this->imaginary>0) {
				cout<<this->real<<" + " <<this->imaginary<<" i"<<endl;	
			}
			else {
				cout<<this->imaginary<<" - "<<abs(this->imaginary)<<" i"<<endl;
			}
		}
	}
	
	void complex::add(complex a,complex b) {
		complex addition(0,0);
		addition.real=a.real+b.real;
		addition.imaginary=a.imaginary+b.imaginary;
		this->real=addition.real;
		this->imaginary=addition.imaginary;
	}
	
	void complex::subtract(complex a,complex b) {
		complex subtraction(0,0);
		subtraction.real=a.real-b.real;
		subtraction.imaginary=a.imaginary-b.imaginary;
		this->real=subtraction.real;
		this->imaginary=subtraction.imaginary;
	}



int main(void) {
	cout<<"Enter the First Complex Number : "<<endl;
	float a,b;
	cin>>a>>b;
	cout<<"Enter the Second Complex Number : "<<endl;
	float c,d;
	cin>>c>>d;
	
	complex obj1(a,b);
	complex obj2(c,d);
	complex sum(0,0);
	complex dif(0,0);
	
	sum.add(obj1,obj2);
	dif.subtract(obj1,obj2);
	
	sum.output();
	dif.output();
	
}


