#include "Eveniment.h"
#include <iostream>
#include <string>
using namespace std;
Eveniment::Eveniment()
{
	Locatie e;
	date.d = 0;
	date.m = 0;
	date.y = 0;
	date.h = 0;
	durata = 0;
	loc = e;
}
Eveniment::Eveniment(string nume, data date, int durata,Locatie loc)
{
	this->date.d = date.d;
	this->date.m = date.m;
	this->date.y = date.y;
	this->date.h = date.h;
	this->durata = durata;
	this->loc = loc;
}
Eveniment::Eveniment(const Eveniment& ev)
{
	this->date.d = ev.date.d;
	this->date.m = ev.date.m;
	this->date.y = ev.date.y;
	this->date.h = ev.date.h;
	this->durata = ev.durata;
	this->nume = ev.nume;
	this->loc = ev.loc;
}
int Eveniment::getdurata()
{
	return this->durata;
}
string Eveniment::getnume()
{
	return this->nume;
}
void Eveniment::setdurata(int durata)
{
	this->durata = durata;
}
void Eveniment::setnume(string nume)
{
	this->nume = nume;
}
ostream& operator<<(ostream& out, Eveniment ev)
{
	out << ev.nume<<endl;
	out << ev.date.d<<endl;
	out << ev.date.m<<endl;
	out << ev.date.y<<endl;
	out << ev.date.h << endl;
	out << ev.durata<<endl;
	return out;
}
istream& operator>>(istream& in, Eveniment& ev)
{
	in >> ev.nume;
	in >> ev.date.d;
	in >> ev.date.m;
	in >> ev.date.y;
	in >> ev.date.h;
	in >> ev.durata;
	return in;
}
Locatie Eveniment::getloc()
{
	return loc;
}
void Eveniment::setloc(Locatie loc)
{
	this->loc = loc;
}