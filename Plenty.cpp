#include <iostream>
#include "Plenty.h"

using namespace std;

Plenty::Plenty(int s)
{
	size = s;
	data = new int[size];
	for (int k = 0; k < s; k++)
		data[k] = 0;
	beg.elem = &data[0];
	end.elem = &data[size];
}

Plenty::Plenty(const Plenty& p)
{
	size = p.size;
	data = new int[size];
	for (int k = 0; k < size; k++)
		data[k] = p.data[k];
	beg.elem = &data[0];
	end.elem = &data[size];
}

Plenty::~Plenty()
{
	delete[] data;
	size = 0;
}

Plenty& Plenty::operator=(const Plenty& p)
{
	if (this == &p) return *this;
	if (size > p.size)
	{
		for (int i = 0; i < p.size; i++)
		{
			data[i] = p.data[i];
		}
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			data[i] = p.data[i];
		}
	}
	return *this;
}

Plenty& Plenty::operator-(const Plenty& p)
{
	if (size != p.size)
	{
		cout << "" << endl;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			data[i] -= p.data[i];
		}
		return *this;
	}
}

int& Plenty::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "" << endl;
}

int Plenty::operator()()
{
	return size;
}

ostream& operator<<(ostream& out, const Plenty& p)
{
	for (int i = 0; i < p.size;++i)
	{
		out << p.data[i] << " ";
	}
	return out;
}

istream& operator>>(istream& in, Plenty& p)
{
	for (int i = 0; i < p.size; ++i)
	{
		in >> p.data[i];
	}
	return in;
}