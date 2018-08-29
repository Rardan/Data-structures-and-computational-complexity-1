#include "stdafx.h"
#include "BHeap.h"
#include <iostream>
#include <fstream>
#include <string>

// Przemys³aw Skoneczny 234946

using namespace std;

BHeap::BHeap()
{
	tab = new int[0];
	size = 0;
}


BHeap::~BHeap()
{
	delete[]tab;
}


void BHeap::push(int liczba)
{
	int *tabb = new int[size + 1];

	for (int i = 0; i < size; i++)
		tabb[i] = tab[i];

	delete[]tab;
	tab = tabb;

	int i = size++;
	int j = (i - 1) / 2;

	while (i && tab[j] > liczba)
	{
		tab[i] = tab[j];
		i = j;
		j = (i - 1) / 2;
	}

	tab[i] = liczba;
	
}

void BHeap::pop()
{
	int i, j, value;

	if (size--)
	{
		value = tab[size];

		i = 0;
		j = 1;

		while (j < size)
		{
			if (j + 1 < size && tab[j + 1] < tab[j])
				j++;

			if (value <= tab[j])
				break;

			tab[i] = tab[j];
			i = j;
			j = 2 * j + 1;
		}

		tab[i] = value;
	}
	
	int *tabb = new int[size];

	for (int i = 0; i < size; i++)
		tabb[i] = tab[i];

	delete[]tab;
	tab = tabb;
}

void BHeap::print_line()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << i << " " << tab[i] << std::endl;
	}

}

void printSpace(int count)
{
	for (int x = 0; x<count; x++)
	{
		cout << "-";
	}
}

void BHeap::print()
{
	int height = ceil(log(size) + 1);
	int width = pow(2, height)*height;
	int i = 0;
	for (int x = 0; x <= height; x++)
	{
		for (int z = 0; z < pow(2, x); z++)
		{
			int digitWidth = 1;
			if (tab[i] != 0)
				digitWidth = floor(log10(abs(tab[i]))) + 1;
			printSpace(width / (pow(2, x)) - digitWidth);
			if (i < size)
				cout << tab[i++];
			else cout << "-";
			printSpace(width / (pow(2, x)));
		}
		cout << endl;
	}

}


void BHeap::save()
{
	fstream plik;
	plik.open("kopiec.txt", ios::out);

	if (!plik.good())
		cout << "Nie mozna otworzyc pliku kopca!" << endl;
	else
	{
		for (int i = 0; i < size; i++)
			plik << tab[i] << endl;

		cout << "Zapisano kopiec!" << endl;
	}
	plik.close();
}

void BHeap::load()
{
	fstream plik;
	plik.open("kopiec.txt", ios::in);
	if (!plik.good())
		cout << "Nie mozna otworzyc pliku!";
	else
	{
		string linia;

		while (!plik.eof())
		{
			getline(plik, linia);
			if (linia != "\0" || linia != "")
				push(atoi(linia.c_str()));

		}
		cout << "Pomyslnie wczytano " << size << " elementow kopca!" << endl;
	}

	plik.close();
}

BHeap & BHeap::operator=(const BHeap & obj)
{
	size = obj.size;
	tab = new int[size];

	for (int i = 0; i < size; i++)
		tab[i] = obj.tab[i];

	return *this;
}

void BHeap::clear()
{
	size = 0;
	delete[]tab;
	tab = NULL;
}

int BHeap::find_v(int x)
{
	for (int i = 0; i < size; i++)
	{
		if (tab[i] == x)
			return i;
	}
	cout << "Nie ma takiego elementu!" << endl;
	return -1;
}

int BHeap::getSize()
{
	return size;
}
