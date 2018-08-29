#include "stdafx.h"
#include "Array.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

// Przemys³aw Skoneczny 234946

using namespace std;

Array::Array()
{
	tab = new int[0];
	size = 0;
}


Array::~Array()
{
	delete[]tab;
}


void Array::add(int liczba, int pozycja)
{
	int s = getSize();
	int *tabb = new int[size + 1];

	for (int i = 0; i < pozycja; i++)
		tabb[i] = tab[i];

	tabb[pozycja] = liczba;

	for (int i = pozycja; i < size; i++)
		tabb[i + 1] = tab[i];
	
	delete[] tab;
	tab = tabb;
	size++;
	setSize(s + 1);
}

void Array::add_front(int liczba)
{
	add(liczba, 0);
}

void Array::add_back(int liczba)
{
	add(liczba, size);
}

void Array::remove(int pozycja)
{
	int *tabb = new int[size - 1];

	for (int i = 0; i < pozycja; i++)
		tabb[i] = tab[i];

	for (int i = pozycja; i < size; i++)
		tabb[i] = tab[i + 1];

	delete[]tab;
	tab = tabb;
	size--;
}

void Array::remove_front()
{
	remove(0);
}

void Array::remove_back()
{
	remove(size - 1);
}

int Array::getSize()
{
	return size;
}

void Array::setSize(int a)
{
	size = a;
}

bool Array::isEmpty()
{
	if (size == 0)
		return true;
	else 
		return false;
}

void Array::print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << i << " " << tab[i] << std::endl;
	}
}

void Array::save()
{
	fstream plik;
	plik.open("tablica.txt", ios::out);
	
	if (!plik.good())
		cout << "Nie mozna otworzyc pliku tablicy!";
	else
	{
		plik << size << endl;

		for (int i = 0; i < size; i++)
			plik << tab[i] << endl;

		cout << "Zapisano tablice!" << endl;
	}
	plik.close();
}

void Array::load()
{
	fstream plik;
	plik.open("tablica.txt", ios::in);
	if (!plik.good())
		cout << "Nie mozna otworzyc pliku!";
	else
	{
		string linia;

		getline(plik, linia);
		size = atoi(linia.c_str());
		int *tabb = new int[size];
		int i = 0;
		while (!plik.eof())
		{
			getline(plik, linia);
			if (linia != "\0" || linia != "")
				tabb[i] = atoi(linia.c_str());
			i++;
		}
		delete[]tab;
		tab = tabb;
		cout << "Pomyslnie wczytano " << getSize() << " elementow tablicy!" << endl;
	}


	plik.close();
}

Array & Array::operator=(const Array & obj)
{
	size = obj.size;
	tab = new int[size];
	
	for (int i = 0; i < size; i++)
		tab[i] = obj.tab[i];

	return *this;
}

void Array::clear()
{
	size = 0;
	delete[]tab;
	tab = NULL;
}


int Array::find_v(int x)
{
	for (int i = 0; i < size; i++)
	{
		if (tab[i] == x)
			return i;
	}
	cout << "Nie ma takiego elementu!" << endl;
	return -1;
}
