/***	IMPLEMENTATION OF THE STRING CLASS USING REFERENCE COUNT	***/
/***	DETAILED DOCUMENTATION IS IN THE FILE IN WHICH THE HEADER FILE IS IMPLEMENTED "raw.cpp"	***/

#ifndef MYSTRING1_H_INCLUDED
#define MYSTRING1_H_INCLUDED
#include<iostream>

class String {
	private :
		char *ch;
		int len;
		int ref;
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
		void del();
		//~String();
		int get_reference();
		void operator=(String&);
		void display();
		
		friend std::ostream &operator<<(std::ostream &os,const String s) {
			os<<s.ch<<std::endl;
		}
};

#endif

