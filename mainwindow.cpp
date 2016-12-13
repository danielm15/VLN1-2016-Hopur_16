#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonAddGenius_clicked()
{
   AddGenius geniusDialog;
   geniusDialog.exec();
}

void MainWindow::on_pushButtonAddComputer_clicked()
{
    AddComputer computerDialog;
    computerDialog.exec();
}
