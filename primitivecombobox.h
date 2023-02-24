#ifndef PRIMITIVECOMBOBOX_H
#define PRIMITIVECOMBOBOX_H

#include <QWidget>

namespace Ui {
    class PrimitiveComboBox;
}

class PrimitiveComboBox : public QWidget
{
    Q_OBJECT
public:
    explicit PrimitiveComboBox(QWidget *parent = nullptr);
private:
    Ui::PrimitiveComboBox* ui;
signals:

};

#endif // PRIMITIVECOMBOBOX_H
