/***		IMPLEMENTATION OF THE HEADER FILE mystring.h	***/

#include<iostream>
#include<string.h>
#include "mystring.h"

using namespace std;

/***		DEFAULT CONSTRUCTOR FOR INITIALIZATION TO NULL		***/
String::String() {
	ch=NULL;
	len=0;
}

/***	OVERLOADED CONSTRUCTOR TO INITIALIZE IT TO C-STYLED STRING		***/
String::String(char *str) {
	int l=strlen(str);
	ch=new char[l+1];
	strcpy(ch,str);
	len=l;
}
/***	COPY CONSTRUCTOR TO ASSIGN ONE OBJECT TO ANOTHER		***/
String::String(String &s) {
	this->ch=new char[s.len];
	strcpy(this->ch,s.ch);
	this->len=s.len;
}
/***	OVERLOADING OF THE + OPERATOR TO FACILITATE STRING CONCATENATION	***/
String& String::operator+(String &s) {
	int l=this->len+s.len;
	char *str=new char[l];
	strcpy(str,this->ch);
	strcat(str,s.ch);
	String mystring(str);
	return mystring;
}
/***	OVERLOADING THE < OPERATOR TO WORK ON STRING OBJECTS BY NORMAL CHARACTER COMPARISON		***/
/***	ACCESSOR FUNCTION ONLY		***/
bool String::operator<(String &s) const {
	int val=compare(s);
	if(val<0)
		return true;
	else
		return false;
}

/***	OVERLOADING THE > OPERATOR TO WORK ON STRING OBJECTS BY NORMAL CHARACTER COMPARISON		***/
bool String::operator>(String &s) const {
	int val=compare(s);
	if(val<0)
		return false;
	else
		return true;
}

/***	OVERLOADING THE == OPERATOR TO WORK ON STRING OBJECTS BY NORMAL CHARACTER COMPARISON		***/
/***	ACCESSOR FUNCTION ONLY		***/
bool String::operator==(String &s) const {
	int val=compare(s);
	if(val==0)
		return true;
	else
		return false;
}

/***	OVERLOADING THE <= OPERATOR TO WORK ON STRING OBJECTS BY NORMAL CHARACTER COMPARISON		***/
/***	ACCESSOR FUNCTION ONLY		***/
bool String::operator<=(String &s) const{
	int val=compare(s);
	if(val<=0)
		return true;
	else
		return false;
}

/***	OVERLOADING THE = OPERATOR TO FACILITATE ASSIGNMENT OF STRING OBJECTS TO OBJECTS		***/
/***	ACCESSOR FUNCTION ONLY		***/
void String::operator=(String &s) {
	this->ch=new char[s.len];
	this->len=s.len;
	strcpy(ch,s.ch);
}

/***	OVERLOADING THE = OPERATOR TO FACILITATE ASSIGNMENT OF  CHAR POINTERS TO OBJECTS		***/
/***	ACCESSOR FUNCTION ONLY		***/
String& String::operator=(char *str) const{
	String myString(str);
	return myString;
}

/***	OVERLOADING THE < OPERATOR TO WORK ON STRING OBJECTS BY NORMAL CHARACTER COMPARISON		***/
/***	ACCESSOR FUNCTION ONLY		***/
bool String::operator>=(String &s) const{
	int val=compare(s);
	if(val>=0)
		return true;
	else
		return false;
}

/***	HELPER FUNCTION TO COMPARE STRING OBJECTS AND RETURN AN INTEGER VALUE		***/
int String::compare(String &s) const {
	std::cout<<strcmp(this->ch,s.ch)<<std::endl;
	return (strcmp(this->ch,s.ch));
}

/***	DISPLAYS THE STRING		***/
void String::display() {
	std::cout<<this->ch;
}

