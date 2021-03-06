	/***
			Implementation of AM/PM 24hour Time Class
	***/

#include<iostream>
#include<stdlib.h>

using namespace std;

class Time {

	/*** 
		 Private Data members of the class
	***/

	int hour;
	int minute;
	int second;

	/*** 
		 Public member Functions of the class
	***/

	public :
		Time(int,int,int);
		Time(int,int,int,char);
		void display_format_24(void);
		void display_format_AMPM(void);
		void addMinute(int);
};

/***
	Constructor for inputting data in 24 Hour Format
***/

Time::Time(int hour,int minute,int second) {
	this->hour=hour;
	this->minute=minute;
	this->second=second;
}

/***
	Overloaded Constructor for inputting data in AM/PM Hour Format
***/


Time::Time(int hour,int minute,int second,char time) {
	if(time=='A') {
		this->hour=hour;
		this->minute=minute;
		this->second=second;
	}
	else if(time=='P') {
		this->hour=hour+12;
		this->minute=minute;
		this->second=second;
	}
}

/***
	24 Hour Display Function
***/

void Time::display_format_24(void) {
	cout<<"Time is : "<<this->hour<<":"<<this->minute<<":"<<this->second<<endl<<endl;
}

/***
	AM/PM Format Display Function
***/

void Time::display_format_AMPM(void) {
	if(this->hour>=12)
		cout<<"Time is : "<<this->hour-12<<":"<<this->minute<<":"<<this->second<<" PM"<<endl<<endl;
	else 
		cout<<"Time is : "<<this->hour<<":"<<this->minute<<":"<<this->second<<" AM"<<endl<<endl;
}

/*** 
	Utility function to add minute to the time object of the class
***/

void Time::addMinute(int x) {
	/*if(this->minute==59) {
		this->hour=(this->hour+1)%24;
		this->minute=0;
	}
	else {
		this->minute++;	
	}*/
	
	
	this->hour=(this->hour+((x+this->minute)/60))%24;
	this->minute=(this->minute+x)%60;
	
}

int main(void) {
	/***
		Entering the time in AM/PM format
	***/

	cout<<"Enter the Time in AM/PM format "<<endl<<endl;
	int min,hr,sec;
	char *ch;
	ch=(char*)malloc(sizeof(char)*2);
	cout<<"Enter the Hour  : ";
	cin>>hr;
	cout<<"Enter the Minute  : ";
	cin>>min;
	cout<<"Enter the Second  : ";
	cin>>sec;
	cout<<"Enter the AM/PM  : ";
	cin>>ch;

	/***
		Constructor call for creating time object of AM/PM format
	***/

	Time time1(hr,min,sec,ch[0]);

	/***
		Entering the time in 24 Hour Format
	***/


	cout<<"Enter the Time in 24 Hour format "<<endl<<endl;
	cout<<"Enter the Hour  : ";
	cin>>hr;
	cout<<"Enter the Minute  : ";
	cin>>min;
	cout<<"Enter the Second  : ";
	cin>>sec;

	/***
		Constructor call for creating time object of 24 Hour format
	***/

	Time time2(hr,min,sec);
	
	/***
		 Display time in 24 Hour Format
	***/

	cout<<"Displaying time in 24 Hour Format"<<endl<<endl;
	time1.display_format_24();
	time2.display_format_24();

	/***
		 Display time in AM/PM Hour Format
	***/

	cout<<"Displaying time in AM/PM Format"<<endl;
	time1.display_format_AMPM();
	time2.display_format_AMPM();

	/*** 
		Incrementing the minute of each of the time instances of the class by some minute
	***/

	cout<<"Enter the minutes to be added  :  "<<endl;
	int x;
	cin>>x;
	
	cout<<"Incrementing both the times by "<<x<<" minutes"<<endl<<endl;
	time1.addMinute(x);
	time2.addMinute(x);
	cout<<"Displaying the times after incrementing"<<endl<<endl;

	/***
		 Display time in 24 Hour Format
	***/

	cout<<"Displaying time in 24 Hour Format"<<endl;
	time1.display_format_24();
	time2.display_format_24();
	
	/***
		 Display time in AM/PM Hour Format
	***/

	cout<<"Displaying time in AM/PM Format"<<endl<<endl;
	time1.display_format_AMPM();
	time2.display_format_AMPM();
	

}
