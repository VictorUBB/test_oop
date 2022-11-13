#include "test_oop.h"
#include <QtWidgets/QApplication>
#include "GUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileRepo repo{ "elevi.txt" };
    Service serv{ repo };
    GUI gui{ serv };
    gui.show();
    return a.exec();
}
