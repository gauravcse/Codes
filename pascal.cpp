/***
		PROGRAM TO GENERATE PASCALS TRIANGLE AND CHECK THE nCr RELATION ON THE GENEFRATED PASCAL TRIANGLE
***/

#include<iostream>
#include<stdlib.h>
#include<iomanip>

using namespace std;

/***
		A CLASS WHICH HOLDS THE TWO DIMENSIONAL MATRIX CONTAINING THE PASCAL TRIANGLE AND OTHER NECESSARY
		MEMBER FUNCTIONS
***/

class Pascal {
	private :
		int **triangle;
		int row;
		int factorial(int);
	public : 
		Pascal(int);
		void generate_triangle();
		void display_triangle();
		void generate_combination(int,int);
};

/*** 
		A CONSTRUCTOR WHICH INITIALIZES PASCALS TRIANGLE WITH THE NUMBER OF ROWS GIVEN AS USER INPUT
***/

Pascal::Pascal(int row) {
	this->row=row+1;
	triangle=(int**)malloc((this->row+1)*sizeof(int));
	for(int i=0;i<=this->row;i++) {
		triangle[i]=new int[this->row];
	}
	
	for(int i=1;i<=this->row;i++) {
		for(int j=0;j<this->row;j++) {
			triangle[i][j]=0;
		}
	}
	triangle[1][0]=1;
	triangle[2][0]=triangle[2][1]=1;
}

/***
		ALGORITHM TO GENERATE THE TRIANGLE
		USES A RECURSIVE OR DYNAMIC PROGRAMMING APPROACH TO CALCULATE THE CORRESPONDING
		ELEMENTS OF THE PASCAL TRIANGLE USING THE OPTIMAL SUBSTRUCTURE THAT THE GIVEN 
		PROBLEM HAS
***/

void Pascal::generate_triangle() {
	for(int i=3;i<=this->row;i++) {
		triangle[i][0]=1;
		for(int j=1;j<i;j++) {
			triangle[i][j]=triangle[i-1][j]+triangle[i-1][j-1];
		}
	}
	
}

/***
		FUNCTION TO PRINT OR DISPLAY THE TRIANGLE.
		USES setw() FUNCTION OF THE IOMANIP C++ HEADER TO ALIGN THE ELEMENTS CORRECTLY
***/

void Pascal::display_triangle() {
	int n_spaces=this->row-1;
	for(int i=1;i<this->row;i++) {
		for(int j=0;j<n_spaces;j++)
			cout<<setw(3)<<' ';
			
		for(int j=0;j<i;j++) {
			cout<<setw(3)<<" "<<triangle[i][j]<<setw(3)<<" ";
		}
		cout<<endl;
		n_spaces--;
	}
}

/***
		TEST FUNCTION TO CHECK WHETHER THE GENERATED PASCAL TRIANGLE IS CORRECT.
		CHECKS WHETHER THE TRIANGLE FOLLOWS THE COMBINATORIAL RULE
		IF IT DOES OUR PASCAL TRIANGLE IS CORRECTLY GENERATED ELSE IT IS NOT
***/

void Pascal::generate_combination(int n,int r) {
	int numerator=factorial(n);
	int denominator=factorial(r)*factorial(n-r);
	int number=(numerator/denominator);
	cout<<"THE COMBINATION WANTED IS "<<n<<"C"<<r<<" : "<<number<<endl;
	if(number==triangle[n+1][r])
		cout<<"THE COMBIMATION AND THE PASCAL TRIANGLE VALUE AT ROW "<<(n+1)<<" AND COLUMN "<<(r+1)<< " MATCHES !!"<<endl;
	else
		cout<<"PROGRAM ERROR !! CHECK OUTPUT !!"<<endl;
}

/***
		HELPER FUNCTION  TO CALCULATE FACTORIAL
***/
int Pascal::factorial(int x) {
	if(x<2)
		return 1;
	else
		return (x*factorial(x-1));
}

/***
			MAIN METHOD CONTAINING THE MENU
***/

int main(void) {
	int n;
	cout<<"ENTER THE NUMBER OF ROWS OF PASCAL TRIANGLE : ";
	cin>>n; 
	Pascal pascal(n);
	pascal.generate_triangle();
	pascal.display_triangle();
	int r;
	cout<<"ENTER THE VALUE OF N and R : "<<endl; 
	cin>>n>>r;
	pascal.generate_combination(n,r);
}



