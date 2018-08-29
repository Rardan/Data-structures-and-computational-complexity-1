#pragma once

// Przemys�aw Skoneczny 234946

class Array
{
	int size;
	int *tab;

public:
	
	Array();
	~Array();
	void add(int, int = 0); //dodaje liczb� do tablicy
	void add_front(int); //dodaje liczb� na pocz�tek tablicy
	void add_back(int); //dodaje liczb� na koniec tablicy
	void remove(int); // usuwa liczb� z pozycji x z tablicy
	void remove_front(); // usuwa liczb� pocz�tku tablicy
	void remove_back(); // usuwa liczb� z ko�ca tablicy
	int getSize(); // zwrca rozmiar tablicy
	void setSize(int); //ustawia rozmiar tablicy
	bool isEmpty(); //sprwdza, czy talbica jest pusta
	void print(); //wypisuje tablice na ekran
	void save(); //zapisuje tablice do pliku
	void load(); //wszytuje teblice z pliku
	Array& operator=(const Array &obj); //operator przypisania
	void clear();
	int find_v(int); //wyszukiwane zwraca indeks el
	
};

