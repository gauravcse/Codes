#ifndef PRIORITY_QUEUE_H_INCLUDED
#define PRIORITY_QUEUE_H_INCLUDED

template<class T>
struct node {
	T value;
	int priority;
	struct node* next;
};

template<class T>
class Priority_queue {
	private:
		node* head;
		int length;
	public:
		Priority_queue();
		bool isEmpty();
		void push(T,int);
		T pop();
		int size();
		T top();
};

#endif
