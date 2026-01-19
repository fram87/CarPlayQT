#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    bluetooth = new Bluetooth(this);
    bluetooth->startScan();
}

MainWindow::~MainWindow()
{
    delete ui;
}

