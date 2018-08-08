#include "stdafx.h"
#include<iostream>
#include "StackV0.h"



using namespace std;



int main() {

	Stack<int> intstack;
	int x = 0;
	while (x < 40) {
		intstack.push(x%5);
		x++;

	} 
	cout << intstack.pop() << '\n';
	intstack.print();
	return 0;
}