/***		IMPLEMENTATION  OF THE ARRAY HEADER			***/

#include<iostream>
#include"array.h"

/***		DEFAULT CONSTRUCTOR TO TAKE AN INTEGER AS SIZE AS THE PARAMETER AND THEN CREATE AN ARRAY
			OBJECT OF THAT SIZE AND THEN INITIALIZE THE ARRAY OBJECT TO ALL ZERO VALUES				***/
template<class T>
Array<T>::Array(int size) {
	this->size=size;
	/***		USES EXCEPTION HANDLING TO OVERCOME THE CASE OF WRONG USER INPUT		***/
	try {
		if(size<0) {
			throw -1;
		}
	}
	catch(int error) {
		std::cout<<"Negative Integer Exception"<<std::endl;
	}
	arr=new T[this->size+1];
	for(int i=0;i<this->size;i++)
		this->arr[i]=0;
}

/***		AN OVERLOADED CONSTRUCTOR THAT TAKES A C-STYLED ARRAY OF TYPE SPECIFIED BY THE TEMPLATE
			AS INPUT AND ALSO THE LENGTH OF THE ARRAY AND ASSIGNS IT TO THE OBJECT OF THE ARRAY CLASS		***/

template<class T>
Array<T>::Array(T *new_arr,int length) {
	this->size=length;
	arr=new T[this->size+1];
	for(int i=0;i<this->size;i++)
		arr[i]=0;
	for(int i=0;i<this->size;i++) {
		arr[i]=new_arr[i];
	}
}

/***		A COPY CONSTRUCTOR WHICH COPIES THE ELEMENTS OF ONE ARRAY OBJECT TO ANOTHER ARRAY OBJECT		***/

template<class T>
Array<T>::Array(Array &array) {
	this->size=array.size;
	arr=new T[this->size+1];
	for(int i=0;i<this->size;i++)
		arr[i]=array.arr[i];
}

/***	OVERLOADING THE + OPERATOR TO PERFORM ARRAY ADDITION.
		IN CASE OF ARRAY OBJECTS HAVNG UNEQUAL ELEMENTS THE REMAINING 
		ELEMENTS OF THE SMALLER ARRAY IS TAKEN TO BE ZERO AND ARRAY ADDITION IS PERFORMED LIKEWISE
***/

template<class T>
void Array<T>::operator+(Array &A) {
	if(this->size>=A.size) {
		T array[this->size];
		for(int i=0;i<A.size;i++)
			array[i]=A.arr[i]+this->arr[i];
		for(int i=A.size;i<this->size;i++)
			array[i]=this->arr[i];
		std::cout<<"ARRAY SUM IS : ";
		for(int i=0;i<this->size;i++) {
			std::cout<<array[i]<<"\t";
		}
		std::cout<<std::endl;
	}
	else {
		T array[A.size];
		for(int i=0;i<this->size;i++)
			array[i]=A.arr[i]+this->arr[i];
		for(int i=this->size;i<A.size;i++)
			array[i]=A.arr[i];
		std::cout<<"ARRAY SUM IS : ";
		for(int i=0;i<A.size;i++) {
			std::cout<<array[i]<<"\t";
		}
		std::cout<<std::endl;
	}
	
}
/***		OVERLOADING THE = OPERATOR TO HELP ASSIGNMENTS OF OBJECTS TO OTHER OBJECTS		***/
template<class T>
Array<T> Array<T>::operator=(Array &A) {
	this->size=A.size;
	this->arr=new T[this->size+1];
	for(int i=0;i<this->size;i++) {
		this->arr[i]=A.arr[i];
	}
	return *this;
}
/***	OVERLOADING THE BOX OPERATOR TO HELP US ACCESS THE ARRAY ELEMENTS AS NORMAL
		C-STYLED ARRAY ELEMENTS			***/
		
template<class T>
T Array<T>::operator[](int index) {
	try {
		if(index>=this->size)
			throw -1;
		return this->arr[index];
	}
	catch(int exception) {
		std::cout<<"Array Index Out of Bounds Exception"<<std::endl;
	}
}

/***		OVERLOADING THE * OPERATOR TO PERFORM THE ARRAY MULTIPLICATION WITH A CONSTANT OPERATION	***/

template<class T>
void Array<T>::operator*(int c)  {
	for(int i=0;i<this->size;i++)
		std::cout<<this->arr[i]*c<<"\t";
	std::cout<<std::endl;
}
/***		HELPER FUNCTION TO COMPUTE ARRAY LENGTH			***/

template<class T>
int Array<T>::length() {
	return this->size;
}

/***	OVERLOADING THE * OPERATOR FOR CONSTANT*ARRAY MULTIPLICATION
		THIS IS A FRIEND FUNCTION NOT A CLASS FUNCTION				***/
template<class Type>
void operator*(int c,Array<Type> array) {
	array*c;
}


