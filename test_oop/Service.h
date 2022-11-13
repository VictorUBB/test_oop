#pragma once
#include "Repo.h"
#include "algorithm"
class Service
{
private:
	Repo& repo;
public:
	Service(Repo& rep) :repo{ rep } {};
	//functie ce returneaza toate lementele din memorie
	vector<Elevi>& getAll();
	//functii desortare
	vector<Elevi> sortMedie();
	vector<Elevi> sortClasa();
	vector<Elevi> sortNume();
};

