#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <set>
using namespace std;

class Node
{
public:
	int value;
	Node* next;
	Node(int vl)
	{
		value = vl;
		next = nullptr;
	}
};
class List
{
public:
	Node* head;
	int number;
	List() { head = nullptr; }
	void insert(int value)
	{
		Node* newNode = new Node(value);
		if (head == nullptr)
		{
			head = newNode;
			head->next = head;
		}
		else
		{
			Node* current = head;
			while (current->next != head)
			{
				current = current->next;
			}
			current->next = newNode;
			newNode->next = head;
		}
		//cout << "added" << endl;
		++number;
	}
	void remove(int vl)
	{
		if (head == nullptr) return;
		Node* current = head;
		Node* prev = nullptr;
		if (head->value == vl && head->next == head)
		{
			delete head;
			head = nullptr;
			--number;
			return;
		}
		do
		{
			if (current->value == vl)
			{
				if (current == head)
				{
					Node* last = head;
					while (last->next != head)
					{
						last = last->next;
					}
					head = head->next;
					last->next = head;
					delete current;
					--number;
					return;
				}
				else
				{
					prev->next = current->next;
					delete current;
					--number;
					return;
				}
			}
			prev = current;
			current = current->next;
		} while (current != head);
	}
	void display()
	{
		if (head == nullptr) return;
		Node* current = head;
		cout << current->value << endl;
		do
		{
			current = current->next;
			cout << current->value << endl;
		}
		while (current->next != head);
	}
	~List()
	{
		Node* current = head;
		while (current != head)
		{
			Node* temp = current->next;
			delete current;
			current = temp;
		}
	}
};

int main()
{
	int number = 0;
	cin >> number;
	List* people = new List();
	for (int i = 1; i <= number; ++i)
	{
		people->insert(i);
	}
	//people->remove(3);
	//people->display();
	Node* current = people->head;
	while (people->number>1)
	{
		Node* next = current->next;
		people->remove(next->value);
		current = current->next;
	}
	cout << people->head->value;
	delete people;
	return 0;
}

