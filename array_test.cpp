/***		FILE CONTAINING THE MENU FOR THE ARRAY IMPLEMENTATION		***/

#include<iostream>
#include "array.cpp"

using namespace std;

int main(void) {
	cout<<"------------------------------------------|"<<endl;
	cout<<"WELCOME TO THE ARRAY CLASS IMPLEMENTATION |"<<endl;
	cout<<"------------------------------------------|"<<endl<<endl;
	bool flag=true;
	OUTER:while(flag) {
		cout<<"--------------------------------------------------------------------------------"<<endl;
		cout<<"1.  FOR CREATING AN ARRAY AND  INITIALING IT WITH NULL "<<endl;
		cout<<"2.  FOR CREATING AN ARRAY OBJECT AND INITIALIZING IT WITH A C STYLED ARRAY"<<endl;
		cout<<"3.  FOR CREATING AN ARRAY OBJECT AND INITIALIZING IT WITH ANOTHER ARRAY OBJECT"<<endl;
		cout<<"4.  ADDING TWO ARRAY OBJECTS"<<endl;
		cout<<"5.  FOR MULTIPLYING WITH CONSTANT"<<endl;
		cout<<"    ANYTHING ELSE TO QUIT"<<endl;
		cout<<"--------------------------------------------------------------------------------"<<endl;
		cout<<"ENTER YOUR CHOICE : ";
		int choice;
		cin>>choice;
		switch(choice) {
			cout<<endl<<endl;
			case 1: {
				cout<<"ENTER THE SIZE OF THE ARRAY : ";
				int s;
				cin>>s;				
				Array<int> arr(s);
				for(int i=0;i<s;i++)
					cout<<arr[i]<<"\t";
				cout<<endl;
				break;
			}
			case 2 : {
				cout<<"ENTER THE LENGTHS FOLLOWED BY CONTENTS OF C-STYLED ARRAY :";
				int l;
				cin>>l;
				int arr[l];
				for(int i=0;i<l;i++)
					cin>>arr[i];
				Array<int> array(arr,l);
				for(int i=0;i<l;i++)
					cout<<array[i]<<"\t";
				cout<<endl;
				break;
			}
			case 3 : {
				cout<<"ENTER THE LENGTH FOLLOWED BY CONTENTS OF ARRAY OBJECT:";
				int l;
				cin>>l;
				int arr[l];
				for(int i=0;i<l;i++)
					cin>>arr[i];
				Array<int> array(arr,l);
				Array<int> array1(array);
				cout<<"THE CONTENTS OF THE COPIED ARRAY ELEMENTS :";
				for(int i=0;i<l;i++)
					cout<<array1[i]<<"\t";
				cout<<endl;
				break;
			}
			case 4 : {
				cout<<"ENTER THE LENGTH FOLLOWED BY CONTENTS OF ARRAY OBJECT:";
				int l;
				cin>>l;
				int arr[l];
				for(int i=0;i<l;i++)
					cin>>arr[i];
				Array<int> array(arr,l);
				cout<<"ENTER THE LENGTH FOLLOWED BY CONTENTS OF ARRAY SECOND OBJECT:";
				cin>>l;
				int arr1[l];
				for(int i=0;i<l;i++)
					cin>>arr1[i];
				Array<int> array1(arr1,l);
				array+array1;
				break;
			}
			case 5 : {
				cout<<"ENTER THE LENGTH FOLLOWED BY CONTENTS OF ARRAY OBJECT :";
				int l;
				cin>>l;
				int arr[l];
				for(int i=0;i<l;i++)
					cin>>arr[i];
				Array<int> array(arr,l);
				cout<<"ENTER THE CONSTANT WITH WHICH IT IS TO BE MULTIPLIED : ";
				cin>>l;
				array*l;
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
