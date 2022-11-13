#pragma once

#include <QtWidgets/QWidget>
#include "ui_test_oop.h"

class test_oop : public QWidget
{
    Q_OBJECT

public:
    test_oop(QWidget *parent = Q_NULLPTR);

private:
    Ui::test_oopClass ui;
};
