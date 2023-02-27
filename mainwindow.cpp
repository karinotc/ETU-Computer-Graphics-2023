#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    //Настройка primitiveBox
    for (auto& primitiveEntry : primitivesList)
        ui->primitiveBox->addItem(primitiveEntry.first);
    ui->primitiveBox->setCurrentText("GL_POINTS");

    //Настройка слайдеров отсечения
    ui->xScissorSlider->setMaximum(800);
    ui->yScissorSlider->setMaximum(800);

    //Настройка alphaBox
    for (auto& alphaEntry : alphaModeList)
        ui->alphaBox->addItem(alphaEntry.first);
    ui->alphaBox->setCurrentText("GL_ALWAYS");

    //Настройка слайдера прозрачности
    ui->alphaSlider->setMaximum(10);

    //Настройка sfactorBox и dfactorBox
    for (auto& sfactorEntry : sfactorList)
        ui->sfactorBox->addItem(sfactorEntry.first);
    ui->sfactorBox->setCurrentText("GL_ONE");
    for (auto& dfactorEntry : dfactorList)
        ui->dfactorBox->addItem(dfactorEntry.first);
    ui->dfactorBox->setCurrentText("GL_ZERO");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_primitiveBox_currentTextChanged(const QString &arg1) {
    ui->GLWidget->setPrimitiveType(arg1);
    ui->GLWidget->update();
}


void MainWindow::on_xScissorSlider_valueChanged(int value) {
    ui->GLWidget->setScissorCoordinates(value, ui->yScissorSlider->value());
    ui->GLWidget->update();
    ui->xScissorLabel->setText(QString::number(value) + " px");
}


void MainWindow::on_yScissorSlider_valueChanged(int value) {
    ui->GLWidget->setScissorCoordinates(ui->xScissorSlider->value(), value);
    ui->GLWidget->update();
    ui->yScissorLabel->setText(QString::number(value) + " px");
}

void MainWindow::on_alphaSlider_valueChanged(int value) {
    ui->GLWidget->setAlphaValue(static_cast<float>(value*0.1));
    ui->GLWidget->update();
    ui->alphaLabel->setText(QString::number(value*0.1));
}


void MainWindow::on_alphaBox_currentTextChanged(const QString &arg1) {
    ui->GLWidget->setAlphaMode(arg1);
    ui->GLWidget->update();
}


void MainWindow::on_sfactorBox_currentTextChanged(const QString &arg1) {
    ui->GLWidget->setSfactorMode(arg1);
    ui->GLWidget->update();
}


void MainWindow::on_dfactorBox_currentTextChanged(const QString &arg1) {
    ui->GLWidget->setDfactorMode(arg1);
    ui->GLWidget->update();
}

