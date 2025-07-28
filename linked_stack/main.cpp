#include <iostream>
using namespace std;

class Stack {
public:
	class Node {
	public:
		int data;
		Node* next;
		Node() {
			data = 0;
			next = nullptr;
		}
	};

	Node* top;

	Stack(){
		top = nullptr;
	}

	void push(int n) {
		Node* temp = new Node;
		temp->data = n;

		if (top == nullptr) {
			top = temp;
		} else {
			temp->next = top;
			top = temp;
		}
	}

	void pop() {
		if (isEmpty())return;

		Node* temp = top;
		top = top->next;
		delete temp;
	}

	bool isEmpty() {
		if (top == nullptr) {
			return true;
		} else {
			return false;
		}
	}

	void peek() {
		if (isEmpty()) {
			cout << -1 << endl;
		} else {
			cout << top->data << endl;
		}
	}
};


int main() {
	Stack myStack;
	myStack.push(10);
	myStack.push(20);
	myStack.peek();
	myStack.pop();
	myStack.peek();

	return 0;
}