#include "Lab1_3sem_GUI.h"
#include <QtWidgets>
#include <QPalette>
#include "write_to_file.h"
int numbers = 0;
Lab1_3sem_GUI::Lab1_3sem_GUI(QWidget *parent)
    : QMainWindow(parent)
{
    ui->setupUi(this);
}


Lab1_3sem_GUI::~Lab1_3sem_GUI()
{}

void Lab1_3sem_GUI:: Execute()
{ 
    this->setStyleSheet("background-color: green");

    QPushButton* button = new QPushButton(this);
    button->setText("Draw graph");
    button->move(20, 100);
    button->resize(50, 60);
    button->setStyleSheet("background-color: purple");
    QObject::connect(button, SIGNAL(clicked()), this, SLOT(clickedSlot()));


    QPushButton* button2 = new QPushButton(this);
    button2->setText("tree sort");
    button2->move(20, 10);
    button2->resize(50, 60);
    button2->setStyleSheet("background-color:blue");
    QObject::connect(button2, SIGNAL(clicked()), this, SLOT(slot1()));

    QPushButton* button3 = new QPushButton(this);
    button3->setText("quick sort");
    button3->move(50, 10);
    button3->resize(50, 60);
    button3->setStyleSheet("background-color:blue");
    QObject::connect(button3, SIGNAL(clicked()), this, SLOT(slot2()));

    QPushButton* button4 = new QPushButton(this);
    button4->setText("shaker sort");
    button4->move(20, 10);
    button4->resize(50, 60);
    button4->setStyleSheet("background-color:blue");
    QObject::connect(button4, SIGNAL(clicked()), this, SLOT(slot3()));

    QPushButton* button5 = new QPushButton(this);
    button5->setText("bubble sort");
    button5->move(50, 10);
    button5->resize(50, 60);
    button5->setStyleSheet("background-color:blue");
    QObject::connect(button5, SIGNAL(clicked()), this, SLOT(slot4()));


    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);
    layout->addWidget(button);
    layout->addWidget(button2);
    layout->addWidget(button3);
    layout->addWidget(button4);
    layout->addWidget(button5);

    setCentralWidget(centralWidget);
    setWindowTitle("Lab1_3sem");
    show();
}

void Lab1_3sem_GUI::clickedSlot()
{
    if (numbers >= 11) {
        write_file(numbers);
        std::string cmd = "python graph.py ";
        system(cmd.c_str());
        numbers = 0;
    }
}

void Lab1_3sem_GUI::slot1() {
    if (numbers < 10) {
        numbers = (numbers * 10) + 1;
    }
}

void Lab1_3sem_GUI::slot2() {
    if (numbers < 10) {
        numbers = (numbers * 10) + 2;
    }
}

void Lab1_3sem_GUI::slot3() {
    if (numbers < 10) {
        numbers = (numbers * 10) + 3;
    }
}

void Lab1_3sem_GUI::slot4() {
    if (numbers < 10) {
        numbers = (numbers * 10) + 4;
    }
}