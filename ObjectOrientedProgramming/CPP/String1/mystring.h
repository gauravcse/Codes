/***		HEADER FILE FOR STRING IMPLEMENTATION IN C++	***/
/***		DETAILED DOCUMENTATION PROVIDED IN THE DEFINTION FILE "strings.cpp"	***/

#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED
#include<iostream>

class String {
	private :
		char *ch;
		int len;
		int compare(String&) const;
		
	public :
		String();
		String(char*);
		String(String&);
		String& operator+(String&) ;
		bool operator<(String&) const;
		bool operator>(String&) const;
		bool operator<=(String&) const;
		bool operator>=(String&) const;
		void operator=(String&) const;
		bool operator==(String&) const;
		String& operator=(char *ch) const;
		void operator=(String&);
		void display();
		
		friend std::ostream &operator<<(std::ostream &os,const String s) {
			os<<s.ch<<std::endl;
		}
};

#endif

