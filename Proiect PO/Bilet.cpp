#include "Bilet.h"
#include <iostream>
#include <string>
using namespace std;

Bilet::Bilet() :id(0)
{
	Eveniment e;
	loc = 0;
	nume = "necunoscut";
	zona = "necunoscuta";
	ev = e;
}
Bilet::Bilet(int id, int loc, string nume, string zona,Eveniment ev):id(id)
{
	this->loc = loc;
	this->nume = nume;
	this->zona = zona;
	this->ev = ev;
}
Bilet::Bilet(const Bilet& b) :id(b.id)
{
	this->loc = b.loc;
	this->nume = b.nume;
	this->zona = b.zona;
	this->ev = b.ev;
}
int Bilet::getloc()
{
	return loc;
}
string Bilet::getnume()
{
	return nume;
}
string Bilet::getzonab()
{
	return this->zona;
}
void Bilet::setloc(int loc)
{
	this->loc = loc;
}
void Bilet::setnume(string nume)
{
	this->nume = nume;
}
void Bilet::setzonab(string zona)
{
	this->zona = zona;
}
void Bilet::ocupareloc(Eveniment& e)
{
	Locatie l = e.getloc();
	int locurisala = l;
	int* scaune = l.getlocuri();
	for (int i = 0; i < locurisala; i++)
		if (i == loc) scaune[i] = 1;
	l.setlocuri(locurisala, scaune);
	e.setloc(l);
}

ostream& operator<<(ostream& out, Bilet b)
{
	out << b.id<<endl;
	out << b.loc<<endl;
	out << b.nume<<endl;
	out << b.zona<<endl;
	out << b.ev << endl;
	return out;
}
istream& operator>>(istream& in, Bilet& b)
{
	in >> b.loc;
	in >> b.nume;
	in >> b.zona;
	in >> b.ev;
	return in;
}
void Bilet::bileteramase(int& nrbilete,Bilet& b)
{
	if (b.id != 0)
		nrbilete--;
}
 int Bilet::getnrbilete()
{
	 return nrbilete;
}
 void Bilet::setnrbilete(int nrbil)
 {
	 nrbilete = nrbil;
 }