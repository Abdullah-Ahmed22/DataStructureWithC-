#include<iostream>
#include<string>

using namespace std;

class Array {
private:
	int size;
	int length;
	int* items;
	
public:
	Array(int array_size) 
	{
		size = array_size;
		length = 0;
		items = new int[array_size];
	}
	void File() 
	{
		int num_of_size;

		cout << "How many items you want to fill ? \n";
		cin >> num_of_size;

		if (num_of_size > size) 
		{
			cout << "You cannot exceed the array size\n";
		}
		else
		{
			for (int i = 0; i < num_of_size; i++)
			{
				cout << "Enter item num: " << i << endl;
				cin >> items[i];
				length++;
			}
		}
	}
	void Display()
	{
		cout << "Display array items" << endl;
		for (int i = 0; i < length; i++)
		{
			cout << items[i] << "\t";
		}
		cout << endl;
	}
	int get_size()
	{
		return size;
	}
	int get_length()
	{
		return length;
	}
	int Search(int key)
	{
		int index = -1;

		for (int i = 0; i < length; i++)
		{
			if (items[i] == key)
			{
				index = i;
				break;
			}
		}
		return index;
	}
	void Append(int newItem)
	{
		if (length < size)
		{
			items[length] = newItem;
			length++;
		}
		else
		{
			cout << "Array is full" << endl;
		}
	}
	void Insert(int index, int newItem)
	{
		if (index >= 0 && index < size)
		{
			for (int i = length; i > index; i--)
			{
				items[i] = items[i - 1];
			}
			items[index] = newItem;
			length++;
		}
		else
		{
			cout << "Index out of range" << endl;
		}
	}
	void Delet(int index)
	{
		if (index >= 0 && index < size)
		{
			for (int i = index; i < length - 1; i++)
			{
				items[i] = items[i + 1];
			}
			length--;
		}
		else
		{
			cout << "Index out of range" << endl;
		}
	}
	void Enlarge(int newSize)
	{
		if (newSize <= size)
		{
			cout << "New size must be larger than old size" << endl;
			return;
		}
		size = newSize;
		int* old = items;
		items = new int[size];
		for (int i = 0; i < length; i++)
		{
			items[i] = old[i];
		}
		delete[] old;
	}
	void Merge(Array other)
	{
		int newSize = size + other.get_size();
		size = newSize;
		int* old = items;
		items = new int[newSize];
		int i;
		for (i = 0; i < length; i++)
		{
			items[i] = old[i];
		}
		delete[] old;
		int j = i;
		for (int i = 0; i < other.get_length(); i++)
		{
			items[j++] = other.items[i];
			length++;
		}
	}

};


int main() {
	cout << "Hello this is array ADT" << endl;
	// ----------------------------------------------
	int arrsize;
	cout << "Enter size of array" << endl;
	cin >> arrsize;
	Array arr(arrsize);
	// ----------------------------------------------
	arr.File();
	// ----------------------------------------------
	arr.Display();
	// ----------------------------------------------
	cout << "Array size = " << arr.get_size() << endl;
	// ----------------------------------------------
	cout << "Array length = " << arr.get_length() << endl;
	// ----------------------------------------------
	int value;
	cout << "Enter the value to search" << endl;
	cin >> value;
	int index = arr.Search(value);
	if (index == -1)
		cout << "Index of value not found" << endl;
	else
		cout << "Index of value = " << index << endl;
	arr.Display();
	// ----------------------------------------------
	int newItem;
	cout << "Enter the Value of new item" << endl;
	cin >> newItem;
	arr.Append(newItem);
	arr.Display();
	cout << "Array length = " << arr.get_length() << endl;
	// ----------------------------------------------
	cout << "Enter index" << endl;
	cin >> index;
	cout << "Enter the Value of new item" << endl;
	cin >> newItem;
	arr.Insert(index, newItem);
	arr.Display();
	cout << "Array length = " << arr.get_length() << endl;
	// ----------------------------------------------
	cout << "Enter index to delet" << endl;
	cin >> index;
	arr.Delet(index);
	arr.Display();
	cout << "Array length = " << arr.get_length() << endl;
	// ----------------------------------------------
	int newSize;
	cout << "Enter new size" << endl;
	cin >> newSize;
	arr.Enlarge(newSize);
	arr.Display();
	cout << "Array size = " << arr.get_size() << endl;
	cout << "Array length = " << arr.get_length() << endl;
	// ----------------------------------------------
	Array other(3);
	arr.Merge(other);
	arr.Display();
	cout << "Array size = " << arr.get_size() << endl;
	cout << "Array length = " << arr.get_length() << endl;

	return 0;
}