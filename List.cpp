#include "stdafx.h"
#include "List.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

// Przemys³aw Skoneczny 234946

using namespace std;

List::List()
{
	head = tail = NULL;
	size = 0;
}


List::~List()
{
	Node *n;

	while (head)
	{
		n = head->next;
		delete head;
		head = n;
	}
}

void List::push_front(int val)
{
	Node *n = new Node;
	n->value = val;
	n->next = head;
	n->prev = NULL;

	if (head)
		head->prev = n;
	
	head = n;
	
	if (!tail)
		tail = head;
	
	size++;

}

void List::push_back(int val)
{
	Node *n = new Node;

	n->value = val;
	n->next = NULL;
	n->prev = tail;
	tail = n;

	if (n->prev)
		n->prev->next = n;
	else
		head = n;

	size++;
}

void List::insert(Node *n1, int val)
{	
	if (n1 == tail)
		push_back(val);
	else
	{
		Node *n2 = new Node;
		n2->value = val;
		n2->next = n1->next;
		n2->prev = n1;
		n1->next->prev = n2;
		n1->next = n2;
		size++;
	}
}

void List::pop_front()
{
	if (size)
		remove(head);
}

void List::pop_back()
{
	if (size)
		remove(tail);
}

int List::getSize()
{
	return size;
}

bool List::isEmpty()
{
	if (size = 0)
		return true;
	else
		return false;
}

void List::remove(Node *n)
{
	if (n->prev)
		n->prev->next = n->next;
	else
		head = n->next;

	if (n->next)
		n->next->prev = n->prev;
	else
		tail = n->prev;

	size--;
}

void List::print()
{
	Node *n = head;

	while (n)
	{
		std::cout << n->value << " ";
		n = n->next;
	}
}

Node * List::getHead()
{
	return head;
}

Node * List::getTail()
{
	return tail;
}

void List::save()
{
	Node *n = head;
	fstream plik;
	plik.open("lista.txt", ios::out);

	if (!plik.good())
		cout << "Nie mozna otworzyc pliku listy!";
	else
	{
//		plik << size << endl;

		while (n)
		{
			plik << n->value << endl;
			n = n->next;
		}

		cout << "Zapisano liste!" << endl;
	}
	plik.close();
}

void List::load()
{
	Node *n = head;
	fstream plik;
	plik.open("lista.txt", ios::in);

	if (!plik.good())
		cout << "Nie mozna otworzyc pliku listy!";
	else
	{
		string linia;
		int val;
	//	getline(plik, linia);
	//	size = atoi(linia.c_str());

		while (!plik.eof())
		{
			getline(plik, linia);
			if (linia != "\0" || linia != "")
			{
				val = atoi(linia.c_str());
				push_back(val);
			}
			
		}
		cout << "Pomyslnie wczytano " << getSize() << " elementow listy!" << endl;
	}
	plik.close();
}

List & List::operator=(const List & obj)
{
	Node *n = obj.head;

	while (n)
	{
		push_back(n->value);
		n = n->next;
	}

	return *this;
}

void List::clear()
{
	while (size != 0)
		pop_back();
}

int List::find_v(int v)
{
	Node *n = head;
	int i = 0;
	while (n)
	{
		if (v == n->value)
		{
			return i;
		}
		else
		{
			n = n->next;
			i++;
		}
	}
	cout << "Nie ma takiego elementu!" << endl;
	return -1;
}
