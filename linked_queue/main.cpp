#include <iostream>
using namespace std;

class Queue {
	class Node {
	public:
		int data;
		Node* next;

		Node(int n) {
			data = n;
			next = nullptr;
		}
	};

public:
	Queue() {
		front = nullptr;
		rear = nullptr;
	}

	Node* front;
	Node* rear;

	void enqueue(int n) {
		Node* temp = new Node(n);
		if (front == nullptr) {
			front = temp;
			rear = temp;
			return;
		}

		rear->next = temp;
		rear = temp;
	}

	void dequeue() {
		if (front == nullptr) {
			return;
		}

		if (front == rear) {
			front = nullptr;
			rear = nullptr;
			return;
		}

		Node* temp = front;
		front = front->next;
		delete temp;
	}

	void peek() {
		if (isEmpty()) {
			cout << -1 << endl;
		} else {
			cout << front->data << endl;
		}
	}

	bool isEmpty() {
		if (front == nullptr) {
			return true;
		} else {
			return false;
		}
	}
};
int main() {
	Queue myQueue;
	myQueue.enqueue(10);
	myQueue.enqueue(20);
	myQueue.peek();
	myQueue.dequeue();
	myQueue.peek();
}