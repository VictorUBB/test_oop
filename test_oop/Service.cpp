#include "Service.h"

vector<Elevi>& Service::getAll()
{
    return repo.getAll();
}

vector<Elevi> Service::sortMedie()
{
    //vector<Elevi> new_list;
    vector<Elevi> vect = repo.getAll();
    vector<Elevi>::iterator it1;
    vector<Elevi>::iterator it2;
    it1 = vect.begin();
    while(it1!=vect.end()){
        it2 = it1 + 1;
        while(it2!=vect.end())
         {
        
            if ((*it1).getMedie() < (*it2).getMedie()) {
                
                Elevi aux = (*it1);
                (*it1) = (*it2);
                (*it2) = aux;
            }
            it2++;
        }
        it1++;
    }
    return vect;

}

vector<Elevi> Service::sortClasa()
{
    vector<Elevi> vect = repo.getAll();
    vector<Elevi>::iterator it1;
    vector<Elevi>::iterator it2;
    it1 = vect.begin();
    while (it1 != vect.end()) {
        it2 = it1 + 1;
        while (it2 != vect.end())
        {

            if ((*it1).getClasa() < (*it2).getClasa()) {

                Elevi aux = (*it1);
                (*it1) = (*it2);
                (*it2) = aux;
            }
            it2++;
        }
        it1++;
    }
    return vect;
}

vector<Elevi> Service::sortNume()
{
    vector<Elevi> vect = repo.getAll();
    vector<Elevi>::iterator it1;
    vector<Elevi>::iterator it2;
    it1 = vect.begin();
    while (it1 != vect.end()) {
        it2 = it1 + 1;
        while (it2 != vect.end())
        {

            if ((*it1).getNume() < (*it2).getNume()) {

                Elevi aux = (*it1);
                (*it1) = (*it2);
                (*it2) = aux;
            }
            it2++;
        }
        it1++;
    }
    return vect;
}
