#include <iostream>
#include <stdexcept>
#include <cstring>

template <typename T>
struct Node {
	T val;
	Node<T>* ptr;

	Node(T val, Node<T>* ptr) {
		this->val = val;
		this->ptr = ptr;
	}
};

template <typename T>
struct LinkedList {
	Node<T>* head;
	int size = 0;

	void add(T val)
	{
		head = new Node<T>(val, head);
		size++;
	}

	void add(T val, unsigned index)
	{
		if (index > size)
		{
			throw std::invalid_argument("Index " + index + " is invalid");
		}
		else if (index == 0)
		{
			add(val);
		}
		else
		{
			Node<T>* temp = head;
			for (unsigned i = 1; i < index; i++)
			{
				temp = temp->ptr;
			}
			temp->ptr = new Node<T>(val, temp);

			size++;
		}
	}

	void remove(unsigned index)
	{
		if (index >= size)
		{
			throw std::invalid_argument("Index " + index + " is invalid");
		}
		else if (index == 0)
		{
			T v = head->val;
			head = head->ptr;
			return v;
		}
		else
		{
			Node<T>* temp = head;
			for (unsigned i = 1; i < size; i++)
			{
				temp = temp->ptr;
			}
			T v = temp->ptr->val;
			Node<T>* temp2 = temp->ptr->ptr;
			delete(temp->ptr);
			temp->ptr = temp2;

			return v;
		}
	}

	void print()
	{
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			std::cout << temp->val << ' ';
			temp = temp->ptr;
		}
	}
};

int main()
{
	struct LinkedList<int> lst;

	lst.add(2);
	lst.add(3);

	lst.remove(0);

	lst.print();

	return 0;
}