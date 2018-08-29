#include "stdafx.h"
#include "Menu.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <fstream>

// Przemys³aw Skoneczny 234946

using namespace std;

double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}
double GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}

Menu::Menu()
{
	Array tablica;
	List lista;
	BHeap kopiec;

	while (1)
	{
		cout << "Menu" << endl;
		cout << "--------------" << endl;
		cout << "1. Tablica dynamiczna" << endl;
		cout << "2. Lista dwukierunkowa" << endl;
		cout << "3. Kopiec binarny" << endl;
	//	cout << "4. Drzewo czerwono-czarne" << endl;
		cout << "4. Wczytaj dane" << endl;
		cout << "5. Zapisz dane" << endl;
		cout << "6. Autor" << endl;
		cout << "Wybor: ";

		int n;
		cin >> n;
		switch (n)
		{
		case 1: 
			menu_array(tablica);
			break;
		case 2:
			menu_list(lista);
			break;
		case 3:
			menu_heap(kopiec);
			break;
		case 4:
			system("cls");
			tablica.load();
			lista.load();
			kopiec.load();
			break;
		case 5:
			system("cls");
			tablica.save();
			lista.save();
			kopiec.save();
			break;
		case 6:
			system("cls");
			cout << "Przemyslaw Skoneczny" << endl;
			cout << "Indeks: 234946" << endl;
			break;
		default:
			system("cls");
			cout << "Podano bledna wartosc!" << endl;
			break;
		}
	}
}

Menu::~Menu()
{
}


