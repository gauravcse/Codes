/****		MAIN FUNCTION TO CHECK THE STRING IMPLEMENTATION		***/

#include<iostream>
#include "strings.cpp"

using namespace std;

int main(void) {

	cout<<"------------------------------------------|"<<endl;
	cout<<"WELCOME TO THE STRING CLASS IMPLEMENTATION |"<<endl;
	cout<<"------------------------------------------|"<<endl<<endl;
	bool flag=true;
	OUTER:while(flag) {
		cout<<"--------------------------------------------------------------------------------"<<endl;
		cout<<"1.  FOR CREATING AN STRING AND  INITIALING IT WITH NULL "<<endl;
		cout<<"2.  FOR CREATING A STRING OBJECT AND INITIALIZING IT WITH A C STYLED STRING"<<endl;
		cout<<"3.  FOR CREATING A STRING OBJECT AND INITIALIZING IT WITH ANOTHER STRING OBJECT"<<endl;
		cout<<"4.  ADDING TWO STRING OBJECTS"<<endl;
		cout<<"5.  INPUT TWO STRINGS AND COMPARE THEM"<<endl;
		cout<<"    ANYTHING ELSE TO QUIT"<<endl;
		cout<<"--------------------------------------------------------------------------------"<<endl;
		cout<<"ENTER YOUR CHOICE : ";
		int choice;
		cin>>choice;
		switch(choice) {
			cout<<endl<<endl;
			case 1: {
				cout<<"NULL STRING "<<endl;
				String string();
				break;
			}
			case 2 : {
				cout<<"ENTER THE CONTENTS OF STRING 1 :";
				char *ch;
				ch=new char[100];
				cin>>ch;
				String s1(ch);
				cout<<"CONTENTS OF THE STRING OBJECT : "<<s1;
				break;
			}
			case 3 : {
				cout<<"ENTER THE CONTENTS OF STRING 1 :";
				char *ch;
				ch=new char[100];
				cin>>ch;
				String s1(ch);
				cout<<"COPYING THE CONTENTS TO STRING OBJECT 2"<<endl;
				String s2(s1);
				cout<<"CONTENTS OF THE SECOND STRING OBJECT : "<<s2;
				break;
			}
			case 4 : {
				cout<<"ENTER THE CONTENTS OF STRING 1 :";
				char *ch;
				ch=new char[100];
				cin>>ch;
				String s1(ch);
				cout<<"ENTER THE CONTENTS OF STRING 2 :";
				cin>>ch;
				String s2(ch);
				String s3=s1+s2;
				cout<<"CONTENTS OF THE ADDED STRING OBJECT : "<<s3;
				break;
			}
			case 5 : {
				cout<<"ENTER THE CONTENTS OF STRING 1 :";
				char *ch;
				ch=new char[100];
				cin>>ch;
				String s1(ch);
				cout<<"ENTER THE CONTENTS OF STRING 2 :";
				cin>>ch;
				String s2(ch);
				//cout<<(s1.display())<<" > "<<(s2.display())<<" = "<<(s1>s2)<<endl;
				cout<<s1<<" < "<<s2<<" = "<<(s1<s2)<<endl;
				cout<<s1<<" >= "<<s2<<" = "<<(s1>=s2)<<endl;
				cout<<s1<<" <= "<<s2<<" = "<<(s1<=s2)<<endl;
				cout<<s1<<" == "<<s2<<" = "<<(s1==s2)<<endl;
				break;
			}
			case 7: {
				flag=false;
				goto OUTER;
				break;
			}
		}
	}
	
}
