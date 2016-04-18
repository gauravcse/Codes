/***
		PRIORITY QUEUE IMPLEMENTED WITH STUDENT DATA
***/

#include<iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;

/***
		A STRUCTURE HOLDING THE INFORMATION OF A STUDENT LIKE NAME,ROLL(UNIQUE) AND OTHER DETAILS AND
		ALSO HAVING A NEXT POINTER LIKE A LINKED LIST
***/

struct node{
	string name;
	int roll;
	float key;
	node* next;
};

/***
		A CLASS HAVING FUNCTION OF A PRIORITY QUEUE
***/

class Priority_queue{

private:
	/***		HEAD NODE OF THE LINKED LIST		***/
	node *front;
public:
	/***		DEFAULT CONSTRUCTOR					***/
	Priority_queue(){
		front=NULL;
	}

	/***		PUSH NODES INTO THE QUEUE ACCORDING TO PRIORITY DECIDED BY THE CGPA
				HIGHER CGPA FIRST														***/
	void push(string a,int b,float cgpa){
		node *t,*q;
		t= new node;
		t->name=a;
		t->roll=b;
		t->key=cgpa;
	    if(front==NULL || cgpa>front->key){
			t->next=front;
			front=t;
		}
		else {
			q=front;
			while(q->next!=NULL && q->next->key>cgpa)
			q=q->next;	
			t->next=q->next;
			q->next=t;
		}
	}
	/***		POPS NODE AND DELETES THE SPACE ACCORDING TO THE PRIORITY 
				THAT IS HIGHER PRIORITY FIRST AND PRIORITY IS THE STUDENT CGPA			***/										
	float pop(){
		node *t;
		t=front;
		free(front);
		front=t->next;
	}

	/***		DISPLAYS THE CURRENT STATE OF THE QUEUE AFTER ANY NUMBER OF OPEARATIONS
				USES setw() FUNCTION OF THE IOMANIP LIBRARY FOR PROPER INDENTATION			***/
				
	void display() {
	int i=0;
	node *t;
	t=front;
	if(front==NULL)
	cout<<"QUEUE IS EMPTY!"<<endl;
	else{
			cout<<"__________________________________________________________"<<endl;
	cout<<setw(15)<<"No"<<setw(15)<<"Name"<<setw(15)<<"Roll"<<setw(15)<<"CGPA"<<endl;
	cout<<"__________________________________________________________"<<endl;
	while(t!=NULL)
	{
	i++;
		string x=t->name;
		int a= t->roll;
		float b=t->key;
		cout<<setw(15)<<i<<setw(15)<<x<<setw(15)<<a<<setw(15)<<b<<endl;
		t=t->next;
		if(t==NULL)
		break;
	}
		cout<<"__________________________________________________________"<<endl;
	}
	
	}									
};

/***		RETURNS THE GRADE OF A SINGLE SUBJECT WHICH IS THEN CUMULATED OVER 5 SUBJECTS		***/

int calculate_cgpa(int n){
	if(n<40)
		return 0;
	else {
		if(n==100)
			return 10;
		else
			return (n/10)+1;
}

/***		HELPER FUNCTION TO CALCULATE THE CGPA USING THE SIMPLE CGPA 
			CALCULATING ALGORITHM THAT 40 IS THE MINIMUM MARKS TO BE OBTAINED TO
			PASS AND A MARKS LESS THAN 40 IN ANY SUBJECT MEANS NO CGPA APPEARS 
			ELSE THE CGPA IS CALCULATED NORMALLY 										***/ 


float cgpa(int subject1,int subject2,int subject3,int subject4,int subject5){
	if(subject1<40 || subject2<40 || subject3<40 || subject4<40 || subject5<40)
	return 0.0;
	else
	{
		return (calculate_cgpa(subject1)+calculate_cgpa(subject2)+calculate_cgpa(subject3)+calculate_cgpa(subject4)+calculate_cgpa(subject5))/5;
	}
}

/***		MAIN FUNCTION CONTAINING THE MENU		***/

int main(){
	Priority_queue A;
	char ch='y';
	while(ch=='y'){
		cout<<"PRESS 1 TO PUSH A STUDENT"<<endl<<"PRESS 2 TO POP A STUDENT"<<endl<<"PRESS 3 TO DISPLAY THE QUEUE"<<endl; 
		int val;
		cin>>val;
		if(val==1){
			cout<<"PLEASE ENTER THE NAME : "<<endl;
			string a;
			cin>>a;
			cout<<"PLEASE ENTER THE ROLL NUMBER :"<<endl;
			int r;
			cin>>r;
			cout<<"PLEASE ENTER THE MARKS OF THE SUBJECTS IN THE GIVEN ORDER :"<<endl;
			int i,marks[5];
			for(i=0;i<5;i++)
			{
				cout<<"MARKS OF THE SUBJECT "<<i<<":"<<endl;
				cin>>marks[i];
				while(marks[i]>100 || marks[i]<0){
						cout<<"INCORRECT INPUT !"<<endl;
						cout<<"MARKS OF THE SUBJECT "<<i<<":"<<endl;
						cin>>marks[i];
				}
			}
			float x=cgpa(marks[0],marks[1],marks[2],marks[3],marks[4]);
			cout<<"CGPA OF "<<a<<"IS :"<<x<<endl;
			A.push(a,r,x);
		}
		else if(val==2){
			A.pop();
		}
		else if(val==3)
			A.display();
		cout<<"ENTER y TO CONTINUE ELSE PRESS n TO STOP"<<endl;
		cin>>ch;
		if(ch=='n')
			break;
	}
	return 0;
}

