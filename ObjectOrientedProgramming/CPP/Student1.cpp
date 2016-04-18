/*** 	Implementing A database with Students	***/


#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Student {
	private :
		vector<int> roll;
		vector<string> name;
		vector<string> course;
		vector<string> admission_date;
		vector<int*> marks;
		static int no_of_students;
		vector<string> subjects;
		int search_roll_no(int);
		
	public :
		Student();
		void add_student(int,string,string,string);
		void update_admission_date(int,string);
		void receive_marks();
		void prepare_mark_sheet();
		/***	Getter Method For Number of Students	***/
		static int admitted_students() {
			return no_of_students;		
		}
};

/***	Initializing the static member Students for the Class		***/

int Student:: no_of_students=0;

/***	Constructor for the Students Class		***/

Student::Student() {
	this->subjects.push_back("Computer Science");
	this->subjects.push_back("Mathematics");
	this->subjects.push_back("Physics");
	this->subjects.push_back("Chemistry");
	this->subjects.push_back("Cosmology");
}

/***	Adding Student to the Database		***/


void Student::add_student(int roll,string name,string course,string admission) {
	int count=this->search_roll_no(roll);
	if(count==-1) {
		this->roll.push_back(roll);
		this->name.push_back(name);
		this->course.push_back(course);
		this->admission_date.push_back(admission);
		no_of_students++;
	}
	else {
		cout<<"Roll Number is Already Present"<<endl;
	}
	
	
}

/***	Function to Search Roll Number		***/

int Student::search_roll_no(int new_roll) {
	int count=0;
	for(vector<int>::iterator it=roll.begin();it!=roll.end();++it) {
		if(new_roll==*it) {
			return count;
		}
		count++;
	}
	return -1;
}

/***	Function to Update Admission Date	***/

void Student::update_admission_date(int roll_no,string date) {
	int count=this->search_roll_no(roll_no);
	if(count!=-1)
		admission_date[count]=date;
	else
		cout<<"No Such Student Exists"<<endl;
}

/*** 	Function to Receive the Marks of Five Subjects	***/

void Student::receive_marks() {
	int arr[5];
	cout<<"Enter the Roll Number whose Marks is to be Entered : ";
	int r;
	cin>>r;
	int count=this->search_roll_no(r);
	if(count==-1) {
		cout<<"Please Check your Input ! "<<endl<<"Roll Number Entered is Wrong ! "<<endl;
	}
	else {
		for(int i=0;i<5;i++) {
			cout<<"Please the Enter the Marks for "<<subjects[i]<<" : ";
			cin>>arr[i];
		}
	}
	marks.push_back(arr);
}

/***	Preparing Mark Sheet	***/

void Student::prepare_mark_sheet() {
	cout<<"Enter the Roll Number whose Marksheet is to be Printed : ";
	int r;
	cin>>r;
	int count=this->search_roll_no(r);
	if(count==-1) {
		cout<<"Please Check your Input ! "<<endl<<"Roll Number Entered is Wrong ! "<<endl;
	}
	else {
		cout<<"\n\n \t\tMark Sheet\t\t\n\n";
		cout<<"-------------------------------------"<<endl<<endl;
		cout<<"\tNAME : \t"<<name[count]<<endl;
		cout<<"\tROLL NUMBER  : \t"<<roll[count]<<endl;
		cout<<"\tCOURSE : \t"<<course[count]<<endl;
		cout<<"\tADMISSION DATE : \t"<<admission_date[count]<<endl;
		cout<<"\t\t\tMARKS\t\t"<<endl;
		cout<<"----------------------------------------------------------------------------"<<endl;
		cout<<subjects[0]<<"\t"<<subjects[1]<<"\t"<<subjects[2]<<"\t\t"<<subjects[3]<<"   "<<subjects[4]<<endl;
		cout<<"----------------------------------------------------------------------------"<<endl;
		int* ptr=marks.front();
		cout<<"  "<<*(ptr)<<"\t\t"<<*(ptr+1)<<"\t\t"<<*(ptr+2)<<"\t\t"<<*(ptr+3)<<"\t\t"<<*(ptr+4)<<endl;
	}
}



int main(void) {
	Student s;
	while(true) {
		cout<<"Do You Want to Add Any Student Press 1 For Yes and 0 for No?:"; 
		int temp;
		cin>>temp;
		if(!temp) {
			break;
		}
		else {
			int r;
			string n;
			string dept;
			string dt;
			cout<<"Enter the Roll Number, Name, Department and Date in Order ";
			cin>>r>>n>>dept>>dt;
			s.add_student(r,n,dept,dt);
		}
	}
	while(true)  {
		cout<<"Do You want to Update Admission Date of any Student ? Yes 1 No 0 : ";
		int temp;
		cin>>temp;
		if(!temp) {
			break;
		}
		else {
			cout<<"Enter the Roll Number Followes By the New Admission date ";
			int r;
			string dt;
			cin>>r>>dt;
			s.update_admission_date(r,dt);
		}
	}
	s.receive_marks();
	s.prepare_mark_sheet();
	cout<<"Total Number of Students Admitted : "<<Student::admitted_students()<<endl;
}

