#pragma once
#include <iostream>
#include <string>
using namespace std;
//enum zone {
//	Vip = 0,
//	Loja = 1,
//	Premium = 2,
//	Gold = 3,
//};
class Locatie
{
private:
    int nr_locuri;
	int* locuri;
	string zona;
public:
	Locatie();
	Locatie(int* locuri, string zona, int nr_locuri);
	Locatie(const Locatie& l);
	 int getnr_locuri();
	int* getlocuri();
	string getzona();
	void setlocuri(int nr_locuri, int* locuri);
	void setzona(string zona);
	void popularesala();
	//ocupare zona;
	void ocuparezona();
	Locatie& operator=(const Locatie& l)
	{
		this->nr_locuri = l.nr_locuri;
		this->zona = l.zona;
		this->locuri = new int[l.nr_locuri];
		for (int i = 0; i < nr_locuri; i++)
			this->locuri[i] = l.locuri[i];
		return *this;
	}
	int operator[](int index)
	{
		if (index >= 0 && index < nr_locuri)
		{
			return locuri[index];
		}
		else return -1;
	}
	operator string()
	{
		return zona;
	}
	operator int()
	{
		return nr_locuri;
	}
	friend istream& operator>>(istream&, Locatie&);
	friend ostream& operator<<(ostream&,Locatie);
	~Locatie()
	{
		delete[] locuri;
	}
};

