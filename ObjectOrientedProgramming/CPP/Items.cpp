	/***
			Implementing A Database of Items
	***/
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
		long long unsigned get_code();
		string get_name();
		float get_rate();
		int get_quantity();
};

/***	Cosntructor to Initialize the item object		***/

Item::Item(long long unsigned code,string str,float r,int q) {
	this->r=r;
	this->q=q;
	this->code=code;
	this->n.assign(str);
}

/***	Getter Function for Getting Code	***/

long long unsigned Item::get_code() {
	return this->code;
}

/***	Getter function for getting Name	***/

string Item::get_name() {
	return n;
}

/***	Getter function for getting Rate	***/

float Item::get_rate() {
	return this->r;
}

/***	Getter function for getting Name	***/

int Item::get_quantity() {
	return this->q;
}

/**		 Aggregation of Items in the Items Class		***/

class Items {
	
	private :
		vector<long long unsigned> item_code;
		vector<string> name;
		vector<float> rate;
		vector<int> quantity;
		int check_code_uniqueness(long long unsigned);
	public :
		void add_new_Item(Item);
		void change_item_rate(Item,float);
		void update_quantity(Item,int,char);
		bool availability(Item);
		void query(Item);	;
				
};

/***	Adding new Item to the list of Items	***/

void Items::add_new_Item(Item item) {
		long long unsigned code=item.get_code();
		if(this->check_code_uniqueness(code)!=-1) 
			cout<<"Cannot Add this Item as the Item Code Already Exists"<<endl;
		else {
			item_code.push_back(code);
			name.push_back(item.get_name());
			rate.push_back(item.get_rate());
			quantity.push_back(item.get_quantity());
		}
}

/***	Changing the Rate of a particular Item among the List	***/


void Items::change_item_rate(Item item,float rte) {
	float rat=item.get_rate();
	long long unsigned code=item.get_code();
	int count=this->check_code_uniqueness(code);
	if(count>=0) {
		rate[count]=rte;
	}
	else {
		cout<<"Item Not Found"<<endl;
	}
}

/***	Update the Quantity of A particular Item	***/

void Items::update_quantity(Item item,int update,char issue) {
	long long unsigned code=item.get_code();
	int count=this->check_code_uniqueness(code);
	if(count>=0) {
		if(issue=='I') {
			if(update>quantity[count]) {
				cout<<"Request Cannot Be Processed as Quantity Available is Less"<<endl;
			}
			else {
				quantity[count]-=update;
			}
		}
		else if(issue=='R') {
			quantity[count]+=update;
		}
	}
}

/***	Check the availability of a Particular Item		***/

bool Items::availability(Item item) {
	long long unsigned code=item.get_code();
	int count=this->check_code_uniqueness(code);
	if(count>=0) {
		if(quantity[count]>0) {
			cout<<"Available"<<endl;
			return true;
		}
		else {
			cout<<"Stock Exhausted"<<endl;
			return false;
		}
	}
}

/*** 	Query for the Rate and Quantity Available for an Item	***/

void Items::query(Item item) {
	long long unsigned code=item.get_code();
	int count=this->check_code_uniqueness(code);
	if(count>=0) {
		if(quantity[count]>0) {
			cout<<"Quantity Available : "<<quantity[count]<<endl<<"Rate : "<<rate[count]<<endl;
		}
		else
			cout<<"Item Unavailable";
	}
}
	
/***	Private Function to Check the Uniqueness of the Code when a new Item is to be Inserted	***/

int Items::check_code_uniqueness(long long unsigned code)  {
	int count=0;
	for(vector<long long unsigned>::iterator it=this->item_code.begin();it!=this->item_code.end();++it) {
		if(*it==code) 
			return count;
		else
			count++;
	}
	return -1;
}

int main(void) {
	Items items;
	int count=0;
	while(true) {
		int t;
		cout<<"Do You Want to Add New Item ? Yes 1 No 0 : ";
		cin>>t;
		if(t) {
			long long unsigned c;
			string n;
			float r;
			int q;
			cout<<"Enter the Item Code : ";
			cin>>c;
			cout<<"Enter the Item Name : ";
			cin>>n;
			cout<<"Enter the Item Rate : ";
			cin>>r;
			cout<<"Enter the Number of Items : ";
			cin>>q;
			Item item(c,n,r,q);
			count++;
			items.add_new_Item(item);
			int flag;
			cout<<"Do You Want to Change Item Rate ? Yes 1 No  0 :"; 
			cin>>flag;
			if(flag) {
				int rt;
				cout<<"Enter the Rate : ";
				cin>>rt;
				items.change_item_rate(item,rt);
			}
			cout<<"Do You Want to Update Quantity ? Yes 1 No  0 :"; 
			cin>>flag;
			if(flag) {
				char ch;
				cout<<"Enter whether the Quantity is to be Received or Decreased ? R for Received I for Decreased : ";
				cin>>ch;
				int rt;
				cout<<"Enter the Quantity By Which it is To be Updated : ";
				cin>>rt;
				items.update_quantity(item,rt,ch);
			}
			cout<<"Do You Want to Query Item Rate and Quantity ? Yes 1 No  0 :"; 
			cin>>flag;
			if(flag) {
				items.query(item);
			}
		}
		else {
			break;
		}
	}


}
