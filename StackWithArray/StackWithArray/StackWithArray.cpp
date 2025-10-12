#include<iostream>

using namespace std;

class Stack
{
private:
	int maxSize;
	int top;
	int* stackArray;

public:
	Stack(int size)
	{
		maxSize = size;
		stackArray = new int[size];
		top = -1;
	}
	bool is_empty()
	{
		return (top == -1);
	}
	bool is_full()
	{
		return (top == maxSize - 1);
	}
	void push(int value)
	{
		if (is_full())
		{
			cout << "Stack is full, you cannot push value in this stack." << endl;
		}
		else
		{
			stackArray[++top] == value;
			cout << value << " is Pushed." << endl;
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
			cout << stackArray[top--] << " is popped from stack." << endl;
		}
	}
	int peek()
	{
		if (is_empty())
		{
			cout << "Stack is empty" << endl;
			return -1;
		}
		else 
		{
			return stackArray[top];
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
			for (int i = 0; i <= top; i++)
			{
				cout << stackArray[i] << "\t";
			}
			cout << endl;
		}
	}
};

int main()
{
	Stack st(5);
	st.push(6);
	st.push(8);
	st.push(10);
	st.display();

	cout << "Top element: " << st.peek() << endl;

	st.pop();
	st.display();

	return 0;
}