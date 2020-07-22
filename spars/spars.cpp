// Espars.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "Espars.h"

using namespace std;

int main()
{
	Espars a(4, 4);
	Espars b(4, 4);
	a.insert(1, 2, 10);
	a.insert(1, 4, 12);
	a.insert(3, 3, 5);
	a.insert(4, 1, 15);
	a.insert(4, 2, 12);
	b.insert(1, 3, 8);
	b.insert(2, 4, 23);
	b.insert(3, 3, 9);
	b.insert(4, 1, 20);
	b.insert(4, 2, 25);

	cout << "martix a:\n";
	a.print();
	cin.get();
	system("cls");
	cout << "martix b:\n";
	b.print();
	cin.get();
	system("cls");

	cout << "martix a.Transposisition:\n";
	a.Transpositoin().print();
	cin.get();
	system("cls");

	cout << "martix a+b:\n";
	(a + b).print();
	cin.get();
	system("cls");

	cout << "martix a*b:\n";
	a.multi(b);
	cin.get();
	cin.get();
}