#include "stdafx.h"
#include <iostream>
#include "Espars.h"

using namespace std;

Espars::Espars(int r, int c)
{
	value = new int*[100];
	for (int i = 0; i<100; i++)
	{
		value[i] = new int[3];
	}
	row = r;
	col = c;
	exeption = 0;
}

void Espars::insert(int r,int c,int val)
{
	if (r > row || c > col) {
		cout << "Error";
	}
	else { 
		value[exeption][0] = r;
		value[exeption][1] = c;
		value[exeption][2] = val;
		exeption++;
	}
}

Espars Espars::Transpositoin()
{
	Espars Transpositoin = *new Espars(row, col);
	Transpositoin.exeption = exeption;
	for (int i = 0; i<exeption ; i++)
	{
		Transpositoin.value[i][0] = value[i][1];
		Transpositoin.value[i][1] = value[i][0];
		Transpositoin.value[i][2] = value[i][2];
	}
	return Transpositoin;
}

void Espars::print()
{
	int i = 0;
	cout << "\n\n\t\t  Row   " << "Column   " << "Sum\n";
	cout << "\t\t --------------------\n";
	for (; i<exeption ; i++)
	{
		cout << "\t\t   " << value[i][0] << "      " << value[i][1] << "      " << value[i][2] << "\n";
	}
	cin.get();
}

Espars Espars::operator +(Espars b)
{
	int repeated = 0;
	for (int i = 1; i<exeption + 1; i++)
	{
		for (int j = 0; j<b.exeption + 1; j++)
		{
			if (value[i][0] == b.value[j][0] && value[i][1] == b.value[j][1])
			{
				repeated++;
				break;
			}
		}
	}
	Espars sum = Espars( value[0][0], value[0][1]);
	sum.exeption = exeption + b.exeption - repeated;
	int index;
	for (index = 0; index<exeption; index++)
	{
		sum.value[index][0] = value[index][0] + 0;
		sum.value[index][1] = value[index][1] + 0;
		sum.value[index][2] = value[index][2] + 0;
	}
	for (int i = 0; i<b.exeption; i++)
	{
		int j = 0;
		for (; j<exeption; j++)
		{
			if (b.value[i][0] == sum.value[j][0] && b.value[i][1] == sum.value[j][1])
			{
				sum.value[j][2] = value[j][2] + b.value[i][2];
				break;
			}
		}
		if (j == exeption)
		{
			sum.value[index][0] = b.value[i][0];
			sum.value[index][1] = b.value[i][1];
			sum.value[index++][2] = b.value[i][2];
		}
	}
	return sum;
}

void Espars::multi(Espars b) {
	//cheking if we can multiply the matrices
	if (col != b.row)
	{
		cout << "We Can't Multiply The Matrices...!!!";
		cin.get();
		exit(0);
	}
	b = b.Transpositoin();
	int apos, bpos;
	Espars result = * new Espars (row, b.col);

	for (apos = 0; apos < exeption;) {
		int r = value[apos][0];
		for (bpos = 0; bpos < b.exeption;) {
			int c = b.value[bpos][0];
			int tempa = apos;
			int tempb = bpos;
			int sum = 0;

			while (tempa < exeption && value[tempa][0] == r && tempb < b.exeption && b.value[tempb][0] == c) {
				if (value[tempa][1] < b.value[tempb][1])
					tempa++;
				else if (value[tempa][1] > b.value[tempb][1])
					tempb++;
				else
					sum += value[tempa++][2] * b.value[tempb++][2];
			}
			if (sum != 0)
				result.insert(r, c, sum);
			while (bpos < b.exeption && b.value [bpos][0] == c)
				bpos++;
		}
		while (apos < exeption && value[apos][0] == r)
			apos++;
	}
	result.print();
}