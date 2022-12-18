#pragma once
#include <iostream>
#include <string>
#include "Locatie.h"
using namespace std;
class Eveniment
{
	string nume;
	struct data
	{
		int d, m, y, h;
	};
	data date;
	Locatie loc;
	int durata;
public:
	Eveniment();
	Eveniment(string nume, data date, int durata,Locatie loc);
	Eveniment(const Eveniment& ev);
	int getdurata();
	string getnume();
	void setdurata(int durata);
	void setnume(string nume);
	Locatie getloc();
	void setloc(Locatie loc);

	Eveniment& operator=(const Eveniment& ev)
	{
		this->nume = ev.nume;
		this->date.d = ev.date.d;
		this->date.m = ev.date.m;
		this->date.y = ev.date.y;
		this->date.h = ev.date.h;
		this->durata = ev.durata;
		this->loc = loc;
		return *this;
	}
	bool operator<(const Eveniment& e)
	{
		if (date.y < e.date.y) return 1;
		if (date.y == e.date.y)
			if (date.m < e.date.m) return 1;
		if (date.y == e.date.y && date.m == e.date.m)
			if (date.d < e.date.d) return 1;
		if (date.y == e.date.y && date.m == e.date.m && date.d == e.date.d)
			if (date.h < date.h) return 1;
			 return 0;
	}
	bool operator>(const Eveniment& e)
	{
		if (date.y > e.date.y) return 1;
		if (date.y == e.date.y)
			if (date.m > e.date.m) return 1;
		if (date.y == e.date.y && date.m == e.date.m)
			if (date.d > e.date.d) return 1;
		if (date.y == e.date.y && date.m == e.date.m && date.d == e.date.d)
			if (date.h > date.h) return 1;
		return 0;
	}
	bool operator==(const Eveniment& e)
	{
		if (date.y == e.date.y && date.m == e.date.m && date.d == e.date.d && date.h == e.date.h)
			return 1;
		return 0;
	}
	Eveniment& operator+(Eveniment& e)
	{
		durata = durata + e.durata;
		return *this;
	}
	friend istream& operator>>(istream&, Eveniment&);
	friend ostream& operator<<(ostream&, Eveniment);
};

