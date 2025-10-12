#include<iostream>

using namespace std;

class Queue
{
private:
	int size, front, rear;
	int* arr;

public:
	Queue(int s)
	{
		size = s;
		arr = new int[size];
		front = -1;
		rear = -1;
	}
	bool is_full()
	{
		return (rear == size - 1);
	}
	bool is_empty()
	{
		return (front == -1 || front > rear);
	}
	void enqueue(int value)
	{
		if (is_full())
		{
			cout << "Queue is full, cannot insert" << endl;
			return;
		}
		if (front == -1)
		{
			front = 0;
		}
		arr[++rear] = value;
		cout << value << " inserted into Queue." << endl;
	}
	void dequeue()
	{
		if (is_empty())
		{
			cout << "Queue is empty." << endl;
			return;
		}
		cout << arr[front] << " removed from Queue." << endl;
		if (front == rear)
		{
			front = rear = -1;
		}
		else
		{
			front++;
		}
	}
	int peek()
	{
		if (is_empty())
		{
			cout << "Queue is empty." << endl;
			return -1;
		}
		return arr[front];
	}
	void display()
	{
		if (is_empty())
		{
			cout << "Queue is empty." << endl;
			return;
		}
		for (int i = front; i <= rear; i++)
		{
			cout << arr[i] << "\t";
		}
		cout << endl;
	}
};


int main()
{
	Queue q(5);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.display();

	cout << "Front element is: " << q.peek() << endl;

	q.dequeue();
	q.display();

	return 0;
}