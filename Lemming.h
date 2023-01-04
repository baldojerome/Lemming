#ifndef LEMMING_H
#define LEMMING_H

#include <iostream>
using namespace std;

class Lemming
{
private:
	int id;
	static int count;

public:
	Lemming();
	friend ostream& operator<< (ostream&, const Lemming&);
	int getId();

};

#endif
