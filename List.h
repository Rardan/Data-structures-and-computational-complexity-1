#pragma once

// Przemys³aw Skoneczny 234946

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
	void push_front(int); //dodaje nowy element na pocz¹tek listy
	void push_back(int); //dodaje nowy element na koniec listy
	void insert(Node*, int); //dodaje nowy element za podanym elementem
	void pop_front();	//usuwa element z pocz¹tku listy
	void pop_back(); //usuwa element z koñca listy
	void remove(Node*); //usuwa wybrany element
	int getSize(); //zwraca rozmiar struktury
	bool isEmpty(); //sprawdza czy struktura jest pusta
	void print(); //wypisuje strukture na ekran
	Node* getHead(); //zwraaca wskaŸnik na g³owê
	Node* getTail(); //zwraca wskaŸnk na ogon
	void save(); //zapisuje liste do pliku
	void load(); //wszytuje liste z pliku
	List& operator=(const List &obj); //operator przypisania
	void clear();
	int find_v(int); //wyszukiwanie zwraca nr elementu
};

