#pragma once
#include "Elevi.h"
#include <vector>
#include <fstream>
using std::vector;
class Repo
{
private:
	//vectorul in care memoram toate entitatile
	vector<Elevi> elevii;
public:
	vector<Elevi>& getAll();
	//functia de adaugare elevi ce va fi rescrisa
	virtual void addElev(Elevi& ev);
};
class FileRepo : public Repo
{
private:
	//numele fisierului in care vrem sa salvam datele
	string filename;
	//fuctii ce se ocupa cu prluarea datelor si salvarea acestora in fisiere
	void load_from_file();
	void save_to_file();
public:
	FileRepo(string file) :Repo(), filename{ file }{
		load_from_file();
	};
	void addElev(Elevi& ev) override{
		Repo::addElev(ev);
		save_to_file();
	}
};

