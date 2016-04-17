#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Item {
	private: 
		long long unsigned code;
		string n;
		float r;
		int q;
	public :
		Item(long long unsigned,string,float,int);
};

Item::Item()


class Items {
	/*private :
		long long unsigned item_code;
		string name;
		float rate;
		int quantity;
		static long long unsigned item_code_vector[1000];
		static int count;
		int check_uniqueness(long long unsigned);
		bool check_existance();
	public :
		
		Items(long long unsigned,char*,float);
		Items(void);
		void update_rate(float);
		void update_quantity(bool);	
	*/
	
	private :
		vector<long long unsigned> item_code;
		vector<string> name;
		vector<float> rate;
		vector<int> quantity;
	public :
		void add_new_Item(Item);
		void change_item_rate(long long unsigned,float);
		void update_quantity();
		
				
					
};



