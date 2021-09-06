#include<iostream>
#include<string>
using namespace std;

class Queue {
	int front, rear, size;
	int* arr;
public:
	Queue(int n) { front = 0; rear = 0; size = n; arr = new int[size]; }
	~Queue() { delete[] arr; }

	bool is_empty() {
		if (front == rear)
			return true;
		return false;
	}
	bool is_full() {
		if (rear + 1 == front)
			return true;
		return false;
	}
	void push() {
		if (!is_full()) {
			int tmp;
			cin >> tmp;
			arr[rear++] = tmp;
		}
	}
	int pop() {
		if (!is_empty())
			return arr[front++];
		return -1;
	}
	int Size() {
		return rear - front;
	}
	int Front() {
		if (!is_empty())
			return arr[front];
		return -1;
	}
	int back() {
		if (!is_empty())
			return arr[rear - 1];
		return -1;
	}
};

int main() {
	int n, tmp;
	string mod;
	cin >> n;
	Queue q(n);
	for (int i = 0; i < n; i++) {
		cin >> mod;
		if (mod == "push") q.push();
		else if (mod == "pop") cout << q.pop() << '\n';
		else if (mod == "size") cout << q.Size() << '\n';
		else if (mod == "empty") cout << q.is_empty() << '\n';
		else if (mod == "front") cout << q.Front() << '\n';
		else if (mod == "back") cout << q.back() << '\n';
	}
}