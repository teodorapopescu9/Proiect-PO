#include "Locatie.h"
#include <iostream>
#include <string>
using namespace std;
Locatie::Locatie()
{
	locuri = nullptr;
	zona = "necunoscuta";
	nr_locuri = 0;
}
Locatie::Locatie(int* locuri, string zona, int nr_locuri)
{
	this->nr_locuri = nr_locuri;
	this->zona = zona;
	delete[] this->locuri;
	this->locuri = new int[nr_locuri];
	for (int i = 0;i < nr_locuri;i++)
		this->locuri[i] = locuri[i];
}
Locatie::Locatie(const Locatie& l)
{
	this->nr_locuri = l.nr_locuri;
	this->zona = l.zona;
	this->locuri = new int[l.nr_locuri];
	for (int i = 0; i < nr_locuri; i++)
		this->locuri[i] = l.locuri[i];
}
int Locatie::getnr_locuri()
{
	return nr_locuri;
}
int* Locatie::getlocuri()
{
	return locuri;
}
string Locatie::getzona()
{
	return zona;
}
void Locatie::setlocuri(int nr_locuri, int* locuri)
{
	delete[] this->locuri;
	this->nr_locuri = nr_locuri;
	this->locuri = new int[nr_locuri];
	for (int i = 0;i < nr_locuri;i++)
		this->locuri[i] = locuri[i];
}
void Locatie::setzona(string zona)
{
	this->zona = zona;
}
void Locatie::popularesala()
{
	delete[] locuri;
	locuri =  new int [nr_locuri];
	for (int i = 0; i < nr_locuri; i++)
		locuri[i] =0;
}
void Locatie::ocuparezona()
{
	int nrlocuripremium = nr_locuri / 4;
	int index = 0;
	for (int i = 0; i < nrlocuripremium / 2; i++)
	{
		locuri[nrlocuripremium / 2 + index] = 2;
		locuri[nrlocuripremium / 2 - index] = 2;
		index++;
	}
}

ostream& operator<<(ostream& out, Locatie l)
{
	out << l.nr_locuri<<endl;
	out << l.zona << endl;
	for (int i = 0;i < l.nr_locuri;i++)
		out << l.locuri[i]<<" ";
	out << endl;
	return out;
}
istream& operator>>(istream& in, Locatie& l)
{
	in >> l.zona;
	in >> l.nr_locuri;
	for (int i = 0;i < l.nr_locuri;i++)
		in >> l.locuri[i];
	return in;
}