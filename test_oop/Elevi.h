#pragma once
#include <string>
using std::string;
class Elevi
{
	//clasa ce creaza obiectul de tip elevii
private:
	int codMatr;
	string nume;
	string prenume;
	int clasa;
	int medie;
public:
	Elevi(int c, string n, string p, int cl, int m) :codMatr{ c }, nume{ n }, prenume{ p }, clasa{ cl }, medie{ m }{};
	Elevi(const Elevi& ev) = default;
	int getCod();
	string getNume();
	string getPrenume();
	int getClasa();
	int getMedie();
};

