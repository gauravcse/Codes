#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class Student {
	private :
		int roll_no;
		char* name;
		char* course;
		char* date;
		float marks[5];
		static int number_of_students;
		void student_count();
	public :
		Student(int,char*,char*,char*);
		void update_date(char*);
		void prepare_marksheet(float[]);
		void show_result();
		int admitted_students();
};

Student::Student(int roll_no,char* name,char* course,char* date) {
	this->roll_no=roll_no;
	this->name=(char*)malloc(sizeof(char)*20);
	this->course=(char*)malloc(sizeof(char)*20);
	this->date=(char*)malloc(sizeof(char)*20);
	strcpy(this->name,name);
	strcpy(this->course,course);
	strcpy(this->date,date);
	for(int i=0;i<5;i++) {
		this->marks[i]=0;
	}
	student_count();
}

int Student::number_of_students=0;

void Student::update_date(char *date) {
	strcpy(this->date,date);
}

void Student::prepare_marksheet(float marks[]) {
	for (int i=0;i<5;i++) 
		this->marks[i]=marks[i];
}

int Student:: admitted_students() {
	return number_of_students;
}

void Student::student_count() {
	number_of_students++;
}

void Student::show_result() {
	cout<<this->roll_no<<"	"<<this->name<<"	"<<this->course<<"	"<<this->date<<endl;
}

int main (void) {
	/*Student s1(25,"Gaurav","JUCSE","28//11/1995");
	float arr[]={10.5,200.5,30,40.5,50.5};
	s1.prepare_marksheet(arr);
	s1.update_date("1/01/1999");
	s1.show_result();*/
	
	Student s[10];
	
	while(true) {
		cout<<"Do you want to Add Student (Press 1 for Yes or 0 for No: ";
		int num;
		cin>>num;
		if(!num) {
			break;
		}
		else {
			int roll;
			char *nm,*cour,*dt;
			nm=(char*)malloc(sizeof(char)*20);
			cour=(char*)malloc(sizeof(char)*20);
			d=(char*)malloc(sizeof(char)*20);
			cout<<"Enter the Roll No : ";
			cin>>roll;
			cout<<"Enter the Name : ";
			scanf("%s",nm);
			cout<<"Enter the Course : ";
			scanf("%s",cour);
			cout<<"Enter the Date in DD/MM/YYYY format : ";
			scanf("%s",dt);
		}
	}
	
	
}

