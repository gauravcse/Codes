#include<iostream>
#include<cstring>
#include "mystring.h"


String::String() {
	ch=NULL;
	len=0;
}

String::String(char *str) {
	int l=strlen(str);
	std::cout<<l<<std::endl;
	ch=new char[l+1];
	strcpy(ch,str);
	std::cout<<ch<<std::endl;
	len=l;
}

String::String(String &s) {
	this->ch=new char[s.len];
	strcpy(this->ch,s.ch);
	this->len=s.len;
}

String& String::operator+(String &s) {
	int l=this->len+s.len;
	char *str=new char[l];
	strcpy(str,this->ch);
	strcat(str,s.ch);
	String mystring(str);
	return mystring;
}

bool String::operator<(String &s) {
	int val=compare(s);
	if(val<0)
		return true;
	else
		return false;
}

bool String::operator>(String &s) {
	int val=compare(s);
	if(val<0)
		return false;
	else
		return true;
}

bool String::operator==(String &s) {
	int val=compare(s);
	if(val==0)
		return true;
	else
		return false;
}
bool String::operator<=(String &s) {
	int val=compare(s);
	if(val<=0)
		return true;
	else
		return false;
}

void String::operator=(String &s) {
	this->ch=new char[s.len];
	this->len=s.len;
	strcpy(ch,s.ch);
}

String& String::operator=(char *str) {
/*	this->ch=new char[strlen(str)];
	this->len=strlen(str);
	strcpy(ch,str);*/
	String myString(str);
	return myString;
}
bool String::operator>=(String &s) {
	int val=compare(s);
	if(val>=0)
		return true;
	else
		return false;
}


int String::compare(String &s) {
	std::cout<<strcmp(this->ch,s.ch)<<std::endl;
	return (strcmp(this->ch,s.ch));
}

void String::display() {
	std::cout<<this->ch<<std::endl;
}
