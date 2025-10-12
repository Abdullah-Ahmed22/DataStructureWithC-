#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class CircularLinkedList
{
public:
    Node* head;

    CircularLinkedList()
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
            head = newNode;
            newNode->next = head; 
        }
        else
        {
            Node* temp = head;
            while (temp->next != head) 
                temp = temp->next;

            newNode->next = head;
            head = newNode;
            temp->next = head; 
        }
    }
    void display()
    {
        if (is_empty())
        {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        do
        {
            cout << temp->data << "\t";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    int count()
    {
        if (is_empty()) return 0;

        int counter = 0;
        Node* temp = head;
        do
        {
            counter++;
            temp = temp->next;
        } while (temp != head);

        return counter;
    }
    bool is_found(int key)
    {
        if (is_empty()) return false;

        Node* temp = head;
        do
        {
            if (temp->data == key)
                return true;
            temp = temp->next;
        } while (temp != head);

        return false;
    }
    void insert_before(int item, int newValue)
    {
        if (is_empty())
        {
            insert_first(newValue);
            return;
        }

        if (!is_found(item))
        {
            cout << "Item not found" << endl;
            return;
        }

        if (head->data == item)
        {
            Node* newNode = new Node();
            newNode->data = newValue;

            Node* last = head;
            while (last->next != head)
                last = last->next;

            newNode->next = head;
            head = newNode;
            last->next = head; 
        }
        else
        {
            Node* newNode = new Node();
            newNode->data = newValue;

            Node* temp = head;
            while (temp->next->data != item)  
            {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void append(int newValue)
    {
        if (is_empty())
        {
            insert_first(newValue);
        }
        else
        {
            Node* newNode = new Node();
            newNode->data = newValue;
            Node* temp = head;

            while (temp->next != head)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }
    }
    void Delete(int item)
    {
        if (is_empty())
        {
            cout << "List is empty, no items to delete" << endl;
            return;
        }

        if (!is_found(item))
        {
            cout << "Item not found" << endl;
            return;
        }

        if (head->data == item)
        {
            if (head->next == head)
            {
                delete head;
                head = NULL;
                return;
            }

            Node* last = head;
            while (last->next != head)  
                last = last->next;

            Node* delptr = head;
            head = head->next;       
            last->next = head;       
            delete delptr;
        }
        else
        {
            
            Node* prev = head;
            Node* delptr = head->next;

            while (delptr->data != item)  
            {
                prev = delptr;
                delptr = delptr->next;
            }

            prev->next = delptr->next;
            delete delptr;
        }
    }
};

int main()
{
    CircularLinkedList lst;

    //-----------------------------------------
    if (lst.is_empty())
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        cout << "The list not empty" << endl;
        cout << "The list contains " << lst.count() << endl;
    }

    //-----------------------------------------
    int item;
    cout << "Enter item to insert in the list" << endl;
    cin >> item;
    lst.insert_first(item);
    lst.display();
    cout << "The list contains " << lst.count() << endl;

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
    cout << "Enter new item to insert before it in the list" << endl;
    cin >> newValue;
    lst.insert_before(item, newValue);
    lst.display();
    cout << "The list contains " << lst.count() << endl;

    //-----------------------------------------
    cout << "Enter new item to append in the list" << endl;
    cin >> newValue;
    lst.append(newValue);
    lst.display();
    cout << "The list contains " << lst.count() << endl;

    //-----------------------------------------
    cout << "Enter item to delete" << endl;
    cin >> item;
    lst.Delete(item);
    lst.display();
    cout << "The list contains " << lst.count() << endl;

    //-----------------------------------------
    return 0;
}