#pragma once

// Przemys�aw Skoneczny 234946

struct Node
{
	Node *next;
	Node *prev;
	int value;
};

class List
{

	Node *head;
	Node *tail;
	int size = 0;

public:
	List();
	~List();
	void push_front(int); //dodaje nowy element na pocz�tek listy
	void push_back(int); //dodaje nowy element na koniec listy
	void insert(Node*, int); //dodaje nowy element za podanym elementem
	void pop_front();	//usuwa element z pocz�tku listy
	void pop_back(); //usuwa element z ko�ca listy
	void remove(Node*); //usuwa wybrany element
	int getSize(); //zwraca rozmiar struktury
	bool isEmpty(); //sprawdza czy struktura jest pusta
	void print(); //wypisuje strukture na ekran
	Node* getHead(); //zwraaca wska�nik na g�ow�
	Node* getTail(); //zwraca wska�nk na ogon
	void save(); //zapisuje liste do pliku
	void load(); //wszytuje liste z pliku
	List& operator=(const List &obj); //operator przypisania
	void clear();
	int find_v(int); //wyszukiwanie zwraca nr elementu
};

