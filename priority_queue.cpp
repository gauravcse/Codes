

#include<iostream>
#include<cstdlib>
#include "priority_queue.h"

template <class T>
Priority_queue::Priority_queue() {
	head=NULL;
	this->length=0;
}

template <class T>
bool Priority_queue::isEmpty() {
	if(length==0) {
		return true;
	}
	else {
		return false;
	}
}

template <class T>
void Priority_queue::push(T info,int prio) {
	node *temp;
	temp = new node;
	temp->value=info;
	temp->priority=prio;
	length++;
	if(head==NULL || head->priority<temp->priority) {
		temp->next=head;
		head=temp;
	}
	else {
		node* temp2;
		temp2=head;
		while(temp2->next!=NULL && temp2->next->priority>=temp->priority)	{
			temp2=temp2->next;
		}
		temp->next=temp2->next;
		temp2->next=temp;
	}
}

int Priority_queue::size() {
	return length;
}

template<class T>
T Priority_queue::top() {
	try {
		if(isEmpty()) {
			throw -1;
		}
		else {
			return head->value;
		}
	}
	catch(int error) {
		std::cout<<"UNDERFLOW EXCEPTION"<<std::endl;
	}
}

template<class T>
T Priority_queue::pop() {
	try {
		if(isEmpty()) {
			throw -1;
		}
		else {
			T data=head->value;
			node* temp=head;
			head=head->next;
			delete temp;
			return data;
			
		}
	}
	catch(int error) {
		std::cout<<"UNDERFLOW EXCEPTION"<<std::endl;
	}
}

