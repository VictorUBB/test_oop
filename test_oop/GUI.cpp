#include "GUI.h"

void GUI::initGui()
{
	QHBoxLayout* mainLy = new QHBoxLayout;
	this->setLayout(mainLy);

	//Lista cu elvii
	eleviList = new QListWidget();
	QFont font = QFont{ "Verdana",18 };
	eleviList->setFont(font);
	mainLy->addWidget(eleviList);

	//Celelalte elemente se afla in stanga
	QWidget* left = new QWidget;
	QVBoxLayout* leftLy = new QVBoxLayout;
	left->setLayout(leftLy);
	//Qline ditul cu detalii despre elevi
	detaliiElev = new QLineEdit();
	QFont font1 = QFont{ "Verdana",10 };
	detaliiElev->setFont(font1);
	leftLy->addWidget(detaliiElev);

	//butoanele pentru sortare
	sortare = new QGroupBox("Sortare");
	sortMed = new QPushButton("Medie");
	sortClass = new QPushButton("Clasa");
	sortNume = new QPushButton("Nume");
	unsort = new QPushButton("Nesortat");
	QVBoxLayout* sortLy = new QVBoxLayout;
	sortare->setLayout(sortLy);
	sortLy->addWidget(sortMed);
	sortLy->addWidget(sortClass);
	sortLy->addWidget(sortNume);
	sortLy->addWidget(unsort);

	leftLy->addWidget(sortare);

	mainLy->addWidget(left);
}

void GUI::connectSlots()
{
	QObject::connect(eleviList, &QListWidget::itemSelectionChanged, [&]() {
		int index = get_index();
		vector<Elevi> listEv = serv.getAll();
		Elevi elev = listEv.at(index);
		detaliiElev->setText(QString::fromStdString(std::to_string(elev.getCod()) + " " + elev.getNume() + " " + elev.getPrenume() + " " + std::to_string(elev.getClasa()) + " " + std::to_string(elev.getMedie())));
		});

	QObject::connect(sortMed, &QPushButton::clicked, [&]() {
		vector<Elevi> new_list = serv.sortMedie();
		reloadList(new_list);
		});
	QObject::connect(sortClass, &QPushButton::clicked, [&]() {
		vector<Elevi> new_list = serv.sortClasa();
		reloadList(new_list);
		});
	QObject::connect(sortNume, &QPushButton::clicked, [&]() {
		vector<Elevi> new_list = serv.sortNume();
		reloadList(new_list);
		});
	QObject::connect(unsort, &QPushButton::clicked, [&]() {
		reloadList(serv.getAll());
		});

}

void GUI::reloadList(vector<Elevi> vect)
{
	eleviList->clear();
	for (auto& elev : vect) {
		QListWidgetItem* itm = new QListWidgetItem(
			QString::fromStdString(std::to_string(elev.getCod()) + " " + elev.getNume()));
		if (elev.getMedie() <= 5)
			itm->setBackground(Qt::red);
		else if(elev.getMedie()<9)
				itm->setBackground(Qt::yellow);
		else itm->setBackground(Qt::green);
		eleviList->addItem(itm);
	}
	//eleviList.

}
