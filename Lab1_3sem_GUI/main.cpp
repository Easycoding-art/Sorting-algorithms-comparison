#include "Lab1_3sem_GUI.h"
#include <QtWidgets/QApplication>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qapplication.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Lab1_3sem_GUI w;
    w.Execute();
    return a.exec();
}
