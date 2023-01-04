#include "Lemming.h"

#include <iostream>

using namespace std;

Lemming::Lemming()
{
	this->id = ++count;
}

int Lemming::getId()
{
	return id;
}

ostream& operator<< (ostream& out, const Lemming& lemming)
{
	out << lemming.id;
	return out;
}

int Lemming::count = 0;