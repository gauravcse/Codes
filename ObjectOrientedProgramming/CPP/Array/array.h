/***		HEADER FILE FOR THE ARRAY CLASS USING TEMPLATE		***/
/***		DOCUMENTATION IS PROVIDED IN THE DEFINITION FILE "array.cpp"	***/

#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

template<class T>
class Array {
	template<class Type>
	friend void operator*(int,Array<Type>&);
	
	private :
		T *arr;
		int size;
	public :
		Array(int);
		Array(T*,int);
		Array(Array&);
		void operator+(Array &);
		Array operator=(Array&);
		T operator[](int);
		void operator*(int);
		int length();
		
};

#endif
