#include "stdafx.h"
#include <iostream>

using namespace std;

#pragma once
class Espars
{
	int **value;
	int exeption;
	int row, col;
public:
	Espars(int, int);
	void insert(int r, int c, int val);
	void print();
	Espars operator +(Espars );
	Espars Transpositoin();
	void  multi (Espars );
};