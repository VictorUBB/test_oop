#include "Repo.h"

vector<Elevi>& Repo::getAll()
{
    return this->elevii;
}

void Repo::addElev(Elevi& ev)
{
    elevii.push_back(ev);
}

void FileRepo::load_from_file()
{
    std::ifstream f(filename);
    while (!f.eof()) {
        int cod, clasa, medie;
        string nume, prenume;
        f >> cod;
        f >> nume;
        f >> prenume;
        f >> clasa;
        f >> medie;
        Elevi el(cod, nume, prenume, clasa, medie);
        Repo::addElev(el);
    }
}

void FileRepo::save_to_file()
{
    std::ofstream f(filename);
    for (auto& el : getAll()) {
        f << el.getCod() << std::endl;
        f << el.getNume() << std::endl;
        f << el.getPrenume() << std::endl;
        f << el.getClasa() << std::endl;
        f << el.getMedie() << std::endl;
    }
    f.close();
}
