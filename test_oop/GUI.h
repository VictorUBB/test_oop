#pragma once
#include "Service.h"
#include "QListWidget"
#include "QLayout"
#include "QWidget"
#include "QLineEdit"
#include "QGroupBox"
#include "QPushButton" 
class GUI: public QWidget
{
private:
	Service& serv;
	
	QListWidget* eleviList;
	
	QLineEdit* detaliiElev;
	
	//pelementele pentru sortare
	QGroupBox* sortare;
	QPushButton* sortMed;
	QPushButton* sortClass;
	QPushButton* sortNume;
	QPushButton* unsort;
	//buton pentru stergere
	QPushButton* delBtn;
	//fuctia ce se ocupa de crearea componentei Gui
	void initGui();
	//functia ce leaga butoanele si optiunile de functii si de ce ar trebui sa faca
	void connectSlots();
	//functie ce incarca elevii in lista
	void reloadList(vector<Elevi> vect);
public:
	GUI(Service& s) :serv{ s } {
		initGui();
		connectSlots();
		reloadList(serv.getAll());
	};
	int get_index() {
		auto index = eleviList->selectionModel()->currentIndex();
		return index.row();
	}

};

