#include<iostream>

using namespace std;

	/*** 
		Class which contains the Tolltax Declaration
	***/

class TOLLTAX {
	private :
		int number_of_cars;
		float amount;
		void increment_cars();
	public :
		static float types[4];
		TOLLTAX();
		TOLLTAX(int,float);
		void receive_toll(int);
		void display_cars();
		void toll_collected();
};

/***
	Default Cosntructor
***/

float TOLLTAX::types[]={10.0,25.0,30.0,50.0};

TOLLTAX::TOLLTAX() {
	this->amount=0.0;
	this->number_of_cars=0;
}

/***
	User Defined Cosntructor
***/

TOLLTAX::TOLLTAX(int number_of_cars,float amount) {
	this->number_of_cars=number_of_cars;
	this->amount=amount;
}

/***
	Increment Cars when each car comes
***/

void TOLLTAX::increment_cars() {
	this->number_of_cars++;
}

/***
	Receive Tolls by Amount
***/

void TOLLTAX::receive_toll(int t) {
	increment_cars();
	this->amount=this->amount+types[t-1];
}

/***
	Displays Cars with this function
***/

void TOLLTAX::display_cars() {
	cout<<"The Number of Cars are : "<<number_of_cars<<endl;
}

/***
	Display Tolls by Amount
***/

void TOLLTAX::toll_collected() {
	cout<<"Total Toll Collections : "<<amount<<endl;
}

/*** 	
	Main Function
***/

int main(void) {
	TOLLTAX toll;
	while(true) {
		cout<<"Any new Car ? (Press 1 if Yes Else Press 0) : \t\t";
		int car;
		cin>>car;
		if(!car)
			break;
		else {
			cout<<"Enter the Type of car \n For two Wheeler press 1 \n For 4 Wheeler press 2 \n For Trucks press 3 \n For Very Heavy vehicles press 4   : \t\t";
			int t;
			cin>>t;
			toll.receive_toll(t);
		}
	}
	toll.display_cars();
	toll.toll_collected();
}
