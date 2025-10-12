#include<iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node(int value)
	{
		data = value;
		next = NULL;
	}
};

class Stack
{
private:
	Node* top;

public:
	Stack()
	{
		top = NULL;
	}
	bool is_empty()
	{
		return (top == NULL);
	}
	void push(int value)
	{
		Node* newNode = new Node(value);
		if (is_empty())
		{
			top = newNode;
		}
		else
		{
			newNode->next = top;
			top = newNode;
		}
	}
	void display()
	{
		if (is_empty())
		{
			cout << "Stack is empty" << endl;
		}
		else
		{
			Node* temp = top;

			while (temp != NULL)
			{
				cout << temp->data << "\t";
				temp = temp->next;
			}
			cout << endl;
		}
	}
	void pop()
	{
		if (is_empty())
		{
			cout << "Stack is empty, you cannot pop value from this stack." << endl;
		}
		else
		{
			Node* temp = top;
			top = top->next;
			cout << temp->data << " is popped from stack." << endl;
			delete temp;
		}
	}
	int peek()
	{
		if (is_empty())
		{
			cout << "Stack is empty, no top element" << endl;
			return -1;
		}
		return top->data;
	}
	int count()
	{
		int counter = 0;
		Node* temp = top;

		while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}	
		return counter;
	}
	bool is_found(int searchItem)
	{
		bool found = false;
		Node* temp = top;

		while (temp != NULL)
		{
			if (temp->data == searchItem)
				found = true;
			temp = temp->next;
		}
		return found;
	}

	// if the memory doesnot have space and it is full, this is very very very low probability.
	void is_full()
	{
		Node* ptr = new Node(0);

		if (ptr == NULL) 
			cout << "Stack is full." << endl;
	}
};

int main()
{
	Stack st;

	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.display();

	st.pop();
	st.display();
	st.pop();
	st.display();

	cout << "Top element: " << st.peek() << endl;
	st.display();

	cout << "Number of Items in stack is: " << st.count() << endl;
	st.display();

	if (st.is_found(20))
	{
		cout << "Item is found" << endl;
		st.display();
	}
	else
	{
		cout << "Item is not found" << endl;
		st.display();
	}


	return 0;
}