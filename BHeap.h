#pragma once
// Przemys�aw Skoneczny 234946
class BHeap
{
	int *tab;
	int size;
public:
	BHeap();
	~BHeap();
	void push(int); //dodaje element do kopca
	void pop(); //usuwa korze� z kopca
	void print_line(); //wypisuje kopiec w jedej lini (zgodnie z zapisem do tabeli)
	void print(); //wy�wietla strukture na ekranie
	void save(); //zapisuje kopiec do pliku
	void load(); //wczytuje kopiec z pliku
	BHeap& operator=(const BHeap &obj); //operator przypisania
	void clear();
	int find_v(int); //wyszukiwanie zwraca indeks indeks
	int getSize(); //zwraca rozmiar struktury
};

