#include <iostream>

using namespace std;



class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class HashTable
{
private:
    int size;
    Node** table;

    int hashFunction(int key) 
    {
        return key % size;
    }

public:
    HashTable(int s)
    {
        size = s;
        table = new Node * [size];
        for (int i = 0; i < size; i++)
        {
            table[i] = NULL;
        }
    }
    void insert(int key)
    {
        int index = hashFunction(key);
        Node* newNode = new Node(key);

        if (table[index] == NULL)
        {
            table[index] = newNode;
        }
        else
        {
            newNode->next = table[index];
            table[index] = newNode;
        }
    }
    bool search(int key)
    {
        int index = hashFunction(key);
        Node* temp = table[index];
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << " --> ";
            Node* temp = table[i];
            while (temp != NULL)
            {
                cout << temp->data << "\t";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    void remove(int key)
    {
        int index = hashFunction(key);
        Node* temp = table[index];
        Node* prev = NULL;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                if (prev == NULL)
                {
                    table[index] = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                delete temp;
                cout << key << "Removed." << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Element Not Found." << endl;
    }
};


int main() {
    HashTable ht(7);

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(17);
    ht.display();

    cout << (ht.search(20) ? "Found" : "Not Found");
    cout << (ht.search(99) ? "Found" : "Not Found");
    ht.display();

    ht.remove(15);
    ht.display();

    ht.remove(99);
    ht.display();

    return 0;
}