#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    //Настройка primitiveBox
    for (auto& primitiveEntry : primitivesList)
        ui->primitiveBox->addItem(primitiveEntry.first);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_primitiveBox_currentTextChanged(const QString &arg1) {
    ui->GLWidget->setPrimitiveType(arg1);
    ui->GLWidget->update();
}

