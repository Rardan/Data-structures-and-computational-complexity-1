#pragma once

#include "Array.h"
#include "List.h"
#include "BHeap.h"
#include "RBTree.h"

// Przemys³aw Skoneczny 234946

class Menu
{
	void menu_array(Array&);
	void menu_list(List&);
	void menu_heap(BHeap&);
public:
	Menu();
	~Menu();
};

