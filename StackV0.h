#ifndef STACKV0_H
#define STACKV0_H

#include "Node.h"
using namespace std;

template<class stackType>
class Stack {

	node<stackType> *top;


public:
	Stack(void) {
		top = NULL;
	}
	int push(stackType item) { // stack will return the index of the stack, aka the size
							   //allocate memory for new node
		//check for no memory
		node<stackType>* tmp = new node<stackType>();
		if(  tmp  == NULL)
			return 0;
		// set the new node's next equal to the current address of top
		tmp->next = top;
		//set top equal to the new node
		top = tmp;
		//set the data of the new node equal to the parameter
		top->data = item;

		//debugging code
		if(DEBUGGING)
			cout << "Pushing " << item << endl;
		//end debugging code
		return this->size();


		// TODO::
		// CHECK FOR ERRORS
	}
	unsigned int size(void) {
		if (top == NULL)
			return 0;
		//incrementing variable
		unsigned int length = 0;
		//make tmp ptr if stack is not empty
		node<stackType>* tmp = top;
		//loop through array incrementing size until top==null

		while (tmp != NULL) {
			length++;
			tmp = tmp->next;

		}
		return length;
	}
	stackType pop() {
		if (this->top == NULL)
			return;
		stackType s = top->data;
		node<stackType>* tmp = top->next;
		delete top;
		top = tmp;
		return s;
	}
	void print() {
		{
			// if stack is empty print nothing
			if (top == NULL)
				return;


			//make tmp ptr if stack is not empty
			node<stackType>* tmp = top;
			//loop through array incrementing size until top==null

			while (tmp != NULL) {
				cout << tmp->data << endl;
				tmp = tmp->next;

			}

		}
	}

	~Stack() {
		if (top == NULL)
			return;


		//make tmp ptr if stack is not empty
		node<stackType>* tmp;

		while (top != NULL) {
			tmp = top;
			top = top->next;
			delete tmp;

		}
		if(DEBUGGING)
			cout << "Nodes deleted\n";
	}

};






#endif // !STACKV0_H
