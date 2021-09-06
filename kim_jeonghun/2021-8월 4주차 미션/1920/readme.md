# 문제-10845 큐

- 자료구조 queue를 구현하는 문제이다.
- 단순 stl을 사용해도 되지만, queue의 구조를 다시한번 뇌에 새겨두기 위해 class로 구현해봤다.

- queue를 class로 선언한 뒤, queue의 구조는 front, rear로 이루어져 있기에 인수로 선언해준다.
- 이후 포인터 배열을 선언해주고 size만큼 동적할당 해준다.

- 문제에서 요구하는 기본적인 함수들을 구현해준다.
	- push나 pop은 queue가 가득찼는지, 비어있는지 확인 해준뒤, rear과 front를 이용해 넣거나 빼주면 된다.
	- front, back, size는 포인터 배열에서 해당 위치를 반환하여 값을 받아주면 된다.
```C
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
```

- 이후 메인 함수에서 구현한 queue 클래스를 이용하여 문제를 구현하면 된다.

```C
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
```
