#include<iostream>
#include"array.cpp"

using namespace std;

int main()
{
	int choice;
	do {
		std::cout << "Enter your choice:\n";
		std::cout << "1. Addition 2. Multiplication 3. Assignment 4. Quit\n";
		std::cin >> choice;
		switch(choice) {
		case 1:
			{
			cout<<"Enter the length of the Array Followed by the Length"<<endl;
				int len;
				cin>>len;
				int arr[len];
				for(int i=0;i<len;i++)			
					cin>>arr[i];
				Array<int> a(arr,len);
			cout<<"Enter the Second Array Followed by the Length"<<endl;
				int arr1[len];
				for(int i=0;i<len;i++)		
					cin>>arr[i];
				Array<int> b(arr1,len);
			a+b;
			
				
			}
		case 2:
			{
			
				
			}
		case 3:
			{
				cout<<"Enter the length of the Array Followed by the Length"<<endl;
				int len;
				cin>>len;
				int arr[len];
				for(int i=0;i<len;i++)			
					cin>>arr[i];
				Array<int> a(arr,len);
				
			}
		case 4:
			break;
		default:
			std::cout << "Invalid option.\n";
			break;
		}
	} while (choice != 4);
	return 0;
}
