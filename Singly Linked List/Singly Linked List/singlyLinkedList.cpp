#include<iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

class Linkedlist
{
public:
	Node* head;

	Linkedlist()
	{
		head = NULL;
	}
	bool is_empty()
	{
		return (head == NULL);
	}
	void insert_first(int newValue)
	{
		Node* newNode = new Node();
		newNode->data = newValue;

		if (is_empty())
		{
			newNode->next = NULL;
			head = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
	}
	void display()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "\t";
			temp = temp->next;
		}
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
	void insert_before(int item, int newValue)
	{
		if (is_empty())
		{
			insert_first(newValue);
			return;
		}

		if (is_found(item))
		{
			Node* newNode = new Node();
			newNode->data = newValue;
			Node* temp = head;

			while (temp->next != NULL && temp->next->data != item)
			{
				temp = temp->next;
			}

			newNode->next = temp->next;
			temp->next = newNode;
		}
		else
		{
			cout << "Item not found" << endl;
		}
	}
	void append(int newValue)
	{
		if (is_empty())
		{
			insert_first(newValue);
			//return;
		}
		else
		{
			Node* newNode = new Node();
			newNode->data = newValue;
			Node* temp = head;

			while (temp->next != NULL)
			{
				temp = temp->next;
			}

			newNode->next = NULL;
			temp->next = newNode;
		}


	}
	void Delete(int item)
	{
		if (!is_found(item))
		{
			cout << "Item not found" << endl;
			return;
		}
		
		if (is_empty())
		{
			cout << "List is empty, no items to delet" << endl;
		}
		else if (head->data == item)
		{
			Node* delptr = head;
			head = head->next;
			delete delptr;
		}
		else
		{
			Node* pre = NULL;
			Node* delptr = head;
			while (delptr->data != item)
			{
				pre = delptr;
				delptr = delptr->next;
			}
			pre->next = delptr->next;
			delete delptr;
		}



	}
};


int main()
{
	Linkedlist lst;
	//-----------------------------------------
	if (lst.is_empty())
	{
		cout << "The list is empty" << endl;
	}
	else
	{
		cout << "The list not empty" << endl;
		cout << "The list conains " << lst.count() << endl;
	}
	//-----------------------------------------
	int item;
	cout << "Enter item to insert in the list" << endl;
	cin >> item;
	lst.insert_first(item);
	lst.display();
	cout << "The list conains " << lst.count() << endl;
	//-----------------------------------------
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
	//-----------------------------------------
	cout << "Enter item" << endl;
	cin >> item;
	int newValue;
	cout << "Enter new item to insert in the list" << endl;
	cin >> newValue;
	lst.insert_before(item, newValue);
	lst.display();
	cout << "The list conains " << lst.count() << endl;
	//-----------------------------------------
	cout << "Enter new item to append in the list" << endl;
	cin >> newValue;
	lst.append(newValue);
	lst.display();
	cout << "The list conains " << lst.count() << endl;
	//-----------------------------------------
	cout << "Enter item to deleted" << endl;
	cin >> item;
	lst.Delete(item);
	lst.display();
	cout << "The list conains " << lst.count() << endl;
	//-----------------------------------------

	return 0;
}