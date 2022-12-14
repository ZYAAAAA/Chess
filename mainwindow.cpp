#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    myopenglwidget = new MyGLWidget(this);
    ui->stackedWidget->addWidget(myopenglwidget);
}

void MainWindow::on_pushButton_2_clicked()
{
    delete myopenglwidget;
    myopenglwidget = nullptr;
}
