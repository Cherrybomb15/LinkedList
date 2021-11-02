#include <iostream>
#include <stdexcept>
#include <string>

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
	Node<T>* head = nullptr;
	unsigned size = 0;

	void add(T val)
	{
		head = new Node<T>(val, head);
		size++;
	}

	void add(T val, unsigned index)
	{
		if (index > size)
		{
			//"Index " + index + " is invalid"
			throw std::invalid_argument("Error");
		}
		else if (index == 0)
		{
			this->add(val);
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

	T remove(unsigned index)
	{
		if (index >= size)
		{
			//"Index " + index + " is invalid"
			throw std::invalid_argument("Error");
		}
		else if (index == 0)
		{
			T v = head->val;
			head = head->ptr;
			size--;
			return v;
		}
		else
		{
			Node<T>* temp = head;
			for (int i = 1; i < size; i++)
			{
				temp = temp->ptr;
			}
			T v = temp->ptr->val;
			Node<T>* temp2 = temp->ptr->ptr;
			delete(temp->ptr);
			temp->ptr = temp2;

			size--;
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
	lst.add(1);

	lst.print();
	std::cout << '\n';
	lst.remove(0);
	lst.add(0, 1);

	lst.print();

	return 0;
}