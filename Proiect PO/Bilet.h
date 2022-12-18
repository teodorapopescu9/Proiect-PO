#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Eveniment.h"

using namespace std;

class Bilet
{
private:
	const int id;
	int loc;
	string nume;
	Eveniment ev;
	string zona;
	static int nrbilete;
public:
	Bilet();
	Bilet(int id, int loc, string nume, string zona,Eveniment ev);
	Bilet(const Bilet& b);
	int getloc();
	string getnume();
	string getzonab();
	void setloc(int loc);
	void setnume(string nume);
	void setzonab(string zona);
	void ocupareloc(Eveniment& e);
	static int getnrbilete();
	static void setnrbilete(int nrbilete);
	static void bileteramase(int& nrbilete,Bilet& b);
	Bilet& operator=(const Bilet& b)
	{
		this->loc = b.loc;
		this->nume = b.nume;
		this->zona = b.zona;
		return *this; 
	}
	bool operator!()
	{
		return id != 0;
	}
	Bilet operator++()
	{
		loc++;
		return *this;
	}
	Bilet operator++(int i)
	{
		Bilet copie = *this;
		loc++;
		return copie;
	}
	Bilet operator--()
	{
		loc--;
		return *this;
	}
	Bilet operator--(int i)
	{
		Bilet copie = *this;
		loc--;
		return copie;
	}

	friend istream& operator>>(istream&, Bilet&);
	friend ostream& operator<<(ostream&, Bilet);

};
int Bilet::nrbilete = 0;