void Menu::menu_array(Array &tablica)
{
	srand(time(NULL));
	int m, i, j, k;
	Array tab1, tab2, tab3;
/*	double a1_f[100], a1_b[100], a1_m[100]; //a - dodanie
	double a2_f[100], a2_b[100], a2_m[100]; //_f - front
	double a4_f[100], a4_b[100], a4_m[100]; //_b - back
	double a8_f[100], a8_b[100], a8_m[100]; //_m - inside
	
*/	
	double t[100];
	
/*	double r1_f[100], r1_b[100], r1_m[100]; //r - usuniêcie
	double r2_f[100], r2_b[100], r2_m[100]; //_f - front
	double r4_f[100], r4_b[100], r4_m[100]; //_b - back
	double r8_f[100], r8_b[100], r8_m[100]; //_m - inside

*/
	fstream plik;

	system("cls");
	cout << "1. Dodaj element na pocz¹tek" << endl;
	cout << "2. Dodaj element na koniec" << endl;
	cout << "3. Dodaj element na pozycje x" << endl;
	cout << "4. Usun pierwszy element" << endl;
	cout << "5. Usun ostatni element" << endl;
	cout << "6. Usun element z pozycji x" << endl;
	cout << "7. Wyszukiwanie" << endl;
	cout << "8. Wyswietl" << endl;
	cout << "-------------" << endl;
	cout << "9. Eksperyment" << endl;
	
/*	cout << "8. 1000 losowych elementow i dodaj 1 element (x100)(RAND_MAX)" << endl;
	cout << "9. 2000 losowych elementow i dodaj 1 element (x100)(RAND_MAX)" << endl;
	cout << "10. 4000 losowych elementow i dodaj 1 element (x100)(RAND_MAX)" << endl;
	cout << "11. 8000 losowych elementow i dodaj 1 element (x100)(RAND_MAX)" << endl;
	cout << "12. 1000 losowych elementow i dodaj 1 element (x100)(RAND_MAX/4)" << endl;
	cout << "13. 2000 losowych elementow i dodaj 1 element (x100)(RAND_MAX/4)" << endl;
	cout << "14. 4000 losowych elementow i dodaj 1 element (x100)(RAND_MAX/4)" << endl;
	cout << "15. 8000 losowych elementow i dodaj 1 element (x100)(RAND_MAX/4)" << endl;

	cout << "16. 1000 losowych elementow i usun 1 element (x100)(RAND_MAX)" << endl;
	cout << "17. 2000 losowych elementow i usun 1 element (x100)(RAND_MAX)" << endl;
	cout << "18. 4000 losowych elementow i usun 1 element (x100)(RAND_MAX)" << endl;
	cout << "19. 8000 losowych elementow i usun 1 element (x100)(RAND_MAX)" << endl;
	cout << "20. 1000 losowych elementow i usun 1 element (x100)(RAND_MAX/4)" << endl;
	cout << "21. 2000 losowych elementow i usun 1 element (x100)(RAND_MAX/4)" << endl;
	cout << "22. 4000 losowych elementow i usun 1 element (x100)(RAND_MAX/4)" << endl;
	cout << "23. 8000 losowych elementow i usun 1 element (x100)(RAND_MAX/4)" << endl;
	
	cout << "24. 1000 losowych elementow i znajdz element (x100)(RAND_MAX)" << endl;
	cout << "25. 2000 losowych elementow i znajdz element (x100)(RAND_MAX)" << endl;
	cout << "26. 4000 losowych elementow i znajdz element (x100)(RAND_MAX)" << endl;
	cout << "27. 8000 losowych elementow i znajdz element (x100)(RAND_MAX)" << endl;
	cout << "28. 1000 losowych elementow i znajdz element (x100)(RAND_MAX/4)" << endl;
	cout << "39. 2000 losowych elementow i znajdz element (x100)(RAND_MAX/4)" << endl;
	cout << "30. 4000 losowych elementow i znajdz element (x100)(RAND_MAX/4)" << endl;
	cout << "31. 8000 losowych elementow i znajdz element (x100)(RAND_MAX/4)" << endl;
	*/
	
	cout << "Wybor: ";
	cin >> m;
	switch (m)
	{
	case 1:
		cout << "Podaj liczbe: "; cin >> j;
		tablica.add_front(j);
		system("cls");
		break;
	case 2:
		cout << "Podaj liczbe: "; cin >> j;
		tablica.add_back(j);
		system("cls");
		break;
	case 3:
		if (tablica.isEmpty() == true)
		{
			cout << "Tablica pusta" << endl;
			cout << "Podaj liczbe: "; cin >> j;
			tablica.add(j);
			system("cls");
		}
		else
		{
			cout << "Podaj liczbe: "; cin >> j;
			cout << "Podaj pozycje: "; cin >> i;
			system("cls");
			if (i > tablica.getSize() + 1)
				cout << "Wartosc wykracza poza dopuszczany zakres." << endl;
			else
				tablica.add(j, i);
		}
		break;
	case 4:
		system("cls");
		if (tablica.getSize() == 0)
			cout << "Tablica pusta!" << endl;
		else
			tablica.remove_front();
		break;
	case 5:
		system("cls");
		if (tablica.getSize() == 0)
			cout << "Tablica pusta!" << endl;
		else
			tablica.remove_back();
		break;
	case 6:
		cout << "Podaj pozycje: "; cin >> i;
		system("cls");
		if (i > tablica.getSize() || i < 0)
			cout << "Wskazana komorka nie znajduje sie w tablicy!";
		else if (tablica.getSize() == 0)
			cout << "Tablica pusta!" << endl;
		else
			tablica.remove(i);
		break;
	case 7:
		system("cls");
		cout << "Podaj wartosc: "; cin >> j;
		if (tablica.getSize() == 0)
			cout << "Tablica pusta!" << endl;
		else
			cout << tablica.find_v(j) << endl;
		break;
	case 8:
		system("cls");
		tablica.print();
		break;
	case 9:
		plik.open("wyniki_tablica.txt", ios::out);

		for (int i = 0; i < 1000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			tablica.add(j);
			
		}
		
		system("cls");

		plik << "a1_f" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab1 = tablica;
			StartCounter();
			tab1.add_front(rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a1_b" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab2 = tablica;
			StartCounter();
			tab2.add_back(rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a1_m" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab3 = tablica;
			k = rand() % (1000 + 1);
			StartCounter();
			tab3.add(rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX, k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		tablica.clear();
		plik.close();
	//	break;

	case 10:
		plik.open("wyniki_tablica.txt", ios::out | ios::app);
		for (int i = 0; i < 2000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			tablica.add(j);
		}

		plik << "a2_f" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab1 = tablica;
			StartCounter();
			tab1.add_front(rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a2_b" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab2 = tablica;
			StartCounter();
			tab2.add_back(rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a2_m" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab3 = tablica;
			k = rand() % (2000 + 1);
			StartCounter();
			tab3.add(rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX, k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		tablica.clear();
		plik.close();
	//	break;

	case 11:
		plik.open("wyniki_tablica.txt", ios::out | ios::app);
		for (int i = 0; i < 4000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			tablica.add(j);
		}

		plik << "a4_f" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab1 = tablica;
			StartCounter();
			tab1.add_front(rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a4_b" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab2 = tablica;
			StartCounter();
			tab2.add_back(rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a4_m" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab3 = tablica;
			k = rand() % (4000 + 1);
			StartCounter();
			tab3.add(rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX, k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		tablica.clear();
		plik.close();
	//	break;

	case 12:
		plik.open("wyniki_tablica.txt", ios::out | ios::app);
		for (int i = 0; i < 8000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			tablica.add(j);
		}

		plik << "a8_f"<< endl;
		for (int i = 0; i < 100; i++)
		{
			tab1 = tablica;
			StartCounter();
			tab1.add_front(rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a8_b" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab2 = tablica;
			StartCounter();
			tab2.add_back(rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a8_m" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab3 = tablica;
			k = rand() % (8000 + 1);
			StartCounter();
			tab3.add(rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX, k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		tablica.clear();
		plik.close();
	//	break;
	case 13:
		plik.open("wyniki_tablica.txt", ios::out | ios::app);
		for (int i = 0; i < 1000; i++)
		{
			j = rand() % (RAND_MAX/4 + RAND_MAX/4 + 1) - RAND_MAX/4;
			tablica.add(j);
		}

		plik << "a1_f_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab1 = tablica;
			StartCounter();
			tab1.add_front(rand() % (RAND_MAX/4 + RAND_MAX/4 + 1) - RAND_MAX/4);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a1_b_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab2 = tablica;
			StartCounter();
			tab2.add_back(rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a1_m_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab3 = tablica;
			k = rand() % (1000 + 1);
			StartCounter();
			tab3.add(rand() % (RAND_MAX/4 + RAND_MAX/4 + 1) - RAND_MAX/4, k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		tablica.clear();
		plik.close();
	//	break;

	case 14:
		plik.open("wyniki_tablica.txt", ios::out | ios::app);
		for (int i = 0; i < 2000; i++)
		{
			j = rand() % (RAND_MAX/4 + RAND_MAX/4 + 1) - RAND_MAX/4;
			tablica.add(j);
		}

		plik << "a2_f_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab1 = tablica;
			StartCounter();
			tab1.add_front(rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a2_b_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab2 = tablica;
			StartCounter();
			tab2.add_back(rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a2_m_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab3 = tablica;
			k = rand() % (2000 + 1);
			StartCounter();
			tab3.add(rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4, k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		tablica.clear();
		plik.close();
	//	break;

	case 15:
		plik.open("wyniki_tablica.txt", ios::out | ios::app);
		for (int i = 0; i < 4000; i++)
		{
			j = rand() % (RAND_MAX/4 + RAND_MAX/4 + 1) - RAND_MAX/4;
			tablica.add(j);
		}

		plik << "a4_f_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab1 = tablica;
			StartCounter();
			tab1.add_front(rand() % (RAND_MAX/4 + RAND_MAX/4 + 1) - RAND_MAX/4);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a4_b_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab2 = tablica;
			StartCounter();
			tab2.add_back(rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a4_m_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab3 = tablica;
			k = rand() % (4000 + 1);
			StartCounter();
			tab3.add(rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4, k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		tablica.clear();
		plik.close();
	//	break;

	case 16:
		plik.open("wyniki_tablica.txt", ios::out | ios::app);
		for (int i = 0; i < 8000; i++)
		{
			j = rand() % (RAND_MAX/4 + RAND_MAX/4 + 1) - RAND_MAX/4;
			tablica.add(j);
		}

		plik << "a8_f_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab1 = tablica;
			StartCounter();
			tab1.add_front(rand() % (RAND_MAX/4 + RAND_MAX/4 + 1) - RAND_MAX/4);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a8_b_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab2 = tablica;
			StartCounter();
			tab2.add_back(rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a8_m_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab3 = tablica;
			k = rand() % (8000 + 1);
			StartCounter();
			tab3.add(rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4, k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		tablica.clear();
		plik.close();
	//	break;
	case 17:
		plik.open("wyniki_tablica.txt", ios::out | ios::app);
		for (int i = 0; i < 1000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			tablica.add(j);
		}

		plik << "r1_f" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab1 = tablica;
			StartCounter();
			tab1.remove(0);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r1_b" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab2 = tablica;
			StartCounter();
			tab2.remove(999);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r1_m" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab3 = tablica;
			k = rand() % (1000 + 1);
			StartCounter();
			tab3.remove(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		tablica.clear();
		plik.close();
	//	break;

	case 18:
		plik.open("wyniki_tablica.txt", ios::out | ios::app);
		for (int i = 0; i < 2000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			tablica.add(j);
		}

		plik << "r2_f" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab1 = tablica;
			StartCounter();
			tab1.remove(0);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r2_b" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab2 = tablica;
			StartCounter();
			tab2.remove(1999);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r2_m" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab3 = tablica;
			k = rand() % (2000 + 1);
			StartCounter();
			tab3.remove(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		tablica.clear();
		plik.close();
	//	break;

	case 19:
		plik.open("wyniki_tablica.txt", ios::out | ios::app);
		for (int i = 0; i < 4000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			tablica.add(j);
		}

		plik << "r4_f" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab1 = tablica;
			StartCounter();
			tab1.remove(0);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r4_b" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab2 = tablica;
			StartCounter();
			tab2.remove(3999);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r4_m" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab3 = tablica;
			k = rand() % (4000 + 1);
			StartCounter();
			tab3.remove(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		tablica.clear();
		plik.close();
	//	break;

	case 20:
		plik.open("wyniki_tablica.txt", ios::out | ios::app);
		for (int i = 0; i < 8000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			tablica.add(j);
		}

		plik << "r8_f" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab1 = tablica;
			StartCounter();
			tab1.remove(0);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r8_b" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab2 = tablica;
			StartCounter();
			tab2.remove(7999);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r8_m" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab3 = tablica;
			k = rand() % (8000 + 1);
			StartCounter();
			tab3.remove(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		tablica.clear();
		plik.close();
	//	break;
	case 21:
		plik.open("wyniki_tablica.txt", ios::out | ios::app);
		for (int i = 0; i < 1000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			tablica.add(j);
		}

		plik << "r1_f_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab1 = tablica;
			StartCounter();
			tab1.remove(0);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r1_b_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab2 = tablica;
			StartCounter();
			tab2.remove(999);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r1_m_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab3 = tablica;
			k = rand() % (1000 + 1);
			StartCounter();
			tab3.remove(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		tablica.clear();
		plik.close();
	//	break;

	case 22:
		plik.open("wyniki_tablica.txt", ios::out | ios::app);
		for (int i = 0; i < 2000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			tablica.add(j);
		}

		plik << "r2_f_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab1 = tablica;
			StartCounter();
			tab1.remove(0);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r2_b_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab2 = tablica;
			StartCounter();
			tab2.remove(1999);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r2_m_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab3 = tablica;
			k = rand() % (2000 + 1);
			StartCounter();
			tab3.remove(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		tablica.clear();
		plik.close();
	//	break;

	case 23:
		plik.open("wyniki_tablica.txt", ios::out | ios::app);
		for (int i = 0; i < 4000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			tablica.add(j);
		}

		plik << "r4_f_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab1 = tablica;
			StartCounter();
			tab1.remove(0);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r4_b_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab2 = tablica;
			StartCounter();
			tab2.remove(3999);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r4_m_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab3 = tablica;
			k = rand() % (4000 + 1);
			StartCounter();
			tab3.remove(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		tablica.clear();
		plik.close();
	//	break;

	case 24:
		plik.open("wyniki_tablica.txt", ios::out | ios::app);
		for (int i = 0; i < 8000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			tablica.add(j);
		}

		plik << "r8_f_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab1 = tablica;
			StartCounter();
			tab1.remove(0);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r8_b_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab2 = tablica;
			StartCounter();
			tab2.remove(7999);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r8_m_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab3 = tablica;
			k = rand() % (8000 + 1);
			StartCounter();
			tab3.remove(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		tablica.clear();
		plik.close();
		//break;
	case 25:
		plik.open("wyniki_tablica.txt", ios::out | ios::app);
		for (int i = 0; i < 1000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			tablica.add(j);
		}

		plik << "fv1" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab2 = tablica;
			k = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			StartCounter();
			tab1.find_v(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		tablica.clear();
		plik.close();
		//	break;

	case 26:
		plik.open("wyniki_tablica.txt", ios::out | ios::app);
		for (int i = 0; i < 2000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			tablica.add(j);
		}

		plik << "fv2" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab2 = tablica;
			k = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			StartCounter();
			tab1.find_v(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		tablica.clear();
		plik.close();
		//	break;

	case 27:
		plik.open("wyniki_tablica.txt", ios::out | ios::app);
		for (int i = 0; i < 4000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			tablica.add(j);
		}

		plik << "fv4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab2 = tablica;
			k = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			StartCounter();
			tab1.find_v(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		tablica.clear();
		plik.close();
		//	break;

	case 28:
		plik.open("wyniki_tablica.txt", ios::out | ios::app);
		for (int i = 0; i < 8000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			tablica.add(j);
		}

		plik << "fv8" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab2 = tablica;
			k = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			StartCounter();
			tab1.find_v(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		tablica.clear();
		plik.close();
		//	break;
	case 29:
		plik.open("wyniki_tablica.txt", ios::out | ios::app);
		for (int i = 0; i < 1000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			tablica.add(j);
		}

		plik << "fv1_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab2 = tablica;
			k = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			StartCounter();
			tab1.find_v(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		tablica.clear();
		plik.close();
		//	break;

	case 30:
		plik.open("wyniki_tablica.txt", ios::out | ios::app);
		for (int i = 0; i < 2000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			tablica.add(j);
		}

		plik << "fv2_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab2 = tablica;
			k = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			StartCounter();
			tab1.find_v(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		tablica.clear();
		plik.close();
		//	break;

	case 31:
		plik.open("wyniki_tablica.txt", ios::out | ios::app);
		for (int i = 0; i < 4000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			tablica.add(j);
		}

		plik << "fv4_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab2 = tablica;
			k = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			StartCounter();
			tab1.find_v(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		tablica.clear();
		plik.close();
		//	break;

	case 32:
		plik.open("wyniki_tablica.txt", ios::out | ios::app);
		for (int i = 0; i < 8000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			tablica.add(j);
		}

		plik << "fv8_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			tab2 = tablica;
			k = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			StartCounter();
			tab1.find_v(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		tablica.clear();
		plik.close();
		system("cls");
		cout << "wykonano!" << endl;
		break;
	default:
		cout << "Blad!";

	}
}

void Menu::menu_list(List &lista)
{
	srand(time(NULL));
	double t[100];
	List l1, l2, l3;
	fstream plik;
	system("cls");
	cout << "1. Dodaj element na poczatek listy" << endl;
	cout << "2. Dodaj element na koniec listy" << endl;
	cout << "3. Dodaj element za podanym elementem" << endl;
	cout << "4. Usun element z poczatku listy" << endl;
	cout << "5. Usun element z konca listy" << endl;
	cout << "6. Usun wybrany element" << endl;
	cout << "7. Wyszukaj element" << endl;
	cout << "8. Wyswietl" << endl;
	cout << "-----------" << endl;
	cout << "9. Eksperyment" << endl;

/*	cout << "8. 1000 losowych elementow i dodaj 1 element (x100)(RAND_MAX)" << endl;
	cout << "9. 2000 losowych elementow i dodaj 1 element (x100)(RAND_MAX)" << endl;
	cout << "10. 4000 losowych elementow i dodaj 1 element (x100)(RAND_MAX)" << endl;
	cout << "11. 8000 losowych elementow i dodaj 1 element (x100)(RAND_MAX)" << endl;
	cout << "12. 1000 losowych elementow i dodaj 1 element (x100)(RAND_MAX/4)" << endl;
	cout << "13. 2000 losowych elementow i dodaj 1 element (x100)(RAND_MAX/4)" << endl;
	cout << "14. 4000 losowych elementow i dodaj 1 element (x100)(RAND_MAX/4)" << endl;
	cout << "15. 8000 losowych elementow i dodaj 1 element (x100)(RAND_MAX/4)" << endl;

	cout << "16. 1000 losowych elementow i usun 1 element (x100)(RAND_MAX)" << endl;
	cout << "17. 2000 losowych elementow i usun 1 element (x100)(RAND_MAX)" << endl;
	cout << "18. 4000 losowych elementow i usun 1 element (x100)(RAND_MAX)" << endl;
	cout << "19. 8000 losowych elementow i usun 1 element (x100)(RAND_MAX)" << endl;
	cout << "20. 1000 losowych elementow i usun 1 element (x100)(RAND_MAX/4)" << endl;
	cout << "21. 2000 losowych elementow i usun 1 element (x100)(RAND_MAX/4)" << endl;
	cout << "22. 4000 losowych elementow i usun 1 element (x100)(RAND_MAX/4)" << endl;
	cout << "23. 8000 losowych elementow i usun 1 element (x100)(RAND_MAX/4)" << endl;

	cout << "24. 1000 losowych elementow i znajdz (x100)(RAND_MAX)" << endl;
	cout << "25. 2000 losowych elementow i znajdz (x100)(RAND_MAX)" << endl;
	cout << "26. 4000 losowych elementow i znajdz (x100)(RAND_MAX)" << endl;
	cout << "27. 8000 losowych elementow i znajdz (x100)(RAND_MAX)" << endl;
	cout << "28. 1000 losowych elementow i znajdz (x100)(RAND_MAX/4)" << endl;
	cout << "29. 2000 losowych elementow i znajdz (x100)(RAND_MAX/4)" << endl;
	cout << "30. 4000 losowych elementow i znajdz (x100)(RAND_MAX/4)" << endl;
	cout << "31. 8000 losowych elementow i znajdz (x100)(RAND_MAX/4)" << endl;
*/
	cout << "Wybor: ";
	int m, i, j, k; cin >> m;
	srand(time(NULL));
	Node *n;
	switch (m)
	{
	case 1:
		system("cls");
		cout << "Podaj warosc wprowdzana: "; cin >> i;
		lista.push_front(i);
		break;
	case 2:
		system("cls");
		cout << "Podaj warosc wprowdzana: "; cin >> i;
		lista.push_back(i);
		break;
	case 3:
		system("cls");
		lista.print();
		cout << "Podaj warosc wprowdzana: "; cin >> i;
		cout << "Podaj element: "; cin >> j;

		Node *n;

		if (j > (lista.getSize() / 2))
		{
			n = lista.getTail();
			int k = lista.getSize() - 1;

			for (k; k > j; k--)
				n = n->prev;

		}
		else
		{
			n = lista.getHead();
			int k = 0;

			for (k; k < j; k++)
				n = n->next;

		}

		lista.insert(n, i);

		break;
	case 4:
		system("cls");
		if (lista.getSize() > 0)
			lista.pop_front();
		else
			cout << "Lista pusta!" << endl;
		break;
	case 5:
		system("cls");
		if (lista.getSize() > 0)
			lista.pop_back();
		else
			cout << "Lista pusta!" << endl;
		break;
	case 6:
		system("cls");
		lista.print();

		cout << endl << "Podaj element: "; cin >> j;
		Node *m;
		if (lista.getSize() <= 0)
			cout << "Lista pusta!" << endl;
		else if (j > lista.getSize() - 1 || j < 0)
			cout << "Element nie znajduje sie w liscie!" << endl;
		else
		{
			if (j > (lista.getSize() / 2))
			{
				m = lista.getTail();
				int k = lista.getSize() - 1;

				for (k; k > j; k--)
					m = m->prev;

			}
			else
			{
				m = lista.getHead();
				int k = 0;

				for (k; k < j; k++)
					m = m->next;

			}
			lista.remove(m);
		}
		break;
	case 7:
		system("cls");
		cout << "Podaj wrtosc: "; cin >> j;
		if (lista.getSize() == 0)
			cout << "Lista pusta!" << endl;
		else
			cout << lista.find_v(j) << endl;
		break;
	case 8:
		system("cls");
		lista.print();
		cout << endl;
		break;
	case 9:
		plik.open("wyniki_lista.txt", ios::out);

		for (int i = 0; i < 1000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			lista.push_back(j);
		}
		l1 = l2 = l3 = lista;
		
		plik << "a1_f" << endl;
		for (int i = 0; i < 100; i++)
		{
			l1 = lista;
			StartCounter();
			l1.push_front(rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a1_b" << endl;
		for (int i = 0; i < 100; i++)
		{
			l2 = lista;
			StartCounter();
			l2.push_back(rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a1_m" << endl;
		
		for (int i = 0; i < 100; i++)
		{
			n = l3.getHead();
			l3 = lista;
			k = rand() % (l3.getSize() + 1);
			StartCounter();
			if (k >(lista.getSize() / 2))
			{
				n = l3.getTail();
				int l = lista.getSize() - 1;

				for (l; l > k; l--)
					n = n->prev;

			}
			else
			{
				n = l3.getHead();
				int l = 0;

				for (l; l < k; l++)
					n = n->next;

			}
			l3.insert(n, rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		lista.clear();
		plik.close();
		//	break;

	case 10:
		plik.open("wyniki_lista.txt", ios::out | ios::app);
		for (int i = 0; i < 2000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			lista.push_back(j);
		}

		plik << "a2_f" << endl;
		for (int i = 0; i < 100; i++)
		{
			l1 = lista;
			StartCounter();
			l1.push_front(rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a2_b" << endl;
		for (int i = 0; i < 100; i++)
		{
			l2 = lista;
			StartCounter();
			l2.push_back(rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a2_m" << endl;
		
		for (int i = 0; i < 100; i++)
		{
			n = l3.getHead();
			l3 = lista;
			k = rand() % (l3.getSize() + 1);
			StartCounter();
			if (k >(lista.getSize() / 2))
			{
				n = l3.getTail();
				int l = lista.getSize() - 1;

				for (l; l > k; l--)
					n = n->prev;

			}
			else
			{
				n = l3.getHead();
				int l = 0;

				for (l; l < k; l++)
					n = n->next;

			}
			l3.insert(n, rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		lista.clear();
		plik.close();
		//	break;

	case 11:
		plik.open("wyniki_lista.txt", ios::out | ios::app);
		for (int i = 0; i < 4000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			lista.push_back(j);
		}

		plik << "a4_f" << endl;
		for (int i = 0; i < 100; i++)
		{
			l1 = lista;
			StartCounter();
			l1.push_front(rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a4_b" << endl;
		for (int i = 0; i < 100; i++)
		{
			l2 = lista;
			StartCounter();
			l2.push_back(rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a4_m" << endl;
		
		for (int i = 0; i < 100; i++)
		{
			n = l3.getHead();
			l3 = lista;
			k = rand() % (l3.getSize() + 1);
			StartCounter();
			if (k >(lista.getSize() / 2))
			{
				n = l3.getTail();
				int l = lista.getSize() - 1;

				for (l; l > k; l--)
					n = n->prev;

			}
			else
			{
				n = l3.getHead();
				int l = 0;

				for (l; l < k; l++)
					n = n->next;

			}
			l3.insert(n, rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		lista.clear();
		plik.close();
		//	break;

	case 12:
		plik.open("wyniki_lista.txt", ios::out | ios::app);
		for (int i = 0; i < 8000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			lista.push_back(j);
		}

		plik << "a8_f" << endl;
		for (int i = 0; i < 100; i++)
		{
			l1 = lista;
			StartCounter();
			l1.push_front(rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a8_b" << endl;
		for (int i = 0; i < 100; i++)
		{
			l2 = lista;
			StartCounter();
			l2.push_back(rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a8_m" << endl;
		for (int i = 0; i < 100; i++)
		{
			n = l3.getHead();
			l3 = lista;
			k = rand() % (l3.getSize() + 1);
			StartCounter();
			if (k >(lista.getSize() / 2))
			{
				n = l3.getTail();
				int l = lista.getSize() - 1;

				for (l; l > k; l--)
					n = n->prev;

			}
			else
			{
				n = l3.getHead();
				int l = 0;

				for (l; l < k; l++)
					n = n->next;

			}
			l3.insert(n, rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		lista.clear();
		plik.close();
		//	break;
	case 13:
		plik.open("wyniki_lista.txt", ios::out | ios::app);
		for (int i = 0; i < 1000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			lista.push_back(j);
		}

		plik << "a1_f_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			l1 = lista;
			StartCounter();
			l1.push_front(rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a1_b_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			l2 = lista;
			StartCounter();
			l2.push_back(rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a1_m_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			n = l3.getHead();
			l3 = lista;
			k = rand() % (l3.getSize() + 1);
			StartCounter();
			if (k >(lista.getSize() / 2))
			{
				n = l3.getTail();
				int l = lista.getSize() - 1;

				for (l; l > k; l--)
					n = n->prev;

			}
			else
			{
				n = l3.getHead();
				int l = 0;

				for (l; l < k; l++)
					n = n->next;

			}
			l3.insert(n, rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		lista.clear();
		plik.close();
		//	break;

	case 14:
		plik.open("wyniki_lista.txt", ios::out | ios::app);
		for (int i = 0; i < 2000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			lista.push_back(j);
		}

		plik << "a2_f_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			l1 = lista;
			StartCounter();
			l1.push_front(rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a2_b_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			l2 = lista;
			StartCounter();
			l2.push_back(rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a2_m_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			n = l3.getHead();
			l3 = lista;
			k = rand() % (l3.getSize() + 1);
			StartCounter();
			if (k >(lista.getSize() / 2))
			{
				n = l3.getTail();
				int l = lista.getSize() - 1;

				for (l; l > k; l--)
					n = n->prev;

			}
			else
			{
				n = l3.getHead();
				int l = 0;

				for (l; l < k; l++)
					n = n->next;

			}
			l3.insert(n, rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		lista.clear();
		plik.close();
		//	break;

	case 15:
		plik.open("wyniki_lista.txt", ios::out | ios::app);
		for (int i = 0; i < 4000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			lista.push_back(j);
		}

		plik << "a4_f_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			l1 = lista;
			StartCounter();
			l1.push_front(rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a4_b_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			l2 = lista;
			StartCounter();
			l2.push_back(rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a4_m_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			n = l3.getHead();
			l3 = lista;
			k = rand() % (l3.getSize() + 1);
			StartCounter();
			if (k >(lista.getSize() / 2))
			{
				n = l3.getTail();
				int l = lista.getSize() - 1;

				for (l; l > k; l--)
					n = n->prev;

			}
			else
			{
				n = l3.getHead();
				int l = 0;

				for (l; l < k; l++)
					n = n->next;

			}
			l3.insert(n, rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		lista.clear();
		plik.close();
		//	break;

	case 16:
		plik.open("wyniki_lista.txt", ios::out | ios::app);
		for (int i = 0; i < 8000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			lista.push_back(j);
		}

		plik << "a8_f_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			l1 = lista;
			StartCounter();
			l1.push_front(j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a8_b_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			l2 = lista;
			StartCounter();
			l2.push_back(j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "a8_m_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			n = l3.getHead();
			l3 = lista;
			k = rand() % (l3.getSize() + 1);
			StartCounter();
			if (k >(lista.getSize() / 2))
			{
				n = l3.getTail();
				int l = lista.getSize() - 1;

				for (l; l > k; l--)
					n = n->prev;

			}
			else
			{
				n = l3.getHead();
				int l = 0;

				for (l; l < k; l++)
					n = n->next;

			}
			l3.insert(n, rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		lista.clear();
		plik.close();
		//	break;
	case 17:
		plik.open("wyniki_lista.txt", ios::out | ios::app);
		for (int i = 0; i < 1000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			lista.push_back(j);
		}

		plik << "r1_f" << endl;
		for (int i = 0; i < 100; i++)
		{
			l1 = lista;
			StartCounter();
			l1.pop_front();
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r1_b" << endl;
		for (int i = 0; i < 100; i++)
		{
			l2 = lista;
			StartCounter();
			l2.pop_back();
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r1_m" << endl;
		for (int i = 0; i < 100; i++)
		{
			n = l3.getHead();
			l3 = lista;
			k = rand() % (l3.getSize() + 1);
			StartCounter();
			if (k >(lista.getSize() / 2))
			{
				n = l3.getTail();
				int l = lista.getSize() - 1;

				for (l; l > k; l--)
					n = n->prev;

			}
			else
			{
				n = l3.getHead();
				int l = 0;

				for (l; l < k; l++)
					n = n->next;

			}
			l3.remove(n);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		lista.clear();
		plik.close();
		//	break;

	case 18:
		plik.open("wyniki_lista.txt", ios::out | ios::app);
		for (int i = 0; i < 2000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			lista.push_back(j);
		}

		plik << "r2_f" << endl;
		for (int i = 0; i < 100; i++)
		{
			l1 = lista;
			StartCounter();
			l1.pop_front();
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r2_b" << endl;
		for (int i = 0; i < 100; i++)
		{
			l2 = lista;
			StartCounter();
			l2.pop_back();
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r2_m" << endl;
		for (int i = 0; i < 100; i++)
		{
			n = l3.getHead();
			l3 = lista;
			k = rand() % (l3.getSize() + 1);
			StartCounter();
			if (k >(lista.getSize() / 2))
			{
				n = l3.getTail();
				int l = lista.getSize() - 1;

				for (l; l > k; l--)
					n = n->prev;

			}
			else
			{
				n = l3.getHead();
				int l = 0;

				for (l; l < k; l++)
					n = n->next;

			}
			l3.remove(n);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		lista.clear();
		plik.close();
		//	break;

	case 19:
		plik.open("wyniki_lista.txt", ios::out | ios::app);
		for (int i = 0; i < 4000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			lista.push_back(j);
		}

		plik << "r4_f" << endl;
		for (int i = 0; i < 100; i++)
		{
			l1 = lista;
			StartCounter();
			l1.pop_front();
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r4_b" << endl;
		for (int i = 0; i < 100; i++)
		{
			l2 = lista;
			StartCounter();
			l2.pop_back();
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r4_m" << endl;
		for (int i = 0; i < 100; i++)
		{
			n = l3.getHead();
			l3 = lista;
			k = rand() % (l3.getSize() + 1);
			StartCounter();
			if (k >(lista.getSize() / 2))
			{
				n = l3.getTail();
				int l = lista.getSize() - 1;

				for (l; l > k; l--)
					n = n->prev;

			}
			else
			{
				n = l3.getHead();
				int l = 0;

				for (l; l < k; l++)
					n = n->next;

			}
			l3.remove(n);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		lista.clear();
		plik.close();
		//	break;

	case 20:
		plik.open("wyniki_lista.txt", ios::out | ios::app);
		for (int i = 0; i < 8000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			lista.push_back(j);
		}

		plik << "r8_f" << endl;
		for (int i = 0; i < 100; i++)
		{
			l1 = lista;
			StartCounter();
			l1.pop_front();
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r8_b" << endl;
		for (int i = 0; i < 100; i++)
		{
			l2 = lista;
			StartCounter();
			l2.pop_back();
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r8_m" << endl;
		for (int i = 0; i < 100; i++)
		{
			n = l3.getHead();
			l3 = lista;
			k = rand() % (l3.getSize() + 1);
			StartCounter();
			if (k >(lista.getSize() / 2))
			{
				n = l3.getTail();
				int l = lista.getSize() - 1;

				for (l; l > k; l--)
					n = n->prev;

			}
			else
			{
				n = l3.getHead();
				int l = 0;

				for (l; l < k; l++)
					n = n->next;

			}
			l3.remove(n);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		lista.clear();
		plik.close();
		//	break;
	case 21:
		plik.open("wyniki_lista.txt", ios::out | ios::app);
		for (int i = 0; i < 1000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			lista.push_back(j);
		}

		plik << "r1_f_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			l1 = lista;
			StartCounter();
			l1.pop_front();
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r1_b_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			l2 = lista;
			StartCounter();
			l2.pop_back();
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r1_m_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			n = l3.getHead();
			l3 = lista;
			k = rand() % (l3.getSize() + 1);
			StartCounter();
			if (k >(lista.getSize() / 2))
			{
				n = l3.getTail();
				int l = lista.getSize() - 1;

				for (l; l > k; l--)
					n = n->prev;

			}
			else
			{
				n = l3.getHead();
				int l = 0;

				for (l; l < k; l++)
					n = n->next;

			}
			l3.remove(n);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		lista.clear();
		plik.close();
		//	break;

	case 22:
		plik.open("wyniki_lista.txt", ios::out | ios::app);
		for (int i = 0; i < 2000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			lista.push_back(j);
		}

		plik << "r2_f_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			l1 = lista;
			StartCounter();
			l1.pop_front();
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r2_b_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			l2 = lista;
			StartCounter();
			l2.pop_back();
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r2_m_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			n = l3.getHead();
			l3 = lista;
			k = rand() % (l3.getSize() + 1);
			StartCounter();
			if (k >(lista.getSize() / 2))
			{
				n = l3.getTail();
				int l = lista.getSize() - 1;

				for (l; l > k; l--)
					n = n->prev;

			}
			else
			{
				n = l3.getHead();
				int l = 0;

				for (l; l < k; l++)
					n = n->next;

			}
			l3.remove(n);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		lista.clear();
		plik.close();
		//	break;

	case 23:
		plik.open("wyniki_lista.txt", ios::out | ios::app);
		for (int i = 0; i < 4000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			lista.push_back(j);
		}

		plik << "r4_f_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			l1 = lista;
			StartCounter();
			l1.pop_front();
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r4_b_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			l2 = lista;
			StartCounter();
			l2.pop_back();
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r4_m_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			n = l3.getHead();
			l3 = lista;
			k = rand() % (l3.getSize() + 1);
			StartCounter();
			if (k >(lista.getSize() / 2))
			{
				n = l3.getTail();
				int l = lista.getSize() - 1;

				for (l; l > k; l--)
					n = n->prev;

			}
			else
			{
				n = l3.getHead();
				int l = 0;

				for (l; l < k; l++)
					n = n->next;

			}
			l3.remove(n);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		lista.clear();
		plik.close();
		//	break;

	case 24:
		plik.open("wyniki_lista.txt", ios::out | ios::app);
		for (int i = 0; i < 8000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			lista.push_back(j);
		}

		plik << "r8_f_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			l1 = lista;
			StartCounter();
			l1.pop_front();
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r8_b_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			l2 = lista;
			StartCounter();
			l2.pop_back();
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		plik << "r8_m_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			n = l3.getHead();
			l3 = lista;
			k = rand() % (l3.getSize() + 1);
			StartCounter();
			if (k >(lista.getSize() / 2))
			{
				n = l3.getTail();
				int l = lista.getSize() - 1;

				for (l; l > k; l--)
					n = n->prev;

			}
			else
			{
				n = l3.getHead();
				int l = 0;

				for (l; l < k; l++)
					n = n->next;

			}
			l3.remove(n);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		lista.clear();
		plik.close();	
		//break;
	case 25:
		plik.open("wyniki_lista.txt", ios::out | ios::app);
		for (int i = 0; i < 1000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			lista.push_back(j);
		}

		plik << "fv1" << endl;
		for (int i = 0; i < 100; i++)
		{
			l1 = lista;
			k = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			StartCounter();
			l1.find_v(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		lista.clear();
		plik.close();
		//	break;

	case 26:
		plik.open("wyniki_lista.txt", ios::out | ios::app);
		for (int i = 0; i < 2000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			lista.push_back(j);
		}

		plik << "fv2" << endl;
		for (int i = 0; i < 100; i++)
		{
			l1 = lista;
			k = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			StartCounter();
			l1.find_v(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		lista.clear();
		plik.close();
		//	break;

	case 27:
		plik.open("wyniki_lista.txt", ios::out | ios::app);
		for (int i = 0; i < 4000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			lista.push_back(j);
		}

		plik << "fv4" << endl;
		for (int i = 0; i < 100; i++)
		{
			l1 = lista;
			k = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			StartCounter();
			l1.find_v(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		lista.clear();
		plik.close();
		//	break;

	case 28:
		plik.open("wyniki_lista.txt", ios::out | ios::app);
		for (int i = 0; i < 8000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			lista.push_back(j);
		}

		plik << "fv8" << endl;
		for (int i = 0; i < 100; i++)
		{
			l1 = lista;
			k = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			StartCounter();
			l1.find_v(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		lista.clear();
		plik.close();
		//	break;
	case 29:
		plik.open("wyniki_lista.txt", ios::out | ios::app);
		for (int i = 0; i < 1000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			lista.push_back(j);
		}

		plik << "fv1_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			l1 = lista;
			k = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			StartCounter();
			l1.find_v(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		lista.clear();
		plik.close();
		//	break;

	case 30:
		plik.open("wyniki_lista.txt", ios::out | ios::app);
		for (int i = 0; i < 2000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			lista.push_back(j);
		}

		plik << "fv2_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			l1 = lista;
			k = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			StartCounter();
			l1.find_v(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		lista.clear();
		plik.close();
		//	break;

	case 31:
		plik.open("wyniki_lista.txt", ios::out | ios::app);
		for (int i = 0; i < 4000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			lista.push_back(j);
		}

		plik << "fv4_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			l1 = lista;
			k = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			StartCounter();
			l1.find_v(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		lista.clear();
		plik.close();
		//	break;

	case 32:
		plik.open("wyniki_lista.txt", ios::out | ios::app);
		for (int i = 0; i < 8000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			lista.push_back(j);
		}

		plik << "fv8_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			l1 = lista;
			k = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			StartCounter();
			l1.find_v(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		lista.clear();
		plik.close();
		system("cls");
		cout << "Wykonano!" << endl;
		break;
	default:
		system("cls");
		cout << "Blad!" << endl;
	}
}

void Menu::menu_heap(BHeap &kopiec)
{
	srand(time(NULL));
	
	system("cls");
	cout << "1. Dodaj element do kopca" << endl;
	cout << "2. Usun korzen" << endl;
	cout << "3. Wyszukiwanie" << endl;
	cout << "4. Wyswietl" << endl;
	cout << "-------------" << endl;
	cout << "5. Eksperyment" << endl;

/*	cout << "4. 1000 losowych elementow i dodaj 1 element (x100)(RAND_MAX)" << endl;
	cout << "5. 2000 losowych elementow i dodaj 1 element (x100)(RAND_MAX)" << endl;
	cout << "6. 4000 losowych elementow i dodaj 1 element (x100)(RAND_MAX)" << endl;
	cout << "7. 8000 losowych elementow i dodaj 1 element (x100)(RAND_MAX)" << endl;
	cout << "8. 1000 losowych elementow i dodaj 1 element (x100)(RAND_MAX/4)" << endl;
	cout << "9. 2000 losowych elementow i dodaj 1 element (x100)(RAND_MAX/4)" << endl;
	cout << "10. 4000 losowych elementow i dodaj 1 element (x100)(RAND_MAX/4)" << endl;
	cout << "11. 8000 losowych elementow i dodaj 1 element (x100)(RAND_MAX/4)" << endl;

	cout << "12. 1000 losowych elementow i usun 1 element (x100)(RAND_MAX)" << endl;
	cout << "13. 2000 losowych elementow i usun 1 element (x100)(RAND_MAX)" << endl;
	cout << "14. 4000 losowych elementow i usun 1 element (x100)(RAND_MAX)" << endl;
	cout << "15. 8000 losowych elementow i usun 1 element (x100)(RAND_MAX)" << endl;
	cout << "16. 1000 losowych elementow i usun 1 element (x100)(RAND_MAX/4)" << endl;
	cout << "17. 2000 losowych elementow i usun 1 element (x100)(RAND_MAX/4)" << endl;
	cout << "18. 4000 losowych elementow i usun 1 element (x100)(RAND_MAX/4)" << endl;
	cout << "19. 8000 losowych elementow i usun 1 element (x100)(RAND_MAX/4)" << endl;

	cout << "20. 1000 losowych elementow i znajdz element (x100)(RAND_MAX)" << endl;
	cout << "21. 2000 losowych elementow i znajdz element (x100)(RAND_MAX)" << endl;
	cout << "22. 4000 losowych elementow i znajdz element (x100)(RAND_MAX)" << endl;
	cout << "23. 8000 losowych elementow i znajdz element (x100)(RAND_MAX)" << endl;
	cout << "24. 1000 losowych elementow i znajdz element (x100)(RAND_MAX/4)" << endl;
	cout << "25. 2000 losowych elementow i znajdz element (x100)(RAND_MAX/4)" << endl;
	cout << "26. 4000 losowych elementow i znajdz element (x100)(RAND_MAX/4)" << endl;
	cout << "27. 8000 losowych elementow i znajdz element (x100)(RAND_MAX/4)" << endl;
	*/
	cout << "Wybor: ";
	int m, i, j, k;
	cin >> m;
	fstream plik;
	BHeap heap;
	double t[100];
	switch (m)
	{
	case 1:
		system("cls");
		cout << "Podaj wartosc elementu: "; cin >> i;
		kopiec.push(i);
		break;
	case 2:
		system("cls");
		if (kopiec.getSize() == 0)
			cout << "Kopiec pusty!" << endl;
		else
			kopiec.pop();
		break;
	case 3:
		system("cls");
		cout << "Podaj wartosc: "; cin >> j;
		if (kopiec.getSize() == 0)
			cout << "Kopiec pusty!" << endl;
		else
			cout << kopiec.find_v(j) << endl;
		break;
	case 4:
		system("cls");
		if (kopiec.getSize() == 0)
			cout << "Kopiec jest pusty!" << endl;
		else
			kopiec.print();
		break;
	case 5:
		plik.open("wyniki_kopiec.txt", ios::out);

		for (int i = 0; i < 1000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			kopiec.push(j);

		}

		system("cls");

		plik << "a1_f" << endl;
		for (int i = 0; i < 100; i++)
		{
			heap = kopiec;
			StartCounter();
			heap.push(rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		kopiec.clear();
		plik.close();
		//	break;

	case 6:
		plik.open("wyniki_kopiec.txt", ios::out | ios::app);
		for (int i = 0; i < 2000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			kopiec.push(j);
		}

		plik << "a2_f" << endl;
		for (int i = 0; i < 100; i++)
		{
			heap = kopiec;
			StartCounter();
			heap.push(rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		kopiec.clear();
		plik.close();
		//	break;

	case 7:
		plik.open("wyniki_kopiec.txt", ios::out | ios::app);
		for (int i = 0; i < 4000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			kopiec.push(j);
		}

		plik << "a4_f" << endl;
		for (int i = 0; i < 100; i++)
		{
			heap = kopiec;
			StartCounter();
			heap.push(rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		kopiec.clear();
		plik.close();
		//	break;

	case 8:
		plik.open("wyniki_kopiec.txt", ios::out | ios::app);
		for (int i = 0; i < 8000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			kopiec.push(j);
		}

		plik << "a8_f" << endl;
		for (int i = 0; i < 100; i++)
		{
			heap = kopiec;
			StartCounter();
			heap.push(rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		kopiec.clear();
		plik.close();
		//	break;
	case 9:
		plik.open("wyniki_kopiec.txt", ios::out | ios::app);
		for (int i = 0; i < 1000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			kopiec.push(j);
		}

		plik << "a1_f_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			heap = kopiec;
			StartCounter();
			heap.push(rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		kopiec.clear();
		plik.close();
		//	break;

	case 10:
		plik.open("wyniki_kopiec.txt", ios::out | ios::app);
		for (int i = 0; i < 2000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			kopiec.push(j);
		}

		plik << "a2_f_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			heap = kopiec;
			StartCounter();
			heap.push(rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		kopiec.clear();
		plik.close();
		//	break;

	case 11:
		plik.open("wyniki_kopiec.txt", ios::out | ios::app);
		for (int i = 0; i < 4000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			kopiec.push(j);
		}

		plik << "a4_f_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			heap = kopiec;
			StartCounter();
			heap.push(rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		kopiec.clear();
		plik.close();
		//	break;

	case 12:
		plik.open("wyniki_kopiec.txt", ios::out | ios::app);
		for (int i = 0; i < 8000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			kopiec.push(j);
		}

		plik << "a8_f_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			heap = kopiec;
			StartCounter();
			heap.push(rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		kopiec.clear();
		plik.close();
		//	break;
	case 13:
		plik.open("wyniki_kopiec.txt", ios::out | ios::app);
		for (int i = 0; i < 1000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			kopiec.push(j);
		}

		plik << "r1_f" << endl;
		for (int i = 0; i < 100; i++)
		{
			heap = kopiec;
			StartCounter();
			heap.pop();
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		kopiec.clear();
		plik.close();
		//	break;

	case 14:
		plik.open("wyniki_kopiec.txt", ios::out | ios::app);
		for (int i = 0; i < 2000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			kopiec.push(j);
		}

		plik << "r2_f" << endl;
		for (int i = 0; i < 100; i++)
		{
			heap = kopiec;
			StartCounter();
			heap.pop();
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		kopiec.clear();
		plik.close();
		//	break;

	case 15:
		plik.open("wyniki_kopiec.txt", ios::out | ios::app);
		for (int i = 0; i < 4000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			kopiec.push(j);
		}

		plik << "r4_f" << endl;
		for (int i = 0; i < 100; i++)
		{
			heap = kopiec;
			StartCounter();
			heap.pop();
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		kopiec.clear();
		plik.close();
		//	break;

	case 16:
		plik.open("wyniki_kopiec.txt", ios::out | ios::app);
		for (int i = 0; i < 8000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			kopiec.push(j);
		}

		plik << "r8_f" << endl;
		for (int i = 0; i < 100; i++)
		{
			heap = kopiec;
			StartCounter();
			heap.pop();
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		kopiec.clear();
		plik.close();
		//	break;
	case 17:
		plik.open("wyniki_kopiec.txt", ios::out | ios::app);
		for (int i = 0; i < 1000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			kopiec.push(j);
		}

		plik << "r1_f_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			heap = kopiec;
			StartCounter();
			heap.pop();
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		kopiec.clear();
		plik.close();
		//	break;

	case 18:
		plik.open("wyniki_kopiec.txt", ios::out | ios::app);
		for (int i = 0; i < 2000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			kopiec.push(j);
		}

		plik << "r2_f_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			heap = kopiec;
			StartCounter();
			heap.pop();
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		kopiec.clear();
		plik.close();
		//	break;

	case 19:
		plik.open("wyniki_kopiec.txt", ios::out | ios::app);
		for (int i = 0; i < 4000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			kopiec.push(j);
		}

		plik << "r4_f_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			heap = kopiec;
			StartCounter();
			heap.pop();
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		kopiec.clear();
		plik.close();
		//	break;

	case 20:
		plik.open("wyniki_kopiec.txt", ios::out | ios::app);
		for (int i = 0; i < 8000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			kopiec.push(j);
		}

		plik << "r8_f_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			heap = kopiec;
			StartCounter();
			heap.pop();
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		kopiec.clear();
		plik.close();
		
		//break;
	case 21:
		plik.open("wyniki_kopiec.txt", ios::out | ios::app);
		for (int i = 0; i < 1000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			kopiec.push(j);
		}

		plik << "fv1" << endl;
		for (int i = 0; i < 100; i++)
		{
			heap = kopiec;
			k = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			StartCounter();
			heap.find_v(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}

		kopiec.clear();
		plik.close();
		//	break;

	case 22:
		plik.open("wyniki_kopiec.txt", ios::out | ios::app);
		for (int i = 0; i < 2000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			kopiec.push(j);
		}

		plik << "fv2" << endl;
		for (int i = 0; i < 100; i++)
		{
			heap = kopiec;
			k = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			StartCounter();
			heap.find_v(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		kopiec.clear();
		plik.close();
		//	break;

	case 23:
		plik.open("wyniki_kopiec.txt", ios::out | ios::app);
		for (int i = 0; i < 4000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			kopiec.push(j);
		}

		plik << "fv4" << endl;
		for (int i = 0; i < 100; i++)
		{
			heap = kopiec;
			k = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			StartCounter();
			heap.find_v(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		kopiec.clear();
		plik.close();
		//	break;

	case 24:
		plik.open("wyniki_kopiec.txt", ios::out | ios::app);
		for (int i = 0; i < 8000; i++)
		{
			j = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			kopiec.push(j);
		}

		plik << "fv8" << endl;
		for (int i = 0; i < 100; i++)
		{
			heap = kopiec;
			k = rand() % (RAND_MAX + RAND_MAX + 1) - RAND_MAX;
			StartCounter();
			heap.find_v(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		kopiec.clear();
		plik.close();
		//	break;
	case 25:
		plik.open("wyniki_kopiec.txt", ios::out | ios::app);
		for (int i = 0; i < 1000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			kopiec.push(j);
		}

		plik << "fv1_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			heap = kopiec;
			k = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			StartCounter();
			heap.find_v(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		kopiec.clear();
		plik.close();
		//	break;

	case 26:
		plik.open("wyniki_kopiec.txt", ios::out | ios::app);
		for (int i = 0; i < 2000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			kopiec.push(j);
		}

		plik << "fv2_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			heap = kopiec;
			k = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			StartCounter();
			heap.find_v(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		kopiec.clear();
		plik.close();
		//	break;

	case 27:
		plik.open("wyniki_kopiec.txt", ios::out | ios::app);
		for (int i = 0; i < 4000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			kopiec.push(j);
		}

		plik << "fv4_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			heap = kopiec;
			k = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			StartCounter();
			heap.find_v(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		kopiec.clear();
		plik.close();
		//	break;

	case 28:
		plik.open("wyniki_kopiec.txt", ios::out | ios::app);
		for (int i = 0; i < 8000; i++)
		{
			j = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			kopiec.push(j);
		}

		plik << "fv8_4" << endl;
		for (int i = 0; i < 100; i++)
		{
			heap = kopiec;
			k = rand() % (RAND_MAX / 4 + RAND_MAX / 4 + 1) - RAND_MAX / 4;
			StartCounter();
			heap.find_v(k);
			t[i] = GetCounter();
			plik << t[i] << endl;
		}
		kopiec.clear();
		plik.close();
		system("cls");
		cout << "wykonano!" << endl;
		break;
	default:
		system("cls");
		cout << "Blad!" << endl;
	}
}

