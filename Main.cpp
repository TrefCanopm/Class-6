#include <iostream>
#include "Plenty.h"
using namespace std;

int main()
{
	Plenty p(5);
	cout << p << endl;
	cin >> p;
	cout << p << endl;
	p[2] = 100;
	cout << p << endl;
	Plenty pl(10);
	pl = p;
	cout << pl << endl;
	cout << "" << p() << endl;

	cout << *(p.first()) << endl;

	Iterator i = p.first();

	++i;
	cout << *i << endl;
	--i;
	cout << *i << endl;
	for (i = p.first(); i != p.last(); ++i)
		cout << *i << endl;
	return 0;
}