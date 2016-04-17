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
		void addMinute(void);
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
	cout<<"Time is : "<<this->hour<<":"<<this->minute<<":"<<this->second<<endl;
}

/***
	AM/PM Format Display Function
***/

void Time::display_format_AMPM(void) {
	if(this->hour>=12)
		cout<<"Time is : "<<this->hour<<":"<<this->minute<<":"<<this->second<<" AM"<<endl;
	else 
		cout<<"Time is : "<<this->hour-12<<":"<<this->minute<<":"<<this->second<<" PM"<<endl;
}

/*** 
	Utility function to add minute to the time object of the class
***/

void Time::addMinute(void) {
	if(this->minute==59) {
		this->hour=(this->hour+1)%24;
		this->minute=0;
	}
	else {
		this->minute++;	
	}
}

int main(void) {
	/***
		Entering the time in AM/PM format
	***/

	cout<<"Enter the Time in AM/PM format "<<endl;
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


	cout<<"Enter the Time in 24 Hour format "<<endl;
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

	cout<<endl<<"Displaying time in 24 Hour Format"<<endl;
	time1.display_format_24();
	time2.display_format_24();

	/***
		 Display time in AM/PM Hour Format
	***/

	cout<<endl<<"Displaying time in AM/PM Format"<<endl;
	time1.display_format_AMPM();
	time2.display_format_AMPM();

	/*** 
		Incrementing the minute of each of the time instances of the class by one minute
	***/

	cout<<endl<<"Incrementing both the times by 1 minute"<<endl;
	time1.addMinute();
	time2.addMinute();
	cout<<endl<<"Displaying the times after incrementing"<<endl;

	/***
		 Display time in 24 Hour Format
	***/

	cout<<endl<<"Displaying time in 24 Hour Format"<<endl;
	time1.display_format_24();
	time2.display_format_24();
	
	/***
		 Display time in AM/PM Hour Format
	***/

	cout<<endl<<endl<<"Displaying time in AM/PM Format"<<endl;
	time1.display_format_AMPM();
	time2.display_format_AMPM();
	

}
