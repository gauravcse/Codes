#include<iostream>

using namespace std;

class TOLLTAX {
	private :
		int number_of_cars;
		float amount;
		void increment_cars();
	public :
		TOLLTAX();
		void receive_toll(float);
		void display_cars();
		void toll_collected();
};

TOLLTAX::TOLLTAX() {
	this->amount=0.0;
	this->number_of_cars=0;
}

void TOLLTAX::increment_cars() {
	this->number_of_cars++;
}

void TOLLTAX::receive_toll(float toll) {
	increment_cars();
	this->amount=this->amount+toll;
}

void TOLLTAX::display_cars() {
	cout<<"The Number of Cars are : "<<number_of_cars<<endl;
}

void TOLLTAX::toll_collected() {
	cout<<"Total Toll Collections : "<<amount<<endl;
}

int main(void) {
	TOLLTAX toll;
	toll.receive_toll(25.25);
	toll.receive_toll(25.25);
	toll.receive_toll(25.25);
	toll.receive_toll(25.25);
	toll.receive_toll(25.25);
	toll.receive_toll(25.25);
	toll.display_cars();
	toll.toll_collected();
}
