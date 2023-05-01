#pragma once

#include <iostream>

using namespace std;

class Iterator
{
	friend class Plenty;
	int* elem;
public:
	Iterator() { elem = 0; };
	Iterator(const Iterator& it) { elem = it.elem; };
	bool operator == (const Iterator& it) { return elem == it.elem;};
	bool operator != (const Iterator& it) { return elem != it.elem; };
	void operator++() { ++elem; };
	void operator--() { --elem; };
	int& operator*() const { return*elem; };
};

class Plenty
{
	int size;
	int* data;
	Iterator beg;
	Iterator end;
public:
	Plenty(int s);
	Plenty(const Plenty&);

	Plenty& operator = (const Plenty&);
	Plenty& operator-(const Plenty&);

	int& operator[](int index);
	int operator() ();

	friend ostream& operator<<(ostream& out, const Plenty&);
	friend istream& operator>>(istream& in, Plenty&);

	Iterator first() { return beg; };
	Iterator last() { return end; };

	~Plenty();
};