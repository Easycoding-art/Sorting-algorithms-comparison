#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_Lab1_3sem_GUI.h"
#include <QPushButton>
#include <QMessageBox>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QPainter>
#include <QDebug>
#include <QComboBox>
#include <QLayout>
#include <QLabel>
#include <Windows.h>
class Lab1_3sem_GUI : public QMainWindow
{
    Q_OBJECT

public:
    Lab1_3sem_GUI(QWidget *parent = nullptr);
    ~Lab1_3sem_GUI();
    void Execute();
public slots:
    void clickedSlot();
    void slot1();
    void slot2();
    void slot3();
    void slot4();

private:
    Ui::Lab1_3sem_GUIClass *ui;
};

