#include<iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node* prev;

	Node(int value)
	{
		data = value;
		next = NULL;
		prev = NULL;
	}
};

class DoublyLinkedList
{
public:
	Node* head;

	DoublyLinkedList()
	{
		head = NULL;
	}
	bool is_empty()
	{
		return (head == NULL);
	}
	void append(int newValue)
	{
		Node* newNode = new Node(newValue);

		if (is_empty())
		{
			head = newNode;
			return;
		}

		Node* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
	}
	void traverseForward()
	{
		if (is_empty())
		{
			cout << "List is empty" << endl;
			return;
		}

		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "\t";
			temp = temp->next;
		}
	}
	void traverseBackward()
	{
		if (is_empty())
		{
			cout << "List is empty" << endl;
			return;
		}

		Node* temp = head;
		// Go to the last node
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		while (temp != NULL)
		{
			cout << temp->data << "\t";
			temp = temp->prev;
		}

	}
	void insert_first(int newValue)
	{
		Node* newNode = new Node(newValue);

		if (is_empty())
		{
			head = newNode;
			return;
		}

		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	void insert_at_position(int newValue, int position)
	{
		if (position == 0)
		{
			insert_first(newValue);
			return;
		}

		Node* newNode = new Node(newValue);
		Node* temp = head;
		int index = 0;
		while (temp != NULL && index < position - 1)
		{
			temp = temp->next;
			index++;
		}

		if (temp == NULL) 
		{
			cout << "Position out of range" << endl;
			delete newNode;
			return;
		}

		newNode->next = temp->next;
		newNode->prev = temp;
		if (temp->next != NULL)
		{
			temp->next->prev = newNode;
		}
		temp->next = newNode;
			 
	}
	void delete_first()
	{
		if (head = NULL)
		{
			return;
		}

		Node* temp = head;
		head = head->next;
		if (head != NULL)
		{
			head->prev = NULL;
		}

		delete temp;
	}
	void delete_end()
	{
		if (head = NULL)
		{
			return;
		}

		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			return;
		}

		Node* temp = head;
		while (temp->next != nullptr) 
		{
			temp = temp->next;
		}
		temp->prev->next = nullptr;
		delete temp;
	}
	void delete_at_position(int position)
	{
		if (head == nullptr) return;

		if (position == 0) 
		{
			delete_first();
			return;
		}

		Node* temp = head;
		int index = 0;
		if (temp != NULL && index < position)
		{
			temp = temp->next;
			index++;
		}

		if (temp == NULL)
		{
			cout << "Position out of range" << endl;
			return;
		}

		if (temp->next != NULL)
		{
			temp->next->prev = temp->prev;
		}
		if (temp->prev != NULL)
		{
			temp->prev->next = temp->next;
		}

		delete temp;
	}
	int count()
	{
		int counter = 0;
		Node* temp = head;
		while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}
		return counter;
	}
	bool is_found(int key)
	{
		bool found = false;
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->data == key)
			{
				found = true;
				break;
			}
			temp = temp->next;
		}
		return found;
	}
};


int main()
{
	DoublyLinkedList lst;
	//--------------------------------------
	if (lst.is_empty())
	{
		cout << "The list is empty" << endl;
	}
	else
	{
		cout << "The list not empty" << endl;
	}
	//--------------------------------------
	int item;
	cout << "Enter item to append" << endl;
	cin >> item;
	lst.append(item);
	//--------------------------------------
	lst.traverseForward();
	//--------------------------------------
	lst.traverseBackward();
	//--------------------------------------
	cout << "Enter item to insert" << endl;
	cin >> item;
	lst.insert_first(item);
	lst.traverseForward();
	//--------------------------------------
	cout << "Enter item to insert" << endl;
	cin >> item;
	int po;
	cout << "Enter position" << endl;
	cin >> po;
	lst.insert_at_position(item, po);
	lst.traverseForward();
	//--------------------------------------
	lst.delete_first();
	lst.traverseForward();
	//--------------------------------------
	lst.delete_end();
	lst.traverseForward();
	//--------------------------------------
	cout << "Enter position to delete" << endl;
	cin >> po;
	lst.delete_at_position(po);
	lst.traverseForward();
	//--------------------------------------
	lst.traverseForward();
	cout << "The list conains " << lst.count() << endl;
	//--------------------------------------
	cout << "Enter item to search in the list" << endl;
	cin >> item;
	if (lst.is_found(item))
	{
		cout << "Item found" << endl;
	}
	else
	{
		cout << "Item not found" << endl;
	}
	lst.traverseForward();
	//--------------------------------------

	return 0;
}