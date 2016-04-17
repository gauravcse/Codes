#include<iostream>
#include<string.h>

class Book {
	private:
		int id;
		char *name;
		
	public:
		Book()  {
			id=-1;
			name=NULL;
		}
		Book(int book,char *str) {
			id=book;
			name=new char[strlen(str)];
			strcpy(name,str);
		};
		Book(Book &b) {
			this->id=b.id;
			this->name=new char[strlen(b.name)];
			strcpy(this->name,b.name);
		}
		void display_data() {
			std::cout<<"Book Name : "<<name<<"\nBook ID : "<<id<<std::endl<<std::endl;
		}
};

class BookList {
	private :
		static int number_of_books;
		Book books[1000];
	public :
		void addBook(Book& b) {
			books[number_of_books]=b;
			number_of_books++;
		};
		void displayList(){
			for(int i=0;i<number_of_books;i++) 
				this->books[i].display_data();
		}
};

class Journal {
	private:
		char *name;
		int volume;
		char *date_of_publish;
		
	public:
		int issue_no;
		Journal()  {
			volume=-1;
			name=NULL;
			date_of_publish=NULL;
			issue_no=0;
		}
		Journal(int volume,char *str,int issue_no,char *date) {
			this->volume=volume;
			name=new char[strlen(str)];
			date_of_publish=new char[strlen(date)];
			date_of_publish=date;
			this->issue_no=issue_no;
			strcpy(name,str);
		};
		Journal(Journal &j) {
			this->volume=j.volume;
			this->name=new char[strlen(j.name)];
			strcpy(this->name,j.name);
			this->issue_no=j.issue_no;
			this->date_of_publish=new char[strlen(j.date_of_publish)];
			strcpy(this->date_of_publish,j.date_of_publish);
		}
		void display_data() {
			std::cout<<"Journal Name : "<<name<<"\nJournal ID : "<<volume<<std::endl<<std::endl;
		}
};

class JournalList {
	private :
		static int number_of_journals;
		Journal journals[1000];
	public :
		void addJournal(Journal& j) {
			journals[number_of_journals]=j;
			number_of_journals++;
		};
		void displayList(){
			for(int i=0;i<number_of_journals;i++) 
				this->journals[i].display_data();
		}
		void display_list(int data) {
			for(int i=0;i<number_of_journals;i++) {
				if(data==journals[i].issue_no) {
					this->journals[i].display_data();
				}
			}
		}
};

/*class Person {
	private :
		int type;
		int id;
		char *name;
	public :
		Person() {
		}
		Person(int type,int id,char *name)  {
			this->type=type;
			this->id=id;
			this->name=new name[strlen(name)];
			strcpy(this->name,name);
		}
};*/

class LibraryTransaction {
	private :
		const static int faculty=10;
		const static int student=2;
		const static int late_student=1;
		const static int late_prof=0;
		const static int days=7;
		char *transaction_date;
		int type;
		int id;
		char *name;
		int pid;
		int fine;
	public :
		Library(int type,int id,char *name,char *date) {
			this->type=type;
			this->id=id;
			this->name=new char[strlen(name)];
			strcpy(this->name,name);
			transaction_date=new char[strlen(name)];
			strcpy(transaction_date,date);
			if(type==1) {
				cout<<"WELCOME FACULTY : "<<endl;
				cout<<"DO YOU WANT BOOK OR JOURNAL"<<endl;
				cout<<"PRESS 1 FOR BOOK AND 2 FOR JOURNAL"<<endl;
				int choice;
				cin>>choice;
				if(choice == 1) {
					cout<<"ENTER THE ID OF THE BOOK : ";
					cin>>pid;	
				}
				else {
					cout<<"ENTER THE ISSUE NO OF THE JOURNAL : ";
					cin>>pid;
				}
				int ret;
				cout<<"HOW MANY DAYS BEFORE RETURNING :";
				cin>>ret;
				fine=0;
				cout<<"FINE INCURRED IS 0:"<<endl;
			}
			else {
				cout<<"WELCOME STUDENT : "<<endl;
				cout<<"ENTER THE ID OF THE BOOK : ";
				cin>>pid;
				cout<<"HOW MANY DAYS BEFORE RETURNING :";
				cin>>ret;
				fine=(ret<=7?0:(ret));
				cout<<"FINE INCURRED IS :"<<(ret<=7?0:(ret))<<endl;
			}
			
		}
		void display_data() {
			cout<<endl<<"NAME OF THE BORROWER : "<<name;
			cout<<"DATE OF TRANSACTION : "<<date<<endl;;
			cout<<"FINE OF THE TRANSACTION : "<<fine<<endl;
			cout<<"RENTING DETAILS : "<<endl;	
		}
};

class LibraryDatabase {
		private :
			int number_of_transactions;
			LibraryTransaction library[1000];
		public :
			LibraryDatabase() {
				number_of_transactions=0;
			}
			void addTransaction(LibraryTransaction &t) {
				library[number_of_transactions]=t;
				number_of_transactions++;
			}
			void displayTransaction(){
				for(int i=0;i<number_of_transactions;i++) 
					this->library[i].display_data();
			}
};

int BookList::number_of_books=0;
int JournalList::number_of_journals=0;

int main(void) {
	Journal b1(1,"Hello1",65,"22/11/1995");
	Journal b2(2,"Hello2",66,"23/11/1995");
	JournalList journallist;
	journallist.addJournal(b1);
	journallist.addJournal(b2);
	journallist.displayList();
}
