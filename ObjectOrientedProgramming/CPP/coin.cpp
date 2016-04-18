/***
		A PROGRAM TO SIMULATE COIN FLIPS
***/

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>

using namespace std;
/***
		A CLASS WHICH HOLDS THE CHARACTERISTICS OF A COIN
	***/
class Coin {
	private :
		const static bool head=true;		//TWO STATES OF A COIN
		const static bool tail=false;
		int number_of_flips;				
		int number_of_heads;
		int number_of_tails;
		void generate_seed();
		bool single_flip();
		void print_flip_result(bool);
		void print_number_of_flips(bool);
	public :
		void start_flipping();
		
};

/***
		FUNCTION THAT SIMULATES COIN FLIP BY STARTING THE PROCESS
***/

void Coin::start_flipping() {
	this->number_of_flips=0;
	this->number_of_heads=0;
	this->number_of_tails=0;
	bool previous_flip;
	this->generate_seed();
	previous_flip=single_flip();
	if(previous_flip)
		this->number_of_heads++;
	else
		this->number_of_tails++;
	
	while(this->number_of_heads<3 && this->number_of_tails<3) {
		bool next_flip;
		next_flip=single_flip();
		if(next_flip==previous_flip) {
			if(next_flip==head)
				this->number_of_heads++;
			else
				this->number_of_tails++;
		}
		else {
			if(next_flip==head) {
				this->number_of_heads=1;
				this->number_of_tails=0;
			}
			else {
				this->number_of_heads=0;
				this->number_of_tails=1;
			}
		}
		previous_flip=next_flip;
		this->print_flip_result(next_flip);
		this->number_of_flips++;
	}
	this->print_number_of_flips(previous_flip);
}

/***
		GENERATES A NEW SEED FOR PSEUDO RANDOM NUMBER GENERATION
***/

void Coin::generate_seed() {
	time_t t;
	t=time(0);
	srand(t);
}

/***
		SIMULATES EACH FLIP
***/

bool Coin::single_flip() {
	int flip=rand()%2;
	if(flip==0)
		return head;
	else
		return tail;
}

/***	
		PRINTS THE RESULT OF EACH FLIP
***/

void Coin::print_flip_result(bool flip) {
	if(flip==head)
		cout<<"head"<<endl;
	else
		cout<<"tail"<<endl;
}

/***
		PRINTS THE DATA (NUMBER OF FLIPS BEFORE THREE CONSECUTIVE HEAD OCCURS
***/	

void Coin::print_number_of_flips(bool flip) {
	cout<<"It took "<<this->number_of_flips<<" to get 3 consecutive"<<(flip==head?" heads":" tails")<<endl;
}

/***
		MAIN TO TEST THE CODE
***/

int main(void) {
	string str;
	while(true) {
		Coin obj;
		cout<<"Do You Want to Play The Coin Game ?  Enter YES or NO:  ";
		cin>>str;
		if(str=="YES")
			obj.start_flipping();
		else {
			break;
		}
		
	}
}
