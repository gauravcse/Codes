#include<iostream>

using namespace std;

int main(void) {
	do {
		int a,b;
		cin>>a;
		if(a==0)
			break;
		int arr1[a+1];
		for(int i=0;i<a;i++)
			cin>>arr1[i];
		arr1[a]=0;
		cin>>b;
		int arr2[b+1];
		arr2[b]=0;
		for(int i=0;i<b;i++)
			cin>>arr2[i];
		/* End of Input	*/
		
		int i,j;
		i=j=0;
		int upper=arr1[0],lower=arr2[0];
		do {
			if(arr1[i]==arr2[j]) {
				int max=upper>lower?upper:lower;
				upper=lower=max;
				i++;
				j++;
				if(i<a)
					upper=upper+arr1[i];
				;
				if(j<b)
					lower+=arr2[j];
				cout<<"Entered Equality\n"<<"Lower = "<<lower<<" Upper = "<<upper<<"\n";
				cout<<"Status \n"<<"i = "<<i<<" j = "<<j<<"\n";
			}
			else {
				if(arr1[i]>arr2[j]) {
					while(arr2[j]<arr1[i] && j<b) {
						lower+=arr2[++j];
					}
					cout<<"Entered i>j \n"<<"Lower = "<<lower<<" Upper = "<<upper<<"\n";
					cout<<"Status \n"<<"i = "<<i<<" j = "<<j<<"\n";
				}
				else if(arr1[i]<arr2[j]) {
					while(arr2[j]>arr1[i] && i<a) {
						upper+=arr1[++i];
					}
					cout<<"Entered i<j \n"<<"Lower = "<<lower<<" Upper = "<<upper<<"\n";
					cout<<"Status \n"<<"i = "<<i<<" j = "<<j<<"\n\n\n";
				}
			}
			
		}while(i<a && j<b);
		
		while(i<a-1) 
			upper+=arr1[++i];
		while(j<b-1)
			lower+=arr2[++j];
		cout<<"Entered i<j \n"<<"Lower = "<<lower<<" Upper = "<<upper<<"\n";
		cout<<"Status \n"<<"i = "<<i<<" j = "<<j<<"\n\n\n";
		cout<<(upper>lower?upper:lower)<<"\n";
	} while(true);
}
