#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include<QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_primitiveBox_currentTextChanged(const QString &arg1);

    void on_xScissorSlider_valueChanged(int value);

    void on_yScissorSlider_valueChanged(int value);

    void on_alphaSlider_valueChanged(int value);

    void on_alphaBox_currentTextChanged(const QString &arg1);

    void on_sfactorBox_currentTextChanged(const QString &arg1);

    void on_dfactorBox_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
