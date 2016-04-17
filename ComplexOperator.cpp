/***
		Implementation of Complex Operation with Operator Overloading
***/

#include<iostream>
#include<stdlib.h>

using namespace std;

class complex {
	private:
		double real ;
		double imaginary ;
	public :
		
		/***
				Constructor
		***/
		
	    complex(int,int);
	    
	    /***
	    		Overloading of Binary + and - operators
	    ***/
	    
		complex operator+(complex);		
		complex operator-(complex);
		
		/*** 
				Overloading of << Cout opeartor
				
		***/
		
		friend ostream &operator<<(ostream &os,const complex c) {
			if(c.real==0 && c.imaginary!=0) {
				if(c.imaginary>0) {
					os<<c.imaginary<<" i"<<endl;	
				}
				else {
					os<<"-"<<abs(c.imaginary)<<" i"<<endl;
				}
			}
			else if(c.imaginary==0) {
				os<<c.real<<endl;
			}
			else {
				if(c.imaginary>0) {
					os<<c.real<<" + " <<c.imaginary<<" i"<<endl;	
				}
				else {
					os<<c.imaginary<<" - "<<abs(c.imaginary)<<" i"<<endl;
				}
			}
		}
	
};


complex::complex(int a,int b) {
	real=a;
	imaginary=b;
}

/***
   		Fuction Body For Overloading of Binary + operator
***/
	    
	
complex complex::operator+(complex a) {
		complex addition(0,0);
		addition.real=a.real+this->real;
		addition.imaginary=a.imaginary+this->imaginary;
		return addition;
}

/***
   		Fuction Body For Overloading of Binary - operator
***/
	
complex complex::operator-(complex a) {
	complex subtraction(0,0);
	subtraction.real=this->real-a.real;
	subtraction.imaginary=this->imaginary-a.imaginary;
	return subtraction;
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
	
	sum=obj1+obj2;
	dif=obj1-obj2;
	
	cout<<sum;
	cout<<dif;
	
}


