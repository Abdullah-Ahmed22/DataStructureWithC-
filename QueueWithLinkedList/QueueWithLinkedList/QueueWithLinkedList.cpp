#include<iostream>
#include<string>


using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node(int value)
	{
		data = value;
		next = NULL:
	}
};

class Queue
{
private:
	Node* front;
	Node* rear;

public:
	Queue()
	{
		front = rear = NULL;
	}
	bool is_empty()
	{
		return (front == NULL);
	}
	void enqueue(int newValue)
	{
		Node* newNode = new Node(newValue);

		if (is_empty())
		{
			front = rear = newNode;
		}
		else
		{
			rear->next = newNode;
			rear = newNode;
			cout << newValue << " inserted into Queue." << endl;
		}
	}
	void dequeue()
	{
		if (is_empty())
		{
			cout << "Queue is empty." << endl;
			//return;
		}
		else if (front == rear)
		{
			cout << front->data << " removed from Queue." << endl;
			delete front;
			front = rear = NULL;
		}
		else
		{
			Node* delptr = front;
			cout << front->data << " removed from Queue." << endl;
			front = front->next;
			delete delptr;
		}
	}
	void display()
	{
		if (is_empty())
		{
			cout << "Queue is empty." << endl;
			return;
		}

		Node* temp = front;
		while (temp != NULL)
		{
			cout << temp->data << "\t";
			temp = temp->next;
		}
		cout << endl;
	}
	int peek()
	{
		if (is_empty())
		{
			cout << "Queue is empty." << endl;
			return -1;
		}

		return front->data;
	}
	int count()
	{
		Node* temp = front;
		int counter = 0;

		while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}
		return counter;
	}
	bool search(int key) {
		Node* temp = front;
		while (temp != NULL) 
		{
			if (temp->data == key) 
				return true;
			temp = temp->next;
		}
		return false;
	}

	void clear() 
	{
		while (!is_empty()) 
		{
			dequeue();
		}
		cout << "Queue cleared" << endl;
};

int maim()
{
	Queue q;

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.display();

	q.dequeue();
	q.display();

	cout << "Front element is: " << q.peek() << endl;
	q.display();

	cout << "Queue size: " << q.count() << endl;
	q.display();

	cout << (q.search(20) ? to_string(20) + " Found\n" : to_string(20) + "Not found\n");
	q.display();

	q.clear();
	q.display();

	return 0;
}